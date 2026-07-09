using System;
using SolidWorks.Interop.sldworks;

namespace IPXQuoteTool.Analysis
{
    internal static class SolidWorksDocumentMetrics
    {
        public static int GetConfigurationCount(ModelDoc2 model)
        {
            try
            {
                object configsObj = model.GetConfigurationNames();
                if (configsObj is Array configs)
                {
                    return configs.Length;
                }
            }
            catch
            {
            }

            return 0;
        }
    }
}
