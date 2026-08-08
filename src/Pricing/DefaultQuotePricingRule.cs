using SolidWorks.Interop.swconst;

namespace IPXQuoteTool.Pricing
{
    public class DefaultQuotePricingRule : IQuotePricingRule
    {
        public QuotePriceResult Calculate(DocumentInfo document, QuotePricingSettings settings)
        {
            double score;
            double discountCoefficient;
            ObjectCoefficientSettings coefficients = settings.ObjectCoefficients ?? ObjectCoefficientSettings.CreateDefault();

            switch (document.DocumentType)
            {
                case swDocumentTypes_e.swDocPART:
                    score =
                        document.FeatureCount * coefficients.PartFeature +
                        document.ConfigurationCount * coefficients.PartConfiguration +
                        document.ExpressionCount * coefficients.PartExpression;
                    discountCoefficient = settings.PartDiscount;
                    break;
                case swDocumentTypes_e.swDocASSEMBLY:
                    score =
                        document.ComponentCount * coefficients.AssemblyComponent +
                        document.MateCount * coefficients.AssemblyMate +
                        document.AssemblyFeatureCount * coefficients.AssemblyFeature +
                        document.ConfigurationCount * coefficients.AssemblyConfiguration +
                        document.ExpressionCount * coefficients.AssemblyExpression;
                    discountCoefficient = settings.AssemblyDiscount;
                    break;
                case swDocumentTypes_e.swDocDRAWING:
                    score =
                        document.ViewCount * coefficients.DrawingView +
                        document.DimensionCount * coefficients.DrawingDimension +
                        document.TableCount * coefficients.DrawingTable;
                    discountCoefficient = settings.DrawingDiscount;
                    break;
                default:
                    score = 0;
                    discountCoefficient = 1;
                    break;
            }

            double unitPrice = settings.UnitPrice > 0 ? settings.UnitPrice : 3.0;
            double complexityCoefficient = (settings.ComplexityPricing ?? ComplexityPricingSettings.CreateDefault()).GetCoefficient(score);

            return new QuotePriceResult
            {
                ComplexityScore = score,
                UnitPrice = unitPrice,
                ComplexityCoefficient = complexityCoefficient,
                DiscountCoefficient = discountCoefficient
            };
        }
    }
}
