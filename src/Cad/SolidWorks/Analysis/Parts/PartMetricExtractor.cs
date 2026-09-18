using SolidWorks.Interop.swconst;
using IPXQuoteTool;
using IPXQuoteTool.Cad.SolidWorks.Analysis;

namespace IPXQuoteTool.Cad.SolidWorks.Analysis.Parts
{
    public class PartMetricExtractor : IDocumentMetricExtractor
    {
        public swDocumentTypes_e SupportedDocumentType => swDocumentTypes_e.swDocPART;

        public void Extract(DocumentAnalysisContext context, DocumentInfo info)
        {
            info.FeatureCount = PartFeatureCounter.CountFeatures(context.Model);
            info.ExpressionCount = SolidWorksEquationCounter.CountEquations(context.Model);
        }
    }
}
