using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using System;
using System.Collections.Generic;
using System.Linq;

namespace IPXQuoteTool.Analysis.Drawings
{
    public class DrawingMetricExtractor : IDocumentMetricExtractor
    {
        public swDocumentTypes_e SupportedDocumentType => swDocumentTypes_e.swDocDRAWING;

        public void Extract(DocumentAnalysisContext context, DocumentInfo info)
        {
            var drawings = TraverseDrawing(context.Model);
            info.ViewCount = drawings.Sum(d => d.ViewCount);
            info.NoteCount = drawings.Sum(d => d.NoteCount);
            info.DimensionCount = drawings.Sum(d => d.DimensionCount);
            info.TableCount = drawings.Sum(d => d.TableCount);
        }

        private static List<DrawingInfo> TraverseDrawing(ModelDoc2 model)
        {
            var drawings = new List<DrawingInfo>();

            try
            {
                DrawingDoc drawingDoc = (DrawingDoc)model;

                object sheetNamesObj = drawingDoc.GetSheetNames();
                if (sheetNamesObj is not Array sheetNames)
                {
                    return drawings;
                }

                foreach (string sheetName in sheetNames)
                {
                    drawingDoc.ActivateSheet(sheetName);
                    Sheet sheet = (Sheet)drawingDoc.GetCurrentSheet();

                    object viewsObj = sheet.GetViews();
                    Array views = viewsObj as Array;

                    int noteCount = 0;
                    int dimensionCount = 0;

                    if (views != null)
                    {
                        foreach (View view in views)
                        {
                            noteCount += view.GetNoteCount();
                            dimensionCount += CountDimensionsInView(view);
                        }
                    }

                    drawings.Add(new DrawingInfo
                    {
                        SheetName = sheetName,
                        ViewCount = views?.Length ?? 0,
                        NoteCount = noteCount,
                        DimensionCount = dimensionCount,
                        TableCount = CountTablesInSheet(sheet)
                    });
                }
            }
            catch
            {
            }

            return drawings;
        }

        private static int CountDimensionsInView(View view)
        {
            try
            {
                object dimensionsObj = view.GetDisplayDimensions();
                if (dimensionsObj is Array dimensions)
                {
                    return dimensions.Length;
                }
            }
            catch
            {
            }

            return 0;
        }

        private static int CountTablesInSheet(Sheet sheet)
        {
            int count = 0;

            try
            {
                dynamic dynSheet = sheet;
                try
                {
                    object tablesObj = dynSheet.GetTables();
                    if (tablesObj is Array tables)
                    {
                        count = tables.Length;
                    }
                }
                catch
                {
                    try
                    {
                        object tablesObj = dynSheet.GetTables2();
                        if (tablesObj is Array tables)
                        {
                            count = tables.Length;
                        }
                    }
                    catch
                    {
                    }
                }
            }
            catch
            {
            }

            return count;
        }
    }
}
