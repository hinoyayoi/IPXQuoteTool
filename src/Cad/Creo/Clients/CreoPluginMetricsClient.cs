using IPXQuoteTool.Cad.Creo.Ipc;
using IPXQuoteTool.Cad.Creo.Models;
using IPXQuoteTool.Cad.Creo.Services;

namespace IPXQuoteTool.Cad.Creo.Clients
{
    internal class CreoPluginMetricsClient
    {
        private readonly CreoPluginPipeClient _pipeClient;

        public CreoPluginMetricsClient()
            : this(new CreoPluginPipeClient())
        {
        }

        internal CreoPluginMetricsClient(CreoPluginPipeClient pipeClient)
        {
            _pipeClient = pipeClient;
        }

        public CreoDocumentMetricsDto TryReadMetrics(string filePath, out string errorMessage)
        {
            return _pipeClient.TryReadDocument(filePath, out errorMessage);
        }

        public CreoDocumentMetricsDto TryReadMetrics(CreoPluginEnvironment environment, string filePath, string previewOutputPath, out string errorMessage)
        {
            CreoPluginPipeClient pipeClient = environment == null
                ? _pipeClient
                : new CreoPluginPipeClient(environment.PipeName, environment.EnvironmentId);

            return pipeClient.TryReadDocument(filePath, previewOutputPath, out errorMessage);
        }
    }
}
