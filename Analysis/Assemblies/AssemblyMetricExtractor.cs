using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using System;
using System.Collections.Generic;
using System.Linq;

namespace IPXQuoteTool.Analysis.Assemblies
{
    public class AssemblyMetricExtractor : IDocumentMetricExtractor
    {
        private static readonly HashSet<string> AssemblyFeatureTypeWhitelist = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
        {
            "LocalChainPattern",
            "LocalCirPattern",
            "LocalCurvePattern",
            "LocalLPattern",
            "LocalSketchPattern",
            "DerivedCirPattern",
            "DerivedLPattern",
            "DerivedHolePattern",
            "FtrFolder",
            "Chamfer",
            "HoleSeries",
            "Fillet",
            "BossThin",
            "HoleWzd",
            "SweepCut",
            "MirrorPattern",
            "MirrorSolid",
            "MirrorStock",
            "MirrorCompFeat"
        };

        public swDocumentTypes_e SupportedDocumentType => swDocumentTypes_e.swDocASSEMBLY;

        public void Extract(DocumentAnalysisContext context, DocumentInfo info)
        {
            info.ComponentCount = CountTopLevelComponentFeatures(context.Model);
            info.MateCount = CountMates(context.Model);
            info.AssemblyFeatureCount = CountAssemblyFeatures(context.Model);
            info.ExpressionCount = SolidWorksEquationCounter.CountEquations(context.Model);
        }

        private static int CountTopLevelComponentFeatures(ModelDoc2 model)
        {
            int count = 0;

            try
            {
                Feature feature = (Feature)model.FirstFeature();
                while (feature != null)
                {
                    Component2 component = TryGetComponentFromFeature(feature);
                    if (component != null && !IsIgnoredComponentFeature(feature, component))
                    {
                        count++;
                    }

                    feature = (Feature)feature.GetNextFeature();
                }
            }
            catch
            {
            }

            return count;
        }

        private static Component2 TryGetComponentFromFeature(Feature feature)
        {
            if (feature == null)
            {
                return null;
            }

            try
            {
                object specificFeature = feature.GetSpecificFeature2() ?? feature.GetSpecificFeature();
                return specificFeature as Component2;
            }
            catch
            {
                try
                {
                    return feature.GetSpecificFeature() as Component2;
                }
                catch
                {
                    return null;
                }
            }
        }

        private static bool IsIgnoredComponentFeature(Feature feature, Component2 component)
        {
            try
            {
                if (feature.IsSuppressed() || component.IsSuppressed())
                {
                    return true;
                }
            }
            catch
            {
            }

            try
            {
                if (component.IsPatternInstance())
                {
                    return true;
                }
            }
            catch
            {
            }

            return false;
        }

        private static int CountMates(ModelDoc2 model)
        {
            try
            {
                int mateGroupCount = CountMatesFromMateGroup(model);
                if (mateGroupCount >= 0)
                {
                    return mateGroupCount;
                }

                dynamic assemblyDoc = model;
                int mateListCount = CountMatesFromList(assemblyDoc);
                if (mateListCount >= 0)
                {
                    return mateListCount;
                }

                try
                {
                    return (int)assemblyDoc.GetMatesCount();
                }
                catch
                {
                    return 0;
                }
            }
            catch
            {
                return 0;
            }
        }

        private static int CountMatesFromMateGroup(ModelDoc2 model)
        {
            try
            {
                Feature feature = (Feature)model.FirstFeature();
                while (feature != null)
                {
                    if (IsMateGroupFeature(feature))
                    {
                        return CountMateSubFeatures(feature);
                    }

                    feature = (Feature)feature.GetNextFeature();
                }
            }
            catch
            {
            }

            return -1;
        }

        private static bool IsMateGroupFeature(Feature feature)
        {
            string typeName = GetFeatureTypeName(feature);
            if (!string.IsNullOrWhiteSpace(typeName) &&
                typeName.IndexOf("MateGroup", StringComparison.OrdinalIgnoreCase) >= 0)
            {
                return true;
            }

            try
            {
                string name = feature.Name;
                return !string.IsNullOrWhiteSpace(name) &&
                       (name.Equals("Mates", StringComparison.OrdinalIgnoreCase) ||
                        name.Equals("配合", StringComparison.OrdinalIgnoreCase));
            }
            catch
            {
                return false;
            }
        }

        private static int CountMateSubFeatures(Feature mateGroupFeature)
        {
            int count = 0;

            try
            {
                Feature subFeature = (Feature)mateGroupFeature.GetFirstSubFeature();
                while (subFeature != null)
                {
                    count += CountMateFeatureRecursive(subFeature);
                    subFeature = (Feature)subFeature.GetNextSubFeature();
                }
            }
            catch
            {
            }

            return count;
        }

        private static int CountMateFeatureRecursive(Feature feature)
        {
            int count = IsMateFeature(feature) ? 1 : 0;

            try
            {
                Feature subFeature = (Feature)feature.GetFirstSubFeature();
                while (subFeature != null)
                {
                    count += CountMateFeatureRecursive(subFeature);
                    subFeature = (Feature)subFeature.GetNextSubFeature();
                }
            }
            catch
            {
            }

            return count;
        }

        private static bool IsMateFeature(Feature feature)
        {
            if (feature == null)
            {
                return false;
            }

            try
            {
                if (feature.IsSuppressed())
                {
                    return false;
                }
            }
            catch
            {
            }

            try
            {
                object specificFeature = feature.GetSpecificFeature2() ?? feature.GetSpecificFeature();
                if (specificFeature is Mate2)
                {
                    return true;
                }
            }
            catch
            {
            }

            string typeName = GetFeatureTypeName(feature);
            return !string.IsNullOrWhiteSpace(typeName) &&
                   typeName.IndexOf("Mate", StringComparison.OrdinalIgnoreCase) >= 0 &&
                   typeName.IndexOf("MateGroup", StringComparison.OrdinalIgnoreCase) < 0;
        }

        private static int CountMatesFromList(dynamic assemblyDoc)
        {
            foreach (bool includeHidden in new[] { true, false })
            {
                try
                {
                    int count = CountVariantItems(assemblyDoc.GetMates(includeHidden));
                    if (count >= 0)
                    {
                        return count;
                    }
                }
                catch
                {
                }
            }

            try
            {
                int count = CountVariantItems(assemblyDoc.GetMates());
                if (count >= 0)
                {
                    return count;
                }
            }
            catch
            {
            }

            return -1;
        }

        private static int CountVariantItems(object value)
        {
            if (value is Array array)
            {
                return array.Length;
            }

            return value == null ? -1 : -1;
        }

        private static string GetFeatureTypeName(Feature feature)
        {
            if (feature == null)
            {
                return string.Empty;
            }

            try
            {
                return feature.GetTypeName2();
            }
            catch
            {
                try
                {
                    return feature.GetTypeName();
                }
                catch
                {
                    return string.Empty;
                }
            }
        }

        private static int CountAssemblyFeatures(ModelDoc2 model)
        {
            int count = 0;

            try
            {
                Feature feat = (Feature)model.FirstFeature();
                while (feat != null)
                {
                    string typeName = GetFeatureTypeName(feat);
                    if (AssemblyFeatureTypeWhitelist.Contains(typeName))
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
    }
}
