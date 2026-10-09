using System;
using System.IO;
using System.Text;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal static class CreoPluginRuntimePath
    {
        private const string RootFolderName = "IPXQuoteTool";
        private const string PluginFolderName = "CreoPluginRuntime";

        public static string GetPluginDirectory(string environmentId)
        {
            string rootDirectory = GetRootDirectory();
            return Path.Combine(rootDirectory, PluginFolderName, SanitizePathSegment(environmentId));
        }

        private static string GetRootDirectory()
        {
            string commonAppData = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
            return Path.Combine(commonAppData, RootFolderName);
        }

        private static string SanitizePathSegment(string value)
        {
            if (string.IsNullOrWhiteSpace(value))
            {
                return "Unknown";
            }

            StringBuilder builder = new StringBuilder(value.Length);
            foreach (char ch in value)
            {
                if ((ch >= 'A' && ch <= 'Z') ||
                    (ch >= 'a' && ch <= 'z') ||
                    (ch >= '0' && ch <= '9') ||
                    ch == '_' ||
                    ch == '-')
                {
                    builder.Append(ch);
                }
                else
                {
                    builder.Append('_');
                }
            }

            return builder.Length == 0 ? "Unknown" : builder.ToString();
        }
    }
}
