using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using WinForms = System.Windows.Forms;

namespace IPXQuoteTool
{
    public partial class MainWindow : Window
    {
        private SolidWorksService _swService;

        public MainWindow()
        {
            InitializeComponent();
            _swService = new SolidWorksService();
            Log("IPX报价工具已启动");
            Log("等待用户配置...");
        }

        private void Log(string message)
        {
            Dispatcher.Invoke(() =>
            {
                txtLog.AppendText($"[{DateTime.Now:HH:mm:ss}] {message}\n");
                txtLog.ScrollToEnd();
            });
        }

        private void LogError(string message)
        {
            Dispatcher.Invoke(() =>
            {
                txtLog.AppendText($"[{DateTime.Now:HH:mm:ss}] ❌ {message}\n");
                txtLog.ScrollToEnd();
            });
        }

        private void LogSuccess(string message)
        {
            Dispatcher.Invoke(() =>
            {
                txtLog.AppendText($"[{DateTime.Now:HH:mm:ss}] ✅ {message}\n");
                txtLog.ScrollToEnd();
            });
        }

        private void BrowseFolder(System.Windows.Controls.TextBox target)
        {
            using (var dlg = new WinForms.FolderBrowserDialog())
            {
                try
                {
                    if (!string.IsNullOrWhiteSpace(target.Text)) dlg.SelectedPath = target.Text;
                }
                catch { }

                var res = dlg.ShowDialog();
                if (res == WinForms.DialogResult.OK)
                {
                    target.Text = dlg.SelectedPath;
                }
            }
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
                }
            }
        }

        private void BrowseSoftware_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtSoftwarePath);
        private void BrowseDrawing_Click(object sender, RoutedEventArgs e) => BrowseFile(txtDrawingPath);
        private void BrowseReport_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtReportPath);

        private void BtnOpenFile_Click(object sender, RoutedEventArgs e)
        {
            BrowseFile(txtDrawingPath);
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
            if (v < 0.1) v = 0.1;
            if (v > 0.9) v = 0.9;
            tb.Text = v.ToString("0.0");
        }

        private void ChangeDiscount(System.Windows.Controls.TextBox tb, double delta)
        {
            if (tb == null) return;
            if (!double.TryParse(tb.Text, out double v)) v = 0.5;
            v = Math.Round(v + delta, 1);
            if (v < 0.1) v = 0.1;
            if (v > 0.9) v = 0.9;
            tb.Text = v.ToString("0.0");
        }

        private void PartUp_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbPartDiscount, 0.1);
        private void PartDown_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbPartDiscount, -0.1);
        private void AssemblyUp_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbAssemblyDiscount, 0.1);
        private void AssemblyDown_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbAssemblyDiscount, -0.1);
        private void DrawingUp_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbDrawingDiscount, 0.1);
        private void DrawingDown_Click(object sender, RoutedEventArgs e) => ChangeDiscount(tbDrawingDiscount, -0.1);

        private async void BtnRun_Click(object sender, RoutedEventArgs e)
        {
            btnRun.IsEnabled = false;
            txtProgressText.Text = "准备中...";
            txtPartCount.Text = "0";
            txtAssemblyCount.Text = "0";
            txtDrawingCount.Text = "0";

            try
            {
                if (string.IsNullOrWhiteSpace(txtSoftwarePath.Text))
                {
                    LogError("请选择 SolidWorks 安装路径！");
                    MessageBox.Show("请选择 SolidWorks 安装路径！");
                    return;
                }
                if (string.IsNullOrWhiteSpace(txtDrawingPath.Text))
                {
                    LogError("请选择图纸路径！");
                    MessageBox.Show("请选择图纸路径！");
                    return;
                }
                if (string.IsNullOrWhiteSpace(txtReportPath.Text))
                {
                    LogError("请选择报表保存路径！");
                    MessageBox.Show("请选择报表保存路径！");
                    return;
                }

                Log("=");
                Log("开始处理...");
                Log($"SolidWorks路径: {txtSoftwarePath.Text}");
                Log($"图纸路径: {txtDrawingPath.Text}");
                Log($"报表路径: {txtReportPath.Text}");

                txtProgressText.Text = "连接 SolidWorks...";

                if (!_swService.ConnectOrStart(txtSoftwarePath.Text))
                {
                    LogError("无法连接到 SolidWorks，请确保 SolidWorks 已安装并正常运行！");
                    MessageBox.Show("无法连接到 SolidWorks，请确保 SolidWorks 已安装并正常运行！");
                    return;
                }

                LogSuccess("成功连接到 SolidWorks");

                txtProgressText.Text = "扫描文件...";

                string drawingPath = txtDrawingPath.Text;
                List<string> files;

                if (File.Exists(drawingPath))
                {
                    files = new List<string> { drawingPath };
                }
                else if (Directory.Exists(drawingPath))
                {
                    files = _swService.GetSolidWorksFiles(drawingPath);
                }
                else
                {
                    LogError("指定的图纸路径无效！");
                    MessageBox.Show("指定的图纸路径无效！");
                    return;
                }

                if (files.Count == 0)
                {
                    LogError("未找到 SolidWorks 文件（.sldprt/.sldasm/.slddrw）！");
                    MessageBox.Show("未找到 SolidWorks 文件（.sldprt/.sldasm/.slddrw）！");
                    return;
                }

                Log($"找到 {files.Count} 个 SolidWorks 文件");

                txtProgressText.Text = "处理文档...";

                var results = new List<DocumentInfo>();
                int partCount = 0;
                int assemblyCount = 0;
                int drawingCount = 0;

                for (int i = 0; i < files.Count; i++)
                {
                    var file = files[i];
                    var info = _swService.ProcessDocument(file);
                    
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
                    }

                    Dispatcher.Invoke(() =>
                    {
                        txtProgressText.Text = $"处理中 ({i + 1}/{files.Count})";
                        txtPartCount.Text = partCount.ToString();
                        txtAssemblyCount.Text = assemblyCount.ToString();
                        txtDrawingCount.Text = drawingCount.ToString();
                    });

                    await Task.Delay(10);
                }

                txtProgressText.Text = "生成报表...";

                var reportContent = _swService.GenerateReport(results);
                bool saveSuccess = _swService.SaveReport(txtReportPath.Text, reportContent);

                txtProgressText.Text = "完成";

                if (saveSuccess)
                {
                    LogSuccess($"处理完成！共处理 {results.Count} 个文件");
                    LogSuccess($"报表已保存到: {txtReportPath.Text}");
                    MessageBox.Show($"处理完成！\n\n零件: {partCount}\n装配: {assemblyCount}\n工程图: {drawingCount}\n\n报表已保存到: {txtReportPath.Text}");
                }
                else
                {
                    LogError("报表保存失败");
                    MessageBox.Show($"处理完成！\n共处理 {results.Count} 个文件\n报表保存失败，请检查路径权限。");
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
                btnRun.IsEnabled = true;
            }
        }
    }
}