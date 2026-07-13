using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using System.Linq;

namespace IPXQuoteTool.Analysis.Parts
{
    internal static class PartFeatureCounter
    {
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
                    string typeName = feat.GetTypeName();
                    if (!IsIgnoredFeature(typeName))
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

        private static bool IsIgnoredFeature(string typeName)
        {
            if (string.IsNullOrEmpty(typeName))
            {
                return true;
            }

            string lowerTypeName = typeName.ToLower();
            string[] ignoredTypes =
            {
                "refplane", "refaxis", "coordinatesystem",
                "sketch", "note", "material", "folder",
                "sensor", "light", "origin", "displaystate",
                "solidbodyfolder", "surfacebodyfolder",
                "datumcurve", "curve", "modeldocannotation", "detailcabinet", "profilefeature"
            };

            return ignoredTypes.Any(t => lowerTypeName.Contains(t));
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
