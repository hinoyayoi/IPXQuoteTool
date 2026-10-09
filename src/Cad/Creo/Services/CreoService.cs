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
        private readonly CreoPreviewImageService _previewImageService;
        private CreoPluginEnvironment _pluginEnvironment;

        public CreoService()
            : this(new CreoPluginJsonClient(), new CreoPluginMetricsClient(), new CreoPreviewImageService())
        {
        }

        internal CreoService(CreoPluginJsonClient pluginJsonClient, CreoPluginMetricsClient pluginMetricsClient, CreoPreviewImageService previewImageService)
        {
            _pluginJsonClient = pluginJsonClient;
            _pluginMetricsClient = pluginMetricsClient;
            _previewImageService = previewImageService;
        }
        public string LastError { get; private set; }


        internal void UsePluginEnvironment(CreoPluginEnvironment environment)
        {
            _pluginEnvironment = environment;
            SoftwarePath = environment?.CreoInstallRoot ?? SoftwarePath;
        }
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
                AttachPreviewImage(failedInfo, filePath, null);
                return failedInfo;
            }

            string pipeError;
            string previewOutputPath = _pluginEnvironment == null ? null : _previewImageService.CreatePreviewOutputPath(_pluginEnvironment, filePath);
            CreoDocumentMetricsDto metrics = _pluginMetricsClient.TryReadMetrics(_pluginEnvironment, filePath, previewOutputPath, out pipeError)
                ?? _pluginJsonClient.TryReadDocument(filePath);
            if (metrics == null || string.IsNullOrWhiteSpace(metrics.PreviewImagePath))
            {
                _previewImageService.TryDeletePreviewFile(previewOutputPath);
            }
            if (metrics == null)
            {
                LastError = "Creo plugin did not return metrics through IPC, and no matching manual JSON was found. IPC error: " + (pipeError ?? "none") + ". Manual JSON: " + CreoPluginJsonClient.GetDefaultMetricsPath();
                DocumentInfo failedInfo = CreoDocumentInfoMapper.CreateFailedDocument(filePath, fileName, documentType, LastError);
                AttachPreviewImage(failedInfo, filePath, null);
                return failedInfo;
            }

            DocumentInfo info = CreoDocumentInfoMapper.ToDocumentInfo(metrics);
            AttachPreviewImage(info, filePath, metrics);
            LastError = info?.IsProcessingFailed == true ? info.ProcessingError : null;
            return info;
        }

        private void AttachPreviewImage(DocumentInfo info, string filePath, CreoDocumentMetricsDto metrics)
        {
            if (info == null || info.PreviewImageBytes?.Length > 0)
            {
                return;
            }

            info.PreviewImageBytes = _previewImageService.TryReadPreviewImageBytes(metrics)
                ?? ShellThumbnailService.TryGetThumbnailImageBytes(filePath);
        }

        private static CadDocumentType GetCreoDocumentType(string filePath)
        {
            CadDocumentType documentType = CadFileTypeDetector.GetDocumentTypeFromPath(filePath);
            return documentType;
        }
    }
}









