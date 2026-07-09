using SolidWorks.Interop.sldworks;

namespace IPXQuoteTool.Analysis
{
    internal static class SolidWorksEquationCounter
    {
        public static int CountEquations(ModelDoc2 model)
        {
            if (model == null)
            {
                return 0;
            }

            try
            {
                dynamic equationManager = model.GetEquationMgr();
                if (equationManager == null)
                {
                    return 0;
                }

                try
                {
                    return (int)equationManager.GetCount();
                }
                catch
                {
                    try
                    {
                        return (int)equationManager.Count;
                    }
                    catch
                    {
                        return 0;
                    }
                }
            }
            catch
            {
                return 0;
            }
        }
    }
}
