using IPXQuoteTool.Cad.Common;

namespace IPXQuoteTool.Cad.Creo.Models
{
    public class CreoDocumentMetricsDto
    {
        public string FilePath { get; set; }
        public string FileName { get; set; }
        public CadDocumentType DocumentType { get; set; }
        public int FeatureCount { get; set; }
        public int ConfigurationCount { get; set; }
        public int ExpressionCount { get; set; }
        public int ComponentCount { get; set; }
        public int MateCount { get; set; }
        public int AssemblyFeatureCount { get; set; }
        public int ViewCount { get; set; }
        public int NoteCount { get; set; }
        public int DimensionCount { get; set; }
        public int TableCount { get; set; }
        public bool Succeeded { get; set; }
        public string ErrorMessage { get; set; }
        public bool PreviewImageSucceeded { get; set; }
        public string PreviewImagePath { get; set; }
        public string PreviewImageFormat { get; set; }
        public string PreviewImageError { get; set; }
    }
}
