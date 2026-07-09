using SolidWorks.Interop.sldworks;
using System.Linq;

namespace IPXQuoteTool.Analysis.Parts
{
    internal static class PartFeatureCounter
    {
        public static int CountFeatures(ModelDoc2 model)
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
                "datumcurve", "curve", "modeldocannotation"
            };

            return ignoredTypes.Any(t => lowerTypeName.Contains(t));
        }
    }
}
