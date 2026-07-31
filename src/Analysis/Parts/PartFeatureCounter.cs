using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using System.Linq;

namespace IPXQuoteTool.Analysis.Parts
{
    internal static class PartFeatureCounter
    {
        private static readonly string[] StaticFeatureTypes =
        {
            // Reference geometry and sketch containers
            "3DProfileFeature",
            "3DSplineCurve",
            "CompositeCurve",
            "CoordSys",
            "CoordinateSystem",
            "CurveInFile",
            "DatumCurve",
            "LayoutProfileFeature",
            "Origin",
            "OriginProfileFeature",
            "PLine",
            "ProfileFeature",
            "RefAxis",
            "RefCurve",
            "RefPlane",
            "RefPoint",
            "RefSurface",
            "ReferenceCurve",
            "SketchBlockDef",
            "SketchBitmap",

            // Body/import placeholders and generated static containers
            "BaseBody",
            "Imported",
            "Stock",
            "ViewerBodyFeature",

            // Metadata, display, configuration, annotation, and system nodes
            "Attribute",
            "BlockDef",
            "Comments",
            "ConfigBuilderFeature",
            "Configuration",
            "DesignTableFeature",
            "DetailCabinet",
            "DisplayState",
            "EmbedLinkDoc",
            "GridFeature",
            "Journal",
            "Material",
            "ModelDocAnnotation",
            "PartConfiguration",
            "ReferenceBrowser",
            "ReferenceEmbedded",
            "ReferenceInternal",
            "Sensor",
            "XMLRulesFeature",

            // Cosmetic/display-only items
            "AmbientLight",
            "CameraFeature",
            "CosmeticThread",
            "DirectionLight",
            "GroundPlane",
            "PointLight",
            "SpotLight"
        };

        public static int CountFeatures(ModelDoc2 model)
        {
            return CountFeatures(model, swDocumentTypes_e.swDocPART, SafeModelPath(model), "特征");
        }

        public static int CountFeatures(ModelDoc2 model, swDocumentTypes_e traceDocumentType, string traceDocumentPath, string traceObjectType)
        {
            int count = 0;

            try
            {
                Feature feat = (Feature)model.FirstFeature();
                while (feat != null)
                {
                    string typeName = GetFeatureTypeName(feat);
                    if (!IsIgnoredFeature(feat))
                    {
                        count++;
                        AnalysisTraceLogger.Write(
                            traceDocumentType,
                            traceDocumentPath,
                            traceObjectType,
                            AnalysisTraceLogger.GetObjectName(feat, $"Feature {count}"),
                            typeName);
                    }

                    feat = (Feature)feat.GetNextFeature();
                }
            }
            catch
            {
            }

            return count;
        }

        private static bool IsIgnoredFeature(Feature feature)
        {
            string typeName = GetFeatureTypeName(feature);
            string typeName2 = GetFeatureTypeName2(feature);
            string featureName = AnalysisTraceLogger.GetObjectName(feature, string.Empty);

            if (string.IsNullOrEmpty(typeName) && string.IsNullOrEmpty(typeName2))
            {
                return true;
            }

            if (IsStaticFeatureType(typeName) || IsStaticFeatureType(typeName2))
            {
                return true;
            }

            return ContainsImportedFeatureText(featureName) ||
                   ContainsImportedFeatureText(typeName) ||
                   ContainsImportedFeatureText(typeName2);
        }

        private static bool IsStaticFeatureType(string typeName)
        {
            if (string.IsNullOrWhiteSpace(typeName))
            {
                return false;
            }

            if (typeName.EndsWith("Folder", System.StringComparison.OrdinalIgnoreCase))
            {
                return true;
            }

            return StaticFeatureTypes.Any(t => typeName.Equals(t, System.StringComparison.OrdinalIgnoreCase));
        }

        private static bool ContainsImportedFeatureText(string text)
        {
            if (string.IsNullOrWhiteSpace(text))
            {
                return false;
            }

            string normalizedText = text.Trim();
            return normalizedText.IndexOf("Import", System.StringComparison.OrdinalIgnoreCase) >= 0 ||
                   normalizedText.IndexOf("输入", System.StringComparison.OrdinalIgnoreCase) >= 0;
        }

        private static string GetFeatureTypeName(Feature feature)
        {
            try
            {
                return feature?.GetTypeName() ?? string.Empty;
            }
            catch
            {
                return string.Empty;
            }
        }

        private static string GetFeatureTypeName2(Feature feature)
        {
            try
            {
                return feature?.GetTypeName2() ?? string.Empty;
            }
            catch
            {
                return string.Empty;
            }
        }

        private static string SafeModelPath(ModelDoc2 model)
        {
            try
            {
                return model?.GetPathName() ?? string.Empty;
            }
            catch
            {
                return string.Empty;
            }
        }
    }
}
