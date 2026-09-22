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
            string localAppData = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData);
            if (IsAsciiPath(localAppData))
            {
                return Path.Combine(localAppData, RootFolderName);
            }

            string commonAppData = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
            if (IsAsciiPath(commonAppData))
            {
                return Path.Combine(commonAppData, RootFolderName);
            }

            string systemDrive = Path.GetPathRoot(Environment.SystemDirectory);
            if (string.IsNullOrWhiteSpace(systemDrive))
            {
                systemDrive = @"C:\";
            }

            return Path.Combine(systemDrive, RootFolderName);
        }

        private static bool IsAsciiPath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return false;
            }

            foreach (char ch in path)
            {
                if (ch > 127)
                {
                    return false;
                }
            }

            return true;
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
