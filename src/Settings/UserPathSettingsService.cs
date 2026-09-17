using System;
using System.IO;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;

namespace IPXQuoteTool.Settings
{
    public class UserPathSettingsService
    {
        private readonly string _settingsFilePath;

        public UserPathSettingsService()
        {
            string appDataPath = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
            string settingsDirectory = Path.Combine(appDataPath, "IPXQuoteTool");
            _settingsFilePath = Path.Combine(settingsDirectory, "user-paths.json");
        }

        public UserPathSettings Load()
        {
            try
            {
                if (!File.Exists(_settingsFilePath))
                {
                    return new UserPathSettings();
                }

                string json = File.ReadAllText(_settingsFilePath);
                return JsonSerializer.Deserialize<UserPathSettings>(json, CreateJsonOptions()) ?? new UserPathSettings();
            }
            catch
            {
                return new UserPathSettings();
            }
        }

        public void Save(UserPathSettings settings)
        {
            try
            {
                PreserveSensitiveSettings(settings);

                string settingsDirectory = Path.GetDirectoryName(_settingsFilePath);
                if (!Directory.Exists(settingsDirectory))
                {
                    Directory.CreateDirectory(settingsDirectory);
                }

                JsonSerializerOptions options = CreateJsonOptions();
                JsonObject settingsJson = ReadExistingSettingsJsonObject() ?? new JsonObject();
                ApplySettings(settingsJson, settings);
                string json = settingsJson.ToJsonString(options);
                File.WriteAllText(_settingsFilePath, json);
            }
            catch
            {
            }
        }

        private JsonObject ReadExistingSettingsJsonObject()
        {
            try
            {
                if (!File.Exists(_settingsFilePath))
                {
                    return null;
                }

                string json = File.ReadAllText(_settingsFilePath);
                return JsonNode.Parse(json) as JsonObject;
            }
            catch
            {
                return null;
            }
        }

        private static void ApplySettings(JsonObject settingsJson, UserPathSettings settings)
        {
            SetString(settingsJson, nameof(UserPathSettings.SelectedSoftwareKind), settings.SelectedSoftwareKind);
            SetString(settingsJson, nameof(UserPathSettings.SolidWorksPath), settings.SolidWorksPath);
            SetString(settingsJson, nameof(UserPathSettings.CreoPath), settings.CreoPath);
            SetString(settingsJson, nameof(UserPathSettings.DrawingFolderPath), settings.DrawingFolderPath);
            SetString(settingsJson, nameof(UserPathSettings.ReportFolderPath), settings.ReportFolderPath);
            settingsJson[nameof(UserPathSettings.UseOfflineDocumentManager)] = settings.UseOfflineDocumentManager;
            SetString(settingsJson, nameof(UserPathSettings.DocumentManagerLicenseKey), settings.DocumentManagerLicenseKey);
        }

        private static void SetString(JsonObject settingsJson, string propertyName, string value)
        {
            if (value == null)
            {
                settingsJson.Remove(propertyName);
                return;
            }

            settingsJson[propertyName] = value;
        }

        private void PreserveSensitiveSettings(UserPathSettings settings)
        {
            if (settings == null || !string.IsNullOrWhiteSpace(settings.DocumentManagerLicenseKey))
            {
                return;
            }

            string existingKey = TryReadExistingDocumentManagerLicenseKey();
            if (!string.IsNullOrWhiteSpace(existingKey))
            {
                settings.DocumentManagerLicenseKey = existingKey;
            }
        }

        private string TryReadExistingDocumentManagerLicenseKey()
        {
            string json = null;

            try
            {
                if (!File.Exists(_settingsFilePath))
                {
                    return null;
                }

                json = File.ReadAllText(_settingsFilePath);
                UserPathSettings existingSettings = JsonSerializer.Deserialize<UserPathSettings>(json, CreateJsonOptions());
                if (!string.IsNullOrWhiteSpace(existingSettings?.DocumentManagerLicenseKey))
                {
                    return existingSettings.DocumentManagerLicenseKey;
                }
            }
            catch
            {
            }

            return TryReadDocumentManagerLicenseKeyFromText(json);
        }

        private static string TryReadDocumentManagerLicenseKeyFromText(string json)
        {
            if (string.IsNullOrWhiteSpace(json))
            {
                return null;
            }

            Match match = Regex.Match(
                json,
                "\"DocumentManagerLicenseKey\"\\s*:\\s*(\"(?:\\\\.|[^\"\\\\])*\"|null)",
                RegexOptions.IgnoreCase);
            if (!match.Success || match.Groups[1].Value == "null")
            {
                return null;
            }

            try
            {
                return JsonSerializer.Deserialize<string>(match.Groups[1].Value);
            }
            catch
            {
                return match.Groups[1].Value.Trim('"');
            }
        }

        private static JsonSerializerOptions CreateJsonOptions()
        {
            return new JsonSerializerOptions
            {
                WriteIndented = true,
                PropertyNameCaseInsensitive = true,
                DefaultIgnoreCondition = JsonIgnoreCondition.WhenWritingNull
            };
        }
    }
}

