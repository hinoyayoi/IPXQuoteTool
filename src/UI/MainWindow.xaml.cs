using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using IPXQuoteTool.Settings;
using IPXQuoteTool.Pricing;
using IPXQuoteTool.Reporting;
using WinForms = System.Windows.Forms;

using IPXQuoteTool.Cad.Common;
using IPXQuoteTool.Cad.Creo.Services;
using IPXQuoteTool.Cad.SolidWorks.Services;

namespace IPXQuoteTool
{
    public partial class MainWindow : Window
    {
        private static readonly TimeSpan DocumentProcessingTimeout = TimeSpan.FromMinutes(5);
        private static readonly bool OfflineModeEntryEnabled = true;
        private const int DeveloperModeClickThreshold = 7;
        private static readonly TimeSpan DeveloperModeClickWindow = TimeSpan.FromSeconds(3);
        private SolidWorksService _swService;
        private CreoService _creoService;
        private CreoQuoteStartupService _creoQuoteStartupService;
        private CadDocumentServiceRouter _cadDocumentServiceRouter;
        private CadDocumentProcessor _cadDocumentProcessor;
        private QuoteReportService _quoteReportService;
        private SolidWorksDocumentProcessor _solidWorksDocumentProcessor;
        private UserPathSettingsService _pathSettingsService;
        private bool _isRunning;
        private bool _cancelRequested;
        private bool _closeAfterCancel;
        private bool _allowClose;
        private bool _developerSingleFileMode;
        private string _developerSingleFilePath;
        private bool _isLoadingSavedPaths;
        private bool _isChangingOfflineMode;
        private CadSoftwareKind _activeSoftwareKind = CadSoftwareKind.SolidWorks;
        private int _developerTitleClickCount;
        private DateTime _firstDeveloperTitleClickTime;
        private Progress<DocumentProgressUpdate> _progressReporter;

        public MainWindow()
        {
            InitializeComponent();
            Closing += MainWindow_Closing;
            _swService = new SolidWorksService();
            _creoService = new CreoService();
            _creoQuoteStartupService = new CreoQuoteStartupService();
            _cadDocumentServiceRouter = new CadDocumentServiceRouter(_swService, _creoService);
            _cadDocumentProcessor = new CadDocumentProcessor(_cadDocumentServiceRouter);
            _quoteReportService = new QuoteReportService();
            _solidWorksDocumentProcessor = new SolidWorksDocumentProcessor(_cadDocumentProcessor, LogError, LogSuccess);
            _pathSettingsService = new UserPathSettingsService();
            LoadSavedPaths();
            string coefficientFilePath = ObjectCoefficientSettingsService.EnsureDefaultFile();
            Log("IPX费用估算已启动");
            Log($"对象系数表: {coefficientFilePath}");
            Log("报价规则已加载");
            Log("等待用户点击运行...");
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
            btnCancel.IsEnabled = false;
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
            discountInputPanel.IsEnabled = isEnabled;
            btnOpenReportPath.IsEnabled = isEnabled;
            chkOfflineMode.IsEnabled = isEnabled && GetSelectedSoftwareKind() == CadSoftwareKind.SolidWorks;
        }

        private void AppTitle_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            DateTime now = DateTime.Now;
            if (_developerTitleClickCount == 0 || now - _firstDeveloperTitleClickTime > DeveloperModeClickWindow)
            {
                _firstDeveloperTitleClickTime = now;
                _developerTitleClickCount = 1;
            }
            else
            {
                _developerTitleClickCount++;
            }

            if (_developerTitleClickCount < DeveloperModeClickThreshold)
            {
                return;
            }

            _developerTitleClickCount = 0;
            ShowDeveloperModeWindow();
        }

        private void ShowDeveloperModeWindow()
        {
            var window = new DeveloperModeWindow(_developerSingleFilePath)
            {
                Owner = this
            };

            bool? result = window.ShowDialog();
            if (window.ResetDeveloperMode)
            {
                _developerSingleFileMode = false;
                _developerSingleFilePath = null;
                Log("开发者单文件费用估算已关闭，恢复目录批量模式。");
                return;
            }

            if (result == true && window.EnableSingleFileMode)
            {
                _developerSingleFileMode = true;
                _developerSingleFilePath = window.SingleFilePath;
                Log($"开发者单文件费用估算已启用: {_developerSingleFilePath}");
            }
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
                dlg.Filter = "CAD文件 (*.sldprt;*.sldasm;*.slddrw;*.prt;*.asm;*.drw)|*.sldprt;*.sldasm;*.slddrw;*.prt;*.asm;*.drw|所有文件 (*.*)|*.*";
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

        private void SoftwareKind_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (_isLoadingSavedPaths || _pathSettingsService == null || txtSoftwarePath == null)
            {
                return;
            }

            CadSoftwareKind selectedSoftware = GetSelectedSoftwareKind();
            var settings = _pathSettingsService.Load();
            SaveSoftwarePath(settings, _activeSoftwareKind, txtSoftwarePath.Text);
            txtSoftwarePath.Text = GetSoftwarePath(settings, selectedSoftware) ?? string.Empty;
            _activeSoftwareKind = selectedSoftware;
            UpdateSoftwareSelectionUi();
            SaveCurrentPaths();
        }
        private void BrowseDrawing_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtDrawingPath);
        private static CadSoftwareKind ParseSoftwareKind(string value)
        {
            return Enum.TryParse(value, ignoreCase: true, out CadSoftwareKind softwareKind) && softwareKind != CadSoftwareKind.Unknown
                ? softwareKind
                : CadSoftwareKind.SolidWorks;
        }

        private CadSoftwareKind GetSelectedSoftwareKind()
        {
            if (cbSoftwareKind?.SelectedItem is ComboBoxItem selectedItem)
            {
                return ParseSoftwareKind(selectedItem.Tag?.ToString());
            }

            return CadSoftwareKind.SolidWorks;
        }

        private void SelectSoftwareKind(CadSoftwareKind softwareKind)
        {
            if (cbSoftwareKind == null)
            {
                return;
            }

            foreach (object item in cbSoftwareKind.Items)
            {
                if (item is ComboBoxItem comboBoxItem && ParseSoftwareKind(comboBoxItem.Tag?.ToString()) == softwareKind)
                {
                    cbSoftwareKind.SelectedItem = comboBoxItem;
                    return;
                }
            }
        }

        private static string GetSoftwarePath(UserPathSettings settings, CadSoftwareKind softwareKind)
        {
            return softwareKind == CadSoftwareKind.Creo ? settings.CreoPath : settings.SolidWorksPath;
        }

        private static void SaveSoftwarePath(UserPathSettings settings, CadSoftwareKind softwareKind, string softwarePath)
        {
            if (softwareKind == CadSoftwareKind.Creo)
            {
                settings.CreoPath = softwarePath;
                return;
            }

            settings.SolidWorksPath = softwarePath;
        }

        private static string GetSoftwareDisplayName(CadSoftwareKind softwareKind)
        {
            return softwareKind == CadSoftwareKind.Creo ? "Creo" : "SolidWorks";
        }

        private void UpdateSoftwareSelectionUi()
        {
            CadSoftwareKind selectedSoftware = GetSelectedSoftwareKind();
            if (txtSoftwarePath != null)
            {
                txtSoftwarePath.ToolTip = selectedSoftware == CadSoftwareKind.Creo
                    ? "请选择 Creo 安装目录，例如：...\\PTC\\Creo 4.0；也可选择版本目录 ...\\M010 或 ...\\Parametric\\bin。"
                    : "请选择 SolidWorks 安装目录，或包含 sldworks.exe 的目录。";
            }

            if (chkOfflineMode != null)
            {
                bool isSolidWorks = selectedSoftware == CadSoftwareKind.SolidWorks;
                chkOfflineMode.IsEnabled = pathConfigPanel?.IsEnabled == true && isSolidWorks;
                chkOfflineMode.ToolTip = isSolidWorks
                    ? "启用后跳过 SolidWorks 启动，使用 Document Manager 离线读取。"
                    : "离线读取只适用于 SolidWorks。";

                if (!isSolidWorks)
                {
                    chkOfflineMode.IsChecked = false;
                }
            }
        }
        private void BrowseReport_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtReportPath);

        private void LoadSavedPaths()
        {
            _isLoadingSavedPaths = true;
            try
            {
                var settings = _pathSettingsService.Load();
                CadSoftwareKind selectedSoftware = ParseSoftwareKind(settings.SelectedSoftwareKind);
                SelectSoftwareKind(selectedSoftware);
                _activeSoftwareKind = selectedSoftware;
                txtSoftwarePath.Text = GetSoftwarePath(settings, selectedSoftware) ?? string.Empty;
                txtDrawingPath.Text = settings.DrawingFolderPath ?? string.Empty;
                txtReportPath.Text = settings.ReportFolderPath ?? string.Empty;
                chkOfflineMode.IsChecked = OfflineModeEntryEnabled && selectedSoftware == CadSoftwareKind.SolidWorks && settings.UseOfflineDocumentManager;
                UpdateSoftwareSelectionUi();
            }
            finally
            {
                _isLoadingSavedPaths = false;
            }
        }

        private void SaveCurrentPaths()
        {
            var settings = _pathSettingsService.Load();
            CadSoftwareKind selectedSoftware = GetSelectedSoftwareKind();
            settings.SelectedSoftwareKind = selectedSoftware.ToString();
            SaveSoftwarePath(settings, selectedSoftware, txtSoftwarePath.Text);
            settings.DrawingFolderPath = txtDrawingPath.Text;
            settings.ReportFolderPath = txtReportPath.Text;

            if (OfflineModeEntryEnabled)
            {
                settings.UseOfflineDocumentManager = selectedSoftware == CadSoftwareKind.SolidWorks && chkOfflineMode.IsChecked == true;
            }

            _pathSettingsService.Save(settings);
        }

        private void ChkOfflineMode_Checked(object sender, RoutedEventArgs e)
        {
            if (_isLoadingSavedPaths || _isChangingOfflineMode)
            {
                return;
            }

            if (!EnsureDocumentManagerLicenseKeyConfigured())
            {
                _isChangingOfflineMode = true;
                try
                {
                    chkOfflineMode.IsChecked = false;
                }
                finally
                {
                    _isChangingOfflineMode = false;
                }
                return;
            }

            SaveCurrentPaths();
            Log("离线读取模式已启用，Document Manager License Key 已记录。");
        }

        private void ChkOfflineMode_Unchecked(object sender, RoutedEventArgs e)
        {
            if (_isLoadingSavedPaths || _isChangingOfflineMode)
            {
                return;
            }

            SaveCurrentPaths();
            Log("离线读取模式已关闭。");
        }

        private bool EnsureDocumentManagerLicenseKeyConfigured()
        {
            var settings = _pathSettingsService.Load();
            if (!string.IsNullOrWhiteSpace(settings.DocumentManagerLicenseKey))
            {
                return true;
            }

            string licenseKey = PromptForDocumentManagerLicenseKey();
            if (string.IsNullOrWhiteSpace(licenseKey))
            {
                MessageBox.Show(
                    this,
                    "未输入 Document Manager License Key，已取消启用离线读取模式。",
                    "离线读取",
                    MessageBoxButton.OK,
                    MessageBoxImage.Information);
                return false;
            }

            settings.DocumentManagerLicenseKey = licenseKey.Trim();
            settings.UseOfflineDocumentManager = true;
            _pathSettingsService.Save(settings);
            return true;
        }

        private string PromptForDocumentManagerLicenseKey()
        {
            var input = new PasswordBox
            {
                Margin = new Thickness(0, 8, 0, 16),
                MinWidth = 420,
                Height = 32,
                VerticalContentAlignment = VerticalAlignment.Center
            };

            var dialog = new Window
            {
                Title = "启用离线读取",
                Owner = this,
                WindowStartupLocation = WindowStartupLocation.CenterOwner,
                SizeToContent = SizeToContent.WidthAndHeight,
                ResizeMode = ResizeMode.NoResize,
                ShowInTaskbar = false
            };

            var root = new StackPanel
            {
                Margin = new Thickness(18)
            };

            root.Children.Add(new TextBlock
            {
                Text = "请输入 SolidWorks Document Manager License Key：",
                Foreground = System.Windows.Media.Brushes.Black
            });
            root.Children.Add(input);

            var buttons = new StackPanel
            {
                Orientation = Orientation.Horizontal,
                HorizontalAlignment = HorizontalAlignment.Right
            };

            var okButton = new Button
            {
                Content = "确定",
                Width = 80,
                Height = 30,
                IsDefault = true,
                Margin = new Thickness(0, 0, 8, 0)
            };
            var cancelButton = new Button
            {
                Content = "取消",
                Width = 80,
                Height = 30,
                IsCancel = true
            };

            okButton.Click += (_, _) =>
            {
                dialog.DialogResult = true;
            };
            cancelButton.Click += (_, _) =>
            {
                dialog.DialogResult = false;
            };

            buttons.Children.Add(okButton);
            buttons.Children.Add(cancelButton);
            root.Children.Add(buttons);
            dialog.Content = root;
            dialog.Loaded += (_, _) => input.Focus();

            return dialog.ShowDialog() == true ? input.Password : null;
        }

        private void BtnClearLog_Click(object sender, RoutedEventArgs e)
        {
            txtLog.Clear();
            Log("日志已清空");
        }

        private void BtnOpenReportPath_Click(object sender, RoutedEventArgs e)
        {
            string reportPath = txtReportPath.Text?.Trim();
            if (string.IsNullOrWhiteSpace(reportPath))
            {
                MessageBox.Show("请先配置报表保存路径！");
                return;
            }

            try
            {
                if (!Directory.Exists(reportPath))
                {
                    MessageBox.Show("报表保存路径不存在，请检查路径配置！");
                    return;
                }

                SaveCurrentPaths();
                Process.Start(new ProcessStartInfo
                {
                    FileName = reportPath,
                    UseShellExecute = true
                });
            }
            catch (Exception ex)
            {
                MessageBox.Show($"无法打开报表路径：\n{ex.Message}");
            }
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
            FormatAndClamp(sender as System.Windows.Controls.TextBox);
        }

        private void Discount_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key != Key.Enter)
            {
                return;
            }

            FormatAndClamp(sender as System.Windows.Controls.TextBox);
            Keyboard.ClearFocus();
            e.Handled = true;
        }

        private void RootGrid_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            if (Keyboard.FocusedElement is not System.Windows.Controls.TextBox focusedTextBox ||
                !IsDiscountTextBox(focusedTextBox))
            {
                return;
            }

            if (e.OriginalSource is DependencyObject source && IsTextBoxInside(source))
            {
                return;
            }

            FormatAndClamp(focusedTextBox);
            Keyboard.ClearFocus();
        }

        private bool IsDiscountTextBox(System.Windows.Controls.TextBox textBox)
        {
            return textBox == tbPartDiscount ||
                   textBox == tbAssemblyDiscount ||
                   textBox == tbDrawingDiscount;
        }

        private static bool IsTextBoxInside(DependencyObject source)
        {
            while (source != null)
            {
                if (source is System.Windows.Controls.TextBox)
                {
                    return true;
                }

                try
                {
                    source = System.Windows.Media.VisualTreeHelper.GetParent(source);
                }
                catch (InvalidOperationException)
                {
                    return false;
                }
            }

            return false;
        }

        private void FormatAndClamp(System.Windows.Controls.TextBox tb)
        {
            if (tb == null)
            {
                return;
            }

            if (!double.TryParse(tb.Text, out double value))
            {
                tb.Text = "0.5";
                return;
            }

            value = Math.Round(value, 1);
            if (value < 0.4)
            {
                value = 0.4;
            }
            if (value > 1.0)
            {
                value = 1.0;
            }

            tb.Text = value.ToString("0.0");
        }

        private void ChangeDiscount(System.Windows.Controls.TextBox tb, double delta)
        {
            if (tb == null)
            {
                return;
            }

            if (!double.TryParse(tb.Text, out double value))
            {
                value = 0.5;
            }

            value = Math.Round(value + delta, 1);
            if (value < 0.4)
            {
                value = 0.4;
            }
            if (value > 1.0)
            {
                value = 1.0;
            }

            tb.Text = value.ToString("0.0");
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

            ObjectCoefficientSettings objectCoefficientSettings = ObjectCoefficientSettingsService.Load();

            return new QuotePricingSettings
            {
                SoftwareKind = GetSelectedSoftwareKind(),
                PartDiscount = double.TryParse(tbPartDiscount.Text, out double partDiscount) ? partDiscount : 1.0,
                AssemblyDiscount = double.TryParse(tbAssemblyDiscount.Text, out double assemblyDiscount) ? assemblyDiscount : 1.0,
                DrawingDiscount = double.TryParse(tbDrawingDiscount.Text, out double drawingDiscount) ? drawingDiscount : 1.0,
                UnitPrice = objectCoefficientSettings.UnitPrice,
                ComplexityPricing = objectCoefficientSettings.ComplexityPricing,
                ObjectCoefficients = objectCoefficientSettings
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
            btnCancel.IsEnabled = true;
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
                CadSoftwareKind selectedSoftware = GetSelectedSoftwareKind();
                bool useOfflineMode = selectedSoftware == CadSoftwareKind.SolidWorks && OfflineModeEntryEnabled && chkOfflineMode.IsChecked == true;
                string softwarePath = txtSoftwarePath.Text;
                string drawingPath = txtDrawingPath.Text;
                string reportPath = txtReportPath.Text;

                if (_developerSingleFileMode && !IsSupportedCadFileForSoftware(_developerSingleFilePath, selectedSoftware))
                {
                    LogError("开发者单文件路径与当前选择的软件不匹配！");
                    MessageBox.Show("开发者单文件路径与当前选择的软件不匹配，请重新选择软件或文件。");
                    return;
                }
                if (!_developerSingleFileMode && string.IsNullOrWhiteSpace(drawingPath))
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
                if (useOfflineMode && !EnsureDocumentManagerLicenseKeyConfigured())
                {
                    LogError("离线读取模式需要填写 Document Manager License Key！");
                    return;
                }

                if (selectedSoftware == CadSoftwareKind.Creo && !await EnsureCreoPluginReadyOrExitAsync(softwarePath))
                {
                    return;
                }

                if (selectedSoftware == CadSoftwareKind.SolidWorks && !useOfflineMode && !EnsureSolidWorksRegistrationOrExit(softwarePath))
                {
                    return;
                }

                SaveCurrentPaths();

                Log("---------- 报价任务分隔线 ----------");
                Log("开始处理...");
                Log($"选择软件: {GetSoftwareDisplayName(selectedSoftware)}");
                Log($"软件路径: {softwarePath}");
                if (_developerSingleFileMode)
                {
                    Log($"开发者单文件: {_developerSingleFilePath}");
                }
                else
                {
                    Log($"图纸路径: {drawingPath}");
                }
                Log($"报表路径: {reportPath}");

                QuotePricingSettings pricingSettings = BuildPricingSettings();
                Log($"已读取对象系数表: {ObjectCoefficientSettingsService.GetDefaultFilePath()}");

                ProcessingResult result = await RunStaTask(() => RunProcessing(selectedSoftware, useOfflineMode, softwarePath, drawingPath, reportPath, pricingSettings, _progressReporter));

                if (result.Cancelled)
                {
                    txtProgressText.Text = result.ReportSaved ? "已取消，报表已生成" : "已取消，报表保存失败";

                    if (result.ReportSaved)
                    {
                        LogSuccess($"已取消计算，已基于当前进度生成报表！共写入 {result.ProcessedCount} 个文件");
                        LogSuccess($"报表已保存到: {reportPath}");
                        MessageBox.Show("已取消计算，并已基于当前进度生成报表，请前往报表路径查看结果！");
                    }
                    else
                    {
                        LogError("已取消计算，但报表保存失败");
                        MessageBox.Show($"已取消计算。\n已处理 {result.ProcessedCount} 个文件。\n报表保存失败，请检查路径权限。");
                    }

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
                btnCancel.IsEnabled = false;
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

        private void BtnCancel_Click(object sender, RoutedEventArgs e)
        {
            if (!_isRunning || _cancelRequested)
            {
                return;
            }

            MessageBoxResult result = MessageBox.Show(
                this,
                "当前正在计算中，是否取消计算？\n\n已分析完成的数据会正常写入费用估算表。",
                "确认取消",
                MessageBoxButton.YesNo,
                MessageBoxImage.Warning);

            if (result != MessageBoxResult.Yes)
            {
                return;
            }

            _cancelRequested = true;
            btnCancel.IsEnabled = false;
            txtProgressText.Text = "正在取消...";
            Log("用户请求取消计算，当前文件处理结束后将生成已完成数据的报表。");
        }

        private async Task<bool> EnsureCreoPluginReadyOrExitAsync(string softwarePath)
        {
            CreoQuoteStartupResult result = await _creoQuoteStartupService.PrepareAsync(
                softwarePath,
                new CreoQuoteStartupInteraction
                {
                    Log = Log,
                    LogSuccess = LogSuccess,
                    SetStatus = status => txtProgressText.Text = status,
                    ConfirmPluginRegistration = ConfirmCreoPluginRegistration,
                    ConfirmCloseForPluginRegistration = ConfirmCloseCreoForPluginRegistration,
                    ConfirmRestartForNotReady = ConfirmRestartCreoForNotReady
                });

            if (result.Succeeded)
            {
                txtProgressText.Text = "Creo 插件已就绪，开始报价...";
                BringQuoteWindowToFront();
                LogSuccess("Creo 插件已 Ready，可以开始报价。 ");
                return true;
            }

            if (!result.IsCancelled && !string.IsNullOrWhiteSpace(result.Message))
            {
                LogError(result.Message);
                MessageBox.Show(
                    this,
                    result.Message,
                    string.IsNullOrWhiteSpace(result.Title) ? "Creo 准备失败" : result.Title,
                    MessageBoxButton.OK,
                    MessageBoxImage.Warning);
            }

            return false;
        }

        private bool ConfirmCreoPluginRegistration(CreoPluginEnvironment environment)
        {
            var dialog = new Window
            {
                Owner = this,
                Title = "配置 Creo 插件",
                Width = 660,
                SizeToContent = SizeToContent.Height,
                ResizeMode = ResizeMode.NoResize,
                WindowStartupLocation = WindowStartupLocation.CenterOwner
            };

            var root = new StackPanel
            {
                Margin = new Thickness(18, 14, 18, 14)
            };

            root.Children.Add(new TextBlock
            {
                Text = "首次使用 Creo 报价前，需要以管理员权限配置 Creo 插件。",
                TextWrapping = TextWrapping.Wrap,
                Margin = new Thickness(0, 0, 0, 12),
                FontWeight = FontWeights.SemiBold
            });

            root.Children.Add(CreateCreoPluginPathRow("Creo 注册文件", environment.RegistryFilePath));
            root.Children.Add(CreateCreoPluginPathRow("插件 DLL", environment.PluginDllPath));

            root.Children.Add(new TextBlock
            {
                Text = "如果取消管理员权限，本次 Creo 报价无法继续。是否继续？",
                TextWrapping = TextWrapping.Wrap,
                Margin = new Thickness(0, 6, 0, 14)
            });

            var buttons = new StackPanel
            {
                Orientation = Orientation.Horizontal,
                HorizontalAlignment = HorizontalAlignment.Right
            };

            var yesButton = new Button
            {
                Content = "是(Y)",
                Width = 82,
                Height = 28,
                Margin = new Thickness(0, 0, 10, 0),
                IsDefault = true
            };
            yesButton.Click += (_, _) => dialog.DialogResult = true;

            var noButton = new Button
            {
                Content = "否(N)",
                Width = 82,
                Height = 28,
                IsCancel = true
            };
            noButton.Click += (_, _) => dialog.DialogResult = false;

            buttons.Children.Add(yesButton);
            buttons.Children.Add(noButton);
            root.Children.Add(buttons);

            dialog.Content = root;
            return dialog.ShowDialog() == true;
        }

        private static Grid CreateCreoPluginPathRow(string label, string value)
        {
            var row = new Grid
            {
                Margin = new Thickness(0, 0, 0, 8)
            };
            row.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(104) });
            row.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });

            var labelBlock = new TextBlock
            {
                Text = label,
                VerticalAlignment = VerticalAlignment.Top,
                FontWeight = FontWeights.SemiBold,
                Margin = new Thickness(0, 5, 8, 0)
            };
            Grid.SetColumn(labelBlock, 0);

            var pathBox = new TextBox
            {
                Text = value ?? string.Empty,
                IsReadOnly = true,
                MinHeight = 30,
                MaxHeight = 46,
                MinLines = 1,
                MaxLines = 2,
                Padding = new Thickness(6, 3, 6, 3),
                TextWrapping = TextWrapping.Wrap,
                HorizontalScrollBarVisibility = ScrollBarVisibility.Disabled,
                VerticalScrollBarVisibility = ScrollBarVisibility.Auto,
                ToolTip = value ?? string.Empty
            };
            Grid.SetColumn(pathBox, 1);

            row.Children.Add(labelBlock);
            row.Children.Add(pathBox);
            return row;
        }

        private bool ConfirmCloseCreoForPluginRegistration(IReadOnlyList<CreoProcessInfo> runningProcesses)
        {
            string runningList = FormatCreoProcessList(runningProcesses);
            return MessageBox.Show(
                this,
                "检测到 Creo 正在运行。配置插件前需要先关闭 Creo。\n\n" + runningList + "\n\n是否关闭 Creo 并继续？",
                "关闭 Creo",
                MessageBoxButton.YesNo,
                MessageBoxImage.Warning) == MessageBoxResult.Yes;
        }

        private bool ConfirmRestartCreoForNotReady(IReadOnlyList<CreoProcessInfo> runningProcesses, string pluginStatus)
        {
            string runningList = FormatCreoProcessList(runningProcesses);
            string statusText = string.IsNullOrWhiteSpace(pluginStatus) ? string.Empty : "\n\n当前状态：" + pluginStatus;
            return MessageBox.Show(
                this,
                "检测到 Creo 正在运行，但报价插件没有返回 Ready。" + statusText + "\n\n" +
                "为确保加载最新的 IPXQuoteCreoPlugin，需要先关闭 Creo，再由报价软件重新启动。\n\n" +
                runningList + "\n\n是否关闭 Creo 并继续？",
                "重启 Creo",
                MessageBoxButton.YesNo,
                MessageBoxImage.Warning) == MessageBoxResult.Yes;
        }

        private static string FormatCreoProcessList(IReadOnlyList<CreoProcessInfo> processes)
        {
            return string.Join("\n", (processes ?? Array.Empty<CreoProcessInfo>()).Select(process => "- " + process.DisplayName));
        }

        private void BringQuoteWindowToFront()
        {
            try
            {
                if (WindowState == WindowState.Minimized)
                {
                    WindowState = WindowState.Normal;
                }

                Activate();
                Topmost = true;
                Topmost = false;
                Focus();
            }
            catch
            {
            }
        }

        private bool EnsureSolidWorksRegistrationOrExit(string softwarePath)
        {
            if (!SolidWorksService.TryGetRegistrationMismatch(softwarePath, out SolidWorksRegistrationMismatch mismatch, out string error))
            {
                if (!string.IsNullOrWhiteSpace(error))
                {
                    LogError(error);
                    MessageBox.Show(error, "SolidWorks 注册检查失败", MessageBoxButton.OK, MessageBoxImage.Warning);
                    return false;
                }

                return true;
            }

            string message =
                "您选定的 SolidWorks 路径并非系统默认 SldWorks.Application 指向的路径，请确认。\n\n" +
                $"选定路径：{mismatch.SelectedExePath}\n" +
                $"系统默认：{(string.IsNullOrWhiteSpace(mismatch.DefaultExePath) ? "未注册或无法解析" : mismatch.DefaultExePath)}\n\n" +
                "是否更改系统默认路径？\n\n" +
                "该操作需要管理员权限，会修改注册表：\n" +
                $"从 HKEY_CLASSES_ROOT\\{mismatch.SelectedProgId}\\CLSID 读取数值数据，\n" +
                "并写入 HKEY_CLASSES_ROOT\\SldWorks.Application\\CLSID。\n" +
                $"目标 CLSID：{mismatch.SelectedClsid}\n\n" +
                "是否授权修改？修改后，打开文件的默认版本将会更改为所选定路径的版本";

            MessageBoxResult result = MessageBox.Show(
                this,
                message,
                "SolidWorks 默认版本不一致",
                MessageBoxButton.YesNo,
                MessageBoxImage.Warning);

            if (result != MessageBoxResult.Yes)
            {
                Log("用户未授权修改 SolidWorks 默认注册路径，程序退出。");
                _allowClose = true;
                Close();
                return false;
            }

            Log("用户授权修改 SolidWorks 默认注册路径，正在请求管理员权限...");
            if (!SolidWorksService.SetDefaultSolidWorksClsidWithElevation(mismatch.SelectedClsid, out string updateError))
            {
                LogError(updateError);
                MessageBox.Show(updateError, "注册表修改失败", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }

            if (SolidWorksService.TryGetRegistrationMismatch(softwarePath, out SolidWorksRegistrationMismatch stillMismatch, out string verifyError))
            {
                string verifyMessage =
                    "注册表修改后，系统默认 SolidWorks 路径仍与所选路径不一致，请检查注册表权限或 SolidWorks 注册状态。\n\n" +
                    $"选定路径：{stillMismatch.SelectedExePath}\n" +
                    $"系统默认：{(string.IsNullOrWhiteSpace(stillMismatch.DefaultExePath) ? "未注册或无法解析" : stillMismatch.DefaultExePath)}";
                LogError(verifyMessage);
                MessageBox.Show(verifyMessage, "注册表修改未生效", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }

            if (!string.IsNullOrWhiteSpace(verifyError))
            {
                LogError(verifyError);
                MessageBox.Show(verifyError, "注册表修改验证失败", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }

            LogSuccess("SolidWorks 默认注册路径已更新，将继续分析报价。");
            return true;
        }

        private ProcessingResult RunProcessing(CadSoftwareKind selectedSoftware, bool useOfflineMode, string softwarePath, string drawingPath, string reportPath, QuotePricingSettings pricingSettings, IProgress<DocumentProgressUpdate> progress)
        {
            progress.Report(new DocumentProgressUpdate("扫描文件...", 0, 1, 0, 0, 0));

            if (!_developerSingleFileMode && !Directory.Exists(drawingPath))
            {
                LogError("指定的图纸路径无效！");
                throw new InvalidOperationException("指定的图纸路径无效！");
            }

            List<string> files = GetFilesForProcessing(drawingPath, selectedSoftware);
            if (files.Count == 0)
            {
                string softwareName = GetSoftwareDisplayName(selectedSoftware);
                LogError($"未找到当前软件支持的 CAD 文件：{softwareName}。");
                throw new InvalidOperationException($"未找到当前软件支持的 CAD 文件：{softwareName}。");
            }

            Log($"找到 {files.Count} 个 {GetSoftwareDisplayName(selectedSoftware)} 文件");

            bool isSolidWorksSelection = selectedSoftware == CadSoftwareKind.SolidWorks;
            if (isSolidWorksSelection && !useOfflineMode)
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
            else if (isSolidWorksSelection)
            {
                Log("离线读取模式：跳过 SolidWorks 启动和连接。");
            }
            else
            {
                Log("Creo 模式：优先通过 Creo 插件 IPC 读取文件，手动 JSON 作为兜底。");
            }

            progress.Report(new DocumentProgressUpdate($"处理文档... (0/{files.Count})", 0, files.Count, 0, 0, 0));

            var results = new List<DocumentInfo>();
            int partCount = 0;
            int assemblyCount = 0;
            int drawingCount = 0;
            bool cancelled = false;
            OfflineDocumentManagerService offlineService = null;
            CreoCommunicationFailureGuard creoCommunicationFailureGuard = selectedSoftware == CadSoftwareKind.Creo
                ? new CreoCommunicationFailureGuard(3)
                : null;

            if (useOfflineMode && isSolidWorksSelection)
            {
                string documentManagerLicenseKey = _pathSettingsService.Load().DocumentManagerLicenseKey;
                Log(string.IsNullOrWhiteSpace(documentManagerLicenseKey)
                    ? "Document Manager License Key 未读取到。"
                    : "Document Manager License Key 已读取。");
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
                    cancelled = true;
                    Log("检测到取消请求，停止处理后续文件。");
                    break;
                }

                string file = files[i];
                bool currentProcessingFailed = false;
                string currentFailureReason = null;
                Log($"处理开始: {Path.GetFileName(file)}，开始时间: {FormatProcessingTime(DateTime.Now)}");
                DocumentInfo info = ProcessCadDocument(file, selectedSoftware, useOfflineMode, offlineService, softwarePath);

                if (info != null)
                {
                    results.Add(info);

                    switch (info.DocumentType)
                    {
                        case CadDocumentType.Part:
                            partCount++;
                            break;
                        case CadDocumentType.Assembly:
                            assemblyCount++;
                            break;
                        case CadDocumentType.Drawing:
                            drawingCount++;
                            break;
                    }

                    if (info.IsProcessingFailed)
                    {
                        currentProcessingFailed = true;
                        currentFailureReason = info.ProcessingError;
                        LogError($"处理失败: {info.FileName}，结束时间: {FormatProcessingTime(DateTime.Now)}");
                        LogError(info.ProcessingError);
                        Log($"已在报表中保留失败图纸占位行: {info.FileName}");
                    }
                    else
                    {
                        string previewStatus = info.PreviewImageBytes?.Length > 0
                            ? $"缩略图已获取，{info.PreviewImageBytes.Length / 1024.0:0.0} KB"
                            : "未获取到缩略图";
                        Log($"处理完成: {info.FileName} ({info.Category})，结束时间: {FormatProcessingTime(DateTime.Now)}，{previewStatus}");
                    }

                    if (useOfflineMode && IsSolidWorksFile(file) && info.DocumentType == CadDocumentType.Part)
                    {
                        Log("提示：离线读取模式无法读取零件 FeatureManager 特征树，零件特征数会显示为 0；如需统计特征数，请使用 SolidWorks 正常读取模式。");
                    }
                }
                else
                {
                    LogError($"处理失败: {Path.GetFileName(file)}，结束时间: {FormatProcessingTime(DateTime.Now)}");
                    string failureReason = null;
                    if (useOfflineMode && IsSolidWorksFile(file) && offlineService != null && !string.IsNullOrWhiteSpace(offlineService.LastError))
                    {
                        failureReason = offlineService.LastError;
                        LogError(failureReason);
                    }
                    else if (!useOfflineMode || !IsSolidWorksFile(file))
                    {
                        failureReason = GetCadServiceLastError(file);
                        if (!string.IsNullOrWhiteSpace(failureReason))
                        {
                            LogError(failureReason);
                        }
                    }

                    currentProcessingFailed = true;
                    currentFailureReason = failureReason;
                    DocumentInfo failedInfo = CreateFailedDocumentPlaceholder(file, failureReason);
                    results.Add(failedInfo);
                    Log($"已在报表中保留失败图纸占位行: {failedInfo.FileName}");
                }

                if (creoCommunicationFailureGuard?.ShouldStopAfterResult(currentProcessingFailed, currentFailureReason, out string creoStopReason) == true)
                {
                    LogError(creoStopReason);
                    break;
                }

                int processedCount = i + 1;
                progress.Report(new DocumentProgressUpdate($"处理中 ({processedCount}/{files.Count})", processedCount, files.Count, partCount, assemblyCount, drawingCount));
            }

            if (_cancelRequested)
            {
                cancelled = true;
            }

            string reportProgressText = cancelled ? "生成已完成数据报表..." : "生成报表...";
            progress.Report(new DocumentProgressUpdate(reportProgressText, results.Count, files.Count, partCount, assemblyCount, drawingCount));
            byte[] reportContent = _quoteReportService.GenerateReport(results, pricingSettings);
            bool saveSuccess = _quoteReportService.SaveReport(reportPath, reportContent);
            return new ProcessingResult(results.Count, saveSuccess, cancelled);
        }

        private string GetCadServiceLastError(string filePath)
        {
            ICadDocumentService service = _cadDocumentServiceRouter.Resolve(filePath);
            if (service is SolidWorksService solidWorksService && !string.IsNullOrWhiteSpace(solidWorksService.LastError))
            {
                return solidWorksService.LastError;
            }

            if (service is CreoService creoService && !string.IsNullOrWhiteSpace(creoService.LastError))
            {
                return creoService.LastError;
            }

            return null;
        }
        private DocumentInfo ProcessCadDocument(string file, CadSoftwareKind selectedSoftware, bool useOfflineMode, OfflineDocumentManagerService offlineService, string softwarePath)
        {
            if (useOfflineMode && IsSolidWorksFile(file) && offlineService != null)
            {
                return _cadDocumentProcessor.ProcessDocument(file, offlineService);
            }

            ICadDocumentService service = _cadDocumentServiceRouter.Resolve(selectedSoftware);
            if (service?.SoftwareKind == CadSoftwareKind.SolidWorks)
            {
                return _solidWorksDocumentProcessor.ProcessWithTimeout(file, softwarePath, DocumentProcessingTimeout);
            }

            return _cadDocumentProcessor.ProcessDocument(file, service);
        }

        private bool SelectionRequiresSolidWorks(string drawingPath)
        {
            if (_developerSingleFileMode)
            {
                return IsSolidWorksFile(_developerSingleFilePath);
            }

            if (string.IsNullOrWhiteSpace(drawingPath) || !Directory.Exists(drawingPath))
            {
                return false;
            }

            return Directory.GetFiles(drawingPath, "*.*", SearchOption.AllDirectories).Any(IsSolidWorksFile);
        }

        private static bool IsSolidWorksFile(string filePath)
        {
            if (string.IsNullOrWhiteSpace(filePath))
            {
                return false;
            }

            return Path.GetExtension(filePath).ToLowerInvariant() switch
            {
                ".sldprt" => true,
                ".sldasm" => true,
                ".slddrw" => true,
                _ => false
            };
        }
        private List<string> GetFilesForProcessing(string drawingPath, CadSoftwareKind selectedSoftware)
        {
            if (_developerSingleFileMode)
            {
                return IsSupportedCadFileForSoftware(_developerSingleFilePath, selectedSoftware)
                    ? new List<string> { _developerSingleFilePath }
                    : new List<string>();
            }

            return _cadDocumentServiceRouter.GetSupportedFiles(drawingPath, selectedSoftware);
        }

        private static DocumentInfo CreateFailedDocumentPlaceholder(string filePath, string failureReason)
        {
            return new DocumentInfo
            {
                FileName = Path.GetFileName(filePath),
                FilePath = filePath,
                DocumentType = GetDocumentTypeFromPath(filePath),
                PreviewImageBytes = ShellThumbnailService.TryGetThumbnailImageBytes(filePath),
                IsProcessingFailed = true,
                ProcessingError = failureReason ?? "处理失败，已跳过。"
            };
        }

        private static string FormatProcessingTime(DateTime time)
        {
            return time.ToString("yyyy-MM-dd HH:mm:ss");
        }

        private static CadDocumentType GetDocumentTypeFromPath(string filePath)
        {
            return CadFileTypeDetector.GetDocumentTypeFromPath(filePath);
        }

        private bool IsSupportedCadFile(string filePath)
        {
            return !string.IsNullOrWhiteSpace(filePath) &&
                File.Exists(filePath) &&
                _cadDocumentServiceRouter.CanProcess(filePath);
        }

        private bool IsSupportedCadFileForSoftware(string filePath, CadSoftwareKind selectedSoftware)
        {
            ICadDocumentService service = _cadDocumentServiceRouter.Resolve(selectedSoftware);
            return !string.IsNullOrWhiteSpace(filePath) &&
                File.Exists(filePath) &&
                service?.CanProcess(filePath) == true;
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































