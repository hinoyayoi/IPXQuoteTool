namespace IPXQuoteTool.Pricing
{
    public class QuotePriceResult
    {
        public double ComplexityScore { get; set; }
        public double Discount { get; set; }
        public double FinalScore => ComplexityScore * Discount;
    }
}
