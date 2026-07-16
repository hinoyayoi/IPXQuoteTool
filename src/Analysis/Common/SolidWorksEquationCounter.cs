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
                    int count = (int)equationManager.GetCount();
                    LogEquations(model, equationManager, count);
                    return count;
                }
                catch
                {
                    try
                    {
                        int count = (int)equationManager.Count;
                        LogEquations(model, equationManager, count);
                        return count;
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

        private static void LogEquations(ModelDoc2 model, dynamic equationManager, int count)
        {
            for (int i = 0; i < count; i++)
            {
                string equationText = $"Equation {i + 1}";
                try
                {
                    equationText = equationManager.Equation[i];
                }
                catch
                {
                }

                AnalysisTraceLogger.Write(model, "表达式", equationText);
            }
        }
    }
}
