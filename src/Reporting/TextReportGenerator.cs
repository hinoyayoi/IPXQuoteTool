using SolidWorks.Interop.swconst;
using IPXQuoteTool.Pricing;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Security;
using System.Text;

namespace IPXQuoteTool.Reporting
{
    public class TextReportGenerator : IReportGenerator
    {
        private readonly IQuotePricingRule _pricingRule = new DefaultQuotePricingRule();

        public byte[] Generate(IReadOnlyList<DocumentInfo> documents, QuotePricingSettings pricingSettings)
        {
            var rows = BuildRows(documents, pricingSettings).ToList();
            return BuildWorkbook(rows, documents.Count, rows.Sum(r => r.Price.ComplexityScore), rows.Sum(r => r.Price.FinalScore), pricingSettings);
        }

        private IEnumerable<ReportDocumentRow> BuildRows(IReadOnlyList<DocumentInfo> documents, QuotePricingSettings pricingSettings)
        {
            int index = 1;
            foreach (DocumentInfo document in documents)
            {
                yield return new ReportDocumentRow(index++, document, _pricingRule.Calculate(document, pricingSettings), GetObjectRows(document));
            }
        }

        private static List<ReportObjectRow> GetObjectRows(DocumentInfo document)
        {
            if (document.IsProcessingFailed)
            {
                return new List<ReportObjectRow> { new ReportObjectRow(string.Empty, 0) };
            }

            switch (document.DocumentType)
            {
                case swDocumentTypes_e.swDocPART:
                    return new List<ReportObjectRow>
                    {
                        new ReportObjectRow("特征", document.FeatureCount),
                        new ReportObjectRow("配置项", document.ConfigurationCount),
                        new ReportObjectRow("表达式", document.ExpressionCount)
                    };
                case swDocumentTypes_e.swDocASSEMBLY:
                    return new List<ReportObjectRow>
                    {
                        new ReportObjectRow("组件数", document.ComponentCount),
                        new ReportObjectRow("装配约束", document.MateCount),
                        new ReportObjectRow("装配特征", document.AssemblyFeatureCount),
                        new ReportObjectRow("配置项", document.ConfigurationCount),
                        new ReportObjectRow("表达式", document.ExpressionCount)
                    };
                case swDocumentTypes_e.swDocDRAWING:
                    return new List<ReportObjectRow>
                    {
                        new ReportObjectRow("视图", document.ViewCount),
                        new ReportObjectRow("标注", document.DimensionCount),
                        new ReportObjectRow("表格", document.TableCount)
                    };
                default:
                    return new List<ReportObjectRow> { new ReportObjectRow("未知", 0) };
            }
        }

        private static byte[] BuildWorkbook(IReadOnlyList<ReportDocumentRow> reportRows, int documentCount, double totalComplexityScore, double totalPrice, QuotePricingSettings pricingSettings)
        {
            using var stream = new MemoryStream();
            using (ZipArchive archive = new ZipArchive(stream, ZipArchiveMode.Create, true))
            {
                var images = new List<ReportImage>();
                string worksheetXml = GetWorksheetXml(reportRows, documentCount, totalComplexityScore, totalPrice, pricingSettings, images);

                AddEntry(archive, "[Content_Types].xml", GetContentTypesXml(images.Count > 0));
                AddEntry(archive, "_rels/.rels", GetRootRelationshipsXml());
                AddEntry(archive, "xl/workbook.xml", GetWorkbookXml());
                AddEntry(archive, "xl/_rels/workbook.xml.rels", GetWorkbookRelationshipsXml());
                AddEntry(archive, "xl/styles.xml", GetStylesXml());
                AddEntry(archive, "xl/worksheets/sheet1.xml", worksheetXml);

                if (images.Count > 0)
                {
                    AddEntry(archive, "xl/worksheets/_rels/sheet1.xml.rels", GetWorksheetRelationshipsXml());
                    AddEntry(archive, "xl/drawings/drawing1.xml", GetDrawingXml(images));
                    AddEntry(archive, "xl/drawings/_rels/drawing1.xml.rels", GetDrawingRelationshipsXml(images));

                    foreach (ReportImage image in images)
                    {
                        AddBinaryEntry(archive, $"xl/media/image{image.Id}.{image.Extension}", image.Bytes);
                    }
                }
            }

            return stream.ToArray();
        }

        private static void AddEntry(ZipArchive archive, string name, string content)
        {
            ZipArchiveEntry entry = archive.CreateEntry(name, CompressionLevel.Optimal);
            using Stream stream = entry.Open();
            using var writer = new StreamWriter(stream, new UTF8Encoding(false));
            writer.Write(content);
        }

        private static void AddBinaryEntry(ZipArchive archive, string name, byte[] content)
        {
            ZipArchiveEntry entry = archive.CreateEntry(name, CompressionLevel.Optimal);
            using Stream stream = entry.Open();
            stream.Write(content, 0, content.Length);
        }

        private static string GetWorksheetXml(IReadOnlyList<ReportDocumentRow> reportRows, int documentCount, double totalComplexityScore, double totalPrice, QuotePricingSettings pricingSettings, List<ReportImage> images)
        {
            const int summaryRow = 3;
            const int headerRow = 4;
            const int firstDataRow = 5;
            int lastRow = headerRow + reportRows.Sum(r => r.ObjectRows.Count);
            int worksheetLastRow = Math.Max(lastRow, headerRow);
            var sb = new StringBuilder();
            var merges = new List<string>();

            sb.AppendLine("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>");
            sb.AppendLine("<worksheet xmlns=\"http://schemas.openxmlformats.org/spreadsheetml/2006/main\" xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\">");
            sb.AppendLine($"  <dimension ref=\"A1:H{worksheetLastRow}\"/>");
            sb.AppendLine("  <sheetViews><sheetView workbookViewId=\"0\"><pane ySplit=\"4\" topLeftCell=\"A5\" activePane=\"bottomLeft\" state=\"frozen\"/></sheetView></sheetViews>");
            sb.AppendLine("  <cols>");
            sb.AppendLine("    <col min=\"1\" max=\"1\" width=\"8\" customWidth=\"1\"/>");
            sb.AppendLine("    <col min=\"2\" max=\"2\" width=\"28\" customWidth=\"1\"/>");
            sb.AppendLine("    <col min=\"3\" max=\"3\" width=\"16\" customWidth=\"1\"/>");
            sb.AppendLine("    <col min=\"4\" max=\"4\" width=\"12\" customWidth=\"1\"/>");
            sb.AppendLine("    <col min=\"5\" max=\"5\" width=\"14\" customWidth=\"1\"/>");
            sb.AppendLine("    <col min=\"6\" max=\"6\" width=\"10\" customWidth=\"1\"/>");
            sb.AppendLine("    <col min=\"7\" max=\"7\" width=\"14\" customWidth=\"1\"/>");
            sb.AppendLine("    <col min=\"8\" max=\"8\" width=\"32\" customWidth=\"1\"/>");
            sb.AppendLine("  </cols>");
            sb.AppendLine("  <sheetData>");

            sb.AppendLine("    <row r=\"1\" ht=\"42\" customHeight=\"1\">");
            AppendInlineCell(sb, "A1", "IPX数据转换费用估算表", 5);
            sb.AppendLine("    </row>");

            sb.AppendLine("    <row r=\"2\" ht=\"24\" customHeight=\"1\">");
            AppendInlineCell(sb, "A2", "注意：本表单仅用于费用估算，不代表最终报价及最终价格。", 6);
            sb.AppendLine("    </row>");

            sb.AppendLine($"    <row r=\"{summaryRow}\" ht=\"42\" customHeight=\"1\">");
            AppendInlineCell(sb, $"A{summaryRow}", "生成\n日期", 1);
            AppendInlineCell(sb, $"B{summaryRow}", DateTime.Now.ToString("yyyy.MM.dd", CultureInfo.InvariantCulture), 1);
            AppendInlineCell(sb, $"C{summaryRow}", "图纸总\n数", 1);
            AppendIntegerCell(sb, $"D{summaryRow}", documentCount, 1);
            AppendInlineCell(sb, $"E{summaryRow}", "等效特\n征数", 1);
            AppendNumberCell(sb, $"F{summaryRow}", totalComplexityScore, 1);
            AppendInlineCell(sb, $"G{summaryRow}", "估算总价\n(元)", 1);
            AppendFormulaNumberCell(sb, $"H{summaryRow}", $"SUM(G{firstDataRow}:G{Math.Max(lastRow, firstDataRow)})", totalPrice, 1);
            sb.AppendLine("    </row>");

            sb.AppendLine($"    <row r=\"{headerRow}\" ht=\"34\" customHeight=\"1\">");
            AppendInlineCell(sb, $"A{headerRow}", "序号", 2);
            AppendInlineCell(sb, $"B{headerRow}", "图纸名", 2);
            AppendInlineCell(sb, $"C{headerRow}", "示例图", 2);
            AppendInlineCell(sb, $"D{headerRow}", "类别", 2);
            AppendInlineCell(sb, $"E{headerRow}", "图纸对象", 2);
            AppendInlineCell(sb, $"F{headerRow}", "计数", 2);
            AppendInlineCell(sb, $"G{headerRow}", "估算单价(元)", 2);
            AppendInlineCell(sb, $"H{headerRow}", "图纸路径", 2);
            sb.AppendLine("    </row>");

            int rowIndex = firstDataRow;
            foreach (ReportDocumentRow reportRow in reportRows)
            {
                int startRow = rowIndex;
                int endRow = rowIndex + reportRow.ObjectRows.Count - 1;

                if (reportRow.Document.PreviewImageBytes != null && reportRow.Document.PreviewImageBytes.Length > 0)
                {
                    images.Add(new ReportImage(images.Count + 1, startRow, endRow, reportRow.Document.PreviewImageBytes));
                }

                for (int i = 0; i < reportRow.ObjectRows.Count; i++)
                {
                    ReportObjectRow objectRow = reportRow.ObjectRows[i];
                    sb.AppendLine($"    <row r=\"{rowIndex}\" ht=\"28\" customHeight=\"1\">");
                    if (i == 0)
                    {
                        AppendIntegerCell(sb, $"A{rowIndex}", reportRow.Index, 4);
                        AppendInlineCell(sb, $"B{rowIndex}", GetDisplayFileName(reportRow.Document), 3);
                        AppendInlineCell(sb, $"C{rowIndex}", string.Empty, 3);
                        AppendInlineCell(sb, $"D{rowIndex}", reportRow.Document.Category, 3);
                        if (reportRow.Document.IsProcessingFailed)
                        {
                            AppendInlineCell(sb, $"E{rowIndex}", string.Empty, 3);
                            AppendInlineCell(sb, $"F{rowIndex}", string.Empty, 4);
                            AppendInlineCell(sb, $"G{rowIndex}", string.Empty, 3);
                        }
                        else
                        {
                            AppendInlineCell(sb, $"E{rowIndex}", objectRow.Name, 3);
                            AppendIntegerCell(sb, $"F{rowIndex}", objectRow.Count, 4);
                            AppendFormulaNumberCell(sb, $"G{rowIndex}", $"{reportRow.Price.ComplexityScore.ToString("0.00", CultureInfo.InvariantCulture)}*{reportRow.Price.UnitPrice.ToString("0.####", CultureInfo.InvariantCulture)}*{reportRow.Price.ComplexityCoefficient.ToString("0.####", CultureInfo.InvariantCulture)}*{reportRow.Price.DiscountCoefficient.ToString("0.####", CultureInfo.InvariantCulture)}", reportRow.Price.FinalScore, 3);
                        }
                        AppendInlineCell(sb, $"H{rowIndex}", GetDisplayFilePath(reportRow.Document), 3);
                    }
                    else
                    {
                        AppendInlineCell(sb, $"E{rowIndex}", objectRow.Name, 3);
                        AppendIntegerCell(sb, $"F{rowIndex}", objectRow.Count, 4);
                    }
                    sb.AppendLine("    </row>");
                    rowIndex++;
                }

                if (endRow > startRow)
                {
                    foreach (string column in new[] { "A", "B", "C", "D", "G", "H" })
                    {
                        merges.Add($"{column}{startRow}:{column}{endRow}");
                    }
                }
            }

            sb.AppendLine("  </sheetData>");

            merges.Add("A1:H1");
            merges.Add("A2:H2");

            if (merges.Count > 0)
            {
                sb.AppendLine($"  <mergeCells count=\"{merges.Count}\">");
                foreach (string merge in merges)
                {
                    sb.AppendLine($"    <mergeCell ref=\"{merge}\"/>");
                }
                sb.AppendLine("  </mergeCells>");
            }

            if (images.Count > 0)
            {
                sb.AppendLine("  <drawing r:id=\"rId1\"/>");
            }

            sb.AppendLine("</worksheet>");
            return sb.ToString();
        }

        private static string GetWorksheetRelationshipsXml()
        {
            return """
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">
  <Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/drawing" Target="../drawings/drawing1.xml"/>
</Relationships>
""";
        }

        private static string GetDrawingRelationshipsXml(IReadOnlyList<ReportImage> images)
        {
            var sb = new StringBuilder();
            sb.AppendLine("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>");
            sb.AppendLine("<Relationships xmlns=\"http://schemas.openxmlformats.org/package/2006/relationships\">");
            foreach (ReportImage image in images)
            {
                sb.AppendLine($"  <Relationship Id=\"rId{image.Id}\" Type=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships/image\" Target=\"../media/image{image.Id}.{image.Extension}\"/>");
            }
            sb.AppendLine("</Relationships>");
            return sb.ToString();
        }

        private static string GetDrawingXml(IReadOnlyList<ReportImage> images)
        {
            var sb = new StringBuilder();
            sb.AppendLine("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>");
            sb.AppendLine("<xdr:wsDr xmlns:xdr=\"http://schemas.openxmlformats.org/drawingml/2006/spreadsheetDrawing\" xmlns:a=\"http://schemas.openxmlformats.org/drawingml/2006/main\" xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\">");
            foreach (ReportImage image in images)
            {
                int fromRow = image.StartRow - 1;
                int toRow = image.EndRow;
                sb.AppendLine("  <xdr:twoCellAnchor editAs=\"oneCell\">");
                sb.AppendLine("    <xdr:from><xdr:col>2</xdr:col><xdr:colOff>120000</xdr:colOff><xdr:row>" + fromRow + "</xdr:row><xdr:rowOff>80000</xdr:rowOff></xdr:from>");
                sb.AppendLine("    <xdr:to><xdr:col>3</xdr:col><xdr:colOff>0</xdr:colOff><xdr:row>" + toRow + "</xdr:row><xdr:rowOff>0</xdr:rowOff></xdr:to>");
                sb.AppendLine("    <xdr:pic>");
                sb.AppendLine($"      <xdr:nvPicPr><xdr:cNvPr id=\"{image.Id}\" name=\"示例图{image.Id}\"/><xdr:cNvPicPr><a:picLocks noChangeAspect=\"1\"/></xdr:cNvPicPr></xdr:nvPicPr>");
                sb.AppendLine($"      <xdr:blipFill><a:blip r:embed=\"rId{image.Id}\"/><a:stretch><a:fillRect/></a:stretch></xdr:blipFill>");
                sb.AppendLine("      <xdr:spPr><a:xfrm><a:off x=\"0\" y=\"0\"/><a:ext cx=\"900000\" cy=\"700000\"/></a:xfrm><a:prstGeom prst=\"rect\"><a:avLst/></a:prstGeom></xdr:spPr>");
                sb.AppendLine("    </xdr:pic>");
                sb.AppendLine("    <xdr:clientData/>");
                sb.AppendLine("  </xdr:twoCellAnchor>");
            }
            sb.AppendLine("</xdr:wsDr>");
            return sb.ToString();
        }

        private static void AppendInlineCell(StringBuilder sb, string reference, string value, int styleIndex)
        {
            sb.AppendLine($"      <c r=\"{reference}\" t=\"inlineStr\" s=\"{styleIndex}\"><is><t>{SecurityElement.Escape(value ?? string.Empty)}</t></is></c>");
        }

        private static string GetDisplayFileName(DocumentInfo document)
        {
            return document.IsProcessingFailed
                ? $"{document.FileName}\n{GetDisplayFailureReason(document)}"
                : document.FileName;
        }

        private static string GetDisplayFailureReason(DocumentInfo document)
        {
            string error = document.ProcessingError ?? string.Empty;
            const string reasonMarker = "原因:";
            int reasonIndex = error.IndexOf(reasonMarker, StringComparison.Ordinal);
            if (reasonIndex >= 0)
            {
                string reason = error.Substring(reasonIndex + reasonMarker.Length).Trim();
                int codeIndex = reason.IndexOf(" (错误码", StringComparison.Ordinal);
                if (codeIndex >= 0)
                {
                    reason = reason.Substring(0, codeIndex).Trim();
                }

                if (!string.IsNullOrWhiteSpace(reason))
                {
                    return reason;
                }
            }

            return string.IsNullOrWhiteSpace(error) ? "处理失败，请补充" : error;
        }

        private static string GetDisplayFilePath(DocumentInfo document)
        {
            if (!document.IsProcessingFailed)
            {
                return document.FilePath ?? string.Empty;
            }

            return $"{document.FilePath ?? string.Empty}\n失败原因: {document.ProcessingError}";
        }

        private static void AppendNumberCell(StringBuilder sb, string reference, double value, int styleIndex)
        {
            sb.AppendLine($"      <c r=\"{reference}\" s=\"{styleIndex}\"><v>{value.ToString("0.00", CultureInfo.InvariantCulture)}</v></c>");
        }

        private static void AppendFormulaNumberCell(StringBuilder sb, string reference, string formula, double cachedValue, int styleIndex)
        {
            sb.AppendLine($"      <c r=\"{reference}\" s=\"{styleIndex}\"><f>{SecurityElement.Escape(formula)}</f><v>{cachedValue.ToString("0.00", CultureInfo.InvariantCulture)}</v></c>");
        }

        private static void AppendIntegerCell(StringBuilder sb, string reference, int value, int styleIndex)
        {
            sb.AppendLine($"      <c r=\"{reference}\" s=\"{styleIndex}\"><v>{value.ToString(CultureInfo.InvariantCulture)}</v></c>");
        }

        private static string GetContentTypesXml(bool hasImages)
        {
            string drawingOverride = hasImages ? "  <Override PartName=\"/xl/drawings/drawing1.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.drawing+xml\"/>\n" : string.Empty;
            return $"""
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">
  <Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>
  <Default Extension="xml" ContentType="application/xml"/>
  <Default Extension="jpg" ContentType="image/jpeg"/>
  <Default Extension="jpeg" ContentType="image/jpeg"/>
  <Default Extension="png" ContentType="image/png"/>
  <Override PartName="/xl/workbook.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"/>
  <Override PartName="/xl/worksheets/sheet1.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"/>
  <Override PartName="/xl/styles.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"/>
{drawingOverride}
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
    <sheet name="费用估算" sheetId="1" r:id="rId1"/>
  </sheets>
  <calcPr calcId="0" calcMode="auto" fullCalcOnLoad="1"/>
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
  <fonts count="4">
    <font><sz val="11"/><name val="Microsoft YaHei"/></font>
    <font><b/><sz val="11"/><name val="Microsoft YaHei"/></font>
    <font><b/><sz val="16"/><name val="Microsoft YaHei"/></font>
    <font><b/><sz val="11"/><color rgb="FFFF0000"/><name val="Microsoft YaHei"/></font>
  </fonts>
  <fills count="3">
    <fill><patternFill patternType="none"/></fill>
    <fill><patternFill patternType="gray125"/></fill>
    <fill><patternFill patternType="solid"><fgColor rgb="FFD9D9D9"/><bgColor indexed="64"/></patternFill></fill>
  </fills>
  <borders count="2">
    <border><left/><right/><top/><bottom/><diagonal/></border>
    <border><left style="thin"><color auto="1"/></left><right style="thin"><color auto="1"/></right><top style="thin"><color auto="1"/></top><bottom style="thin"><color auto="1"/></bottom><diagonal/></border>
  </borders>
  <cellStyleXfs count="1"><xf numFmtId="0" fontId="0" fillId="0" borderId="0"/></cellStyleXfs>
  <cellXfs count="7">
    <xf numFmtId="0" fontId="0" fillId="0" borderId="0" xfId="0"/>
    <xf numFmtId="0" fontId="1" fillId="2" borderId="1" xfId="0" applyFont="1" applyFill="1" applyBorder="1" applyAlignment="1"><alignment horizontal="center" vertical="center" wrapText="1"/></xf>
    <xf numFmtId="0" fontId="1" fillId="0" borderId="1" xfId="0" applyFont="1" applyBorder="1" applyAlignment="1"><alignment horizontal="center" vertical="center" wrapText="1"/></xf>
    <xf numFmtId="2" fontId="0" fillId="0" borderId="1" xfId="0" applyNumberFormat="1" applyBorder="1" applyAlignment="1"><alignment horizontal="center" vertical="center" wrapText="1"/></xf>
    <xf numFmtId="1" fontId="0" fillId="0" borderId="1" xfId="0" applyNumberFormat="1" applyBorder="1" applyAlignment="1"><alignment horizontal="center" vertical="center" wrapText="1"/></xf>
    <xf numFmtId="0" fontId="2" fillId="0" borderId="0" xfId="0" applyFont="1" applyAlignment="1"><alignment horizontal="center" vertical="center"/></xf>
    <xf numFmtId="0" fontId="3" fillId="0" borderId="0" xfId="0" applyFont="1" applyAlignment="1"><alignment horizontal="right" vertical="center"/></xf>
  </cellXfs>
  <cellStyles count="1"><cellStyle name="Normal" xfId="0" builtinId="0"/></cellStyles>
</styleSheet>
""";
        }

        private class ReportDocumentRow
        {
            public ReportDocumentRow(int index, DocumentInfo document, QuotePriceResult price, List<ReportObjectRow> objectRows)
            {
                Index = index;
                Document = document;
                Price = price;
                ObjectRows = objectRows;
            }

            public int Index { get; }
            public DocumentInfo Document { get; }
            public QuotePriceResult Price { get; }
            public List<ReportObjectRow> ObjectRows { get; }
        }

        private class ReportObjectRow
        {
            public ReportObjectRow(string name, int count)
            {
                Name = name;
                Count = count;
            }

            public string Name { get; }
            public int Count { get; }
        }

        private class ReportImage
        {
            public ReportImage(int id, int startRow, int endRow, byte[] bytes)
            {
                Id = id;
                StartRow = startRow;
                EndRow = endRow;
                Bytes = bytes;
                Extension = GetImageExtension(bytes);
            }

            public int Id { get; }
            public int StartRow { get; }
            public int EndRow { get; }
            public byte[] Bytes { get; }
            public string Extension { get; }
        }

        private static string GetImageExtension(byte[] bytes)
        {
            if (bytes != null &&
                bytes.Length >= 8 &&
                bytes[0] == 0x89 &&
                bytes[1] == 0x50 &&
                bytes[2] == 0x4E &&
                bytes[3] == 0x47 &&
                bytes[4] == 0x0D &&
                bytes[5] == 0x0A &&
                bytes[6] == 0x1A &&
                bytes[7] == 0x0A)
            {
                return "png";
            }

            return "jpg";
        }
    }
}

