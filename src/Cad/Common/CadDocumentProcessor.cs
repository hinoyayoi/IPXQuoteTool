using System;

namespace IPXQuoteTool.Cad.Common
{
    public class CadDocumentProcessor
    {
        private readonly CadDocumentServiceRouter _serviceRouter;

        public CadDocumentProcessor(CadDocumentServiceRouter serviceRouter)
        {
            _serviceRouter = serviceRouter ?? throw new ArgumentNullException(nameof(serviceRouter));
        }

        public DocumentInfo ProcessDocument(string filePath)
        {
            ICadDocumentService service = _serviceRouter.Resolve(filePath);
            return ProcessDocument(filePath, service);
        }

        public DocumentInfo ProcessDocument(string filePath, ICadDocumentService service)
        {
            if (service == null || !service.CanProcess(filePath))
            {
                return null;
            }

            return service.ProcessDocument(filePath);
        }
    }
}