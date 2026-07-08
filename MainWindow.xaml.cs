using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using IPXQuoteTool.Settings;
using IPXQuoteTool.Pricing;
using WinForms = System.Windows.Forms;

namespace IPXQuoteTool
{
    public partial class MainWindow : Window
    {
        private SolidWorksService _swService;
        private UserPathSettingsService _pathSettingsService;
        private bool _isRunning;
        private bool _cancelRequested;
        private bool _closeAfterCancel;
        private bool _allowClose;
        private Progress<DocumentProgressUpdate> _progressReporter;

        public MainWindow()
        {
            InitializeComponent();
            Closing += MainWindow_Closing;
            _swService = new SolidWorksService();
            _pathSettingsService = new UserPathSettingsService();
            LoadSavedPaths();
            string coefficientFilePath = ObjectCoefficientSettingsService.EnsureDefaultFile();
            Log("IPX报价工具已启动");
            Log($"对象系数表: {coefficientFilePath}");
            Log("等待用户配置...");
            _progressReporter = new Progress<DocumentProgressUpdate>(ApplyProgressUpdate);
        }


        private void MainWindow_Closing(object sender, CancelEventArgs e)
        {
            if (_allowClose || !_isRunning)
            {
                return;
            }

            var result = MessageBox.Show(
                this,
                "当前正在计算中，是否确认取消执行？",
                "确认取消",
                MessageBoxButton.YesNo,
                MessageBoxImage.Warning);

            if (result != MessageBoxResult.Yes)
            {
                e.Cancel = true;
                return;
            }

            e.Cancel = true;
            _cancelRequested = true;
            _closeAfterCancel = true;
            btnRun.IsEnabled = false;
            txtProgressText.Text = "正在取消...";
            Log("用户请求取消执行，正在等待当前处理步骤结束...");
        }
        private void ApplyProgressUpdate(DocumentProgressUpdate update)
        {
            txtProgressText.Text = update.Text;
            progressBar.Maximum = update.TotalCount <= 0 ? 1 : update.TotalCount;
            progressBar.Value = Math.Min(update.ProcessedCount, progressBar.Maximum);
            txtPartCount.Text = update.PartCount.ToString();
            txtAssemblyCount.Text = update.AssemblyCount.ToString();
            txtDrawingCount.Text = update.DrawingCount.ToString();
        }

        private void SetInputControlsEnabled(bool isEnabled)
        {
            pathConfigPanel.IsEnabled = isEnabled;
            discountPanel.IsEnabled = isEnabled;
            chkOfflineMode.IsEnabled = isEnabled;
        }

        private void Log(string message)
        {
            AppendLog($"[{DateTime.Now:HH:mm:ss}] {message}\n");
        }

        private void LogError(string message)
        {
            AppendLog($"[{DateTime.Now:HH:mm:ss}] ❌ {message}\n");
        }

        private void LogSuccess(string message)
        {
            AppendLog($"[{DateTime.Now:HH:mm:ss}] ✅ {message}\n");
        }

        private void AppendLog(string text)
        {
            _ = Dispatcher.BeginInvoke(new Action(() =>
            {
                txtLog.AppendText(text);
                txtLog.ScrollToEnd();
            }));
        }

        private bool BrowseFolder(System.Windows.Controls.TextBox target)
        {
            using (var dlg = new WinForms.FolderBrowserDialog())
            {
                try
                {
                    if (!string.IsNullOrWhiteSpace(target.Text))
                    {
                        if (Directory.Exists(target.Text))
                        {
                            dlg.SelectedPath = target.Text;
                        }
                        else if (File.Exists(target.Text))
                        {
                            dlg.SelectedPath = Path.GetDirectoryName(target.Text);
                        }
                    }
                }
                catch { }

                var res = dlg.ShowDialog();
                if (res == WinForms.DialogResult.OK)
                {
                    target.Text = dlg.SelectedPath;
                    SaveCurrentPaths();
                    return true;
                }
            }

            return false;
        }

        private void BrowseFile(System.Windows.Controls.TextBox target)
        {
            using (var dlg = new WinForms.OpenFileDialog())
            {
                dlg.Filter = "SolidWorks文件 (*.sldprt;*.sldasm;*.slddrw)|*.sldprt;*.sldasm;*.slddrw|所有文件 (*.*)|*.*";
                dlg.Multiselect = false;

                try
                {
                    if (!string.IsNullOrWhiteSpace(target.Text))
                    {
                        if (File.Exists(target.Text))
                        {
                            dlg.FileName = target.Text;
                        }
                        else if (Directory.Exists(target.Text))
                        {
                            dlg.InitialDirectory = target.Text;
                        }
                    }
                }
                catch { }

                var res = dlg.ShowDialog();
                if (res == WinForms.DialogResult.OK)
                {
                    target.Text = dlg.FileName;
                    SaveCurrentPaths();
                }
            }
        }

        private void BrowseSoftware_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtSoftwarePath);
        private void BrowseDrawing_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtDrawingPath);
        private void BrowseReport_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtReportPath);

        private void LoadSavedPaths()
        {
            var settings = _pathSettingsService.Load();
            txtSoftwarePath.Text = settings.SolidWorksPath ?? string.Empty;
            txtDrawingPath.Text = settings.DrawingFolderPath ?? string.Empty;
            txtReportPath.Text = settings.ReportFolderPath ?? string.Empty;
            chkOfflineMode.IsChecked = settings.UseOfflineDocumentManager;
        }

        private void SaveCurrentPaths()
        {
            _pathSettingsService.Save(new UserPathSettings
            {
                SolidWorksPath = txtSoftwarePath.Text,
                DrawingFolderPath = txtDrawingPath.Text,
                ReportFolderPath = txtReportPath.Text,
                UseOfflineDocumentManager = chkOfflineMode.IsChecked == true
            });
        }

        private void BtnClearLog_Click(object sender, RoutedEventArgs e)
        {
            txtLog.Clear();
            Log("日志已清空");
        }

        private void Discount_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            var tb = sender as System.Windows.Controls.TextBox;
            string newText = tb.Text;
            if (tb.SelectionLength > 0)
            {
                newText = newText.Remove(tb.SelectionStart, tb.SelectionLength);
            }
            newText = newText.Insert(tb.SelectionStart, e.Text);

            var regex = new Regex("^$|^[0-9](\\.[0-9]?)?$");
            e.Handled = !regex.IsMatch(newText);
        }

        private void Discount_LostFocus(object sender, RoutedEventArgs e)
        {
            var tb = sender as System.Windows.Controls.TextBox;
            FormatAndClamp(tb);
        }

        private void FormatAndClamp(System.Windows.Controls.TextBox tb)
        {
            if (tb == null) return;
            if (!double.TryParse(tb.Text, out double v))
            {
                tb.Text = "0.5";
                return;
            }
            v = Math.Round(v, 1);
            if (v < 0.4) v = 0.4;
            if (v > 1.0) v = 1.0;
            tb.Text = v.ToString("0.0");
        }

        private void ChangeDiscount(System.Windows.Controls.TextBox tb, double delta)
        {
            if (tb == null) return;
            if (!double.TryParse(tb.Text, out double v)) v = 0.5;
            v = Math.Round(v + delta, 1);
            if (v < 0.4) v = 0.4;
            if (v > 1.0) v = 1.0;
            tb.Text = v.ToString("0.0");
        }

        private void PartUp_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbPartDiscount, 0.1);
        private void PartDown_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbPartDiscount, -0.1);
        private void AssemblyUp_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbAssemblyDiscount, 0.1);
        private void AssemblyDown_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbAssemblyDiscount, -0.1);
        private void DrawingUp_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbDrawingDiscount, 0.1);
        private void DrawingDown_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbDrawingDiscount, -0.1);

        private Task<TResult> RunStaTask<TResult>(Func<TResult> work)
        {
            var completion = new TaskCompletionSource<TResult>();
            var thread = new Thread(() =>
            {
                try
                {
                    completion.SetResult(work());
                }
                catch (Exception ex)
                {
                    completion.SetException(ex);
                }
            });
            thread.IsBackground = true;
            thread.SetApartmentState(ApartmentState.STA);
            thread.Start();
            return completion.Task;
        }

        private QuotePricingSettings BuildPricingSettings()
        {
            FormatAndClamp(tbPartDiscount);
            FormatAndClamp(tbAssemblyDiscount);
            FormatAndClamp(tbDrawingDiscount);

            return new QuotePricingSettings
            {
                PartDiscount = double.TryParse(tbPartDiscount.Text, out double partDiscount) ? partDiscount : 0.5,
                AssemblyDiscount = double.TryParse(tbAssemblyDiscount.Text, out double assemblyDiscount) ? assemblyDiscount : 0.4,
                DrawingDiscount = double.TryParse(tbDrawingDiscount.Text, out double drawingDiscount) ? drawingDiscount : 0.8,
                ObjectCoefficients = ObjectCoefficientSettingsService.Load()
            };
        }
        private async void BtnRun_Click(object sender, RoutedEventArgs e)
        {
            if (_isRunning)
            {
                return;
            }

            _isRunning = true;
            _cancelRequested = false;
            _closeAfterCancel = false;
            btnRun.IsEnabled = false;
            SetInputControlsEnabled(false);
            txtProgressText.Text = "准备中...";
            progressBar.Minimum = 0;
            progressBar.Maximum = 1;
            progressBar.Value = 0;
            txtPartCount.Text = "0";
            txtAssemblyCount.Text = "0";
            txtDrawingCount.Text = "0";

            try
            {
                bool useOfflineMode = chkOfflineMode.IsChecked == true;
                string softwarePath = txtSoftwarePath.Text;
                string drawingPath = txtDrawingPath.Text;
                string reportPath = txtReportPath.Text;

                if (!useOfflineMode && string.IsNullOrWhiteSpace(softwarePath))
                {
                    LogError("请选择 SolidWorks 安装路径！");
                    MessageBox.Show("请选择 SolidWorks 安装路径！");
                    return;
                }
                if (string.IsNullOrWhiteSpace(drawingPath))
                {
                    LogError("请选择图纸路径！");
                    MessageBox.Show("请选择图纸路径！");
                    return;
                }
                if (string.IsNullOrWhiteSpace(reportPath))
                {
                    LogError("请选择报表保存路径！");
                    MessageBox.Show("请选择报表保存路径！");
                    return;
                }

                SaveCurrentPaths();

                Log("=");
                Log("开始处理...");
                Log($"SolidWorks路径: {softwarePath}");
                Log($"图纸路径: {drawingPath}");
                Log($"报表路径: {reportPath}");

                QuotePricingSettings pricingSettings = BuildPricingSettings();
                Log($"已读取对象系数表: {ObjectCoefficientSettingsService.GetDefaultFilePath()}");

                ProcessingResult result = await RunStaTask(() => RunProcessing(useOfflineMode, softwarePath, drawingPath, reportPath, pricingSettings, _progressReporter));

                if (result.Cancelled)
                {
                    txtProgressText.Text = "已取消";
                    Log("处理已取消");
                    return;
                }

                txtProgressText.Text = "完成";
                progressBar.Value = progressBar.Maximum;

                if (result.ReportSaved)
                {
                    LogSuccess($"处理完成！共处理 {result.ProcessedCount} 个文件");
                    LogSuccess($"报表已保存到: {reportPath}");
                    MessageBox.Show("计算已完成，请前往报表路径查看结果！");
                }
                else
                {
                    LogError("报表保存失败");
                    MessageBox.Show($"处理完成！\n共处理 {result.ProcessedCount} 个文件\n报表保存失败，请检查路径权限。");
                }
            }
            catch (Exception ex)
            {
                LogError($"处理过程中出错：{ex.Message}");
                LogError($"异常详情：{ex.StackTrace}");
                MessageBox.Show($"处理过程中出错：\n{ex.Message}");
            }
            finally
            {
                _isRunning = false;
                if (!_closeAfterCancel)
                {
                    btnRun.IsEnabled = true;
                    SetInputControlsEnabled(true);
                }

                if (_closeAfterCancel)
                {
                    _allowClose = true;
                    _ = Dispatcher.BeginInvoke(new Action(Close));
                }
            }
        }

        private ProcessingResult RunProcessing(bool useOfflineMode, string softwarePath, string drawingPath, string reportPath, QuotePricingSettings pricingSettings, IProgress<DocumentProgressUpdate> progress)
        {
            if (!useOfflineMode)
            {
                progress.Report(new DocumentProgressUpdate("连接 SolidWorks...", 0, 1, 0, 0, 0));

                if (!_swService.ConnectOrStart(softwarePath))
                {
                    string error = string.IsNullOrWhiteSpace(_swService.LastError)
                        ? "无法连接到 SolidWorks，请确认 SolidWorks 已安装并正常运行。"
                        : _swService.LastError;
                    LogError(error);
                    throw new InvalidOperationException(error);
                }

                LogSuccess("成功连接到 SolidWorks");
            }
            else
            {
                Log("离线读取模式：跳过 SolidWorks 启动和连接。");
            }

            progress.Report(new DocumentProgressUpdate("扫描文件...", 0, 1, 0, 0, 0));

            if (!Directory.Exists(drawingPath))
            {
                LogError("指定的图纸路径无效！");
                throw new InvalidOperationException("指定的图纸路径无效！");
            }

            List<string> files = _swService.GetSolidWorksFiles(drawingPath);
            if (files.Count == 0)
            {
                LogError("未找到 SolidWorks 文件（.sldprt/.sldasm/.slddrw）！");
                throw new InvalidOperationException("未找到 SolidWorks 文件（.sldprt/.sldasm/.slddrw）！");
            }

            Log($"找到 {files.Count} 个 SolidWorks 文件");
            progress.Report(new DocumentProgressUpdate($"处理文档... (0/{files.Count})", 0, files.Count, 0, 0, 0));

            var results = new List<DocumentInfo>();
            int partCount = 0;
            int assemblyCount = 0;
            int drawingCount = 0;
            OfflineDocumentManagerService offlineService = null;

            if (useOfflineMode)
            {
                string documentManagerLicenseKey = _pathSettingsService.Load().DocumentManagerLicenseKey;
                offlineService = new OfflineDocumentManagerService(documentManagerLicenseKey);
                if (!offlineService.Initialize())
                {
                    LogError(offlineService.LastError);
                    throw new InvalidOperationException(offlineService.LastError);
                }
            }

            for (int i = 0; i < files.Count; i++)
            {
                if (_cancelRequested)
                {
                    return ProcessingResult.CancelledResult(results.Count);
                }

                string file = files[i];
                DocumentInfo info = useOfflineMode
                    ? offlineService.ProcessDocument(file)
                    : _swService.ProcessDocument(file);

                if (info != null)
                {
                    results.Add(info);

                    switch (info.DocumentType)
                    {
                        case SolidWorks.Interop.swconst.swDocumentTypes_e.swDocPART:
                            partCount++;
                            break;
                        case SolidWorks.Interop.swconst.swDocumentTypes_e.swDocASSEMBLY:
                            assemblyCount++;
                            break;
                        case SolidWorks.Interop.swconst.swDocumentTypes_e.swDocDRAWING:
                            drawingCount++;
                            break;
                    }

                    Log($"处理完成: {info.FileName} ({info.Category})");
                }
                else
                {
                    LogError($"处理失败: {Path.GetFileName(file)}");
                    if (useOfflineMode && !string.IsNullOrWhiteSpace(offlineService.LastError))
                    {
                        LogError(offlineService.LastError);
                    }
                }

                int processedCount = i + 1;
                progress.Report(new DocumentProgressUpdate($"处理中 ({processedCount}/{files.Count})", processedCount, files.Count, partCount, assemblyCount, drawingCount));
            }

            if (_cancelRequested)
            {
                return ProcessingResult.CancelledResult(results.Count);
            }

            progress.Report(new DocumentProgressUpdate("生成报表...", files.Count, files.Count, partCount, assemblyCount, drawingCount));
            byte[] reportContent = _swService.GenerateReport(results, pricingSettings);
            bool saveSuccess = _swService.SaveReport(reportPath, reportContent);
            return new ProcessingResult(results.Count, saveSuccess, false);
        }

        private class DocumentProgressUpdate
        {
            public DocumentProgressUpdate(string text, int processedCount, int totalCount, int partCount, int assemblyCount, int drawingCount)
            {
                Text = text;
                ProcessedCount = processedCount;
                TotalCount = totalCount;
                PartCount = partCount;
                AssemblyCount = assemblyCount;
                DrawingCount = drawingCount;
            }

            public string Text { get; }
            public int ProcessedCount { get; }
            public int TotalCount { get; }
            public int PartCount { get; }
            public int AssemblyCount { get; }
            public int DrawingCount { get; }
        }

        private class ProcessingResult
        {
            public ProcessingResult(int processedCount, bool reportSaved, bool cancelled)
            {
                ProcessedCount = processedCount;
                ReportSaved = reportSaved;
                Cancelled = cancelled;
            }

            public int ProcessedCount { get; }
            public bool ReportSaved { get; }
            public bool Cancelled { get; }

            public static ProcessingResult CancelledResult(int processedCount)
            {
                return new ProcessingResult(processedCount, false, true);
            }
        }
    }
}








