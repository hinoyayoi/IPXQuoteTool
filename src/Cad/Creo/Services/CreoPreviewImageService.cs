using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.IO;
using System.Text;
using IPXQuoteTool.Cad.Creo.Models;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal class CreoPreviewImageService
    {
        private const int PreviewWidth = 520;
        private const int PreviewHeight = 360;

        public string CreatePreviewOutputPath(CreoPluginEnvironment environment, string filePath)
        {
            string environmentId = environment?.EnvironmentId ?? "Default";
            string directory = Path.Combine(Path.GetTempPath(), "IPXQuoteTool", "CreoPreview", environmentId);
            Directory.CreateDirectory(directory);

            string fileName = SanitizeFileName(Path.GetFileNameWithoutExtension(filePath));
            if (string.IsNullOrWhiteSpace(fileName))
            {
                fileName = "preview";
            }

            return Path.Combine(directory, fileName + "_" + Guid.NewGuid().ToString("N") + ".jpg");
        }

        public byte[] TryReadPreviewImageBytes(CreoDocumentMetricsDto metrics)
        {
            string previewPath = metrics?.PreviewImagePath;
            if (string.IsNullOrWhiteSpace(previewPath))
            {
                return null;
            }

            try
            {
                if (!metrics.PreviewImageSucceeded || !File.Exists(previewPath))
                {
                    return null;
                }

                using Image source = Image.FromFile(previewPath);
                using var bitmap = new Bitmap(source);
                return NormalizePreview(bitmap);
            }
            catch
            {
                return null;
            }
            finally
            {
                TryDeletePreviewFile(previewPath);
            }
        }

        public void TryDeletePreviewFile(string previewPath)
        {
            try
            {
                if (!string.IsNullOrWhiteSpace(previewPath) && File.Exists(previewPath))
                {
                    File.Delete(previewPath);
                }
            }
            catch
            {
            }
        }

        private static byte[] NormalizePreview(Bitmap source)
        {
            using var output = new Bitmap(PreviewWidth, PreviewHeight);
            using (Graphics graphics = Graphics.FromImage(output))
            {
                graphics.Clear(Color.White);
                graphics.InterpolationMode = InterpolationMode.HighQualityBicubic;
                graphics.SmoothingMode = SmoothingMode.HighQuality;
                graphics.PixelOffsetMode = PixelOffsetMode.HighQuality;
                graphics.CompositingQuality = CompositingQuality.HighQuality;

                float scale = Math.Min(
                    PreviewWidth / (float)source.Width,
                    PreviewHeight / (float)source.Height);
                int drawWidth = Math.Max(1, (int)Math.Round(source.Width * scale));
                int drawHeight = Math.Max(1, (int)Math.Round(source.Height * scale));
                int drawX = (PreviewWidth - drawWidth) / 2;
                int drawY = (PreviewHeight - drawHeight) / 2;

                graphics.DrawImage(source, new Rectangle(drawX, drawY, drawWidth, drawHeight));
            }

            using var stream = new MemoryStream();
            output.Save(stream, ImageFormat.Jpeg);
            return stream.ToArray();
        }

        private static string SanitizeFileName(string value)
        {
            if (string.IsNullOrWhiteSpace(value))
            {
                return null;
            }

            var builder = new StringBuilder(value.Length);
            char[] invalidChars = Path.GetInvalidFileNameChars();
            foreach (char ch in value)
            {
                builder.Append(Array.IndexOf(invalidChars, ch) >= 0 ? '_' : ch);
            }

            string sanitized = builder.ToString().Trim();
            return sanitized.Length <= 64 ? sanitized : sanitized.Substring(0, 64);
        }
    }
}
