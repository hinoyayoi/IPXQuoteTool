using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Security;
using System.Text;
using System.Text.RegularExpressions;
using System.Xml.Linq;

namespace IPXQuoteTool.Pricing
{
    public static class ObjectCoefficientSettingsService
    {
        public const string FileName = "对象系数.xlsx";

        public static readonly IReadOnlyList<ObjectCoefficientRow> DefaultRows = new List<ObjectCoefficientRow>
        {
            new ObjectCoefficientRow("零件", "特征", 1.00, ""),
            new ObjectCoefficientRow("零件", "配置项", 0.50, ""),
            new ObjectCoefficientRow("零件", "表达式", 0.10, ""),
            new ObjectCoefficientRow("装配", "组件数", 0.60, "装配只统计一级子组件；如果子组件为虚拟组件时，需对应拟组件按照零件的逻辑进行统计后，归入装配特征进行计算"),
            new ObjectCoefficientRow("装配", "装配约束", 0.80, ""),
            new ObjectCoefficientRow("装配", "装配特征", 1.00, ""),
            new ObjectCoefficientRow("装配", "配置项", 0.50, ""),
            new ObjectCoefficientRow("装配", "表达式", 0.10, ""),
            new ObjectCoefficientRow("工程图", "视图", 0.80, ""),
            new ObjectCoefficientRow("工程图", "标注", 0.50, ""),
            new ObjectCoefficientRow("工程图", "表格", 0.50, "")
        };

        public static string GetDefaultFilePath()
        {
            return Path.Combine(AppDomain.CurrentDomain.BaseDirectory, FileName);
        }

        public static string EnsureDefaultFile()
        {
            string filePath = GetDefaultFilePath();
            if (!File.Exists(filePath))
            {
                WriteDefaultFile(filePath);
            }
            else if (!FileContainsPricingSections(filePath))
            {
                ObjectCoefficientSettings existingSettings = LoadFromFile(filePath);
                WriteDefaultFile(filePath, existingSettings);
            }

            return filePath;
        }

        public static ObjectCoefficientSettings Load()
        {
            string filePath = EnsureDefaultFile();
            return LoadFromFile(filePath);
        }

        private static ObjectCoefficientSettings LoadFromFile(string filePath)
        {
            var settings = ObjectCoefficientSettings.CreateDefault();

            try
            {
                foreach (var row in ReadRows(filePath))
                {
                    if (TryParseCoefficient(row.CoefficientText, out double coefficient))
                    {
                        settings.SetValue(row.Category, row.ObjectName, coefficient);
                    }
                }

                LoadPricingSections(filePath, settings);
            }
            catch
            {
            }

            return settings;
        }

        private static IEnumerable<WorkbookRow> ReadRows(string filePath)
        {
            using ZipArchive archive = ZipFile.OpenRead(filePath);
            List<string> sharedStrings = ReadSharedStrings(archive);
            ZipArchiveEntry sheetEntry = archive.GetEntry("xl/worksheets/sheet1.xml");
            if (sheetEntry == null)
            {
                yield break;
            }

            XNamespace ns = "http://schemas.openxmlformats.org/spreadsheetml/2006/main";
            using Stream sheetStream = sheetEntry.Open();
            XDocument sheetDocument = XDocument.Load(sheetStream);

            foreach (XElement row in sheetDocument.Descendants(ns + "row"))
            {
                var cells = row.Elements(ns + "c")
                    .Select(cell => new
                    {
                        Column = GetColumnIndex((string)cell.Attribute("r")),
                        Value = GetCellValue(cell, sharedStrings, ns)
                    })
                    .ToDictionary(cell => cell.Column, cell => cell.Value);

                string category = GetCell(cells, 1);
                if (string.IsNullOrWhiteSpace(category) || category == "类别")
                {
                    continue;
                }

                string objectName = GetCell(cells, 2);
                string coefficientText = GetCell(cells, 3);
                if (!string.IsNullOrWhiteSpace(objectName) && !string.IsNullOrWhiteSpace(coefficientText))
                {
                    yield return new WorkbookRow(category, objectName, coefficientText);
                }
            }
        }

        private static List<string> ReadSharedStrings(ZipArchive archive)
        {
            var values = new List<string>();
            ZipArchiveEntry entry = archive.GetEntry("xl/sharedStrings.xml");
            if (entry == null)
            {
                return values;
            }

            XNamespace ns = "http://schemas.openxmlformats.org/spreadsheetml/2006/main";
            using Stream stream = entry.Open();
            XDocument document = XDocument.Load(stream);
            foreach (XElement item in document.Descendants(ns + "si"))
            {
                values.Add(string.Concat(item.Descendants(ns + "t").Select(t => t.Value)));
            }

            return values;
        }

        private static string GetCellValue(XElement cell, List<string> sharedStrings, XNamespace ns)
        {
            string cellType = (string)cell.Attribute("t");
            if (cellType == "inlineStr")
            {
                return cell.Descendants(ns + "t").FirstOrDefault()?.Value ?? string.Empty;
            }

            string value = cell.Element(ns + "v")?.Value ?? string.Empty;
            if (cellType == "s" && int.TryParse(value, out int sharedStringIndex) && sharedStringIndex >= 0 && sharedStringIndex < sharedStrings.Count)
            {
                return sharedStrings[sharedStringIndex];
            }

            return value;
        }

        private static int GetColumnIndex(string cellReference)
        {
            if (string.IsNullOrWhiteSpace(cellReference))
            {
                return 0;
            }

            Match match = Regex.Match(cellReference, "^[A-Z]+", RegexOptions.IgnoreCase);
            int index = 0;
            foreach (char c in match.Value.ToUpperInvariant())
            {
                index = index * 26 + c - 'A' + 1;
            }

            return index;
        }

        private static string GetCell(Dictionary<int, string> cells, int column)
        {
            return cells.TryGetValue(column, out string value) ? value.Trim() : string.Empty;
        }

        private static bool FileContainsPricingSections(string filePath)
        {
            try
            {
                Dictionary<string, string> cells = ReadCellMap(filePath);
                return cells.Values.Any(value => ContainsCellText(value, "单价")) &&
                       cells.Values.Any(value => ContainsCellText(value, "等效特征数范围")) &&
                       cells.Values.Any(value => ContainsCellText(value, "最大特征数"));
            }
            catch
            {
                return false;
            }
        }

        private static bool ContainsCellText(string value, string expectedText)
        {
            return !string.IsNullOrWhiteSpace(value) &&
                   value.Replace("\n", string.Empty).Replace("\r", string.Empty).Contains(expectedText);
        }

        private static void LoadPricingSections(string filePath, ObjectCoefficientSettings settings)
        {
            Dictionary<string, string> cells = ReadCellMap(filePath);

            if (TryParseCoefficient(GetFirstCell(cells, "B15", "B14"), out double unitPrice) && unitPrice > 0)
            {
                settings.UnitPrice = unitPrice;
            }

            if (TryParseCoefficient(GetFirstCell(cells, "B19", "B17"), out double range0Max) && range0Max > 0)
            {
                settings.ComplexityPricing.Range0MaxFeatureCount = range0Max;
            }

            if (TryParseCoefficient(GetFirstCell(cells, "B20", "B18"), out double range1Max) && range1Max > 0)
            {
                settings.ComplexityPricing.Range1MaxFeatureCount = range1Max;
            }

            if (TryParseCoefficient(GetFirstCell(cells, "B21", "B19"), out double range2Max) && range2Max > 0)
            {
                settings.ComplexityPricing.Range2MaxFeatureCount = range2Max;
            }

            if (TryParseCoefficient(GetFirstCell(cells, "C19", "C17"), out double range0To15))
            {
                settings.ComplexityPricing.Range0To15Coefficient = range0To15;
            }

            if (TryParseCoefficient(GetFirstCell(cells, "C20", "C18"), out double range15To40))
            {
                settings.ComplexityPricing.Range15To40Coefficient = range15To40;
            }

            if (TryParseCoefficient(GetFirstCell(cells, "C21", "C19"), out double range40To80))
            {
                settings.ComplexityPricing.Range40To80Coefficient = range40To80;
            }

            if (TryParseCoefficient(GetFirstCell(cells, "C22", "C20"), out double rangeOver80))
            {
                settings.ComplexityPricing.RangeOver80Coefficient = rangeOver80;
            }
        }

        private static Dictionary<string, string> ReadCellMap(string filePath)
        {
            var cells = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);

            using ZipArchive archive = ZipFile.OpenRead(filePath);
            List<string> sharedStrings = ReadSharedStrings(archive);
            ZipArchiveEntry sheetEntry = archive.GetEntry("xl/worksheets/sheet1.xml");
            if (sheetEntry == null)
            {
                return cells;
            }

            XNamespace ns = "http://schemas.openxmlformats.org/spreadsheetml/2006/main";
            using Stream sheetStream = sheetEntry.Open();
            XDocument sheetDocument = XDocument.Load(sheetStream);

            foreach (XElement cell in sheetDocument.Descendants(ns + "c"))
            {
                string reference = (string)cell.Attribute("r");
                if (!string.IsNullOrWhiteSpace(reference))
                {
                    cells[reference] = GetCellValue(cell, sharedStrings, ns);
                }
            }

            return cells;
        }

        private static string GetCell(Dictionary<string, string> cells, string reference)
        {
            return cells.TryGetValue(reference, out string value) ? value.Trim() : string.Empty;
        }

        private static string GetFirstCell(Dictionary<string, string> cells, params string[] references)
        {
            foreach (string reference in references)
            {
                string value = GetCell(cells, reference);
                if (!string.IsNullOrWhiteSpace(value))
                {
                    return value;
                }
            }

            return string.Empty;
        }

        private static void WriteDefaultFile(string filePath)
        {
            WriteDefaultFile(filePath, ObjectCoefficientSettings.CreateDefault());
        }

        private static void WriteDefaultFile(string filePath, ObjectCoefficientSettings settings)
        {
            string directory = Path.GetDirectoryName(filePath);
            if (!string.IsNullOrWhiteSpace(directory) && !Directory.Exists(directory))
            {
                Directory.CreateDirectory(directory);
            }

            if (File.Exists(filePath))
            {
                File.Delete(filePath);
            }

            using ZipArchive archive = ZipFile.Open(filePath, ZipArchiveMode.Create);
            AddEntry(archive, "[Content_Types].xml", GetContentTypesXml());
            AddEntry(archive, "_rels/.rels", GetRootRelationshipsXml());
            AddEntry(archive, "xl/workbook.xml", GetWorkbookXml());
            AddEntry(archive, "xl/_rels/workbook.xml.rels", GetWorkbookRelationshipsXml());
            AddEntry(archive, "xl/styles.xml", GetStylesXml());
            AddEntry(archive, "xl/worksheets/sheet1.xml", GetWorksheetXml(settings));
        }

        private static void AddEntry(ZipArchive archive, string name, string content)
        {
            ZipArchiveEntry entry = archive.CreateEntry(name, CompressionLevel.Optimal);
            using Stream stream = entry.Open();
            using var writer = new StreamWriter(stream, new UTF8Encoding(false));
            writer.Write(content);
        }

        private static string GetContentTypesXml()
        {
            return """
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">
  <Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>
  <Default Extension="xml" ContentType="application/xml"/>
  <Override PartName="/xl/workbook.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"/>
  <Override PartName="/xl/worksheets/sheet1.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"/>
  <Override PartName="/xl/styles.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"/>
</Types>
""";
        }

        private static string GetRootRelationshipsXml()
        {
            return """
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">
  <Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument" Target="xl/workbook.xml"/>
</Relationships>
""";
        }

        private static string GetWorkbookXml()
        {
            return """
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<workbook xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships">
  <sheets>
    <sheet name="对象系数" sheetId="1" r:id="rId1"/>
  </sheets>
</workbook>
""";
        }

        private static string GetWorkbookRelationshipsXml()
        {
            return """
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">
  <Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet" Target="worksheets/sheet1.xml"/>
  <Relationship Id="rId2" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles" Target="styles.xml"/>
</Relationships>
""";
        }

        private static string GetStylesXml()
        {
            return """
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<styleSheet xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main">
  <fonts count="2">
    <font><sz val="11"/><name val="Microsoft YaHei"/></font>
    <font><b/><sz val="11"/><name val="Microsoft YaHei"/></font>
  </fonts>
  <fills count="2"><fill><patternFill patternType="none"/></fill><fill><patternFill patternType="gray125"/></fill></fills>
  <borders count="1"><border><left/><right/><top/><bottom/><diagonal/></border></borders>
  <cellStyleXfs count="1"><xf numFmtId="0" fontId="0" fillId="0" borderId="0"/></cellStyleXfs>
  <cellXfs count="3">
    <xf numFmtId="0" fontId="0" fillId="0" borderId="0" xfId="0"/>
    <xf numFmtId="0" fontId="1" fillId="0" borderId="0" xfId="0" applyFont="1"/>
    <xf numFmtId="2" fontId="0" fillId="0" borderId="0" xfId="0" applyNumberFormat="1"/>
  </cellXfs>
  <cellStyles count="1"><cellStyle name="Normal" xfId="0" builtinId="0"/></cellStyles>
</styleSheet>
""";
        }

        private static string GetWorksheetXml(ObjectCoefficientSettings settings)
        {
            var sb = new StringBuilder();
            sb.AppendLine("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>");
            sb.AppendLine("<worksheet xmlns=\"http://schemas.openxmlformats.org/spreadsheetml/2006/main\">");
            sb.AppendLine("  <dimension ref=\"A1:D22\"/>");
            sb.AppendLine("  <sheetViews><sheetView workbookViewId=\"0\"><pane ySplit=\"1\" topLeftCell=\"A2\" activePane=\"bottomLeft\" state=\"frozen\"/></sheetView></sheetViews>");
            sb.AppendLine("  <cols><col min=\"1\" max=\"1\" width=\"14\" customWidth=\"1\"/><col min=\"2\" max=\"2\" width=\"18\" customWidth=\"1\"/><col min=\"3\" max=\"3\" width=\"42\" customWidth=\"1\"/><col min=\"4\" max=\"4\" width=\"72\" customWidth=\"1\"/></cols>");
            sb.AppendLine("  <sheetData>");
            sb.AppendLine("    <row r=\"1\">");
            AppendInlineCell(sb, "A1", "类别", 1);
            AppendInlineCell(sb, "B1", "图纸对象", 1);
            AppendInlineCell(sb, "C1", "图纸对象系数(表中为默认值，可配置，要求数值非负)", 1);
            AppendInlineCell(sb, "D1", "备注", 1);
            sb.AppendLine("    </row>");

            for (int i = 0; i < DefaultRows.Count; i++)
            {
                ObjectCoefficientRow row = DefaultRows[i];
                int rowIndex = i + 2;
                sb.AppendLine($"    <row r=\"{rowIndex}\">");
                AppendInlineCell(sb, $"A{rowIndex}", row.Category, 0);
                AppendInlineCell(sb, $"B{rowIndex}", row.ObjectName, 0);
                AppendNumberCell(sb, $"C{rowIndex}", settings.GetCoefficient(row.Category, row.ObjectName, row.Coefficient));
                AppendInlineCell(sb, $"D{rowIndex}", row.Remark, 0);
                sb.AppendLine("    </row>");
            }

            sb.AppendLine("    <row r=\"14\">");
            AppendInlineCell(sb, "A14", "报价基准", 1);
            AppendInlineCell(sb, "B14", "单价（元/步，可配置）", 1);
            sb.AppendLine("    </row>");

            sb.AppendLine("    <row r=\"15\">");
            AppendInlineCell(sb, "A15", "取值范围", 1);
            AppendNumberCell(sb, "B15", settings.UnitPrice);
            sb.AppendLine("    </row>");

            sb.AppendLine("    <row r=\"18\">");
            AppendInlineCell(sb, "A18", "等效特征数范围", 1);
            AppendInlineCell(sb, "B18", "最大特征数", 1);
            AppendInlineCell(sb, "C18", "复杂度系数", 1);
            AppendInlineCell(sb, "D18", "备注", 1);
            sb.AppendLine("    </row>");

            AppendComplexityRow(sb, 19, BuildRangeLabel(0, settings.ComplexityPricing.Range0MaxFeatureCount), settings.ComplexityPricing.Range0MaxFeatureCount, settings.ComplexityPricing.Range0To15Coefficient, $"含{FormatReferenceNumber(settings.ComplexityPricing.Range0MaxFeatureCount)}");
            AppendComplexityRow(sb, 20, BuildRangeLabel(settings.ComplexityPricing.Range0MaxFeatureCount, settings.ComplexityPricing.Range1MaxFeatureCount), settings.ComplexityPricing.Range1MaxFeatureCount, settings.ComplexityPricing.Range15To40Coefficient, $"含{FormatReferenceNumber(settings.ComplexityPricing.Range1MaxFeatureCount)}");
            AppendComplexityRow(sb, 21, BuildRangeLabel(settings.ComplexityPricing.Range1MaxFeatureCount, settings.ComplexityPricing.Range2MaxFeatureCount), settings.ComplexityPricing.Range2MaxFeatureCount, settings.ComplexityPricing.Range40To80Coefficient, $"含{FormatReferenceNumber(settings.ComplexityPricing.Range2MaxFeatureCount)}");
            AppendComplexityOverMaxRow(sb, 22, settings.ComplexityPricing.Range2MaxFeatureCount, settings.ComplexityPricing.RangeOver80Coefficient);

            sb.AppendLine("  </sheetData>");
            sb.AppendLine("</worksheet>");
            return sb.ToString();
        }

        private static void AppendComplexityRow(StringBuilder sb, int rowIndex, string range, double maxFeatureCount, double coefficient, string remark)
        {
            sb.AppendLine($"    <row r=\"{rowIndex}\">");
            AppendInlineCell(sb, $"A{rowIndex}", range, 0);
            AppendNumberCell(sb, $"B{rowIndex}", maxFeatureCount);
            AppendNumberCell(sb, $"C{rowIndex}", coefficient);
            AppendInlineCell(sb, $"D{rowIndex}", remark, 0);
            sb.AppendLine("    </row>");
        }

        private static void AppendComplexityOverMaxRow(StringBuilder sb, int rowIndex, double previousMaxFeatureCount, double coefficient)
        {
            sb.AppendLine($"    <row r=\"{rowIndex}\">");
            AppendInlineCell(sb, $"A{rowIndex}", $"{FormatReferenceNumber(previousMaxFeatureCount)}以上", 0);
            AppendInlineCell(sb, $"B{rowIndex}", string.Empty, 0);
            AppendNumberCell(sb, $"C{rowIndex}", coefficient);
            AppendInlineCell(sb, $"D{rowIndex}", string.Empty, 0);
            sb.AppendLine("    </row>");
        }

        private static string BuildRangeLabel(double previousMaxFeatureCount, double currentMaxFeatureCount)
        {
            if (previousMaxFeatureCount <= 0)
            {
                return $"0~{FormatReferenceNumber(currentMaxFeatureCount)}";
            }

            double start = IsWholeNumber(previousMaxFeatureCount)
                ? previousMaxFeatureCount + 1
                : previousMaxFeatureCount;
            return $"{FormatReferenceNumber(start)}~{FormatReferenceNumber(currentMaxFeatureCount)}";
        }

        private static bool IsWholeNumber(double value)
        {
            return Math.Abs(value - Math.Round(value)) < 0.000001;
        }

        private static string FormatReferenceNumber(double value)
        {
            return value.ToString("0.####", CultureInfo.InvariantCulture);
        }

        private static void AppendInlineCell(StringBuilder sb, string reference, string value, int styleIndex)
        {
            sb.AppendLine($"      <c r=\"{reference}\" t=\"inlineStr\" s=\"{styleIndex}\"><is><t>{SecurityElement.Escape(value ?? string.Empty)}</t></is></c>");
        }

        private static void AppendNumberCell(StringBuilder sb, string reference, double value)
        {
            sb.AppendLine($"      <c r=\"{reference}\" s=\"2\"><v>{value.ToString("0.00", CultureInfo.InvariantCulture)}</v></c>");
        }

        private static bool TryParseCoefficient(string text, out double coefficient)
        {
            if (double.TryParse(text?.Trim(), NumberStyles.Float, CultureInfo.InvariantCulture, out coefficient) ||
                double.TryParse(text?.Trim(), NumberStyles.Float, CultureInfo.CurrentCulture, out coefficient))
            {
                if (coefficient < 0)
                {
                    coefficient = 0;
                }

                return true;
            }

            coefficient = 0;
            return false;
        }

        private class WorkbookRow
        {
            public WorkbookRow(string category, string objectName, string coefficientText)
            {
                Category = category;
                ObjectName = objectName;
                CoefficientText = coefficientText;
            }

            public string Category { get; }
            public string ObjectName { get; }
            public string CoefficientText { get; }
        }
    }

    public class ObjectCoefficientRow
    {
        public ObjectCoefficientRow(string category, string objectName, double coefficient, string remark)
        {
            Category = category;
            ObjectName = objectName;
            Coefficient = coefficient;
            Remark = remark;
        }

        public string Category { get; }
        public string ObjectName { get; }
        public double Coefficient { get; }
        public string Remark { get; }
    }
}
