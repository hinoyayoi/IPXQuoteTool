using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using IPXQuoteTool.Pricing;

namespace IPXQuoteTool.Reporting
{
    public class QuoteReportService
    {
        private readonly IReportGenerator _reportGenerator;

        public QuoteReportService()
            : this(new TextReportGenerator())
        {
        }

        internal QuoteReportService(IReportGenerator reportGenerator)
        {
            _reportGenerator = reportGenerator;
        }

        public byte[] GenerateReport(IReadOnlyList<DocumentInfo> documents, QuotePricingSettings pricingSettings)
        {
            return _reportGenerator.Generate(documents, pricingSettings);
        }

        public bool SaveReport(string reportPath, byte[] content)
        {
            try
            {
                if (!Directory.Exists(reportPath))
                {
                    Directory.CreateDirectory(reportPath);
                }

                string filePath = Path.Combine(reportPath, $"费用估算_{DateTime.Now:yyyyMMdd_HHmmss}.xlsx");
                File.WriteAllBytes(filePath, content);
                return true;
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"保存报表失败: {ex.Message}");
                return false;
            }
        }
    }
}