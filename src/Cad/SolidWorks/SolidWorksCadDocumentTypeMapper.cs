using IPXQuoteTool.Cad.Common;
using SolidWorks.Interop.swconst;

namespace IPXQuoteTool.Cad.SolidWorks
{
    public static class SolidWorksCadDocumentTypeMapper
    {
        public static CadDocumentType ToCadDocumentType(swDocumentTypes_e documentType)
        {
            return documentType switch
            {
                swDocumentTypes_e.swDocPART => CadDocumentType.Part,
                swDocumentTypes_e.swDocASSEMBLY => CadDocumentType.Assembly,
                swDocumentTypes_e.swDocDRAWING => CadDocumentType.Drawing,
                _ => CadDocumentType.Unknown
            };
        }

        public static swDocumentTypes_e ToSolidWorksDocumentType(CadDocumentType documentType)
        {
            return documentType switch
            {
                CadDocumentType.Part => swDocumentTypes_e.swDocPART,
                CadDocumentType.Assembly => swDocumentTypes_e.swDocASSEMBLY,
                CadDocumentType.Drawing => swDocumentTypes_e.swDocDRAWING,
                _ => swDocumentTypes_e.swDocNONE
            };
        }
    }
}

