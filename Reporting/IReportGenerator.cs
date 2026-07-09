using System.Collections.Generic;
using IPXQuoteTool.Pricing;

namespace IPXQuoteTool.Reporting
{
    public interface IReportGenerator
    {
        byte[] Generate(IReadOnlyList<DocumentInfo> documents, QuotePricingSettings pricingSettings);
    }
}
