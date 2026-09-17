using SolidWorks.Interop.swconst;
using IPXQuoteTool;

namespace IPXQuoteTool.Cad.SolidWorks.Analysis
{
    public interface IDocumentMetricExtractor
    {
        swDocumentTypes_e SupportedDocumentType { get; }

        void Extract(DocumentAnalysisContext context, DocumentInfo info);
    }
}
