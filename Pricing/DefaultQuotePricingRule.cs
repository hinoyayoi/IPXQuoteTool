using SolidWorks.Interop.swconst;

namespace IPXQuoteTool.Pricing
{
    public class DefaultQuotePricingRule : IQuotePricingRule
    {
        public QuotePriceResult Calculate(DocumentInfo document, QuotePricingSettings settings)
        {
            double score;
            double discount;
            ObjectCoefficientSettings coefficients = settings.ObjectCoefficients ?? ObjectCoefficientSettings.CreateDefault();

            switch (document.DocumentType)
            {
                case swDocumentTypes_e.swDocPART:
                    score =
                        document.FeatureCount * coefficients.PartFeature +
                        document.ConfigurationCount * coefficients.PartConfiguration +
                        document.ExpressionCount * coefficients.PartExpression;
                    discount = settings.PartDiscount;
                    break;
                case swDocumentTypes_e.swDocASSEMBLY:
                    score =
                        document.ComponentCount * coefficients.AssemblyComponent +
                        document.MateCount * coefficients.AssemblyMate +
                        document.AssemblyFeatureCount * coefficients.AssemblyFeature +
                        document.ConfigurationCount * coefficients.AssemblyConfiguration +
                        document.ExpressionCount * coefficients.AssemblyExpression;
                    discount = settings.AssemblyDiscount;
                    break;
                case swDocumentTypes_e.swDocDRAWING:
                    score =
                        document.ViewCount * coefficients.DrawingView +
                        document.DimensionCount * coefficients.DrawingDimension +
                        document.TableCount * coefficients.DrawingTable;
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
