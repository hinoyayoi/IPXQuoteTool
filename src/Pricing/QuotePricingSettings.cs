namespace IPXQuoteTool.Pricing
{
    public class QuotePricingSettings
    {
        public double PartDiscount { get; set; } = 0.5;
        public double AssemblyDiscount { get; set; } = 0.4;
        public double DrawingDiscount { get; set; } = 0.8;
        public double UnitPrice { get; set; } = 0.32;
        public ObjectCoefficientSettings ObjectCoefficients { get; set; } = ObjectCoefficientSettings.CreateDefault();
        public ComplexityPricingSettings ComplexityPricing { get; set; } = ComplexityPricingSettings.CreateDefault();
    }

    public class ComplexityPricingSettings
    {
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
            if (equivalentFeatureCount <= 15)
            {
                return Range0To15Coefficient;
            }

            if (equivalentFeatureCount <= 40)
            {
                return Range15To40Coefficient;
            }

            if (equivalentFeatureCount <= 80)
            {
                return Range40To80Coefficient;
            }

            return RangeOver80Coefficient;
        }
    }
}
