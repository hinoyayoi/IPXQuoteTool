namespace IPXQuoteTool.Pricing
{
    public class QuotePriceResult
    {
        public double ComplexityScore { get; set; }
        public double UnitPrice { get; set; } = 3.0;
        public double ComplexityCoefficient { get; set; } = 1.0;
        public double DiscountCoefficient { get; set; } = 1.0;
        public double FinalScore => ComplexityScore * UnitPrice * ComplexityCoefficient * DiscountCoefficient;
    }
}
