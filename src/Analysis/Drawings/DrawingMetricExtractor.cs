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
                        int annotationCount = CountAnnotationsInView(model, viewInfo);
                        dimensionCount += annotationCount;
                        noteCount += CountNotesInView(model, viewInfo);

                        if (!viewInfo.IsSheetView)
                        {
                            AnalysisTraceLogger.Write(model, "视图", GetViewName(viewInfo.View), sheetName);
                        }

                        tableCount += CountTablesInView(model, viewInfo.View);
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

                object oleObjectsObj = extension.GetOLEObjects(0);
                if (oleObjectsObj is Array oleObjects)
                {
                    for (int i = 0; i < oleObjects.Length; i++)
                    {
                        AnalysisTraceLogger.Write(model, "标注:OLE对象", $"OLE对象 {i + 1}");
                    }

                    return oleObjects.Length;
                }
            }
            catch
            {
            }

            try
            {
                int count = model.Extension?.GetOLEObjectCount(0) ?? 0;
                for (int i = 0; i < count; i++)
                {
                    AnalysisTraceLogger.Write(model, "标注:OLE对象", $"OLE对象 {i + 1}");
                }

                return count;
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

        private static int CountNotesInView(ModelDoc2 model, ViewInfo viewInfo)
        {
            return CountFilteredNotesInView(model, viewInfo, logObjects: false);
        }

        private static int CountAnnotationsInView(ModelDoc2 model, ViewInfo viewInfo)
        {
            View view = viewInfo.View;
            int count = 0;

            count += CountAndLogObjects(model, view, "标注:焊缝bead", () => view.GetWeldBeads(), () => view.GetWeldBeadCount());
            count += CountFilteredNotesInView(model, viewInfo, logObjects: true);

            count += CountAndLogObjects(model, view, "标注:基准标签", () => view.GetDatumTags(), () => view.GetDatumTagCount());
            count += CountAndLogObjects(model, view, "标注:基准目标", () => view.GetDatumTargetSyms(), () => view.GetDatumTargetSymCount());
            count += CountAndLogObjects(model, view, "标注:焊接符号", () => view.GetWeldSymbols(), () => view.GetWeldSymbolCount());
            count += CountAndLogObjects(model, view, "标注:几何公差", () => view.GetGTols(), () => view.GetGTolCount());
            count += CountAndLogObjects(model, view, "标注:中心线", () => view.GetCenterLines(), () => view.GetCenterLineCount());
            count += CountAndLogObjects(model, view, "标注:中心标记", () => view.GetCenterMarks(), () => CountCenterMarksInView(view));
            count += CountAndLogObjects(model, view, "标注:表面粗糙度", () => view.GetSFSymbols(), () => view.GetSFSymbolCount());
            count += CountAndLogObjects(model, view, "标注:修订云线", () => view.GetRevisionClouds(), () => view.GetRevisionCloudCount());
            count += CountAndLogObjects(model, view, "标注:销钉符号", () => view.GetDowelSymbols(), () => view.GetDowelSymbolCount());
            count += CountAndLogObjects(model, view, "标注:可见尺寸", () => view.GetDisplayDimensions(), () => CountDimensionsInView(view));

            return count;
        }

        private static int CountFilteredNotesInView(ModelDoc2 model, ViewInfo viewInfo, bool logObjects)
        {
            try
            {
                object notesObj = viewInfo.View.GetNotes();
                if (notesObj is not Array notes)
                {
                    return 0;
                }

                int count = 0;
                foreach (object note in notes)
                {
                    if (!ShouldCountNote(note))
                    {
                        continue;
                    }

                    count++;
                    if (logObjects)
                    {
                        AnalysisTraceLogger.Write(model, "标注:普通注释", GetObjectName(note, $"普通注释 {count}"), GetNoteTraceDetail(note, viewInfo.View));
                    }
                }

                return count;
            }
            catch
            {
                return 0;
            }
        }

        private static bool ShouldCountNote(object note)
        {
            object annotation = GetAnnotation(note);
            if (note == null ||
                annotation == null ||
                !IsAnnotationVisible(annotation) ||
                !IsEditableDrawingNote(annotation, note) ||
                IsBomBalloon(note))
            {
                return false;
            }

            string propertyLinkedText = GetPropertyLinkedText(note);
            if (IsPropertyLinkedOrSystemNote(propertyLinkedText))
            {
                return false;
            }

            string text = GetNoteText(note);
            if (string.IsNullOrWhiteSpace(text))
            {
                return false;
            }

            return !IsPropertyLinkedOrSystemNote(text);
        }

        private static bool IsAnnotationVisible(object value)
        {
            try
            {
                dynamic dynAnnotation = value;
                return dynAnnotation.Visible == true;
            }
            catch
            {
                return true;
            }
        }

        private static object GetAnnotation(object value)
        {
            try
            {
                dynamic dynValue = value;
                return dynValue.GetAnnotation();
            }
            catch
            {
                return null;
            }
        }

        private static bool IsEditableDrawingNote(object annotation, object note)
        {
            if (!HasEditableDrawingOwner(annotation))
            {
                return false;
            }

            if (IsBehindSheet(note) || IsPositionLocked(note))
            {
                return false;
            }

            return true;
        }

        private static bool HasEditableDrawingOwner(object annotation)
        {
            try
            {
                dynamic dynAnnotation = annotation;
                int ownerType = dynAnnotation.OwnerType;
                return ownerType == (int)swAnnotationOwner_e.swAnnotationOwner_DrawingView ||
                    ownerType == (int)swAnnotationOwner_e.swAnnotationOwner_DrawingSheet;
            }
            catch
            {
                return false;
            }
        }

        private static bool IsBehindSheet(object note)
        {
            try
            {
                dynamic dynNote = note;
                return dynNote.BehindSheet == true;
            }
            catch
            {
                return false;
            }
        }

        private static bool IsPositionLocked(object note)
        {
            try
            {
                dynamic dynNote = note;
                return dynNote.LockPosition == true;
            }
            catch
            {
                return false;
            }
        }

        private static string GetNoteText(object note)
        {
            try
            {
                dynamic dynNote = note;
                string text = dynNote.GetText();
                if (!string.IsNullOrWhiteSpace(text))
                {
                    return text;
                }
            }
            catch
            {
            }

            try
            {
                dynamic dynNote = note;
                int textCount = dynNote.GetTextCount();
                var parts = new List<string>();
                for (int i = 0; i < textCount; i++)
                {
                    string text = dynNote.GetTextAtIndex(i);
                    if (!string.IsNullOrWhiteSpace(text))
                    {
                        parts.Add(text);
                    }
                }

                return string.Join(" ", parts);
            }
            catch
            {
                return string.Empty;
            }
        }

        private static bool IsBomBalloon(object note)
        {
            try
            {
                dynamic dynNote = note;
                return dynNote.IsBomBalloon() == true;
            }
            catch
            {
                return false;
            }
        }

        private static string GetPropertyLinkedText(object note)
        {
            try
            {
                dynamic dynNote = note;
                string text = dynNote.PropertyLinkedText;
                if (!string.IsNullOrWhiteSpace(text))
                {
                    return text;
                }
            }
            catch
            {
            }

            try
            {
                dynamic dynNote = note;
                string text = dynNote.GetPropertyLinkedText();
                return text ?? string.Empty;
            }
            catch
            {
                return string.Empty;
            }
        }

        private static bool IsPropertyLinkedOrSystemNote(string text)
        {
            if (string.IsNullOrWhiteSpace(text))
            {
                return false;
            }

            string normalized = text.Trim();
            return normalized.StartsWith("$PRP", StringComparison.OrdinalIgnoreCase) ||
                normalized.StartsWith("$PRPSHEET", StringComparison.OrdinalIgnoreCase) ||
                normalized.StartsWith("$PRPVIEW", StringComparison.OrdinalIgnoreCase) ||
                normalized.StartsWith("SW-", StringComparison.OrdinalIgnoreCase);
        }

        private static string GetNoteTraceDetail(object note, View view)
        {
            object annotation = GetAnnotation(note);
            return $"{GetViewName(view)}; OwnerType={GetAnnotationOwnerType(annotation)}; Layer={GetAnnotationLayer(annotation)}";
        }

        private static string GetAnnotationOwnerType(object annotation)
        {
            try
            {
                dynamic dynAnnotation = annotation;
                int ownerType = dynAnnotation.OwnerType;
                return ((swAnnotationOwner_e)ownerType).ToString();
            }
            catch
            {
                return "Unknown";
            }
        }

        private static string GetAnnotationLayer(object annotation)
        {
            try
            {
                dynamic dynAnnotation = annotation;
                string layer = dynAnnotation.Layer;
                return string.IsNullOrWhiteSpace(layer) ? "(none)" : layer;
            }
            catch
            {
                return "Unknown";
            }
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

        private static int CountTablesInView(ModelDoc2 model, View view)
        {
            try
            {
                object tablesObj = view.GetTableAnnotations();
                if (tablesObj is Array tables)
                {
                    for (int i = 0; i < tables.Length; i++)
                    {
                        AnalysisTraceLogger.Write(model, "表格", GetObjectName(tables.GetValue(i), $"Table {i + 1}"), GetViewName(view));
                    }

                    return tables.Length;
                }
            }
            catch
            {
            }

            try
            {
                int tableAnnotationCount = view.GetTableAnnotationCount();
                if (tableAnnotationCount >= 0)
                {
                    for (int i = 0; i < tableAnnotationCount; i++)
                    {
                        AnalysisTraceLogger.Write(model, "表格", $"Table {i + 1}", GetViewName(view));
                    }

                    return tableAnnotationCount;
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
                    AnalysisTraceLogger.Write(model, "表格", GetObjectName(table, $"Table {count}"), GetViewName(view));
                    table = table.GetNext();
                }
            }
            catch
            {
            }

            return count;
        }

        private static int CountAndLogObjects(ModelDoc2 model, View view, string objectType, Func<object> objectsProvider, Func<int> countProvider)
        {
            try
            {
                object objectsObj = objectsProvider();
                if (objectsObj is Array objects)
                {
                    for (int i = 0; i < objects.Length; i++)
                    {
                        AnalysisTraceLogger.Write(model, objectType, GetObjectName(objects.GetValue(i), $"{objectType} {i + 1}"), GetViewName(view));
                    }

                    return objects.Length;
                }
            }
            catch
            {
            }

            int count = SafeCount(countProvider);
            for (int i = 0; i < count; i++)
            {
                AnalysisTraceLogger.Write(model, objectType, $"{objectType} {i + 1}", GetViewName(view));
            }

            return count;
        }

        private static string GetObjectName(object value, string fallback)
        {
            try
            {
                dynamic dynValue = value;
                object annotationObj = dynValue.GetAnnotation();
                string annotationName = AnalysisTraceLogger.GetObjectName(annotationObj, null);
                if (!string.IsNullOrWhiteSpace(annotationName))
                {
                    return annotationName;
                }
            }
            catch
            {
            }

            return AnalysisTraceLogger.GetObjectName(value, fallback);
        }

        private static string GetViewName(View view)
        {
            return AnalysisTraceLogger.GetObjectName(view, "View");
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
