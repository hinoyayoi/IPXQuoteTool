namespace IPXQuoteTool.Pricing
{
    public class QuotePricingSettings
    {
        public double PartDiscount { get; set; } = 1.0;
        public double AssemblyDiscount { get; set; } = 1.0;
        public double DrawingDiscount { get; set; } = 1.0;
        public double UnitPrice { get; set; } = 0.32;
        public ObjectCoefficientSettings ObjectCoefficients { get; set; } = ObjectCoefficientSettings.CreateDefault();
        public ComplexityPricingSettings ComplexityPricing { get; set; } = ComplexityPricingSettings.CreateDefault();
    }

    public class ComplexityPricingSettings
    {
        public double Range0MaxFeatureCount { get; set; } = 15;
        public double Range1MaxFeatureCount { get; set; } = 40;
        public double Range2MaxFeatureCount { get; set; } = 80;
        public double Range0To15Coefficient { get; set; } = 0.2;
        public double Range15To40Coefficient { get; set; } = 0.6;
        public double Range40To80Coefficient { get; set; } = 0.8;
        public double RangeOver80Coefficient { get; set; } = 1.0;

        public static ComplexityPricingSettings CreateDefault()
        {
            return new ComplexityPricingSettings();
        }

        public double GetCoefficient(double equivalentFeatureCount)
        {
            double firstMax = Range0MaxFeatureCount > 0 ? Range0MaxFeatureCount : 15;
            double secondMax = Range1MaxFeatureCount > firstMax ? Range1MaxFeatureCount : 40;
            double thirdMax = Range2MaxFeatureCount > secondMax ? Range2MaxFeatureCount : 80;

            if (equivalentFeatureCount <= firstMax)
            {
                return Range0To15Coefficient;
            }

            if (equivalentFeatureCount <= secondMax)
            {
                return Range15To40Coefficient;
            }

            if (equivalentFeatureCount <= thirdMax)
            {
                return Range40To80Coefficient;
            }

            return RangeOver80Coefficient;
        }
    }
}
