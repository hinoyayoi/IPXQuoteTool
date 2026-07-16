using SolidWorks.Interop.swconst;

namespace IPXQuoteTool.Analysis
{
    public interface IDocumentMetricExtractor
    {
        swDocumentTypes_e SupportedDocumentType { get; }

        void Extract(DocumentAnalysisContext context, DocumentInfo info);
    }
}
