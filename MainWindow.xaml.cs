<<<<<<< ours
using System.Text;
=======
﻿using System;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
>>>>>>> theirs
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Threading;
using WinForms = System.Windows.Forms;

namespace IPXQuoteTool
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
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

        private void BrowseSoftware_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtSoftwarePath);
        private void BrowseDrawing_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtDrawingPath);
        private void BrowseReport_Click(object sender, RoutedEventArgs e) => BrowseFolder(txtReportPath);

        // Allow only digits and one decimal point, and at most one digit after decimal
        private void Discount_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            var tb = sender as System.Windows.Controls.TextBox;
            string newText = tb.Text;
            if (tb.SelectionLength > 0)
            {
                newText = newText.Remove(tb.SelectionStart, tb.SelectionLength);
            }
            newText = newText.Insert(tb.SelectionStart, e.Text);

            // Valid pattern: optional digit, optional . and optional one digit
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
            progressBar.IsIndeterminate = true;
            try
            {
                // Simulate work - replace with real business logic
                await Task.Delay(1500);
            }
            finally
            {
                progressBar.IsIndeterminate = false;
                progressBar.Value = 100;
                btnRun.IsEnabled = true;
            }
        }
    }
}
