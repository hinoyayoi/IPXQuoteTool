using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using System;
using System.Collections.Generic;
using System.Linq;

namespace IPXQuoteTool.Analysis.Assemblies
{
    public class AssemblyMetricExtractor : IDocumentMetricExtractor
    {
        public swDocumentTypes_e SupportedDocumentType => swDocumentTypes_e.swDocASSEMBLY;

        public void Extract(DocumentAnalysisContext context, DocumentInfo info)
        {
            var components = TraverseAssembly(context.Model);
            info.ComponentCount = components.Sum(c => c.Quantity);
            info.MateCount = CountMates(context.Model);
            info.AssemblyFeatureCount = CountAssemblyFeatures(context.Model);
        }

        private static List<ComponentInfo> TraverseAssembly(ModelDoc2 model)
        {
            var components = new List<ComponentInfo>();

            try
            {
                Configuration conf = (Configuration)model.GetActiveConfiguration();
                Component2 rootComp = (Component2)conf.GetRootComponent();
                TraverseComponentRecursive(rootComp, components, 0);
            }
            catch
            {
            }

            return components;
        }

        private static void TraverseComponentRecursive(Component2 comp, List<ComponentInfo> list, int level)
        {
            if (comp == null)
            {
                return;
            }

            int quantity = 1;

            try
            {
                dynamic dynComp = comp;
                try
                {
                    quantity = (int)dynComp.GetCount();
                }
                catch
                {
                    try
                    {
                        quantity = (int)dynComp.GetCount2(false);
                    }
                    catch
                    {
                    }
                }
            }
            catch
            {
            }

            list.Add(new ComponentInfo
            {
                Name = comp.Name2,
                Level = level,
                Configuration = comp.ReferencedConfiguration,
                Quantity = quantity
            });

            try
            {
                object childrenObj = comp.GetChildren();
                if (childrenObj is Array children)
                {
                    foreach (var child in children)
                    {
                        TraverseComponentRecursive((Component2)child, list, level + 1);
                    }
                }
            }
            catch
            {
            }
        }

        private static int CountMates(ModelDoc2 model)
        {
            try
            {
                dynamic assemblyDoc = model;
                try
                {
                    return (int)assemblyDoc.GetMatesCount();
                }
                catch
                {
                    try
                    {
                        object mates = assemblyDoc.GetMates(true);
                        if (mates is Array matesArray)
                        {
                            return matesArray.Length;
                        }
                    }
                    catch
                    {
                    }

                    return 0;
                }
            }
            catch
            {
                return 0;
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
                    string typeName = feat.GetTypeName();
                    if (typeName.Contains("Assembly") ||
                        typeName.Contains("Pattern") ||
                        typeName.Contains("Mate"))
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
