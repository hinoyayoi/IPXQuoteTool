using System.IO;
using IPXQuoteTool.Cad.Common;
using IPXQuoteTool.Cad.Creo.Clients;
using IPXQuoteTool.Cad.Creo.Diagnostics;
using IPXQuoteTool.Cad.Creo.Mapping;
using IPXQuoteTool.Cad.Creo.Models;

namespace IPXQuoteTool.Cad.Creo.Services
{
    public class CreoService : ICadDocumentService
    {
        private readonly CreoPluginJsonClient _pluginJsonClient;
        private readonly CreoPluginMetricsClient _pluginMetricsClient;

        public CreoService()
            : this(new CreoPluginJsonClient(), new CreoPluginMetricsClient())
        {
        }

        internal CreoService(CreoPluginJsonClient pluginJsonClient, CreoPluginMetricsClient pluginMetricsClient)
        {
            _pluginJsonClient = pluginJsonClient;
            _pluginMetricsClient = pluginMetricsClient;
        }
        public string LastError { get; private set; }

        public string SoftwarePath { get; set; }

        public CadSoftwareKind SoftwareKind => CadSoftwareKind.Creo;

        public bool CanProcess(string filePath)
        {
            CadDocumentType type = GetCreoDocumentType(filePath);
            return type != CadDocumentType.Unknown;
        }

        public DocumentInfo ProcessDocument(string filePath)
        {
            CadDocumentType documentType = GetCreoDocumentType(filePath);
            string fileName = string.IsNullOrWhiteSpace(filePath) ? string.Empty : Path.GetFileName(filePath);

            LastError = null;

            if (documentType == CadDocumentType.Unknown)
            {
                LastError = "Unsupported Creo file extension.";
                DocumentInfo failedInfo = CreoDocumentInfoMapper.CreateFailedDocument(filePath, fileName, documentType, LastError);
                AttachPreviewImage(failedInfo, filePath);
                return failedInfo;
            }

            string pipeError;
            CreoDocumentMetricsDto metrics = _pluginMetricsClient.TryReadMetrics(filePath, out pipeError)
                ?? _pluginJsonClient.TryReadDocument(filePath);
            if (metrics == null)
            {
                LastError = "Creo plugin did not return metrics through IPC, and no matching manual JSON was found. IPC error: " + (pipeError ?? "none") + ". Manual JSON: " + CreoPluginJsonClient.GetDefaultMetricsPath();
                DocumentInfo failedInfo = CreoDocumentInfoMapper.CreateFailedDocument(filePath, fileName, documentType, LastError);
                AttachPreviewImage(failedInfo, filePath);
                return failedInfo;
            }

            DocumentInfo info = CreoDocumentInfoMapper.ToDocumentInfo(metrics);
            AttachPreviewImage(info, filePath);
            LastError = info?.IsProcessingFailed == true ? info.ProcessingError : null;
            return info;
        }

        private static void AttachPreviewImage(DocumentInfo info, string filePath)
        {
            if (info == null || info.PreviewImageBytes?.Length > 0)
            {
                return;
            }

            info.PreviewImageBytes = ShellThumbnailService.TryGetThumbnailImageBytes(filePath);
        }

        private static CadDocumentType GetCreoDocumentType(string filePath)
        {
            CadDocumentType documentType = CadFileTypeDetector.GetDocumentTypeFromPath(filePath);
            return documentType;
        }
    }
}









