using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal class CreoPluginDeploymentService
    {
        private const string PluginName = "IPXQuoteCreoPlugin";
        private const int ShowWindowMinimize = 6;
        private const int ShowWindowForceMinimize = 11;
        private const string PluginDllName = "IPXQuoteCreoPlugin.dll";
        private const string PackagedPluginFolderName = "creo-plugin";
        private const string RuntimePluginRootFolderName = "IPXQuoteTool";
        private const string RuntimePluginFolderName = "CreoPluginRuntime";
        private static readonly string[] CreoProcessNames = { "xtop", "parametric" };

        public bool TryResolveEnvironment(string selectedCreoPath, out CreoPluginEnvironment environment, out string error)
        {
            environment = null;
            error = null;

            string binDirectory = ResolveCreoBinDirectory(selectedCreoPath);
            if (string.IsNullOrWhiteSpace(binDirectory) || !Directory.Exists(binDirectory))
            {
                error = "未找到 Creo 启动目录。请在软件路径中选择 Creo 安装目录，例如：...\\PTC\\Creo 4.0；也兼容选择版本目录 ...\\M010 或 ...\\Parametric\\bin。";
                return false;
            }

            string parametricExePath = Path.Combine(binDirectory, "parametric.exe");
            string parametricBatPath = Path.Combine(binDirectory, "parametric.bat");
            if (!File.Exists(parametricExePath) && !File.Exists(parametricBatPath))
            {
                error = $"选定目录下未找到 parametric.exe 或 parametric.bat：{binDirectory}";
                return false;
            }

            string creoInstallRoot = ResolveCreoInstallRoot(binDirectory);
            if (string.IsNullOrWhiteSpace(creoInstallRoot))
            {
                error = $"无法根据软件路径解析 Creo 安装根目录：{binDirectory}";
                return false;
            }

            string registryFilePath = Path.Combine(binDirectory, "protk.dat");
            string packagedPluginDirectory = Path.Combine(AppContext.BaseDirectory, PackagedPluginFolderName);
            string packagedPluginDllPath = Path.Combine(packagedPluginDirectory, PluginDllName);
            string packagedTextDirectory = Path.Combine(packagedPluginDirectory, "text");
            string environmentId = CreoPluginEnvironmentIdentity.CreateEnvironmentId(creoInstallRoot);
            string pipeName = CreoPluginEnvironmentIdentity.CreatePipeName(environmentId);
            string deployedPluginDirectory = CreoPluginRuntimePath.GetPluginDirectory(environmentId);
            string deployedPluginDllPath = Path.Combine(deployedPluginDirectory, PluginDllName);
            string deployedTextDirectory = Path.Combine(deployedPluginDirectory, "text");

            environment = new CreoPluginEnvironment(
                environmentId,
                pipeName,
                binDirectory,
                parametricExePath,
                parametricBatPath,
                creoInstallRoot,
                registryFilePath,
                packagedPluginDirectory,
                packagedPluginDllPath,
                packagedTextDirectory,
                deployedPluginDirectory,
                deployedPluginDllPath,
                deployedTextDirectory);
            return true;
        }

        public bool TryRefreshPackagedPluginFromDevelopmentOutput(CreoPluginEnvironment environment, out string message)
        {
            message = null;

            if (environment == null)
            {
                return false;
            }

            string sourceDllPath = FindDevelopmentPluginDll(AppContext.BaseDirectory);
            if (string.IsNullOrWhiteSpace(sourceDllPath) || PathsEqual(sourceDllPath, environment.PackagedPluginDllPath))
            {
                return false;
            }

            try
            {
                Directory.CreateDirectory(environment.PackagedPluginDirectory);

                FileInfo sourceInfo = new FileInfo(sourceDllPath);
                FileInfo targetInfo = new FileInfo(environment.PackagedPluginDllPath);
                if (targetInfo.Exists && sourceInfo.Length == targetInfo.Length && FilesHaveSameContent(sourceDllPath, environment.PackagedPluginDllPath))
                {
                    return false;
                }

                File.Copy(sourceDllPath, environment.PackagedPluginDllPath, overwrite: true);
                TryRefreshPluginTextDirectory(sourceDllPath, environment.PackagedTextDirectory);
                message = "本地调试：已同步最新 Creo 插件 DLL 到发布包目录。";
                return true;
            }
            catch (IOException ex)
            {
                message = "本地调试：无法同步最新 Creo 插件 DLL，通常是 Creo 仍在占用旧 DLL。请完全关闭 Creo 后重试。详情：" + ex.Message;
                return false;
            }
            catch (UnauthorizedAccessException ex)
            {
                message = "本地调试：无法同步最新 Creo 插件 DLL，请检查运行目录权限。详情：" + ex.Message;
                return false;
            }
        }
        public bool HasPackagedPlugin(CreoPluginEnvironment environment, out string error)
        {
            error = null;

            if (environment == null)
            {
                error = "Creo 插件环境为空。";
                return false;
            }

            if (!File.Exists(environment.PackagedPluginDllPath))
            {
                error = $"发布包中未找到 Creo 插件 DLL：{environment.PackagedPluginDllPath}";
                return false;
            }

            if (!Directory.Exists(environment.PackagedTextDirectory))
            {
                error = $"发布包中未找到 Creo 插件 text 目录：{environment.PackagedTextDirectory}";
                return false;
            }

            return true;
        }

        private static string FindDevelopmentPluginDll(string startDirectory)
        {
            if (string.IsNullOrWhiteSpace(startDirectory))
            {
                return null;
            }

            string preferredConfiguration = GetConfigurationNameFromPath(startDirectory);
            var candidates = new List<string>();
            DirectoryInfo directory = new DirectoryInfo(startDirectory);
            while (directory != null)
            {
                string artifactPluginRoot = Path.Combine(directory.FullName, "artifacts", "bin", "CreoPlugin", "x64");
                AddPluginDllCandidates(candidates, artifactPluginRoot, preferredConfiguration);

                string legacyPluginRoot = Path.Combine(directory.FullName, "bridges", "CreoPlugin", "x64");
                AddPluginDllCandidates(candidates, legacyPluginRoot, preferredConfiguration);
                directory = directory.Parent;
            }

            return candidates
                .Where(File.Exists)
                .Select(path => new FileInfo(path))
                .OrderByDescending(file => IsPreferredConfiguration(file.FullName, preferredConfiguration))
                .ThenByDescending(file => file.LastWriteTimeUtc)
                .Select(file => file.FullName)
                .FirstOrDefault();
        }

        private static void AddPluginDllCandidates(List<string> candidates, string pluginRoot, string preferredConfiguration)
        {
            if (!string.IsNullOrWhiteSpace(preferredConfiguration))
            {
                candidates.Add(Path.Combine(pluginRoot, preferredConfiguration, PluginDllName));
            }

            candidates.Add(Path.Combine(pluginRoot, "Release", PluginDllName));
            candidates.Add(Path.Combine(pluginRoot, "Debug", PluginDllName));
        }

        private static string GetConfigurationNameFromPath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return null;
            }

            string normalizedPath = path.Replace(Path.AltDirectorySeparatorChar, Path.DirectorySeparatorChar);
            if (normalizedPath.IndexOf(Path.DirectorySeparatorChar + "Debug" + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase) >= 0)
            {
                return "Debug";
            }

            if (normalizedPath.IndexOf(Path.DirectorySeparatorChar + "Release" + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase) >= 0)
            {
                return "Release";
            }

            return null;
        }

        private static bool IsPreferredConfiguration(string path, string preferredConfiguration)
        {
            if (string.IsNullOrWhiteSpace(path) || string.IsNullOrWhiteSpace(preferredConfiguration))
            {
                return false;
            }

            string marker = Path.DirectorySeparatorChar + preferredConfiguration + Path.DirectorySeparatorChar;
            return path.Replace(Path.AltDirectorySeparatorChar, Path.DirectorySeparatorChar)
                .IndexOf(marker, StringComparison.OrdinalIgnoreCase) >= 0;
        }

        private static bool FilesHaveSameContent(string sourcePath, string targetPath)
        {
            const int BufferSize = 81920;
            using FileStream sourceStream = File.OpenRead(sourcePath);
            using FileStream targetStream = File.OpenRead(targetPath);
            byte[] sourceBuffer = new byte[BufferSize];
            byte[] targetBuffer = new byte[BufferSize];

            while (true)
            {
                int sourceRead = sourceStream.Read(sourceBuffer, 0, sourceBuffer.Length);
                int targetRead = targetStream.Read(targetBuffer, 0, targetBuffer.Length);
                if (sourceRead != targetRead)
                {
                    return false;
                }

                if (sourceRead == 0)
                {
                    return true;
                }

                for (int index = 0; index < sourceRead; index++)
                {
                    if (sourceBuffer[index] != targetBuffer[index])
                    {
                        return false;
                    }
                }
            }
        }

        private static void TryRefreshPluginTextDirectory(string sourceDllPath, string targetTextDirectory)
        {
            try
            {
                DirectoryInfo pluginProjectDirectory = new DirectoryInfo(Path.GetDirectoryName(sourceDllPath));
                if (pluginProjectDirectory.Parent != null &&
                    (pluginProjectDirectory.Name.Equals("Release", StringComparison.OrdinalIgnoreCase) ||
                     pluginProjectDirectory.Name.Equals("Debug", StringComparison.OrdinalIgnoreCase)))
                {
                    pluginProjectDirectory = pluginProjectDirectory.Parent;
                }

                if (pluginProjectDirectory.Parent != null && pluginProjectDirectory.Name.Equals("x64", StringComparison.OrdinalIgnoreCase))
                {
                    pluginProjectDirectory = pluginProjectDirectory.Parent;
                }

                string sourceTextDirectory = Path.Combine(pluginProjectDirectory.FullName, "text");
                if (!Directory.Exists(sourceTextDirectory))
                {
                    return;
                }

                foreach (string sourceFile in Directory.GetFiles(sourceTextDirectory, "*", SearchOption.AllDirectories))
                {
                    string relativePath = sourceFile.Substring(sourceTextDirectory.Length).TrimStart(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar);
                    string targetFile = Path.Combine(targetTextDirectory, relativePath);
                    Directory.CreateDirectory(Path.GetDirectoryName(targetFile));
                    File.Copy(sourceFile, targetFile, overwrite: true);
                }
            }
            catch
            {
                // Text resources are best-effort for local debugging; the DLL freshness check is the critical part.
            }
        }
        public bool IsConfigured(CreoPluginEnvironment environment)
        {
            if (environment == null || !File.Exists(environment.RegistryFilePath))
            {
                return false;
            }

            try
            {
                string text = File.ReadAllText(environment.RegistryFilePath);
                string block = ExtractPluginBlock(text);
                if (string.IsNullOrWhiteSpace(block))
                {
                    return false;
                }

                string expectedExecFile = NormalizePath(environment.PluginDllPath);
                string expectedTextDir = NormalizePath(environment.TextDirectory);
                string actualExecFile = NormalizePath(ReadRegistryField(block, "exec_file"));
                string actualTextDir = NormalizePath(ReadRegistryField(block, "text_dir"));

                return PathsEqual(expectedExecFile, actualExecFile) && PathsEqual(expectedTextDir, actualTextDir);
            }
            catch
            {
                return false;
            }
        }

        public bool InstallWithElevation(CreoPluginEnvironment environment, out string error)
        {
            error = null;

            if (environment == null)
            {
                error = "Creo 插件环境为空，无法安装插件。";
                return false;
            }

            string registryBlock = BuildRegistryBlock(environment);
            string script = BuildInstallScript(environment.RegistryFilePath, registryBlock);
            string encodedScript = Convert.ToBase64String(Encoding.Unicode.GetBytes(script));

            try
            {
                var startInfo = new ProcessStartInfo
                {
                    FileName = "powershell.exe",
                    Arguments = "-NoProfile -ExecutionPolicy Bypass -EncodedCommand " + encodedScript,
                    UseShellExecute = true,
                    Verb = "runas",
                    WindowStyle = ProcessWindowStyle.Hidden
                };

                using Process process = Process.Start(startInfo);
                if (process == null)
                {
                    error = "未能启动 Creo 插件配置进程。";
                    return false;
                }

                process.WaitForExit();
                if (process.ExitCode != 0)
                {
                    error = $"Creo 插件配置失败，退出码：{process.ExitCode}";
                    return false;
                }

                return true;
            }
            catch (Win32Exception ex) when ((uint)ex.NativeErrorCode == 1223)
            {
                error = "用户取消了管理员权限请求，无法完成 Creo 插件配置。";
                return false;
            }
            catch (Exception ex)
            {
                error = "Creo 插件配置失败：" + ex.Message;
                return false;
            }
        }
        private delegate bool EnumWindowsProc(IntPtr hWnd, IntPtr lParam);

        [DllImport("user32.dll")]
        private static extern bool ShowWindowAsync(IntPtr hWnd, int nCmdShow);

        [DllImport("user32.dll")]
        private static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        [DllImport("user32.dll")]
        private static extern bool EnumWindows(EnumWindowsProc lpEnumFunc, IntPtr lParam);

        [DllImport("user32.dll")]
        private static extern bool IsWindowVisible(IntPtr hWnd);


        [DllImport("user32.dll")]
        private static extern uint GetWindowThreadProcessId(IntPtr hWnd, out int processId);

        public void MinimizeCreoProcesses(CreoPluginEnvironment environment)
        {
            var processIds = new HashSet<int>(FindRunningCreoProcesses(environment).Select(process => process.ProcessId));
            if (processIds.Count == 0)
            {
                return;
            }

            EnumWindows((windowHandle, _) =>
            {
                try
                {
                    if (!IsWindowVisible(windowHandle))
                    {
                        return true;
                    }

                    GetWindowThreadProcessId(windowHandle, out int windowProcessId);
                    if (processIds.Contains(windowProcessId))
                    {
                        ShowWindowAsync(windowHandle, ShowWindowForceMinimize);
                        ShowWindow(windowHandle, ShowWindowMinimize);
                    }
                }
                catch
                {
                }

                return true;
            }, IntPtr.Zero);
        }


        public List<CreoProcessInfo> FindRunningCreoProcesses(CreoPluginEnvironment environment)
        {
            var processes = new List<CreoProcessInfo>();
            if (environment == null)
            {
                return processes;
            }

            foreach (string processName in CreoProcessNames)
            {
                foreach (Process process in Process.GetProcessesByName(processName))
                {
                    string processPath = TryGetProcessPath(process);
                    if (!string.IsNullOrWhiteSpace(processPath) && !IsUnderDirectory(processPath, environment.CreoInstallRoot))
                    {
                        process.Dispose();
                        continue;
                    }

                    processes.Add(new CreoProcessInfo(process.Id, process.ProcessName, processPath));
                    process.Dispose();
                }
            }

            return processes
                .GroupBy(process => process.ProcessId)
                .Select(group => group.First())
                .OrderBy(process => process.ProcessName, StringComparer.OrdinalIgnoreCase)
                .ThenBy(process => process.ProcessId)
                .ToList();
        }

        public bool CloseCreoProcesses(IEnumerable<CreoProcessInfo> processes, out string error)
        {
            error = null;

            foreach (CreoProcessInfo processInfo in processes ?? Enumerable.Empty<CreoProcessInfo>())
            {
                try
                {
                    using Process process = Process.GetProcessById(processInfo.ProcessId);
                    if (process.HasExited)
                    {
                        continue;
                    }

                    if (process.CloseMainWindow())
                    {
                        process.WaitForExit(15000);
                    }

                    if (!process.HasExited)
                    {
                        error = $"Creo 进程仍在运行：{processInfo.DisplayName}。请保存文件并手动关闭 Creo 后重试。";
                        return false;
                    }
                }
                catch (ArgumentException)
                {
                }
                catch (Exception ex)
                {
                    error = $"关闭 Creo 进程失败：{processInfo.DisplayName}，原因：{ex.Message}";
                    return false;
                }
            }

            return true;
        }

        public bool StartCreo(CreoPluginEnvironment environment, out string error)
        {
            error = null;

            if (environment == null)
            {
                error = "Creo 插件环境为空，无法启动 Creo。";
                return false;
            }

            string startPath = File.Exists(environment.ParametricExePath)
                ? environment.ParametricExePath
                : environment.ParametricBatPath;

            if (!File.Exists(startPath))
            {
                error = $"未找到 Creo 启动程序：{startPath}";
                return false;
            }

            try
            {
                var startInfo = new ProcessStartInfo
                {
                    FileName = startPath,
                    WorkingDirectory = environment.BinDirectory,
                    UseShellExecute = true,
                    WindowStyle = ProcessWindowStyle.Normal
                };
                Process.Start(startInfo);
                return true;
            }
            catch (Exception ex)
            {
                error = "启动 Creo 失败：" + ex.Message;
                return false;
            }
        }
        private static string ResolveCreoBinDirectory(string selectedCreoPath)
        {
            if (string.IsNullOrWhiteSpace(selectedCreoPath))
            {
                return null;
            }

            string normalizedPath = NormalizePath(selectedCreoPath.Trim().Trim('"'));
            if (File.Exists(normalizedPath))
            {
                string fileName = Path.GetFileName(normalizedPath);
                if (fileName.Equals("parametric.exe", StringComparison.OrdinalIgnoreCase) ||
                    fileName.Equals("parametric.bat", StringComparison.OrdinalIgnoreCase))
                {
                    return NormalizePath(Path.GetDirectoryName(normalizedPath));
                }

                return null;
            }

            if (!Directory.Exists(normalizedPath))
            {
                return null;
            }

            if (File.Exists(Path.Combine(normalizedPath, "parametric.exe")) ||
                File.Exists(Path.Combine(normalizedPath, "parametric.bat")))
            {
                return normalizedPath;
            }

            string commonBin = Path.Combine(normalizedPath, "Parametric", "bin");
            if (IsCreoBinDirectory(commonBin))
            {
                return NormalizePath(commonBin);
            }

            string nestedBin = FindCreoBinDirectoryBelow(normalizedPath);
            if (!string.IsNullOrWhiteSpace(nestedBin))
            {
                return nestedBin;
            }

            return null;
        }

        private static bool IsCreoBinDirectory(string directoryPath)
        {
            return !string.IsNullOrWhiteSpace(directoryPath) &&
                Directory.Exists(directoryPath) &&
                (File.Exists(Path.Combine(directoryPath, "parametric.exe")) ||
                 File.Exists(Path.Combine(directoryPath, "parametric.bat")));
        }

        private static string FindCreoBinDirectoryBelow(string rootDirectory)
        {
            if (string.IsNullOrWhiteSpace(rootDirectory) || !Directory.Exists(rootDirectory))
            {
                return null;
            }

            try
            {
                var pending = new Queue<DirectorySearchItem>();
                pending.Enqueue(new DirectorySearchItem(rootDirectory, 0));

                while (pending.Count > 0)
                {
                    DirectorySearchItem current = pending.Dequeue();
                    string candidate = Path.Combine(current.DirectoryPath, "Parametric", "bin");
                    if (IsCreoBinDirectory(candidate))
                    {
                        return NormalizePath(candidate);
                    }

                    if (current.Depth >= 3)
                    {
                        continue;
                    }

                    foreach (string childDirectory in Directory.EnumerateDirectories(current.DirectoryPath))
                    {
                        pending.Enqueue(new DirectorySearchItem(childDirectory, current.Depth + 1));
                    }
                }
            }
            catch
            {
            }

            return null;
        }

        private static string ResolveCreoInstallRoot(string binDirectory)
        {
            try
            {
                var binInfo = new DirectoryInfo(binDirectory);
                if (binInfo.Name.Equals("bin", StringComparison.OrdinalIgnoreCase) &&
                    binInfo.Parent?.Name.Equals("Parametric", StringComparison.OrdinalIgnoreCase) == true &&
                    binInfo.Parent.Parent != null)
                {
                    return NormalizePath(binInfo.Parent.Parent.FullName);
                }

                DirectoryInfo current = binInfo;
                while (current != null)
                {
                    if (Directory.Exists(Path.Combine(current.FullName, "Common Files", "text")) &&
                        Directory.Exists(Path.Combine(current.FullName, "Parametric", "bin")))
                    {
                        return NormalizePath(current.FullName);
                    }

                    current = current.Parent;
                }
            }
            catch
            {
            }

            return null;
        }

        private static string BuildRegistryBlock(CreoPluginEnvironment environment)
        {
            return string.Join(Environment.NewLine, new[]
            {
                "name " + PluginName,
                "startup dll",
                "exec_file " + environment.PluginDllPath,
                "text_dir " + environment.TextDirectory,
                "revision 4",
                "end"
            }) + Environment.NewLine;
        }

        private static string BuildInstallScript(string registryFilePath, string registryBlock)
        {
            return @"
$ErrorActionPreference = 'Stop'
$target = " + ToPowerShellString(registryFilePath) + @"
$block = @'
" + registryBlock + @"'@
$directory = Split-Path -Parent $target
if (!(Test-Path -LiteralPath $directory)) {
    New-Item -ItemType Directory -Path $directory -Force | Out-Null
}
$text = ''
if (Test-Path -LiteralPath $target) {
    $text = Get-Content -LiteralPath $target -Raw -ErrorAction SilentlyContinue
    if ($null -eq $text) { $text = '' }
}
$pattern = '(?ims)^\s*name\s+IPXQuoteCreoPlugin\s*$.*?^\s*end\s*$\r?\n?'
$text = [regex]::Replace($text, $pattern, '')
$text = $text.TrimEnd(" + '"' + "`r" + '"' + @", " + '"' + "`n" + '"' + @")
if ($text.Length -gt 0) {
    $text += " + '"' + "`r`n`r`n" + '"' + @"
}
$text += $block
Set-Content -LiteralPath $target -Value $text -Encoding ASCII
";
        }

        private static string ExtractPluginBlock(string registryText)
        {
            if (string.IsNullOrWhiteSpace(registryText))
            {
                return null;
            }

            Match match = Regex.Match(
                registryText,
                @"(?ims)^\s*name\s+IPXQuoteCreoPlugin\s*$.*?^\s*end\s*$",
                RegexOptions.IgnoreCase | RegexOptions.Multiline | RegexOptions.Singleline);
            return match.Success ? match.Value : null;
        }

        private static string ReadRegistryField(string block, string fieldName)
        {
            if (string.IsNullOrWhiteSpace(block))
            {
                return null;
            }

            Match match = Regex.Match(
                block,
                @"(?im)^\s*" + Regex.Escape(fieldName) + @"\s+(.+?)\s*$",
                RegexOptions.IgnoreCase | RegexOptions.Multiline);
            return match.Success ? match.Groups[1].Value.Trim().Trim('"') : null;
        }

        private static string TryGetProcessPath(Process process)
        {
            try
            {
                return NormalizePath(process.MainModule?.FileName);
            }
            catch
            {
                return null;
            }
        }

        private static bool IsUnderDirectory(string path, string directory)
        {
            string normalizedPath = NormalizePath(path);
            string normalizedDirectory = NormalizePath(directory);
            if (string.IsNullOrWhiteSpace(normalizedPath) || string.IsNullOrWhiteSpace(normalizedDirectory))
            {
                return false;
            }

            return normalizedPath.StartsWith(
                normalizedDirectory.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar) + Path.DirectorySeparatorChar,
                StringComparison.OrdinalIgnoreCase);
        }

        private static bool PathsEqual(string left, string right)
        {
            string normalizedLeft = NormalizePath(left);
            string normalizedRight = NormalizePath(right);
            return string.Equals(normalizedLeft, normalizedRight, StringComparison.OrdinalIgnoreCase);
        }

        private static string NormalizePath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return null;
            }

            try
            {
                return Path.GetFullPath(path.Trim().Trim('"')).TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar);
            }
            catch
            {
                return path.Trim().Trim('"');
            }
        }

        private static string ToPowerShellString(string value)
        {
            return "'" + (value ?? string.Empty).Replace("'", "''") + "'";
        }
    }

    internal class DirectorySearchItem
    {
        public DirectorySearchItem(string directoryPath, int depth)
        {
            DirectoryPath = directoryPath;
            Depth = depth;
        }

        public string DirectoryPath { get; }
        public int Depth { get; }
    }
    internal class CreoPluginEnvironment
    {
        public CreoPluginEnvironment(
            string environmentId,
            string pipeName,
            string binDirectory,
            string parametricExePath,
            string parametricBatPath,
            string creoInstallRoot,
            string registryFilePath,
            string packagedPluginDirectory,
            string packagedPluginDllPath,
            string packagedTextDirectory,
            string deployedPluginDirectory,
            string pluginDllPath,
            string textDirectory)
        {
            EnvironmentId = environmentId;
            PipeName = pipeName;
            BinDirectory = binDirectory;
            ParametricExePath = parametricExePath;
            ParametricBatPath = parametricBatPath;
            CreoInstallRoot = creoInstallRoot;
            RegistryFilePath = registryFilePath;
            PackagedPluginDirectory = packagedPluginDirectory;
            PackagedPluginDllPath = packagedPluginDllPath;
            PackagedTextDirectory = packagedTextDirectory;
            DeployedPluginDirectory = deployedPluginDirectory;
            PluginDllPath = pluginDllPath;
            TextDirectory = textDirectory;
        }

        public string EnvironmentId { get; }
        public string PipeName { get; }
        public string BinDirectory { get; }
        public string ParametricExePath { get; }
        public string ParametricBatPath { get; }
        public string CreoInstallRoot { get; }
        public string RegistryFilePath { get; }
        public string PackagedPluginDirectory { get; }
        public string PackagedPluginDllPath { get; }
        public string PackagedTextDirectory { get; }
        public string DeployedPluginDirectory { get; }
        public string PluginDllPath { get; }
        public string TextDirectory { get; }
    }

    internal class CreoProcessInfo
    {
        public CreoProcessInfo(int processId, string processName, string executablePath)
        {
            ProcessId = processId;
            ProcessName = processName;
            ExecutablePath = executablePath;
        }

        public int ProcessId { get; }
        public string ProcessName { get; }
        public string ExecutablePath { get; }

        public string DisplayName
        {
            get
            {
                return string.IsNullOrWhiteSpace(ExecutablePath)
                    ? $"{ProcessName}.exe (PID {ProcessId})"
                    : $"{ProcessName}.exe (PID {ProcessId}) - {ExecutablePath}";
            }
        }
    }
}



