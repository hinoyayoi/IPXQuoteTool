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
            var components = GetComponentsFromAssemblyDoc(model);
            if (components.Count == 0)
            {
                components = GetTopLevelComponentsFromFeatures(model);
            }

            for (int i = 0; i < components.Count; i++)
            {
                IComponent2 component = components[i];
                AnalysisTraceLogger.Write(
                    model,
                    "组件数",
                    AnalysisTraceLogger.GetObjectName(component, $"Component {i + 1}"),
                    IsVirtualComponent(component) ? "虚拟组件" : SafeComponentPath(component));
            }

            return components.Count;
        }

        private static List<IComponent2> GetComponentsFromAssemblyDoc(ModelDoc2 model)
        {
            var components = new List<IComponent2>();

            try
            {
                if (!(model is AssemblyDoc assemblyDoc))
                {
                    return components;
                }

                object rawComponents = assemblyDoc.GetComponents(false);
                foreach (object rawComponent in EnumerateVariantItems(rawComponents))
                {
                    if (rawComponent is IComponent2 component &&
                        IsTopLevelComponent(component) &&
                        !IsIgnoredComponent(component))
                    {
                        components.Add(component);
                    }
                }

                if (components.Count == 0)
                {
                    foreach (object rawComponent in EnumerateVariantItems(assemblyDoc.GetComponents(true)))
                    {
                        if (rawComponent is IComponent2 component && !IsIgnoredComponent(component))
                        {
                            components.Add(component);
                        }
                    }
                }
            }
            catch
            {
            }

            return components;
        }

        private static bool IsTopLevelComponent(IComponent2 component)
        {
            try
            {
                Component2 parent = component.GetParent();
                if (parent == null)
                {
                    return true;
                }

                return parent.IsRoot();
            }
            catch
            {
                return false;
            }
        }

        private static IEnumerable<object> EnumerateVariantItems(object value)
        {
            if (value == null)
            {
                yield break;
            }

            if (value is Array array)
            {
                foreach (object item in array)
                {
                    yield return item;
                }

                yield break;
            }

            yield return value;
        }

        private static List<IComponent2> GetTopLevelComponentsFromFeatures(ModelDoc2 model)
        {
            var components = new List<IComponent2>();

            try
            {
                Feature feature = (Feature)model.FirstFeature();
                while (feature != null)
                {
                    IComponent2 component = TryGetComponentFromFeature(feature);
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

        private static IComponent2 TryGetComponentFromFeature(Feature feature)
        {
            if (feature == null)
            {
                return null;
            }

            try
            {
                object specificFeature = feature.GetSpecificFeature2();
                return specificFeature as IComponent2;
            }
            catch
            {
                try
                {
                    return feature.GetSpecificFeature() as IComponent2;
                }
                catch
                {
                    return null;
                }
            }
        }

        private static bool IsIgnoredComponent(IComponent2 component)
        {
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

        private static bool IsIgnoredComponentFeature(Feature feature, IComponent2 component)
        {
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

        private static bool IsVirtualComponent(IComponent2 component)
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

        private static string SafeComponentPath(IComponent2 component)
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
            var components = GetComponentsFromAssemblyDoc(assemblyModel);
            if (components.Count == 0)
            {
                components = GetTopLevelComponentsFromFeatures(assemblyModel);
            }

            foreach (IComponent2 component in components)
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

        private static int CountVirtualPartFeatures(ModelDoc2 assemblyModel, IComponent2 component)
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

        private static ModelDoc2 GetComponentModel(IComponent2 component)
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
