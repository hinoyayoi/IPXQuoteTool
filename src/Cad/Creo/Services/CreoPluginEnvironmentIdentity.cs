using System;
using System.Globalization;
using System.IO;
using System.Text;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal static class CreoPluginEnvironmentIdentity
    {
        private const ulong FnvOffsetBasis = 14695981039346656037UL;
        private const ulong FnvPrime = 1099511628211UL;

        public static string CreateEnvironmentId(string creoInstallRoot)
        {
            string normalizedPath = NormalizePathForHash(creoInstallRoot);
            if (string.IsNullOrWhiteSpace(normalizedPath))
            {
                normalizedPath = "unknown";
            }

            ulong hash = FnvOffsetBasis;
            foreach (char ch in normalizedPath.ToUpperInvariant())
            {
                hash ^= ch;
                hash *= FnvPrime;
            }

            return "Creo_" + hash.ToString("X16", CultureInfo.InvariantCulture);
        }

        public static string CreatePipeName(string environmentId)
        {
            return "IPXQuoteCreoPlugin_" + SanitizePipeSegment(environmentId);
        }

        private static string NormalizePathForHash(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return null;
            }

            try
            {
                path = Path.GetFullPath(path.Trim().Trim('"'));
            }
            catch
            {
                path = path.Trim().Trim('"');
            }

            return path.Replace('/', '\\').TrimEnd('\\');
        }

        private static string SanitizePipeSegment(string value)
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
