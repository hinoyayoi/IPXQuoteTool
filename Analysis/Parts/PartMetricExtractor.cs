using SolidWorks.Interop.swconst;

namespace IPXQuoteTool.Analysis.Parts
{
    public class PartMetricExtractor : IDocumentMetricExtractor
    {
        public swDocumentTypes_e SupportedDocumentType => swDocumentTypes_e.swDocPART;

        public void Extract(DocumentAnalysisContext context, DocumentInfo info)
        {
            info.FeatureCount = PartFeatureCounter.CountFeatures(context.Model);
        }
    }
}
