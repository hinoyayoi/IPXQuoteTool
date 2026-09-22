using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using IPXQuoteTool.Cad.Common;
using IPXQuoteTool.Cad.Creo.Models;

namespace IPXQuoteTool.Cad.Creo.Diagnostics
{
    internal class CreoPluginJsonClient
    {
        private const string MetricsEnvironmentVariable = "IPX_QUOTE_CREO_METRICS";
        private const string PluginSource = "CreoPlugin";

        public static string GetDefaultMetricsPath()
        {
            return Path.Combine(Path.GetTempPath(), "IPXQuoteCreoPlugin", "last-result.json");
        }

        public CreoDocumentMetricsDto TryReadDocument(string requestedFilePath)
        {
            foreach (string metricsPath in GetCandidateMetricsPaths())
            {
                CreoDocumentMetricsDto metrics = TryReadMetricsFile(metricsPath, requestedFilePath);
                if (metrics != null)
                {
                    return metrics;
                }
            }

            return null;
        }

        private static CreoDocumentMetricsDto TryReadMetricsFile(string metricsPath, string requestedFilePath)
        {
            if (string.IsNullOrWhiteSpace(metricsPath) || !File.Exists(metricsPath))
            {
                return null;
            }

            try
            {
                using FileStream stream = File.OpenRead(metricsPath);
                using JsonDocument document = JsonDocument.Parse(stream);
                JsonElement root = document.RootElement;

                string source = GetString(root, "source");
                if (!string.IsNullOrWhiteSpace(source) &&
                    !string.Equals(source, PluginSource, StringComparison.OrdinalIgnoreCase))
                {
                    return null;
                }

                string jsonFilePath = GetString(root, "FilePath");
                string jsonFileName = GetString(root, "FileName");
                if (!MatchesRequestedFile(requestedFilePath, jsonFilePath, jsonFileName))
                {
                    return null;
                }

                CadDocumentType documentType = ToCadDocumentType(GetString(root, "DocumentKind"));
                if (documentType == CadDocumentType.Unknown)
                {
                    documentType = CadFileTypeDetector.GetDocumentTypeFromPath(requestedFilePath);
                }

                string requestedFileName = string.IsNullOrWhiteSpace(requestedFilePath)
                    ? jsonFileName
                    : Path.GetFileName(requestedFilePath);

                int configurationCount = GetInt(root, "ConfigurationCount");
                return new CreoDocumentMetricsDto
                {
                    FilePath = string.IsNullOrWhiteSpace(requestedFilePath) ? jsonFilePath : requestedFilePath,
                    FileName = string.IsNullOrWhiteSpace(requestedFileName) ? jsonFileName : requestedFileName,
                    DocumentType = documentType,
                    FeatureCount = GetInt(root, "FeatureCount"),
                    ConfigurationCount = configurationCount,
                    ExpressionCount = GetInt(root, "ExpressionCount"),
                    ComponentCount = GetInt(root, "ComponentCount"),
                    MateCount = GetInt(root, "MateCount"),
                    AssemblyFeatureCount = GetInt(root, "AssemblyFeatureCount"),
                    ViewCount = GetInt(root, "ViewCount"),
                    NoteCount = GetInt(root, "NoteCount"),
                    DimensionCount = GetInt(root, "DimensionCount"),
                    TableCount = GetInt(root, "TableCount"),
                    Succeeded = GetBool(root, "Succeeded"),
                    ErrorMessage = GetString(root, "ErrorMessage"),
                    PreviewImageSucceeded = GetBool(root, "PreviewImageSucceeded"),
                    PreviewImagePath = GetString(root, "PreviewImagePath"),
                    PreviewImageFormat = GetString(root, "PreviewImageFormat"),
                    PreviewImageError = GetString(root, "PreviewImageError")
                };
            }
            catch
            {
                return null;
            }
        }

        private static IEnumerable<string> GetCandidateMetricsPaths()
        {
            string explicitPath = Environment.GetEnvironmentVariable(MetricsEnvironmentVariable);
            if (!string.IsNullOrWhiteSpace(explicitPath))
            {
                yield return explicitPath.Trim().Trim('"');
            }

            yield return GetDefaultMetricsPath();
        }

        private static bool MatchesRequestedFile(string requestedFilePath, string jsonFilePath, string jsonFileName)
        {
            if (string.IsNullOrWhiteSpace(requestedFilePath))
            {
                return true;
            }

            if (!string.IsNullOrWhiteSpace(jsonFilePath))
            {
                string requestedComparablePath = NormalizeCreoComparablePath(requestedFilePath);
                string jsonComparablePath = NormalizeCreoComparablePath(jsonFilePath);
                if (string.Equals(requestedComparablePath, jsonComparablePath, StringComparison.OrdinalIgnoreCase))
                {
                    return true;
                }
            }

            string requestedComparableName = NormalizeCreoFileName(Path.GetFileName(requestedFilePath));
            string jsonComparableName = NormalizeCreoFileName(jsonFileName);
            return !string.IsNullOrWhiteSpace(requestedComparableName) &&
                   string.Equals(requestedComparableName, jsonComparableName, StringComparison.OrdinalIgnoreCase);
        }

        private static string NormalizeCreoComparablePath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return string.Empty;
            }

            string trimmed = path.Trim().Trim('"');
            string directory = Path.GetDirectoryName(trimmed) ?? string.Empty;
            string fileName = NormalizeCreoFileName(Path.GetFileName(trimmed));
            string combined = string.IsNullOrWhiteSpace(directory) ? fileName : Path.Combine(directory, fileName);

            try
            {
                return Path.GetFullPath(combined);
            }
            catch
            {
                return combined;
            }
        }

        private static string NormalizeCreoFileName(string fileName)
        {
            if (string.IsNullOrWhiteSpace(fileName))
            {
                return string.Empty;
            }

            string lower = fileName.Trim().Trim('"').ToLowerInvariant();
            foreach (string extension in new[] { ".prt", ".asm", ".drw" })
            {
                int markerIndex = lower.LastIndexOf(extension + ".", StringComparison.OrdinalIgnoreCase);
                if (markerIndex < 0)
                {
                    continue;
                }

                int versionStart = markerIndex + extension.Length + 1;
                if (versionStart >= lower.Length)
                {
                    continue;
                }

                bool allDigits = true;
                for (int i = versionStart; i < lower.Length; i++)
                {
                    if (!char.IsDigit(lower[i]))
                    {
                        allDigits = false;
                        break;
                    }
                }

                if (allDigits)
                {
                    return lower.Substring(0, markerIndex + extension.Length);
                }
            }

            return lower;
        }

        private static CadDocumentType ToCadDocumentType(string kind)
        {
            return kind switch
            {
                "Part" => CadDocumentType.Part,
                "Assembly" => CadDocumentType.Assembly,
                "Drawing" => CadDocumentType.Drawing,
                _ => CadDocumentType.Unknown
            };
        }

        private static string GetString(JsonElement root, string propertyName)
        {
            return root.TryGetProperty(propertyName, out JsonElement value) && value.ValueKind == JsonValueKind.String
                ? value.GetString()
                : null;
        }

        private static int GetInt(JsonElement root, string propertyName)
        {
            return root.TryGetProperty(propertyName, out JsonElement value) && value.TryGetInt32(out int result)
                ? result
                : 0;
        }

        private static bool GetBool(JsonElement root, string propertyName)
        {
            return root.TryGetProperty(propertyName, out JsonElement value) && value.ValueKind == JsonValueKind.True;
        }
    }
}


