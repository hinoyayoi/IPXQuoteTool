using SolidWorks.Interop.swdocumentmgr;
using SolidWorks.Interop.swconst;
using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;

namespace IPXQuoteTool
{
    public class OfflineDocumentManagerService
    {
        private readonly string _licenseKey;
        private SwDMApplication _application;

        public OfflineDocumentManagerService(string licenseKey)
        {
            _licenseKey = licenseKey ?? string.Empty;
        }

        public string LastError { get; private set; }

        public bool Initialize()
        {
            try
            {
                Type factoryType = Type.GetTypeFromProgID("SwDocumentMgr.SwDMClassFactory");
                if (factoryType == null)
                {
                    LastError = "未找到 SwDocumentMgr.SwDMClassFactory。请确认 SolidWorks Document Manager 已安装/注册。";
                    return false;
                }

                object factoryObj = Activator.CreateInstance(factoryType);
                var factory = factoryObj as ISwDMClassFactory;
                if (factory == null)
                {
                    LastError = "无法创建 ISwDMClassFactory。";
                    return false;
                }

                _application = factory.GetApplication(_licenseKey);
                if (_application == null)
                {
                    LastError = "Document Manager 初始化失败。通常需要有效的 Document Manager license key。";
                    return false;
                }

                return true;
            }
            catch (COMException ex)
            {
                LastError = $"Document Manager COM 初始化失败: {ex.Message}";
                return false;
            }
            catch (Exception ex)
            {
                LastError = $"Document Manager 初始化失败: {ex.Message}";
                return false;
            }
        }

        public DocumentInfo ProcessDocument(string filePath)
        {
            if (_application == null && !Initialize())
            {
                return null;
            }

            ISwDMDocument29 document = null;

            try
            {
                SwDmDocumentType dmDocumentType = GetDocumentManagerType(filePath);
                if (dmDocumentType == SwDmDocumentType.swDmDocumentUnknown)
                {
                    LastError = $"不支持的文件类型: {filePath}";
                    return null;
                }

                SwDmDocumentOpenError openError;
                SwDMDocument rawDocument = _application.GetDocument(filePath, dmDocumentType, true, out openError);
                document = rawDocument as ISwDMDocument29;
                if (document == null || openError != SwDmDocumentOpenError.swDmDocumentOpenErrorNone)
                {
                    LastError = $"Document Manager 打开失败: {Path.GetFileName(filePath)} ({openError})";
                    return null;
                }

                var info = new DocumentInfo
                {
                    FileName = Path.GetFileName(filePath),
                    FilePath = filePath,
                    DocumentType = GetSolidWorksDocumentType(dmDocumentType),
                    ConfigurationCount = GetConfigurationCount(document)
                };

                switch (info.DocumentType)
                {
                    case swDocumentTypes_e.swDocPART:
                        // Document Manager can read metadata, configurations, cut lists, custom properties,
                        // and DimXpert data, but it does not expose the normal FeatureManager tree.
                        info.FeatureCount = 0;
                        break;

                    case swDocumentTypes_e.swDocASSEMBLY:
                        info.ComponentCount = SafeGetComponentCount(document);
                        break;

                    case swDocumentTypes_e.swDocDRAWING:
                        FillDrawingMetrics(document, info);
                        break;
                }

                return info;
            }
            catch (Exception ex)
            {
                LastError = $"离线处理失败: {Path.GetFileName(filePath)} - {ex.Message}";
                return null;
            }
            finally
            {
                try
                {
                    document?.CloseDoc();
                }
                catch
                {
                }
            }
        }

        private static SwDmDocumentType GetDocumentManagerType(string filePath)
        {
            string extension = Path.GetExtension(filePath).ToLowerInvariant();
            return extension switch
            {
                ".sldprt" => SwDmDocumentType.swDmDocumentPart,
                ".sldasm" => SwDmDocumentType.swDmDocumentAssembly,
                ".slddrw" => SwDmDocumentType.swDmDocumentDrawing,
                _ => SwDmDocumentType.swDmDocumentUnknown
            };
        }

        private static swDocumentTypes_e GetSolidWorksDocumentType(SwDmDocumentType documentType)
        {
            return documentType switch
            {
                SwDmDocumentType.swDmDocumentPart => swDocumentTypes_e.swDocPART,
                SwDmDocumentType.swDmDocumentAssembly => swDocumentTypes_e.swDocASSEMBLY,
                SwDmDocumentType.swDmDocumentDrawing => swDocumentTypes_e.swDocDRAWING,
                _ => swDocumentTypes_e.swDocNONE
            };
        }

        private static int GetConfigurationCount(ISwDMDocument29 document)
        {
            try
            {
                SwDMConfigurationMgr configurationManager = document.ConfigurationManager;
                return configurationManager?.GetConfigurationCount() ?? 0;
            }
            catch
            {
                return 0;
            }
        }

        private static int SafeGetComponentCount(ISwDMDocument29 document)
        {
            try
            {
                return document.GetComponentCount();
            }
            catch
            {
                return 0;
            }
        }

        private static void FillDrawingMetrics(ISwDMDocument29 document, DocumentInfo info)
        {
            try
            {
                info.ViewCount = CountArrayItems(document.GetViews());
            }
            catch
            {
            }

            try
            {
                info.TableCount =
                    CountArrayItems(document.GetTableNames(SwDmTableType.swDmTableTypeRevision)) +
                    CountArrayItems(document.GetTableNames(SwDmTableType.swDmTableTypeBOM)) +
                    CountArrayItems(document.GetTableNames(SwDmTableType.swDmTableTypeBOMHidden));
            }
            catch
            {
            }

            try
            {
                info.NoteCount = 0;
                info.DimensionCount = 0;
                info.ViewCount = Math.Max(info.ViewCount, CountViewsFromSheets(document));
            }
            catch
            {
            }
        }

        private static int CountViewsFromSheets(ISwDMDocument29 document)
        {
            int count = 0;
            object sheetsObj = document.GetSheets();
            if (sheetsObj is Array sheets)
            {
                foreach (object sheetObj in sheets)
                {
                    if (sheetObj is ISwDMSheet4 sheet)
                    {
                        count += CountArrayItems(sheet.GetViews());
                    }
                }
            }

            return count;
        }

        private static int CountArrayItems(object value)
        {
            return value is Array array ? array.Length : 0;
        }
    }
}
