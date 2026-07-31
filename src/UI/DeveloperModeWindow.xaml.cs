using System;
using System.ComponentModel;
using System.IO;
using System.Windows;
using WinForms = System.Windows.Forms;

namespace IPXQuoteTool
{
    public partial class DeveloperModeWindow : Window
    {
        public DeveloperModeWindow(string currentSingleFilePath)
        {
            InitializeComponent();
            txtSingleFilePath.Text = currentSingleFilePath ?? string.Empty;
        }

        public bool EnableSingleFileMode { get; private set; }
        public bool ResetDeveloperMode { get; private set; }
        public string SingleFilePath { get; private set; }

        protected override void OnClosing(CancelEventArgs e)
        {
            if (!EnableSingleFileMode)
            {
                ResetDeveloperMode = true;
            }

            base.OnClosing(e);
        }

        private void ShowSingleFilePanel_Click(object sender, RoutedEventArgs e)
        {
            singleFilePanel.Visibility = Visibility.Visible;
            btnEnableSingleFile.Visibility = Visibility.Visible;
            txtSingleFilePath.Focus();
        }

        private void CloseSingleFilePanel_Click(object sender, RoutedEventArgs e)
        {
            singleFilePanel.Visibility = Visibility.Collapsed;
            btnEnableSingleFile.Visibility = Visibility.Collapsed;
        }

        private void Browse_Click(object sender, RoutedEventArgs e)
        {
            using var dialog = new WinForms.OpenFileDialog
            {
                Filter = "SolidWorks文件 (*.sldprt;*.sldasm;*.slddrw)|*.sldprt;*.sldasm;*.slddrw|所有文件 (*.*)|*.*",
                Multiselect = false
            };

            string currentPath = txtSingleFilePath.Text?.Trim();
            if (!string.IsNullOrWhiteSpace(currentPath))
            {
                if (File.Exists(currentPath))
                {
                    dialog.FileName = currentPath;
                }
                else if (Directory.Exists(currentPath))
                {
                    dialog.InitialDirectory = currentPath;
                }
            }

            if (dialog.ShowDialog() == WinForms.DialogResult.OK)
            {
                txtSingleFilePath.Text = dialog.FileName;
            }
        }

        private void Enable_Click(object sender, RoutedEventArgs e)
        {
            string filePath = txtSingleFilePath.Text?.Trim();
            if (!IsSupportedSolidWorksFile(filePath))
            {
                MessageBox.Show(this, "请选择有效的 SolidWorks 文件（.sldprt/.sldasm/.slddrw）。", "单文件路径无效", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            SingleFilePath = filePath;
            EnableSingleFileMode = true;
            DialogResult = true;
            Close();
        }

        private void CloseAndReset_Click(object sender, RoutedEventArgs e)
        {
            ResetDeveloperMode = true;
            DialogResult = false;
            Close();
        }

        private static bool IsSupportedSolidWorksFile(string filePath)
        {
            if (string.IsNullOrWhiteSpace(filePath) || !File.Exists(filePath))
            {
                return false;
            }

            if (SolidWorksService.IsTemporarySolidWorksFile(filePath))
            {
                return false;
            }

            string extension = Path.GetExtension(filePath);
            return extension.Equals(".sldprt", StringComparison.OrdinalIgnoreCase) ||
                   extension.Equals(".sldasm", StringComparison.OrdinalIgnoreCase) ||
                   extension.Equals(".slddrw", StringComparison.OrdinalIgnoreCase);
        }
    }
}
