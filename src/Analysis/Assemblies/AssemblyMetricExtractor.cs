using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using IPXQuoteTool.Analysis.Parts;
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
            var components = GetTopLevelComponentsFromFeatures(model);

            for (int i = 0; i < components.Count; i++)
            {
                Component2 component = components[i];
                AnalysisTraceLogger.Write(
                    model,
                    "组件数",
                    AnalysisTraceLogger.GetObjectName(component, $"Component {i + 1}"),
                    IsVirtualComponent(component) ? "虚拟组件" : SafeComponentPath(component));
            }

            return components.Count;
        }

        private static List<Component2> GetTopLevelComponentsFromFeatures(ModelDoc2 model)
        {
            var components = new List<Component2>();

            try
            {
                Feature feature = (Feature)model.FirstFeature();
                while (feature != null)
                {
                    Component2 component = TryGetComponentFromFeature(feature);
                    if (component != null && !IsIgnoredComponentFeature(feature, component))
                    {
                        components.Add(component);
                    }

                    feature = (Feature)feature.GetNextFeature();
                }
            }
            catch
            {
            }

            return components;
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

        private static bool IsVirtualComponent(Component2 component)
        {
            try
            {
                return component?.IsVirtual == true;
            }
            catch
            {
                return false;
            }
        }

        private static string SafeComponentPath(Component2 component)
        {
            try
            {
                return component?.GetPathName() ?? string.Empty;
            }
            catch
            {
                return string.Empty;
            }
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
                        return CountMateSubFeatures(model, feature);
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

        private static int CountMateSubFeatures(ModelDoc2 model, Feature mateGroupFeature)
        {
            int count = 0;

            try
            {
                Feature subFeature = (Feature)mateGroupFeature.GetFirstSubFeature();
                while (subFeature != null)
                {
                    count += CountMateFeatureRecursive(model, subFeature);
                    subFeature = (Feature)subFeature.GetNextSubFeature();
                }
            }
            catch
            {
            }

            return count;
        }

        private static int CountMateFeatureRecursive(ModelDoc2 model, Feature feature)
        {
            int count = 0;
            if (IsMateFeature(feature))
            {
                count++;
                AnalysisTraceLogger.Write(
                    model,
                    "装配约束",
                    AnalysisTraceLogger.GetObjectName(feature, $"Mate {count}"),
                    GetFeatureTypeName(feature));
            }

            try
            {
                Feature subFeature = (Feature)feature.GetFirstSubFeature();
                while (subFeature != null)
                {
                    count += CountMateFeatureRecursive(model, subFeature);
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
            int count = CountVirtualComponentPartFeatures(model);

            try
            {
                Feature feat = (Feature)model.FirstFeature();
                while (feat != null)
                {
                    string typeName = GetFeatureTypeName(feat);
                    if (AssemblyFeatureTypeWhitelist.Contains(typeName))
                    {
                        count++;
                        AnalysisTraceLogger.Write(
                            model,
                            "装配特征",
                            AnalysisTraceLogger.GetObjectName(feat, $"AssemblyFeature {count}"),
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

        private static int CountVirtualComponentPartFeatures(ModelDoc2 assemblyModel)
        {
            int count = 0;

            foreach (Component2 component in GetTopLevelComponentsFromFeatures(assemblyModel))
            {
                if (!IsVirtualComponent(component))
                {
                    continue;
                }

                try
                {
                        count += CountVirtualPartFeatures(assemblyModel, component);
                }
                catch
                {
                }
            }

            return count;
        }

        private static int CountVirtualPartFeatures(ModelDoc2 assemblyModel, Component2 component)
        {
            ModelDoc2 componentModel = GetComponentModel(component);
            if (componentModel == null || (swDocumentTypes_e)componentModel.GetType() != swDocumentTypes_e.swDocPART)
            {
                return 0;
            }

            return PartFeatureCounter.CountFeatures(
                componentModel,
                swDocumentTypes_e.swDocASSEMBLY,
                SafeModelPath(assemblyModel),
                $"虚拟组件零件特征:{AnalysisTraceLogger.GetObjectName(component, "VirtualComponent")}");
        }

        private static ModelDoc2 GetComponentModel(Component2 component)
        {
            if (component == null)
            {
                return null;
            }

            try
            {
                if (component.GetModelDoc2() is ModelDoc2 model)
                {
                    return model;
                }
            }
            catch
            {
            }

            try
            {
                if (component.IGetModelDoc() is ModelDoc2 model)
                {
                    return model;
                }
            }
            catch
            {
            }

            try
            {
                return component.GetModelDoc() as ModelDoc2;
            }
            catch
            {
                return null;
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
