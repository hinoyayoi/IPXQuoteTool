namespace IPXQuoteTool.Pricing
{
    public class QuotePriceResult
    {
        public double ComplexityScore { get; set; }
        public double UnitPrice { get; set; } = 0.32;
        public double ComplexityCoefficient { get; set; } = 1.0;
        public double DiscountCoefficient { get; set; } = 1.0;
        public double FinalScore => ComplexityScore * UnitPrice * ComplexityCoefficient * DiscountCoefficient;
    }
}
