using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using IPXQuoteTool.Analysis;
using IPXQuoteTool.Pricing;
using IPXQuoteTool.Reporting;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using Microsoft.Win32;
using System.Runtime.InteropServices;
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

        public string LastError { get; private set; }

        public bool ConnectOrStart(string swInstallPath, int timeoutSeconds = 60)
        {
            LastError = null;
            Debug.WriteLine("===== Start connecting SolidWorks =====");

            string selectedExePath = GetSelectedSolidWorksExePath(swInstallPath);
            if (string.IsNullOrEmpty(selectedExePath) || !File.Exists(selectedExePath))
            {
                LastError = $"未找到您选定路径下的 sldworks.exe：{selectedExePath}";
                return false;
            }

            string defaultExePath = GetDefaultSolidWorksExePath();
            if (string.IsNullOrEmpty(defaultExePath))
            {
                LastError = "系统默认 SldWorks.Application 未注册，无法通过 COM 启动 SolidWorks。请先确认 SolidWorks 安装和 COM 注册状态。";
                return false;
            }

            if (!PathsEqual(selectedExePath, defaultExePath))
            {
                LastError =
                    "您选定的 SolidWorks 路径并非系统默认 SldWorks.Application 指向的路径，请确认。\n\n" +
                    $"选定路径：{selectedExePath}\n" +
                    $"系统默认：{defaultExePath}";
                return false;
            }

            if (TryGetRunningDefaultSolidWorks(out string runningPath))
            {
                if (!string.IsNullOrEmpty(runningPath) && !PathsEqual(runningPath, defaultExePath))
                {
                    LastError =
                        "当前已运行的 SolidWorks 与系统默认 SldWorks.Application 指向的路径不一致，请关闭不匹配的 SolidWorks 后重试。\n\n" +
                        $"正在运行：{runningPath}\n" +
                        $"系统默认：{defaultExePath}";
                    _swApp = null;
                    return false;
                }

                ConfigureConnectedSolidWorks();
                Debug.WriteLine("Connected to running default SolidWorks instance.");
                return true;
            }

            return StartDefaultSolidWorksByCom();
        }

        private bool StartDefaultSolidWorksByCom()
        {
            try
            {
                Type swType = Type.GetTypeFromProgID("SldWorks.Application");
                if (swType == null)
                {
                    LastError = "无法解析系统默认 SldWorks.Application。";
                    return false;
                }

                _swApp = Activator.CreateInstance(swType) as SldWorks;
                if (_swApp == null)
                {
                    LastError = "通过 COM 启动 SolidWorks 失败。";
                    return false;
                }

                ConfigureConnectedSolidWorks();
                Debug.WriteLine("Started default SolidWorks through COM.");
                return true;
            }
            catch (Exception ex)
            {
                LastError = $"通过 COM 启动 SolidWorks 失败：{ex.Message}";
                Debug.WriteLine(LastError);
                return false;
            }
        }

        private bool TryGetRunningDefaultSolidWorks(out string runningPath)
        {
            runningPath = null;

            try
            {
                object obj = GetActiveObject("SldWorks.Application", out string displayName);
                _swApp = obj as SldWorks;
                if (_swApp == null)
                {
                    return false;
                }

                runningPath = GetSolidWorksPathFromRotDisplayName(displayName);
                Debug.WriteLine($"Connected ROT entry: {displayName}, Path: {runningPath}");
                return true;
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"获取运行中的 SolidWorks 实例失败：{ex.Message}");
                return false;
            }
        }

        private void ConfigureConnectedSolidWorks()
        {
            _swApp.Visible = false;
            try
            {
                Debug.WriteLine($"Connected SolidWorks RevisionNumber: {_swApp.RevisionNumber()}");
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"读取 SolidWorks 版本失败：{ex.Message}");
            }
        }

        private static string GetSelectedSolidWorksExePath(string swInstallPath)
        {
            if (string.IsNullOrWhiteSpace(swInstallPath))
            {
                return null;
            }

            string candidate = Path.GetFileName(swInstallPath).Equals("sldworks.exe", StringComparison.OrdinalIgnoreCase)
                ? swInstallPath
                : Path.Combine(swInstallPath, "sldworks.exe");

            return NormalizePath(candidate);
        }

        private static string GetDefaultSolidWorksExePath()
        {
            try
            {
                using RegistryKey progIdKey = Registry.ClassesRoot.OpenSubKey(@"SldWorks.Application\CLSID");
                string clsid = progIdKey?.GetValue(null) as string;
                if (string.IsNullOrWhiteSpace(clsid))
                {
                    return null;
                }

                using RegistryKey serverKey = Registry.ClassesRoot.OpenSubKey($@"CLSID\{clsid}\LocalServer32");
                string serverCommand = serverKey?.GetValue(null) as string;
                return NormalizePath(ExtractExecutablePath(serverCommand));
            }
            catch
            {
                return null;
            }
        }

        private static string ExtractExecutablePath(string serverCommand)
        {
            if (string.IsNullOrWhiteSpace(serverCommand))
            {
                return null;
            }

            string trimmed = serverCommand.Trim();
            if (trimmed.StartsWith("\""))
            {
                int endQuote = trimmed.IndexOf('"', 1);
                if (endQuote > 1)
                {
                    return trimmed.Substring(1, endQuote - 1);
                }
            }

            int exeIndex = trimmed.IndexOf(".exe", StringComparison.OrdinalIgnoreCase);
            return exeIndex >= 0 ? trimmed.Substring(0, exeIndex + 4) : trimmed;
        }

        private static string NormalizePath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return null;
            }

            try
            {
                return Path.GetFullPath(path.Trim().Trim('"')).TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar);
            }
            catch
            {
                return path.Trim().Trim('"');
            }
        }

        private static bool PathsEqual(string left, string right)
        {
            string normalizedLeft = NormalizePath(left);
            string normalizedRight = NormalizePath(right);
            return string.Equals(normalizedLeft, normalizedRight, StringComparison.OrdinalIgnoreCase);
        }

        private static string GetSolidWorksPathFromRotDisplayName(string displayName)
        {
            int? pid = TryParseSolidWorksPid(displayName);
            if (!pid.HasValue)
            {
                return null;
            }

            try
            {
                using Process process = Process.GetProcessById(pid.Value);
                return NormalizePath(process.MainModule?.FileName);
            }
            catch
            {
                return null;
            }
        }

        private static int? TryParseSolidWorksPid(string displayName)
        {
            if (string.IsNullOrWhiteSpace(displayName))
            {
                return null;
            }

            const string marker = "SolidWorks_PID_";
            int markerIndex = displayName.IndexOf(marker, StringComparison.OrdinalIgnoreCase);
            if (markerIndex < 0)
            {
                return null;
            }

            int start = markerIndex + marker.Length;
            int end = start;
            while (end < displayName.Length && char.IsDigit(displayName[end]))
            {
                end++;
            }

            return int.TryParse(displayName.Substring(start, end - start), out int pid) ? pid : null;
        }

        private object GetActiveObject(string progId, out string matchedDisplayName)
        {
            matchedDisplayName = null;
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
                            bool matched =
                                displayName.Equals(progId, StringComparison.OrdinalIgnoreCase) ||
                                displayName.Contains(progId, StringComparison.OrdinalIgnoreCase) ||
                                displayName.StartsWith("SolidWorks_PID", StringComparison.OrdinalIgnoreCase);

                            if (matched)
                            {
                                Debug.WriteLine($"匹配到 ROT 条目: {displayName}");
                                object obj = null;
                                hr = rot.GetObject(moniker[0], out obj);
                                if (hr == 0 && obj != null)
                                {
                                    SldWorks sw = obj as SldWorks;
                                    if (sw != null)
                                    {
                                        matchedDisplayName = displayName;
                                        return obj;
                                    }
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

                byte[] cachedPreviewImageBytes = TryGetPreviewImageBytes(filePath, null);

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
                info.PreviewImageBytes =
                    TryCaptureModelViewImageBytes(model, docType) ??
                    cachedPreviewImageBytes ??
                    TryGetPreviewImageBytes(filePath, model);
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


        private byte[] TryCaptureModelViewImageBytes(ModelDoc2 model, swDocumentTypes_e docType)
        {
            string bitmapPath = null;

            try
            {
                if (model == null)
                {
                    return null;
                }

                bitmapPath = Path.Combine(Path.GetTempPath(), $"IPXQuote_capture_{Guid.NewGuid():N}.bmp");
                PrepareModelViewForCapture(model, docType);

                bool success = model.SaveBMP(bitmapPath, 520, 360);
                if (!success || !File.Exists(bitmapPath))
                {
                    Debug.WriteLine($"实时视图截图未返回文件: {model.GetTitle()}");
                    return null;
                }

                FileInfo bitmapFile = new FileInfo(bitmapPath);
                if (bitmapFile.Length == 0)
                {
                    Debug.WriteLine($"实时视图截图返回空文件: {model.GetTitle()}");
                    return null;
                }

                return ConvertBitmapFileToJpegBytes(bitmapPath);
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"实时视图截图失败: {ex.Message}");
                return null;
            }
            finally
            {
                try
                {
                    if (!string.IsNullOrWhiteSpace(bitmapPath) && File.Exists(bitmapPath))
                    {
                        File.Delete(bitmapPath);
                    }
                }
                catch
                {
                }
            }
        }

        private static void PrepareModelViewForCapture(ModelDoc2 model, swDocumentTypes_e docType)
        {
            try
            {
                if (docType == swDocumentTypes_e.swDocDRAWING)
                {
                    model.Extension?.ViewZoomToSheet();
                }
                else
                {
                    model.ShowNamedView2("*Isometric", (int)swStandardViews_e.swIsometricView);
                    model.ViewZoomtofit2();

                    if (model.IActiveView is ModelView activeView)
                    {
                        activeView.DisplayMode = (int)swDisplayMode_e.swSHADED_EDGES;
                        activeView.DisplayZebraStripes = false;
                    }
                    else
                    {
                        model.ViewDisplayShaded();
                    }
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"准备实时视图截图失败: {ex.Message}");
            }
        }

        private byte[] TryGetPreviewImageBytes(string filePath, ModelDoc2 model)
        {
            if (_swApp == null || string.IsNullOrWhiteSpace(filePath))
            {
                return null;
            }

            foreach (string configurationName in GetPreviewConfigurationNames(model))
            {
                string bitmapPath = null;

                try
                {
                    bitmapPath = Path.Combine(Path.GetTempPath(), $"IPXQuote_preview_{Guid.NewGuid():N}.bmp");
                    bool success = _swApp.GetPreviewBitmapFile(filePath, configurationName, bitmapPath);
                    if (!success || !File.Exists(bitmapPath))
                    {
                        Debug.WriteLine($"获取预览图未返回文件: {Path.GetFileName(filePath)}, 配置: {configurationName}");
                        continue;
                    }

                    FileInfo bitmapFile = new FileInfo(bitmapPath);
                    if (bitmapFile.Length == 0)
                    {
                        Debug.WriteLine($"获取预览图返回空文件: {Path.GetFileName(filePath)}, 配置: {configurationName}");
                        continue;
                    }

                    byte[] imageBytes = ConvertBitmapFileToJpegBytes(bitmapPath);
                    Debug.WriteLine($"获取预览图成功: {Path.GetFileName(filePath)}, 配置: {configurationName}, 字节: {imageBytes.Length}");
                    return imageBytes;
                }
                catch (Exception ex)
                {
                    Debug.WriteLine($"获取预览图失败 {filePath}, 配置: {configurationName}: {ex.Message}");
                }
                finally
                {
                    try
                    {
                        if (!string.IsNullOrWhiteSpace(bitmapPath) && File.Exists(bitmapPath))
                        {
                            File.Delete(bitmapPath);
                        }
                    }
                    catch
                    {
                    }
                }
            }

            return null;
        }

        private static byte[] ConvertBitmapFileToJpegBytes(string bitmapPath)
        {
            using Image image = Image.FromFile(bitmapPath);
            using var imageStream = new MemoryStream();
            image.Save(imageStream, ImageFormat.Jpeg);
            return imageStream.ToArray();
        }

        private static IEnumerable<string> GetPreviewConfigurationNames(ModelDoc2 model)
        {
            yield return string.Empty;

            if (model == null)
            {
                yield break;
            }

            string activeConfigurationName = null;
            try
            {
                if (model.GetActiveConfiguration() is Configuration configuration)
                {
                    activeConfigurationName = configuration.Name;
                }
            }
            catch
            {
            }

            if (!string.IsNullOrWhiteSpace(activeConfigurationName))
            {
                yield return activeConfigurationName;
            }
        }
        public DocumentInfo GetDocumentInfo(ModelDoc2 model)
        {
            return _documentAnalyzer.Analyze(model);
        }

        public byte[] GenerateReport(List<DocumentInfo> documents, QuotePricingSettings pricingSettings)
        {
            return _reportGenerator.Generate(documents, pricingSettings);
        }

        public bool SaveReport(string reportPath, byte[] content)
        {
            try
            {
                if (!Directory.Exists(reportPath))
                {
                    Directory.CreateDirectory(reportPath);
                }

                string filePath = Path.Combine(reportPath, $"报价报表_{DateTime.Now:yyyyMMdd_HHmmss}.xlsx");
                File.WriteAllBytes(filePath, content);
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



