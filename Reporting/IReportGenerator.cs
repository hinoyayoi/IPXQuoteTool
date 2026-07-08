using System.Collections.Generic;
using IPXQuoteTool.Pricing;

namespace IPXQuoteTool.Reporting
{
    public interface IReportGenerator
    {
        string Generate(IReadOnlyList<DocumentInfo> documents, QuotePricingSettings pricingSettings);
    }
}
