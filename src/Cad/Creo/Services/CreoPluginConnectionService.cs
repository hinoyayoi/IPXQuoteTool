using System;
using System.Threading;
using System.Threading.Tasks;
using IPXQuoteTool.Cad.Creo.Ipc;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal class CreoPluginConnectionService
    {
        private readonly CreoPluginPipeClient _pipeClient;

        public CreoPluginConnectionService()
            : this(new CreoPluginPipeClient())
        {
        }

        internal CreoPluginConnectionService(CreoPluginPipeClient pipeClient)
        {
            _pipeClient = pipeClient;
        }

        public Task<CreoPluginReadyResult> WaitUntilReadyAsync(TimeSpan timeout, CancellationToken cancellationToken = default)
        {
            return WaitUntilReadyAsync(null, timeout, cancellationToken);
        }

        public Task<CreoPluginReadyResult> WaitUntilReadyAsync(CreoPluginEnvironment environment, TimeSpan timeout, CancellationToken cancellationToken = default)
        {
            return Task.Run(() => WaitUntilReady(environment, timeout, cancellationToken), cancellationToken);
        }

        private CreoPluginReadyResult WaitUntilReady(CreoPluginEnvironment environment, TimeSpan timeout, CancellationToken cancellationToken)
        {
            DateTime deadline = DateTime.Now + timeout;
            string statusMessage = null;
            CreoPluginPipeClient pipeClient = environment == null
                ? _pipeClient
                : new CreoPluginPipeClient(environment.PipeName, environment.EnvironmentId);

            while (DateTime.Now < deadline)
            {
                cancellationToken.ThrowIfCancellationRequested();

                if (pipeClient.TryPing(out statusMessage))
                {
                    return CreoPluginReadyResult.Ready(statusMessage);
                }

                Thread.Sleep(500);
            }

            if (string.IsNullOrWhiteSpace(statusMessage))
            {
                statusMessage = "Creo 插件在等待时间内没有返回 Ready 状态。";
            }

            return CreoPluginReadyResult.NotReady(statusMessage);
        }
    }

    internal class CreoPluginReadyResult
    {
        private CreoPluginReadyResult(bool isReady, string statusMessage)
        {
            IsReady = isReady;
            StatusMessage = statusMessage;
        }

        public bool IsReady { get; }
        public string StatusMessage { get; }

        public static CreoPluginReadyResult Ready(string statusMessage)
        {
            return new CreoPluginReadyResult(true, statusMessage);
        }

        public static CreoPluginReadyResult NotReady(string statusMessage)
        {
            return new CreoPluginReadyResult(false, statusMessage);
        }
    }
}