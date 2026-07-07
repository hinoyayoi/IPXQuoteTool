using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using IPXQuoteTool.Analysis;
using IPXQuoteTool.Reporting;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

namespace IPXQuoteTool
{
    public class SolidWorksService
    {
        private SldWorks _swApp;
        private readonly DocumentAnalyzer _documentAnalyzer;
        private readonly IReportGenerator _reportGenerator;

        public SolidWorksService()
        {
            _documentAnalyzer = new DocumentAnalyzer();
            _reportGenerator = new TextReportGenerator();
        }

        public bool ConnectOrStart(string swInstallPath, int timeoutSeconds = 60)
        {
            Debug.WriteLine("===== 开始连接 SolidWorks =====");

            // 如果提供了安装路径，尝试从路径中推断出版本化的 ProgID（例如 2024 -> SldWorks.Application.24）
            string versionedProgId = null;
            if (!string.IsNullOrEmpty(swInstallPath))
            {
                try
                {
                    var m = System.Text.RegularExpressions.Regex.Match(swInstallPath, "(19|20)\\d{2}");
                    if (m.Success && int.TryParse(m.Value, out int year))
                    {
                        int suffix = year % 100;
                        versionedProgId = $"SldWorks.Application.{suffix}";
                        Debug.WriteLine($"推断 SolidWorks ProgID: {versionedProgId}");
                    }
                }
                catch { }
            }

            if (TryGetRunningSolidWorks(versionedProgId))
            {
                Debug.WriteLine("成功连接到已运行的 SolidWorks 实例");
                return true;
            }

            Debug.WriteLine("未找到运行中的 SolidWorks 实例，尝试启动...");

            if (!string.IsNullOrEmpty(swInstallPath))
            {
                string swExePath = Path.Combine(swInstallPath, "sldworks.exe");
                Debug.WriteLine($"SolidWorks 路径: {swExePath}");
                
                if (File.Exists(swExePath))
                {
                    try
                    {
                        ProcessStartInfo psi = new ProcessStartInfo
                        {
                            FileName = swExePath,
                            WorkingDirectory = swInstallPath,
                            UseShellExecute = true
                        };
                        Process swProcess = Process.Start(psi);
                        Debug.WriteLine($"SolidWorks 进程已启动，PID: {swProcess.Id}");
                        // 记录进程所属会话和用户，帮助诊断 ROT 可见性问题
                        try
                        {
                            LogProcessInfo(Process.GetCurrentProcess());
                            LogProcessInfo(swProcess);
                        }
                        catch { }
                        // 立即列出 ROT 条目以便诊断（看看是否已有 SolidWorks 条目但未匹配到）
                        LogRunningObjectTableEntries();

                        // 先尝试快速连接已运行的实例（使用版本化 ProgID 优先匹配对应版本）
                        if (TryGetRunningSolidWorks(versionedProgId))
                        {
                            Debug.WriteLine("SolidWorks 启动成功 (快速检测)");
                            return true;
                        }

                        // 不使用通过 COM 创建默认 ProgID 的方式（可能会启动系统默认版本），改为等待由启动的可执行注册到 ROT
                        int retryCount = 0;
                        int maxRetries = timeoutSeconds * 4; // 提高等待时间以适应慢启动

                        while (retryCount < maxRetries)
                        {
                            Thread.Sleep(500);
                            Debug.WriteLine($"尝试连接第 {retryCount + 1} 次...");

                        // 尝试连接（不再因启动进程退出而立即中断，因为主进程可能是启动器）
                        if (TryGetRunningSolidWorks(versionedProgId))
                        {
                            Debug.WriteLine($"SolidWorks 启动成功，耗时 {retryCount * 0.5} 秒");
                            return true;
                        }

                        if (swProcess.HasExited)
                        {
                            Debug.WriteLine($"SolidWorks 启动器进程已退出，退出码: {swProcess.ExitCode}。继续等待子进程在 ROT 中注册。");
                            try
                            {
                                var others = Process.GetProcessesByName("sldworks");
                                foreach (var p in others)
                                {
                                    Debug.WriteLine($"检测到 sldworks 进程 PID={p.Id}, SessionId={p.SessionId}");
                                }
                            }
                            catch { }
                        }

                            retryCount++;
                            Debug.WriteLine($"等待 SolidWorks 启动... ({retryCount}/{maxRetries})");

                            // 每 10 次重试再列出一次 ROT 以观察变化
                            if (retryCount % 10 == 0) LogRunningObjectTableEntries();
                        }

                        Debug.WriteLine("SolidWorks 启动超时");
                    }
                    catch (Exception ex)
                    {
                        Debug.WriteLine($"启动 SolidWorks 失败: {ex.Message}");
                        Debug.WriteLine($"异常详情: {ex.StackTrace}");
                    }
                }
                else
                {
                    Debug.WriteLine($"SolidWorks 可执行文件不存在: {swExePath}");
                }
            }
            else
            {
                Debug.WriteLine("SolidWorks 安装路径为空");
            }

            return false;
        }

        private bool TryGetRunningSolidWorks(string progId = null)
        {
            try
            {
                // 使用自定义的 ROT 扫描方法获取运行中的 SolidWorks 实例
                string pid = string.IsNullOrEmpty(progId) ? "SldWorks.Application" : progId;
                _swApp = GetActiveObject(pid) as SldWorks;
                if (_swApp != null)
                {
                    _swApp.Visible = true;
                    Debug.WriteLine($"SolidWorks 连接成功 (ROT -> {pid})");
                    return true;
                }
                return false;
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"获取 SolidWorks 实例失败: {ex.Message}");
                return false;
            }
        }

        // 注：为避免通过 COM 创建默认 ProgID 导致启动其他版本的 SolidWorks，删除自动 CreateInstance 的行为。
        // 仅保留通过启动指定可执行并等待其在 ROT 中注册的逻辑。
        // 如果未来需要强制通过 COM 创建特定版本的实例，请确保对应的版本化 ProgID 已注册并谨慎使用。

        private object GetActiveObject(string progId)
        {
            System.Runtime.InteropServices.ComTypes.IRunningObjectTable rot = null;
            System.Runtime.InteropServices.ComTypes.IEnumMoniker enumMoniker = null;
            System.Runtime.InteropServices.ComTypes.IMoniker[] moniker = new System.Runtime.InteropServices.ComTypes.IMoniker[1];

            try
            {
                int hr = Ole32.GetRunningObjectTable(0, out rot);
                if (hr != 0 || rot == null) return null;

                rot.EnumRunning(out enumMoniker);
                if (enumMoniker == null) return null;

                enumMoniker.Reset();
                while (enumMoniker.Next(1, moniker, IntPtr.Zero) == 0)
                {
                    System.Runtime.InteropServices.ComTypes.IBindCtx bindCtx = null;
                    try
                    {
                        hr = Ole32.CreateBindCtx(0, out bindCtx);
                        if (hr != 0 || bindCtx == null) continue;

                        string displayName = null;
                        moniker[0].GetDisplayName(bindCtx, null, out displayName);
                        Debug.WriteLine($"ROT entry: {displayName}");

                        if (!string.IsNullOrEmpty(displayName))
                        {
                            bool matched = false;
                            
                            if (!string.IsNullOrEmpty(progId))
                            {
                                matched = displayName.Equals(progId, StringComparison.OrdinalIgnoreCase) ||
                                          displayName.Contains(progId, StringComparison.OrdinalIgnoreCase);
                            }
                            
                            if (!matched)
                            {
                                if (displayName.StartsWith("SolidWorks_PID", StringComparison.OrdinalIgnoreCase))
                                {
                                    matched = true;
                                }
                                else if (displayName.IndexOf("SldWorks", StringComparison.OrdinalIgnoreCase) >= 0)
                                {
                                    matched = true;
                                }
                                else if (displayName.IndexOf("SolidWorks", StringComparison.OrdinalIgnoreCase) >= 0)
                                {
                                    matched = true;
                                }
                            }

                            if (matched)
                            {
                                Debug.WriteLine($"匹配到 ROT 条目: {displayName}");
                                object obj = null;
                                hr = rot.GetObject(moniker[0], out obj);
                                if (hr == 0 && obj != null)
                                {
                                    SldWorks sw = obj as SldWorks;
                                    if (sw != null) return obj;
                                    Debug.WriteLine("获取到对象但不是 SldWorks 类型");
                                }
                            }
                        }
                    }
                    finally
                    {
                        if (bindCtx != null) Marshal.ReleaseComObject(bindCtx);
                    }
                }
            }
            finally
            {
                if (enumMoniker != null) Marshal.ReleaseComObject(enumMoniker);
                if (rot != null) Marshal.ReleaseComObject(rot);
            }

            return null;
        }

        // 列出当前 ROT 中所有条目，用于诊断为什么看不到目标 SolidWorks COM 对象
        private void LogRunningObjectTableEntries()
        {
            try
            {
                System.Runtime.InteropServices.ComTypes.IRunningObjectTable rot = null;
                System.Runtime.InteropServices.ComTypes.IEnumMoniker enumMoniker = null;
                System.Runtime.InteropServices.ComTypes.IMoniker[] moniker = new System.Runtime.InteropServices.ComTypes.IMoniker[1];

                int hr = Ole32.GetRunningObjectTable(0, out rot);
                if (hr != 0 || rot == null) return;

                rot.EnumRunning(out enumMoniker);
                if (enumMoniker == null) return;

                enumMoniker.Reset();
                while (enumMoniker.Next(1, moniker, IntPtr.Zero) == 0)
                {
                    System.Runtime.InteropServices.ComTypes.IBindCtx bindCtx = null;
                    try
                    {
                        hr = Ole32.CreateBindCtx(0, out bindCtx);
                        if (hr != 0 || bindCtx == null) continue;

                        string displayName = null;
                        moniker[0].GetDisplayName(bindCtx, null, out displayName);
                        Debug.WriteLine($"ROT listing: {displayName}");
                    }
                    finally
                    {
                        if (bindCtx != null) Marshal.ReleaseComObject(bindCtx);
                    }
                }

                if (enumMoniker != null) Marshal.ReleaseComObject(enumMoniker);
                if (rot != null) Marshal.ReleaseComObject(rot);
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"列出 ROT 条目失败: {ex.Message}");
            }
        }

        private void LogProcessInfo(Process p)
        {
            try
            {
                int sid = p.SessionId;
                Debug.WriteLine($"Process Info - Name: {p.ProcessName}, PID: {p.Id}, SessionId: {sid}");
            }
            catch { }
        }

        private static class Ole32
        {
            [DllImport("ole32.dll")]
            public static extern int GetRunningObjectTable(int reserved, out System.Runtime.InteropServices.ComTypes.IRunningObjectTable prot);

            [DllImport("ole32.dll")]
            public static extern int CreateBindCtx(int reserved, out System.Runtime.InteropServices.ComTypes.IBindCtx ppbc);
        }

        public List<string> GetSolidWorksFiles(string folderPath)
        {
            if (!Directory.Exists(folderPath)) return new List<string>();

            string[] extensions = { ".sldprt", ".sldasm", ".slddrw" };
            return Directory.GetFiles(folderPath, "*.*", SearchOption.AllDirectories)
                .Where(f => extensions.Contains(Path.GetExtension(f).ToLower()))
                .ToList();
        }

        public DocumentInfo ProcessDocument(string filePath)
        {
            try
            {
                if (!File.Exists(filePath))
                {
                    Debug.WriteLine($"文件不存在: {filePath}");
                    return null;
                }

                int errors = 0;
                int warnings = 0;
                
                string extension = Path.GetExtension(filePath).ToLower();
                swDocumentTypes_e docType = extension switch
                {
                    ".sldprt" => swDocumentTypes_e.swDocPART,
                    ".sldasm" => swDocumentTypes_e.swDocASSEMBLY,
                    ".slddrw" => swDocumentTypes_e.swDocDRAWING,
                    _ => swDocumentTypes_e.swDocNONE
                };

                if (docType == swDocumentTypes_e.swDocNONE)
                {
                    Debug.WriteLine($"不支持的文件类型: {filePath}");
                    return null;
                }

                Debug.WriteLine($"正在打开文件: {filePath} (类型: {docType})");

                ModelDoc2 model = (ModelDoc2)_swApp.OpenDoc6(
                    filePath, 
                    (int)docType, 
                    (int)swOpenDocOptions_e.swOpenDocOptions_Silent | (int)swOpenDocOptions_e.swOpenDocOptions_ReadOnly, 
                    "", 
                    ref errors, 
                    ref warnings);

                if (model == null)
                {
                    Debug.WriteLine($"打开文件失败: {filePath} (错误码: {errors}, 警告码: {warnings})");
                    return null;
                }

                Debug.WriteLine($"文件打开成功: {filePath}");

                var info = GetDocumentInfo(model);
                _swApp.CloseDoc(filePath);

                Debug.WriteLine($"文件处理完成: {filePath}");

                return info;
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"处理文件出错 {filePath}: {ex.Message}");
                Debug.WriteLine($"异常详情: {ex.StackTrace}");
                return null;
            }
        }

        public DocumentInfo GetDocumentInfo(ModelDoc2 model)
        {
            return _documentAnalyzer.Analyze(model);
        }

        public string GenerateReport(List<DocumentInfo> documents)
        {
            return _reportGenerator.Generate(documents);
        }

        public bool SaveReport(string reportPath, string content)
        {
            try
            {
                if (!Directory.Exists(reportPath))
                {
                    Directory.CreateDirectory(reportPath);
                }

                string filePath = Path.Combine(reportPath, $"报价报表_{DateTime.Now:yyyyMMdd_HHmmss}.txt");
                File.WriteAllText(filePath, content, Encoding.UTF8);
                return true;
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"保存报表失败: {ex.Message}");
                return false;
            }
        }
    }
}
