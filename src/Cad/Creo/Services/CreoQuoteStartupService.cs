using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal class CreoQuoteStartupService
    {
        private readonly CreoPluginDeploymentService _pluginSetupService;
        private readonly CreoPluginConnectionService _pluginConnectionService;
        private readonly CreoPluginRuntimeDeployer _pluginRuntimeDeployer;

        public CreoQuoteStartupService()
            : this(new CreoPluginDeploymentService(), new CreoPluginConnectionService(), new CreoPluginRuntimeDeployer())
        {
        }

        internal CreoQuoteStartupService(CreoPluginDeploymentService pluginSetupService, CreoPluginConnectionService pluginConnectionService, CreoPluginRuntimeDeployer pluginRuntimeDeployer)
        {
            _pluginSetupService = pluginSetupService;
            _pluginConnectionService = pluginConnectionService;
            _pluginRuntimeDeployer = pluginRuntimeDeployer;
        }
        public void MinimizeCreoProcesses(CreoPluginEnvironment environment)
        {
            _pluginSetupService.MinimizeCreoProcesses(environment);
        }

        private bool TryDeployPluginRuntime(CreoPluginEnvironment environment, CreoQuoteStartupInteraction interaction, out string error)
        {
            if (_pluginRuntimeDeployer.TryDeploy(environment, out string deployMessage, out error))
            {
                if (!string.IsNullOrWhiteSpace(deployMessage))
                {
                    interaction.Log?.Invoke(deployMessage);
                }

                return true;
            }

            List<CreoProcessInfo> runningProcesses = _pluginSetupService.FindRunningCreoProcesses(environment);
            if (runningProcesses.Count == 0)
            {
                return false;
            }

            if (interaction.ConfirmCloseForPluginRegistration == null || !interaction.ConfirmCloseForPluginRegistration(runningProcesses))
            {
                interaction.Log?.Invoke("用户拒绝关闭 Creo，已停止 Creo 插件运行目录准备。 ");
                return false;
            }

            interaction.Log?.Invoke("正在关闭占用插件的 Creo 进程...");
            if (!_pluginSetupService.CloseCreoProcesses(runningProcesses, out string closeError))
            {
                error = closeError;
                return false;
            }

            if (_pluginRuntimeDeployer.TryDeploy(environment, out deployMessage, out error))
            {
                if (!string.IsNullOrWhiteSpace(deployMessage))
                {
                    interaction.Log?.Invoke(deployMessage);
                }

                return true;
            }

            return false;
        }

        public async Task<CreoQuoteStartupResult> PrepareAsync(string softwarePath, CreoQuoteStartupInteraction interaction)
        {
            interaction ??= new CreoQuoteStartupInteraction();

            if (!_pluginSetupService.TryResolveEnvironment(softwarePath, out CreoPluginEnvironment environment, out string resolveError))
            {
                return CreoQuoteStartupResult.Failed("Creo 路径无效", resolveError);
            }

            interaction.Log?.Invoke($"Creo 启动目录: {environment.BinDirectory}");
            interaction.Log?.Invoke($"Creo 插件注册文件: {environment.RegistryFilePath}");
            interaction.Log?.Invoke($"Creo 插件运行目录: {environment.DeployedPluginDirectory}");
            interaction.Log?.Invoke($"Creo IPC 管道: {environment.PipeName}");

            if (_pluginSetupService.TryRefreshPackagedPluginFromDevelopmentOutput(environment, out string refreshMessage) ||
                !string.IsNullOrWhiteSpace(refreshMessage))
            {
                interaction.Log?.Invoke(refreshMessage);
            }
            if (!_pluginSetupService.HasPackagedPlugin(environment, out string packageError))
            {
                return CreoQuoteStartupResult.Failed(
                    "Creo 插件缺失",
                    packageError + "\n\n请先重新打包，确保发布包中包含 creo-plugin 文件夹。");
            }

            if (!TryDeployPluginRuntime(environment, interaction, out string deployError))
            {
                return CreoQuoteStartupResult.Failed(
                    "Creo 插件运行目录准备失败",
                    deployError ?? "无法复制 Creo 插件到运行目录。");
            }


            if (!_pluginSetupService.IsConfigured(environment))
            {
                if (interaction.ConfirmPluginRegistration == null || !interaction.ConfirmPluginRegistration(environment))
                {
                    interaction.Log?.Invoke("用户取消 Creo 插件配置，已停止 Creo 报价。");
                    return CreoQuoteStartupResult.Cancelled();
                }

                List<CreoProcessInfo> runningProcesses = _pluginSetupService.FindRunningCreoProcesses(environment);
                if (runningProcesses.Count > 0)
                {
                    if (interaction.ConfirmCloseForPluginRegistration == null || !interaction.ConfirmCloseForPluginRegistration(runningProcesses))
                    {
                        interaction.Log?.Invoke("用户拒绝关闭 Creo，已停止 Creo 插件配置。");
                        return CreoQuoteStartupResult.Cancelled();
                    }

                    interaction.Log?.Invoke("正在关闭 Creo 进程...");
                    if (!_pluginSetupService.CloseCreoProcesses(runningProcesses, out string closeError))
                    {
                        return CreoQuoteStartupResult.Failed("关闭 Creo 失败", closeError);
                    }
                }

                interaction.Log?.Invoke("正在请求管理员权限配置 Creo 插件...");
                if (!_pluginSetupService.InstallWithElevation(environment, out string installError))
                {
                    return CreoQuoteStartupResult.Failed("Creo 插件配置失败", installError);
                }

                if (!_pluginSetupService.IsConfigured(environment))
                {
                    return CreoQuoteStartupResult.Failed("Creo 插件配置失败", "Creo 插件配置后未通过验证，请检查 protk.dat 是否写入成功。");
                }

                interaction.LogSuccess?.Invoke("Creo 插件配置已完成。只有插件路径或 Creo 路径变化时才需要重新配置。");
            }
            else
            {
                interaction.Log?.Invoke("Creo 插件配置已存在，跳过管理员配置。 ");
            }

            List<CreoProcessInfo> runningCreoProcesses = _pluginSetupService.FindRunningCreoProcesses(environment);
            if (runningCreoProcesses.Count > 0)
            {
                interaction.Log?.Invoke("检测到运行中的 Creo，正在检查插件 Ready...");
                interaction.SetStatus?.Invoke("检查 Creo 插件...");

                CreoPluginReadyResult existingReadyResult = await _pluginConnectionService.WaitUntilReadyAsync(environment, TimeSpan.FromSeconds(45));
                if (existingReadyResult.IsReady)
                {
                    return CreoQuoteStartupResult.Ready(environment, existingReadyResult.StatusMessage);
                }

                if (interaction.ConfirmRestartForNotReady == null || !interaction.ConfirmRestartForNotReady(runningCreoProcesses, existingReadyResult.StatusMessage))
                {
                    interaction.Log?.Invoke("用户取消关闭 Creo，已停止 Creo 报价。 ");
                    return CreoQuoteStartupResult.Cancelled();
                }

                interaction.Log?.Invoke("正在关闭 Creo 进程...");
                if (!_pluginSetupService.CloseCreoProcesses(runningCreoProcesses, out string closeError))
                {
                    return CreoQuoteStartupResult.Failed("关闭 Creo 失败", closeError);
                }
            }

            if (_pluginSetupService.FindRunningCreoProcesses(environment).Count == 0)
            {
                interaction.Log?.Invoke("未检测到运行中的 Creo，正在启动 Creo...");
                if (!_pluginSetupService.StartCreo(environment, out string startError))
                {
                    return CreoQuoteStartupResult.Failed("启动 Creo 失败", startError);
                }
            }

            interaction.Log?.Invoke("正在等待 Creo 插件 Ready...");
            interaction.SetStatus?.Invoke("等待 Creo 插件...");

            CreoPluginReadyResult readyResult = await _pluginConnectionService.WaitUntilReadyAsync(environment, TimeSpan.FromSeconds(120));
            if (!readyResult.IsReady)
            {
                return CreoQuoteStartupResult.Failed(
                    "Creo 插件未就绪",
                    "Creo 已启动，但报价插件没有返回 Ready 状态。\n\n" +
                    $"状态：{readyResult.StatusMessage}\n\n" +
                    "请确认 Creo 已完全启动，并且 IPXQuoteCreoPlugin 已加载后重试。");
            }

            return CreoQuoteStartupResult.Ready(environment, readyResult.StatusMessage);
        }
    }

    internal class CreoQuoteStartupInteraction
    {
        public Action<string> Log { get; set; }
        public Action<string> LogSuccess { get; set; }
        public Action<string> SetStatus { get; set; }
        public Func<CreoPluginEnvironment, bool> ConfirmPluginRegistration { get; set; }
        public Func<IReadOnlyList<CreoProcessInfo>, bool> ConfirmCloseForPluginRegistration { get; set; }
        public Func<IReadOnlyList<CreoProcessInfo>, string, bool> ConfirmRestartForNotReady { get; set; }
    }

    internal class CreoQuoteStartupResult
    {
        private CreoQuoteStartupResult(bool succeeded, bool cancelled, string title, string message, CreoPluginEnvironment environment, string pluginStatus)
        {
            Succeeded = succeeded;
            IsCancelled = cancelled;
            Title = title;
            Message = message;
            Environment = environment;
            PluginStatus = pluginStatus;
        }

        public bool Succeeded { get; }
        public bool IsCancelled { get; }
        public string Title { get; }
        public string Message { get; }
        public CreoPluginEnvironment Environment { get; }
        public string PluginStatus { get; }

        public static CreoQuoteStartupResult Ready(CreoPluginEnvironment environment, string pluginStatus)
        {
            return new CreoQuoteStartupResult(true, false, null, null, environment, pluginStatus);
        }

        public static CreoQuoteStartupResult Cancelled()
        {
            return new CreoQuoteStartupResult(false, true, null, null, null, null);
        }

        public static CreoQuoteStartupResult Failed(string title, string message)
        {
            return new CreoQuoteStartupResult(false, false, title, message, null, null);
        }
    }
}
