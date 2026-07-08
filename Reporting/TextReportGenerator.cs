using SolidWorks.Interop.swconst;
using IPXQuoteTool.Pricing;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IPXQuoteTool.Reporting
{
    public class TextReportGenerator : IReportGenerator
    {
        private readonly IQuotePricingRule _pricingRule = new DefaultQuotePricingRule();

        public string Generate(IReadOnlyList<DocumentInfo> documents, QuotePricingSettings pricingSettings)
        {
            var sb = new StringBuilder();

            var parts = documents.Where(d => d.DocumentType == swDocumentTypes_e.swDocPART).ToList();
            var assemblies = documents.Where(d => d.DocumentType == swDocumentTypes_e.swDocASSEMBLY).ToList();
            var drawings = documents.Where(d => d.DocumentType == swDocumentTypes_e.swDocDRAWING).ToList();

            sb.AppendLine($"{"图纸名",-35} {"类别",-8} {"特征",-6} {"配置项",-8} {"表达式",-8} {"视图",-6} {"标注",-6} {"表格",-6} {"组件数",-8} {"装配约束",-10} {"装配特征",-10} {"对象加权",-10} {"类型系数",-10} {"报价分值",-10}");
            sb.AppendLine(new string('-', 185));

            foreach (var doc in parts)
            {
                AppendDocumentLine(sb, doc, pricingSettings);
            }

            foreach (var doc in assemblies)
            {
                AppendDocumentLine(sb, doc, pricingSettings);
            }

            foreach (var doc in drawings)
            {
                AppendDocumentLine(sb, doc, pricingSettings);
            }

            return sb.ToString();
        }

        private void AppendDocumentLine(StringBuilder sb, DocumentInfo doc, QuotePricingSettings pricingSettings)
        {
            QuotePriceResult price = _pricingRule.Calculate(doc, pricingSettings);
            sb.AppendLine($"{doc.FileName,-35} {doc.Category,-8} {GetPartFeatureCount(doc),-6} {doc.ConfigurationCount,-8} {doc.ExpressionCount,-8} {doc.ViewCount,-6} {doc.DimensionCount,-6} {doc.TableCount,-6} {doc.ComponentCount,-8} {doc.MateCount,-10} {doc.AssemblyFeatureCount,-10} {price.ComplexityScore,-10:0.00} {price.Discount,-10:0.00} {price.FinalScore,-10:0.00}");
        }

        private static int GetPartFeatureCount(DocumentInfo doc)
        {
            return doc.DocumentType == swDocumentTypes_e.swDocPART ? doc.FeatureCount : 0;
        }
    }
}
