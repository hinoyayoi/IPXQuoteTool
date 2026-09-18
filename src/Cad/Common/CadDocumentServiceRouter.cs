using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace IPXQuoteTool.Cad.Common
{
    public class CadDocumentServiceRouter
    {
        private readonly IReadOnlyList<ICadDocumentService> _services;

        public CadDocumentServiceRouter(params ICadDocumentService[] services)
        {
            _services = services?
                .Where(service => service != null)
                .ToList()
                ?? new List<ICadDocumentService>();
        }

        public ICadDocumentService Resolve(string filePath)
        {
            return _services.FirstOrDefault(service => service.CanProcess(filePath));
        }

        public ICadDocumentService Resolve(CadSoftwareKind softwareKind)
        {
            return _services.FirstOrDefault(service => service.SoftwareKind == softwareKind);
        }

        public bool CanProcess(string filePath)
        {
            return Resolve(filePath) != null;
        }

        public List<string> GetSupportedFiles(string folderPath)
        {
            if (!Directory.Exists(folderPath))
            {
                return new List<string>();
            }

            return Directory.GetFiles(folderPath, "*.*", SearchOption.AllDirectories)
                .Where(CanProcess)
                .ToList();
        }
        public List<string> GetSupportedFiles(string folderPath, CadSoftwareKind softwareKind)
        {
            ICadDocumentService service = Resolve(softwareKind);
            if (service == null || !Directory.Exists(folderPath))
            {
                return new List<string>();
            }

            return Directory.GetFiles(folderPath, "*.*", SearchOption.AllDirectories)
                .Where(service.CanProcess)
                .ToList();
        }
    }
}
