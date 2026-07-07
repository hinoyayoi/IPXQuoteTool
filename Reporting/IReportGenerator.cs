using System.Collections.Generic;

namespace IPXQuoteTool.Reporting
{
    public interface IReportGenerator
    {
        string Generate(IReadOnlyList<DocumentInfo> documents);
    }
}
