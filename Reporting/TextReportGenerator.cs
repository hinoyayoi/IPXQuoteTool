using SolidWorks.Interop.swconst;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IPXQuoteTool.Reporting
{
    public class TextReportGenerator : IReportGenerator
    {
        public string Generate(IReadOnlyList<DocumentInfo> documents)
        {
            var sb = new StringBuilder();

            var parts = documents.Where(d => d.DocumentType == swDocumentTypes_e.swDocPART).ToList();
            var assemblies = documents.Where(d => d.DocumentType == swDocumentTypes_e.swDocASSEMBLY).ToList();
            var drawings = documents.Where(d => d.DocumentType == swDocumentTypes_e.swDocDRAWING).ToList();

            sb.AppendLine($"{"图纸名",-35} {"类别",-8} {"特征",-6} {"配置项",-8} {"表达式",-8} {"视图",-6} {"标注",-6} {"表格",-6} {"组件数",-8} {"装配约束",-10} {"装配特征",-10}");
            sb.AppendLine(new string('-', 150));

            foreach (var doc in parts)
            {
                sb.AppendLine($"{doc.FileName,-35} {doc.Category,-8} {doc.FeatureCount,-6} {doc.ConfigurationCount,-8} {0,-8} {0,-6} {0,-6} {0,-6} {0,-8} {0,-10} {0,-10}");
            }

            foreach (var doc in assemblies)
            {
                sb.AppendLine($"{doc.FileName,-35} {doc.Category,-8} {0,-6} {doc.ConfigurationCount,-8} {0,-8} {0,-6} {0,-6} {0,-6} {doc.ComponentCount,-8} {doc.MateCount,-10} {doc.AssemblyFeatureCount,-10}");
            }

            foreach (var doc in drawings)
            {
                sb.AppendLine($"{doc.FileName,-35} {doc.Category,-8} {0,-6} {doc.ConfigurationCount,-8} {0,-8} {doc.ViewCount,-6} {doc.DimensionCount,-6} {doc.TableCount,-6} {0,-8} {0,-10} {0,-10}");
            }

            return sb.ToString();
        }
    }
}
