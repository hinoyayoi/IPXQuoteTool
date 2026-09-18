using System.IO;

namespace IPXQuoteTool.Cad.Common
{
    public static class CadFileTypeDetector
    {
        public static CadDocumentType GetDocumentTypeFromPath(string filePath)
        {
            if (string.IsNullOrWhiteSpace(filePath))
            {
                return CadDocumentType.Unknown;
            }

            string fileName = Path.GetFileName(filePath).ToLowerInvariant();
            string extension = Path.GetExtension(filePath).ToLowerInvariant();

            return extension switch
            {
                ".sldprt" => CadDocumentType.Part,
                ".sldasm" => CadDocumentType.Assembly,
                ".slddrw" => CadDocumentType.Drawing,
                ".prt" => CadDocumentType.Part,
                ".asm" => CadDocumentType.Assembly,
                ".drw" => CadDocumentType.Drawing,
                _ when HasCreoVersionSuffix(fileName, ".prt") => CadDocumentType.Part,
                _ when HasCreoVersionSuffix(fileName, ".asm") => CadDocumentType.Assembly,
                _ when HasCreoVersionSuffix(fileName, ".drw") => CadDocumentType.Drawing,
                _ => CadDocumentType.Unknown
            };
        }

        public static bool IsSupported(string filePath)
        {
            return GetDocumentTypeFromPath(filePath) != CadDocumentType.Unknown;
        }

        private static bool HasCreoVersionSuffix(string fileName, string creoExtension)
        {
            int markerIndex = fileName.LastIndexOf(creoExtension + ".");
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
    }
}
