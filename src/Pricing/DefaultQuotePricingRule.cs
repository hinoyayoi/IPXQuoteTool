using IPXQuoteTool.Cad.Common;

namespace IPXQuoteTool.Pricing
{
    public class DefaultQuotePricingRule : IQuotePricingRule
    {
        public QuotePriceResult Calculate(DocumentInfo document, QuotePricingSettings settings)
        {
            double score;
            double discountCoefficient;
            ObjectCoefficientSettings coefficients = settings.ObjectCoefficients ?? ObjectCoefficientSettings.CreateDefault();
            CadSoftwareKind softwareKind = settings.SoftwareKind;

            switch (document.DocumentType)
            {
                case CadDocumentType.Part:
                    score =
                        CalculateObjectScore(document.FeatureCount, coefficients, "零件", "特征", coefficients.PartFeature, softwareKind) +
                        CalculateObjectScore(document.ConfigurationCount, coefficients, "零件", "配置项", coefficients.PartConfiguration, softwareKind) +
                        CalculateObjectScore(document.ExpressionCount, coefficients, "零件", "表达式", coefficients.PartExpression, softwareKind);
                    discountCoefficient = settings.PartDiscount;
                    break;
                case CadDocumentType.Assembly:
                    score =
                        CalculateObjectScore(document.ComponentCount, coefficients, "装配", "组件数", coefficients.AssemblyComponent, softwareKind) +
                        CalculateObjectScore(document.MateCount, coefficients, "装配", "装配约束", coefficients.AssemblyMate, softwareKind) +
                        CalculateObjectScore(document.AssemblyFeatureCount, coefficients, "装配", "装配特征", coefficients.AssemblyFeature, softwareKind) +
                        CalculateObjectScore(document.ConfigurationCount, coefficients, "装配", "配置项", coefficients.AssemblyConfiguration, softwareKind) +
                        CalculateObjectScore(document.ExpressionCount, coefficients, "装配", "表达式", coefficients.AssemblyExpression, softwareKind);
                    discountCoefficient = settings.AssemblyDiscount;
                    break;
                case CadDocumentType.Drawing:
                    score =
                        CalculateObjectScore(document.ViewCount, coefficients, "工程图", "视图", coefficients.DrawingView, softwareKind) +
                        CalculateObjectScore(document.DimensionCount, coefficients, "工程图", "标注", coefficients.DrawingDimension, softwareKind) +
                        CalculateObjectScore(document.TableCount, coefficients, "工程图", "表格", coefficients.DrawingTable, softwareKind);
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

        private static double CalculateObjectScore(int count, ObjectCoefficientSettings coefficients, string category, string objectName, double objectCoefficient, CadSoftwareKind softwareKind)
        {
            return count * objectCoefficient * coefficients.GetSoftwareCoefficient(category, objectName, softwareKind);
        }
    }
}
