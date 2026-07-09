using System.Collections.Generic;

namespace IPXQuoteTool.Pricing
{
    public class ObjectCoefficientSettings
    {
        private readonly Dictionary<string, double> _values = new Dictionary<string, double>();

        public double PartFeature => GetValue("零件", "特征", 1);
        public double PartConfiguration => GetValue("零件", "配置项", 0.5);
        public double PartExpression => GetValue("零件", "表达式", 0.1);

        public double AssemblyComponent => GetValue("装配", "组件数", 0.6);
        public double AssemblyMate => GetValue("装配", "装配约束", 0.8);
        public double AssemblyFeature => GetValue("装配", "装配特征", 1);
        public double AssemblyConfiguration => GetValue("装配", "配置项", 0.5);
        public double AssemblyExpression => GetValue("装配", "表达式", 0.1);

        public double DrawingView => GetValue("工程图", "视图", 0.8);
        public double DrawingDimension => GetValue("工程图", "标注", 0.5);
        public double DrawingTable => GetValue("工程图", "表格", 0.5);

        public static ObjectCoefficientSettings CreateDefault()
        {
            var settings = new ObjectCoefficientSettings();
            foreach (var row in ObjectCoefficientSettingsService.DefaultRows)
            {
                settings.SetValue(row.Category, row.ObjectName, row.Coefficient);
            }

            return settings;
        }

        public void SetValue(string category, string objectName, double coefficient)
        {
            _values[BuildKey(category, objectName)] = coefficient;
        }

        private double GetValue(string category, string objectName, double defaultValue)
        {
            return _values.TryGetValue(BuildKey(category, objectName), out double value) ? value : defaultValue;
        }

        private static string BuildKey(string category, string objectName)
        {
            return $"{category?.Trim()}|{objectName?.Trim()}";
        }
    }
}
