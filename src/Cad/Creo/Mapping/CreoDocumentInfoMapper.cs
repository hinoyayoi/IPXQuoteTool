using IPXQuoteTool.Cad.Creo.Models;
using IPXQuoteTool.Cad.Common;

namespace IPXQuoteTool.Cad.Creo.Mapping
{
    public static class CreoDocumentInfoMapper
    {
        public static DocumentInfo ToDocumentInfo(CreoDocumentMetricsDto metrics)
        {
            if (metrics == null)
            {
                return CreateFailedDocument(string.Empty, string.Empty, CadDocumentType.Unknown, "Creo metrics are empty.");
            }

            return new DocumentInfo
            {
                FilePath = metrics.FilePath,
                FileName = metrics.FileName,
                DocumentType = metrics.DocumentType,
                FeatureCount = metrics.FeatureCount,
                ConfigurationCount = metrics.ConfigurationCount,
                ExpressionCount = metrics.ExpressionCount,
                ComponentCount = metrics.ComponentCount,
                MateCount = metrics.MateCount,
                AssemblyFeatureCount = metrics.AssemblyFeatureCount,
                ViewCount = metrics.ViewCount,
                NoteCount = metrics.NoteCount,
                DimensionCount = metrics.DimensionCount,
                TableCount = metrics.TableCount,
                IsProcessingFailed = !metrics.Succeeded,
                ProcessingError = metrics.Succeeded ? null : metrics.ErrorMessage
            };
        }

        public static DocumentInfo CreateFailedDocument(string filePath, string fileName, CadDocumentType documentType, string errorMessage)
        {
            return new DocumentInfo
            {
                FilePath = filePath,
                FileName = fileName,
                DocumentType = documentType,
                IsProcessingFailed = true,
                ProcessingError = errorMessage
            };
        }
    }
}
