using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Drawing.Drawing2D;
using System.IO;
using System.Runtime.InteropServices;

namespace IPXQuoteTool.Cad.Common
{
    public static class ShellThumbnailService
    {
        private const int ThumbnailWidth = 520;
        private const int ThumbnailHeight = 360;

        public static byte[] TryGetThumbnailImageBytes(string filePath)
        {
            if (string.IsNullOrWhiteSpace(filePath) || !File.Exists(filePath))
            {
                return null;
            }

            string thumbnailPath = null;
            try
            {
                thumbnailPath = PrepareThumbnailSourcePath(filePath);
                return TryGetShellThumbnail(thumbnailPath ?? filePath);
            }
            catch
            {
                return null;
            }
            finally
            {
                TryDeleteTemporaryFile(thumbnailPath, filePath);
            }
        }

        private static byte[] TryGetShellThumbnail(string filePath)
        {
            Guid factoryId = typeof(IShellItemImageFactory).GUID;
            SHCreateItemFromParsingName(filePath, IntPtr.Zero, ref factoryId, out IShellItemImageFactory factory);
            if (factory == null)
            {
                return null;
            }

            IntPtr bitmapHandle = IntPtr.Zero;
            try
            {
                factory.GetImage(new Size { Width = ThumbnailWidth, Height = ThumbnailHeight }, SIIGBF.BiggerSizeOk | SIIGBF.ThumbnailOnly, out bitmapHandle);
                if (bitmapHandle == IntPtr.Zero)
                {
                    return null;
                }

                using Bitmap bitmap = Image.FromHbitmap(bitmapHandle);
                return NormalizeThumbnail(bitmap);
            }
            finally
            {
                if (bitmapHandle != IntPtr.Zero)
                {
                    DeleteObject(bitmapHandle);
                }

                if (factory != null)
                {
                    Marshal.ReleaseComObject(factory);
                }
            }
        }


        private static byte[] NormalizeThumbnail(Bitmap source)
        {
            Rectangle contentBounds = FindContentBounds(source);
            if (contentBounds.Width <= 0 || contentBounds.Height <= 0)
            {
                contentBounds = new Rectangle(0, 0, source.Width, source.Height);
            }

            int paddingX = Math.Max(8, contentBounds.Width / 12);
            int paddingY = Math.Max(8, contentBounds.Height / 12);
            contentBounds = Rectangle.Intersect(
                new Rectangle(
                    contentBounds.Left - paddingX,
                    contentBounds.Top - paddingY,
                    contentBounds.Width + paddingX * 2,
                    contentBounds.Height + paddingY * 2),
                new Rectangle(0, 0, source.Width, source.Height));

            using var output = new Bitmap(ThumbnailWidth, ThumbnailHeight);
            using (Graphics graphics = Graphics.FromImage(output))
            {
                graphics.Clear(Color.White);
                graphics.InterpolationMode = InterpolationMode.HighQualityBicubic;
                graphics.SmoothingMode = SmoothingMode.HighQuality;
                graphics.PixelOffsetMode = PixelOffsetMode.HighQuality;
                graphics.CompositingQuality = CompositingQuality.HighQuality;

                float scale = Math.Min(
                    ThumbnailWidth / (float)contentBounds.Width,
                    ThumbnailHeight / (float)contentBounds.Height);
                int drawWidth = Math.Max(1, (int)Math.Round(contentBounds.Width * scale));
                int drawHeight = Math.Max(1, (int)Math.Round(contentBounds.Height * scale));
                int drawX = (ThumbnailWidth - drawWidth) / 2;
                int drawY = (ThumbnailHeight - drawHeight) / 2;

                graphics.DrawImage(
                    source,
                    new Rectangle(drawX, drawY, drawWidth, drawHeight),
                    contentBounds,
                    GraphicsUnit.Pixel);
            }

            using var stream = new MemoryStream();
            output.Save(stream, ImageFormat.Jpeg);
            return stream.ToArray();
        }

        private static Rectangle FindContentBounds(Bitmap bitmap)
        {
            Color background = bitmap.GetPixel(0, 0);
            int minX = bitmap.Width;
            int minY = bitmap.Height;
            int maxX = -1;
            int maxY = -1;

            for (int y = 0; y < bitmap.Height; y++)
            {
                for (int x = 0; x < bitmap.Width; x++)
                {
                    Color pixel = bitmap.GetPixel(x, y);
                    if (IsBackgroundPixel(pixel, background))
                    {
                        continue;
                    }

                    minX = Math.Min(minX, x);
                    minY = Math.Min(minY, y);
                    maxX = Math.Max(maxX, x);
                    maxY = Math.Max(maxY, y);
                }
            }

            if (maxX < minX || maxY < minY)
            {
                return Rectangle.Empty;
            }

            return Rectangle.FromLTRB(minX, minY, maxX + 1, maxY + 1);
        }

        private static bool IsBackgroundPixel(Color pixel, Color background)
        {
            if (pixel.A < 20)
            {
                return true;
            }

            int distance = Math.Abs(pixel.R - background.R) +
                Math.Abs(pixel.G - background.G) +
                Math.Abs(pixel.B - background.B);

            if (distance <= 36)
            {
                return true;
            }

            return pixel.R >= 246 && pixel.G >= 246 && pixel.B >= 246;
        }
        private static string PrepareThumbnailSourcePath(string filePath)
        {
            string normalizedExtension = GetCreoVersionedExtension(filePath);
            if (string.IsNullOrWhiteSpace(normalizedExtension))
            {
                return filePath;
            }

            string tempPath = Path.Combine(Path.GetTempPath(), $"IPXQuote_creo_preview_{Guid.NewGuid():N}{normalizedExtension}");
            File.Copy(filePath, tempPath, overwrite: true);
            return tempPath;
        }

        private static string GetCreoVersionedExtension(string filePath)
        {
            string fileName = Path.GetFileName(filePath)?.ToLowerInvariant();
            if (string.IsNullOrWhiteSpace(fileName))
            {
                return null;
            }

            if (HasCreoVersionSuffix(fileName, ".prt"))
            {
                return ".prt";
            }

            if (HasCreoVersionSuffix(fileName, ".asm"))
            {
                return ".asm";
            }

            if (HasCreoVersionSuffix(fileName, ".drw"))
            {
                return ".drw";
            }

            return null;
        }

        private static bool HasCreoVersionSuffix(string fileName, string creoExtension)
        {
            int markerIndex = fileName.LastIndexOf(creoExtension + ".", StringComparison.OrdinalIgnoreCase);
            if (markerIndex < 0)
            {
                return false;
            }

            int versionStart = markerIndex + creoExtension.Length + 1;
            if (versionStart >= fileName.Length)
            {
                return false;
            }

            for (int i = versionStart; i < fileName.Length; i++)
            {
                if (!char.IsDigit(fileName[i]))
                {
                    return false;
                }
            }

            return true;
        }

        private static void TryDeleteTemporaryFile(string thumbnailPath, string originalPath)
        {
            try
            {
                if (!string.IsNullOrWhiteSpace(thumbnailPath) &&
                    !string.Equals(thumbnailPath, originalPath, StringComparison.OrdinalIgnoreCase) &&
                    File.Exists(thumbnailPath))
                {
                    File.Delete(thumbnailPath);
                }
            }
            catch
            {
            }
        }

        [DllImport("shell32.dll", CharSet = CharSet.Unicode, PreserveSig = false)]
        private static extern void SHCreateItemFromParsingName(
            [MarshalAs(UnmanagedType.LPWStr)] string pszPath,
            IntPtr pbc,
            ref Guid riid,
            [MarshalAs(UnmanagedType.Interface)] out IShellItemImageFactory ppv);

        [DllImport("gdi32.dll")]
        private static extern bool DeleteObject(IntPtr hObject);

        [ComImport]
        [Guid("bcc18b79-ba16-442f-80c4-8a59c30c463b")]
        [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
        private interface IShellItemImageFactory
        {
            void GetImage(Size size, SIIGBF flags, out IntPtr phbm);
        }

        [StructLayout(LayoutKind.Sequential)]
        private struct Size
        {
            public int Width;
            public int Height;
        }

        [Flags]
        private enum SIIGBF
        {
            ResizeToFit = 0x00,
            BiggerSizeOk = 0x01,
            MemoryOnly = 0x02,
            IconOnly = 0x04,
            ThumbnailOnly = 0x08,
            InCacheOnly = 0x10
        }
    }
}


