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
            count += CountCenterAnnotationsInView(model, view);
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

        private static int CountCenterAnnotationsInView(ModelDoc2 model, View view)
        {
            var items = new Dictionary<string, CenterAnnotationInfo>(StringComparer.OrdinalIgnoreCase);

            AddCenterAnnotationsFromAnnotationChain(items, view);
            AddCenterObjects(items, "标注:中心线", GetCenterLineObjects(view), "View");
            AddCenterObjects(items, "标注:中心标记", GetCenterMarkObjects(view), "View");
            AddCenterMarksFromFeatureChain(items, view);

            AddMissingCenterPlaceholders(items, "标注:中心线", SafeCount(() => view.GetCenterLineCount()), "ViewCount");
            AddMissingCenterPlaceholders(items, "标注:中心标记", CountCenterMarksInView(view), "ViewCount");

            foreach (CenterAnnotationInfo item in items.Values)
            {
                AnalysisTraceLogger.Write(model, item.ObjectType, item.ObjectName, $"{GetViewName(view)}; {item.Source}");
            }

            return items.Count;
        }

        private static void AddCenterAnnotationsFromAnnotationChain(Dictionary<string, CenterAnnotationInfo> items, View view)
        {
            try
            {
                object annotationObj = GetFirstAnnotation(view);
                while (annotationObj != null)
                {
                    if (IsCenterAnnotation(annotationObj, out string objectType))
                    {
                        AddCenterObject(items, objectType, annotationObj, "AnnotationChain");
                    }

                    annotationObj = GetNextAnnotation(annotationObj);
                }
            }
            catch
            {
            }
        }

        private static void AddCenterMarksFromFeatureChain(Dictionary<string, CenterAnnotationInfo> items, View view)
        {
            try
            {
                object centerMark = GetFirstCenterMark(view);
                while (centerMark != null)
                {
                    AddCenterObject(items, "标注:中心标记", centerMark, "CenterMarkChain");
                    centerMark = GetNextCenterMark(centerMark);
                }
            }
            catch
            {
            }
        }

        private static void AddCenterObjects(Dictionary<string, CenterAnnotationInfo> items, string objectType, IReadOnlyList<object> objects, string source)
        {
            foreach (object item in objects)
            {
                AddCenterObject(items, objectType, item, source);
            }
        }

        private static void AddCenterObject(Dictionary<string, CenterAnnotationInfo> items, string objectType, object value, string source)
        {
            if (value == null)
            {
                return;
            }

            string objectName = GetObjectName(value, null);
            if (string.IsNullOrWhiteSpace(objectName))
            {
                objectName = GetAnnotationName(value);
            }

            if (string.IsNullOrWhiteSpace(objectName))
            {
                objectName = $"{objectType} {GetCenterTypeCount(items, objectType) + 1}";
            }

            string key = $"{objectType}:{objectName}";
            if (!items.ContainsKey(key))
            {
                items.Add(key, new CenterAnnotationInfo(objectType, objectName, source));
            }
        }

        private static void AddMissingCenterPlaceholders(Dictionary<string, CenterAnnotationInfo> items, string objectType, int totalCount, string source)
        {
            int existingCount = GetCenterTypeCount(items, objectType);
            for (int i = existingCount; i < totalCount; i++)
            {
                string objectName = $"{objectType} {i + 1}";
                items[$"{objectType}:{objectName}"] = new CenterAnnotationInfo(objectType, objectName, source);
            }
        }

        private static int GetCenterTypeCount(Dictionary<string, CenterAnnotationInfo> items, string objectType)
        {
            return items.Values.Count(item => item.ObjectType == objectType);
        }

        private static int CountCenterAnnotationsFromAnnotationChain(ModelDoc2 model, View view)
        {
            int count = 0;

            try
            {
                object annotationObj = GetFirstAnnotation(view);
                while (annotationObj != null)
                {
                    if (IsCenterAnnotation(annotationObj, out string objectType))
                    {
                        count++;
                        AnalysisTraceLogger.Write(model, objectType, GetObjectName(annotationObj, $"{objectType} {count}"), $"{GetViewName(view)}; AnnotationChain");
                    }

                    annotationObj = GetNextAnnotation(annotationObj);
                }
            }
            catch
            {
            }

            return count;
        }

        private static object GetFirstAnnotation(View view)
        {
            try
            {
                dynamic dynView = view;
                return dynView.GetFirstAnnotation3();
            }
            catch
            {
            }

            try
            {
                dynamic dynView = view;
                return dynView.GetFirstAnnotation2();
            }
            catch
            {
            }

            try
            {
                dynamic dynView = view;
                return dynView.GetFirstAnnotation();
            }
            catch
            {
                return null;
            }
        }

        private static object GetNextAnnotation(object annotation)
        {
            try
            {
                dynamic dynAnnotation = annotation;
                return dynAnnotation.GetNext3();
            }
            catch
            {
            }

            try
            {
                dynamic dynAnnotation = annotation;
                return dynAnnotation.GetNext2();
            }
            catch
            {
            }

            try
            {
                dynamic dynAnnotation = annotation;
                return dynAnnotation.GetNext();
            }
            catch
            {
                return null;
            }
        }

        private static bool IsCenterAnnotation(object annotation, out string objectType)
        {
            int annotationType = GetAnnotationType(annotation);
            if (annotationType == (int)swAnnotationType_e.swCenterLine)
            {
                objectType = "标注:中心线";
                return true;
            }

            if (annotationType == (int)swAnnotationType_e.swCenterMarkSym)
            {
                objectType = "标注:中心标记";
                return true;
            }

            object specificAnnotation = GetSpecificAnnotation(annotation);
            string specificTypeName = specificAnnotation?.GetType().FullName ?? string.Empty;
            if (specificTypeName.IndexOf("Centerline", StringComparison.OrdinalIgnoreCase) >= 0 ||
                specificTypeName.IndexOf("CenterLine", StringComparison.OrdinalIgnoreCase) >= 0)
            {
                objectType = "标注:中心线";
                return true;
            }

            if (specificTypeName.IndexOf("CenterMark", StringComparison.OrdinalIgnoreCase) >= 0)
            {
                objectType = "标注:中心标记";
                return true;
            }

            objectType = null;
            return false;
        }

        private static int GetAnnotationType(object annotation)
        {
            try
            {
                Annotation typedAnnotation = (Annotation)annotation;
                object type = typedAnnotation.GetType();
                if (type is int intType)
                {
                    return intType;
                }
            }
            catch
            {
            }

            try
            {
                dynamic dynAnnotation = annotation;
                object type = dynAnnotation.GetType();
                if (type is int intType)
                {
                    return intType;
                }
            }
            catch
            {
            }

            return 0;
        }

        private static object GetSpecificAnnotation(object annotation)
        {
            try
            {
                dynamic dynAnnotation = annotation;
                return dynAnnotation.GetSpecificAnnotation();
            }
            catch
            {
                return null;
            }
        }

        private static int CountCenterLinesInView(ModelDoc2 model, View view)
        {
            int loggedCount = 0;
            int arrayCount = CountAndLogCenterObjects(model, view, "标注:中心线", GetCenterLineObjects(view), ref loggedCount);
            int countProviderCount = SafeCount(() => view.GetCenterLineCount());

            int count = Math.Max(arrayCount, countProviderCount);
            LogMissingCenterObjects(model, view, "标注:中心线", loggedCount, count);
            return count;
        }

        private static int CountCenterMarksInView(ModelDoc2 model, View view)
        {
            int loggedCount = 0;
            int arrayCount = CountAndLogCenterObjects(model, view, "标注:中心标记", GetCenterMarkObjects(view), ref loggedCount);
            int countProviderCount = CountCenterMarksInView(view);

            int count = Math.Max(arrayCount, countProviderCount);
            LogMissingCenterObjects(model, view, "标注:中心标记", loggedCount, count);
            return count;
        }

        private static int CountCenterMarksFromFeatureChain(ModelDoc2 model, View view)
        {
            int count = 0;

            try
            {
                object centerMark = GetFirstCenterMark(view);
                while (centerMark != null)
                {
                    count++;
                    AnalysisTraceLogger.Write(model, "标注:中心标记", GetObjectName(centerMark, $"标注:中心标记 {count}"), $"{GetViewName(view)}; CenterMarkChain");
                    centerMark = GetNextCenterMark(centerMark);
                }
            }
            catch
            {
            }

            return count;
        }

        private static object GetFirstCenterMark(View view)
        {
            try
            {
                dynamic dynView = view;
                return dynView.GetFirstCenterMark();
            }
            catch
            {
            }

            try
            {
                dynamic dynView = view;
                return dynView.IGetFirstCenterMark();
            }
            catch
            {
                return null;
            }
        }

        private static object GetNextCenterMark(object centerMark)
        {
            try
            {
                dynamic dynCenterMark = centerMark;
                return dynCenterMark.GetNext();
            }
            catch
            {
            }

            try
            {
                dynamic dynCenterMark = centerMark;
                return dynCenterMark.IGetNext();
            }
            catch
            {
                return null;
            }
        }

        private static IReadOnlyList<object> GetCenterLineObjects(View view)
        {
            var objects = new List<object>();
            AddObjects(objects, () => view.GetCenterLines());
            AddObjects(objects, () =>
            {
                dynamic dynView = view;
                return dynView.GetCenterLines2();
            });
            return objects;
        }

        private static IReadOnlyList<object> GetCenterMarkObjects(View view)
        {
            var objects = new List<object>();
            AddObjects(objects, () => view.GetCenterMarks());
            AddObjects(objects, () =>
            {
                dynamic dynView = view;
                return dynView.GetCenterMarks2();
            });
            AddObjects(objects, () =>
            {
                dynamic dynView = view;
                return dynView.GetCenterMarkSymbols();
            });
            AddObjects(objects, () =>
            {
                dynamic dynView = view;
                return dynView.GetCenterMarkSymbols2();
            });
            return objects;
        }

        private static void AddObjects(List<object> target, Func<object> objectsProvider)
        {
            try
            {
                object objectsObj = objectsProvider();
                if (objectsObj is not Array objects)
                {
                    return;
                }

                foreach (object item in objects)
                {
                    if (item != null)
                    {
                        target.Add(item);
                    }
                }
            }
            catch
            {
            }
        }

        private static int CountAndLogCenterObjects(ModelDoc2 model, View view, string objectType, IReadOnlyList<object> objects, ref int loggedCount)
        {
            if (objects.Count == 0)
            {
                return 0;
            }

            var keys = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            int count = 0;

            foreach (object item in objects)
            {
                string key = GetCenterObjectKey(item, count);
                if (!keys.Add(key))
                {
                    continue;
                }

                count++;
                loggedCount++;
                AnalysisTraceLogger.Write(model, objectType, GetObjectName(item, $"{objectType} {count}"), GetViewName(view));
            }

            return count;
        }

        private static string GetCenterObjectKey(object value, int index)
        {
            string name = GetObjectName(value, null);
            if (!string.IsNullOrWhiteSpace(name))
            {
                return name;
            }

            string annotationName = GetAnnotationName(value);
            if (!string.IsNullOrWhiteSpace(annotationName))
            {
                return annotationName;
            }

            return $"{value.GetType().FullName}:{index}";
        }

        private static string GetAnnotationName(object value)
        {
            try
            {
                dynamic dynValue = value;
                object annotationObj = dynValue.GetAnnotation();
                return AnalysisTraceLogger.GetObjectName(annotationObj, null);
            }
            catch
            {
                return null;
            }
        }

        private static void LogMissingCenterObjects(ModelDoc2 model, View view, string objectType, int loggedCount, int totalCount)
        {
            for (int i = loggedCount; i < totalCount; i++)
            {
                AnalysisTraceLogger.Write(model, objectType, $"{objectType} {i + 1}", GetViewName(view));
            }
        }

        private static int CountCenterMarksInView(View view)
        {
            try
            {
                int count = view.GetCenterMarkCount();
                if (count >= 0)
                {
                    return count;
                }
            }
            catch
            {
            }

            int maxCount = 0;

            try
            {
                int size = 0;
                maxCount = Math.Max(maxCount, view.GetCenterMarkCount2(ref size));
            }
            catch
            {
            }

            try
            {
                dynamic dynView = view;
                int count = dynView.GetCenterMarkSymbolCount();
                maxCount = Math.Max(maxCount, count);
            }
            catch
            {
            }

            try
            {
                dynamic dynView = view;
                int count = dynView.GetCenterMarkSymbolCount2();
                maxCount = Math.Max(maxCount, count);
            }
            catch
            {
            }

            return maxCount;
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

        private class CenterAnnotationInfo
        {
            public CenterAnnotationInfo(string objectType, string objectName, string source)
            {
                ObjectType = objectType;
                ObjectName = objectName;
                Source = source;
            }

            public string ObjectType { get; }
            public string ObjectName { get; }
            public string Source { get; }
        }
    }
}
