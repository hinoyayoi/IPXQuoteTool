using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;

namespace IPXQuoteTool.Cad.SolidWorks.Analysis
{
    public class DocumentAnalysisContext
    {
        public DocumentAnalysisContext(ModelDoc2 model, swDocumentTypes_e documentType)
        {
            Model = model;
            DocumentType = documentType;
        }

        public ModelDoc2 Model { get; }
        public swDocumentTypes_e DocumentType { get; }
    }
}
