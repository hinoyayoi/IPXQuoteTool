using SolidWorks.Interop.swconst;

namespace IPXQuoteTool.Pricing
{
    public class DefaultQuotePricingRule : IQuotePricingRule
    {
        public QuotePriceResult Calculate(DocumentInfo document, QuotePricingSettings settings)
        {
            double score;
            double discount;

            switch (document.DocumentType)
            {
                case swDocumentTypes_e.swDocPART:
                    score = document.FeatureCount + document.ConfigurationCount;
                    discount = settings.PartDiscount;
                    break;
                case swDocumentTypes_e.swDocASSEMBLY:
                    score = document.ComponentCount + document.MateCount + document.AssemblyFeatureCount;
                    discount = settings.AssemblyDiscount;
                    break;
                case swDocumentTypes_e.swDocDRAWING:
                    score = document.ViewCount + document.DimensionCount + document.TableCount;
                    discount = settings.DrawingDiscount;
                    break;
                default:
                    score = 0;
                    discount = 1;
                    break;
            }

            return new QuotePriceResult
            {
                ComplexityScore = score,
                Discount = discount
            };
        }
    }
}
