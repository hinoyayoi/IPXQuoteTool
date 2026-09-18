namespace IPXQuoteTool.Cad.Common
{
    public interface ICadDocumentService
    {
        CadSoftwareKind SoftwareKind { get; }

        bool CanProcess(string filePath);

        DocumentInfo ProcessDocument(string filePath);
    }
}
