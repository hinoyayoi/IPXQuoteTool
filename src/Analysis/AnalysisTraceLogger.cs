using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using System;
using System.IO;
using System.Text;

namespace IPXQuoteTool.Analysis
{
    internal static class AnalysisTraceLogger
    {
        private static readonly object SyncRoot = new object();
        private static readonly string RunId = DateTime.Now.ToString("yyyyMMdd_HHmmss");

        public static void Write(ModelDoc2 model, string objectType, string objectName, string detail = null)
        {
            if (model == null)
            {
                return;
            }

            swDocumentTypes_e documentType;
            try
            {
                documentType = (swDocumentTypes_e)model.GetType();
            }
            catch
            {
                documentType = swDocumentTypes_e.swDocNONE;
            }

            string documentPath = SafeCall(() => model.GetPathName());
            Write(documentType, documentPath, objectType, objectName, detail);
        }

        public static void Write(swDocumentTypes_e documentType, string documentPath, string objectType, string objectName, string detail = null)
        {
            try
            {
                string directory = Path.Combine(
                    System.Environment.GetFolderPath(System.Environment.SpecialFolder.ApplicationData),
                    "IPXQuoteTool");
                Directory.CreateDirectory(directory);

                string filePath = Path.Combine(directory, $"{GetDocumentTypeName(documentType)}统计明细_{RunId}.txt");
                string line =
                    $"{DateTime.Now:HH:mm:ss}\t{Sanitize(documentPath)}\t{Sanitize(objectType)}\t{Sanitize(objectName)}\t{Sanitize(detail)}{System.Environment.NewLine}";

                lock (SyncRoot)
                {
                    File.AppendAllText(filePath, line, new UTF8Encoding(true));
                }
            }
            catch
            {
            }
        }

        public static string GetObjectName(object value, string fallback)
        {
            if (value == null)
            {
                return fallback;
            }

            foreach (string memberName in new[] { "Name", "Name2" })
            {
                string name = TryGetStringProperty(value, memberName);
                if (!string.IsNullOrWhiteSpace(name))
                {
                    return name;
                }
            }

            try
            {
                dynamic dynValue = value;
                string name = dynValue.GetName();
                if (!string.IsNullOrWhiteSpace(name))
                {
                    return name;
                }
            }
            catch
            {
            }

            return fallback;
        }

        private static string TryGetStringProperty(object value, string propertyName)
        {
            try
            {
                object propertyValue = value.GetType().GetProperty(propertyName)?.GetValue(value);
                return propertyValue as string;
            }
            catch
            {
                return null;
            }
        }

        private static string GetDocumentTypeName(swDocumentTypes_e documentType)
        {
            return documentType switch
            {
                swDocumentTypes_e.swDocPART => "零件",
                swDocumentTypes_e.swDocASSEMBLY => "装配",
                swDocumentTypes_e.swDocDRAWING => "工程图",
                _ => "未知"
            };
        }

        private static string Sanitize(string value)
        {
            return (value ?? string.Empty)
                .Replace("\r", " ")
                .Replace("\n", " ")
                .Replace("\t", " ");
        }

        private static string SafeCall(Func<string> valueProvider)
        {
            try
            {
                return valueProvider();
            }
            catch
            {
                return string.Empty;
            }
        }
    }
}
