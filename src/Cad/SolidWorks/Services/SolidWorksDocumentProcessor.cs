using IPXQuoteTool.Cad.Common;
using System;
using System.IO;
using System.Threading;

namespace IPXQuoteTool.Cad.SolidWorks.Services
{
    public class SolidWorksDocumentProcessor
    {
        private readonly CadDocumentProcessor _documentProcessor;
        private readonly Action<string> _logError;
        private readonly Action<string> _logSuccess;

        public SolidWorksDocumentProcessor(CadDocumentProcessor documentProcessor, Action<string> logError, Action<string> logSuccess)
        {
            _documentProcessor = documentProcessor ?? throw new ArgumentNullException(nameof(documentProcessor));
            _logError = logError ?? (_ => { });
            _logSuccess = logSuccess ?? (_ => { });
        }

        public DocumentInfo ProcessWithTimeout(string file, string softwarePath, TimeSpan timeout)
        {
            DocumentInfo info = null;
            string failureReason = null;

            var thread = new Thread(() =>
            {
                var service = new SolidWorksService();
                try
                {
                    if (!service.ConnectOrStart(softwarePath))
                    {
                        failureReason = string.IsNullOrWhiteSpace(service.LastError)
                            ? "无法连接到 SolidWorks。"
                            : service.LastError;
                        return;
                    }

                    info = ProcessWithRecovery(service, file, softwarePath);
                    if (info == null && !string.IsNullOrWhiteSpace(service.LastError))
                    {
                        failureReason = service.LastError;
                    }
                }
                catch (Exception ex)
                {
                    failureReason = ex.Message;
                }
                finally
                {
                    service.ResetConnection();
                }
            });

            thread.IsBackground = true;
            thread.SetApartmentState(ApartmentState.STA);
            thread.Start();

            if (!thread.Join(timeout))
            {
                _logError($"处理超时，已跳过: {Path.GetFileName(file)}");
                _logError($"单图纸处理超过 {timeout.TotalMinutes:0} 分钟，正在尝试重置 SolidWorks 后继续。");
                _logError("图纸处理超时，请人工手动排查");
                SolidWorksService.TryTerminateSolidWorksProcesses(softwarePath);
                return CreateTimedOutDocumentPlaceholder(file, timeout);
            }

            if (info != null)
            {
                return info;
            }

            return CreateFailedDocumentPlaceholder(file, failureReason);
        }

        private DocumentInfo ProcessWithRecovery(SolidWorksService service, string file, string softwarePath)
        {
            DocumentInfo info = _documentProcessor.ProcessDocument(file, service);
            if (info != null)
            {
                return info;
            }

            if (service.IsConnectionAlive())
            {
                return null;
            }

            _logError($"检测到 SolidWorks 连接已断开，准备重启并重试当前文件: {Path.GetFileName(file)}");
            service.ResetConnection();

            if (!service.ConnectOrStart(softwarePath))
            {
                string error = string.IsNullOrWhiteSpace(service.LastError)
                    ? "SolidWorks 重启失败。"
                    : service.LastError;
                _logError(error);
                return null;
            }

            _logSuccess("SolidWorks 已重新连接，正在重试当前文件...");
            info = _documentProcessor.ProcessDocument(file, service);
            if (info == null)
            {
                _logError($"重试后仍处理失败: {Path.GetFileName(file)}");
                if (!string.IsNullOrWhiteSpace(service.LastError))
                {
                    _logError(service.LastError);
                }
            }

            return info;
        }

        private static DocumentInfo CreateFailedDocumentPlaceholder(string filePath, string failureReason)
        {
            return new DocumentInfo
            {
                FileName = Path.GetFileName(filePath),
                FilePath = filePath,
                DocumentType = CadFileTypeDetector.GetDocumentTypeFromPath(filePath),
                IsProcessingFailed = true,
                ProcessingError = failureReason ?? "处理失败，已跳过。"
            };
        }

        private static DocumentInfo CreateTimedOutDocumentPlaceholder(string filePath, TimeSpan timeout)
        {
            DocumentInfo info = CreateFailedDocumentPlaceholder(
                filePath,
                $"处理超时超过 {timeout.TotalMinutes:0} 分钟，已自动跳过，后续请人工排查该图纸。");
            info.IsProcessingTimedOut = true;
            return info;
        }
    }
}