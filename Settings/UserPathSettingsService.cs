using System;
using System.IO;
using System.Text.Json;

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
                return JsonSerializer.Deserialize<UserPathSettings>(json) ?? new UserPathSettings();
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
                string settingsDirectory = Path.GetDirectoryName(_settingsFilePath);
                if (!Directory.Exists(settingsDirectory))
                {
                    Directory.CreateDirectory(settingsDirectory);
                }

                var options = new JsonSerializerOptions { WriteIndented = true };
                string json = JsonSerializer.Serialize(settings, options);
                File.WriteAllText(_settingsFilePath, json);
            }
            catch
            {
            }
        }
    }
}
