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
                int oleObjectCount = CountOleObjects(model);

                object sheetNamesObj = drawingDoc.GetSheetNames();
                if (sheetNamesObj is not Array sheetNames)
                {
                    return drawings;
                }

                foreach (string sheetName in sheetNames)
                {
                    drawingDoc.ActivateSheet(sheetName);
                    var views = GetViewsFromActiveSheet(drawingDoc);

                    int noteCount = 0;
                    int dimensionCount = 0;
                    int tableCount = 0;

                    foreach (ViewInfo viewInfo in views)
                    {
                        int annotationCount = CountAnnotationsInView(viewInfo);
                        dimensionCount += annotationCount;
                        noteCount += viewInfo.IsSheetView ? 0 : CountNotesInView(viewInfo.View);

                        tableCount += CountTablesInView(viewInfo.View);
                    }

                    if (drawings.Count == 0)
                    {
                        dimensionCount += oleObjectCount;
                    }

                    drawings.Add(new DrawingInfo
                    {
                        SheetName = sheetName,
                        ViewCount = views.Count(v => !v.IsSheetView),
                        NoteCount = noteCount,
                        DimensionCount = dimensionCount,
                        TableCount = tableCount
                    });
                }
            }
            catch
            {
            }

            return drawings;
        }

        private static int CountOleObjects(ModelDoc2 model)
        {
            try
            {
                ModelDocExtension extension = model.Extension;
                if (extension == null)
                {
                    return 0;
                }

                int count = extension.GetOLEObjectCount(0);
                if (count >= 0)
                {
                    return count;
                }
            }
            catch
            {
            }

            try
            {
                object oleObjectsObj = model.Extension?.GetOLEObjects(0);
                if (oleObjectsObj is Array oleObjects)
                {
                    return oleObjects.Length;
                }
            }
            catch
            {
            }

            return 0;
        }

        private static List<ViewInfo> GetViewsFromActiveSheet(DrawingDoc drawingDoc)
        {
            var views = new List<ViewInfo>();

            try
            {
                View view = (View)drawingDoc.GetFirstView();
                bool isFirstView = true;

                while (view != null)
                {
                    views.Add(new ViewInfo(view, isFirstView));
                    view = (View)view.GetNextView();
                    isFirstView = false;
                }
            }
            catch
            {
            }

            return views;
        }

        private static int CountNotesInView(View view)
        {
            try
            {
                return view.GetNoteCount();
            }
            catch
            {
                return 0;
            }
        }

        private static int CountAnnotationsInView(ViewInfo viewInfo)
        {
            View view = viewInfo.View;
            int count = 0;

            count += SafeCount(() => view.GetWeldBeadCount());

            if (!viewInfo.IsSheetView)
            {
                count += CountNotesInView(view);
            }

            count += SafeCount(() => view.GetDatumTagCount());
            count += SafeCount(() => view.GetDatumTargetSymCount());
            count += SafeCount(() => view.GetWeldSymbolCount());
            count += SafeCount(() => view.GetGTolCount());
            count += SafeCount(() => view.GetCenterLineCount());
            count += CountCenterMarksInView(view);
            count += SafeCount(() => view.GetSFSymbolCount());
            count += SafeCount(() => view.GetRevisionCloudCount());
            count += SafeCount(() => view.GetDowelSymbolCount());
            count += CountDimensionsInView(view);

            return count;
        }

        private static int CountCenterMarksInView(View view)
        {
            try
            {
                return view.GetCenterMarkCount();
            }
            catch
            {
            }

            try
            {
                int size = 0;
                return view.GetCenterMarkCount2(ref size);
            }
            catch
            {
                return 0;
            }
        }

        private static int CountDimensionsInView(View view)
        {
            try
            {
                int count = view.GetDisplayDimensionCount();
                if (count >= 0)
                {
                    return count;
                }
            }
            catch
            {
            }

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

        private static int SafeCount(Func<int> countProvider)
        {
            try
            {
                int count = countProvider();
                return count > 0 ? count : 0;
            }
            catch
            {
                return 0;
            }
        }

        private static int CountTablesInView(View view)
        {
            try
            {
                int tableAnnotationCount = view.GetTableAnnotationCount();
                if (tableAnnotationCount >= 0)
                {
                    return tableAnnotationCount;
                }
            }
            catch
            {
            }

            try
            {
                object tablesObj = view.GetTableAnnotations();
                if (tablesObj is Array tables)
                {
                    return tables.Length;
                }
            }
            catch
            {
            }

            int count = 0;

            try
            {
                TableAnnotation table = view.GetFirstTableAnnotation();
                while (table != null)
                {
                    count++;
                    table = table.GetNext();
                }
            }
            catch
            {
            }

            return count;
        }

        private class ViewInfo
        {
            public ViewInfo(View view, bool isSheetView)
            {
                View = view;
                IsSheetView = isSheetView;
            }

            public View View { get; }
            public bool IsSheetView { get; }
        }
    }
}
