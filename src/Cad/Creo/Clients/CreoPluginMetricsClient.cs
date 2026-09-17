using IPXQuoteTool.Cad.Creo.Ipc;
using IPXQuoteTool.Cad.Creo.Models;

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
    }
}