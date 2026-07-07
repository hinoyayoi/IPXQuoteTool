namespace IPXQuoteTool.Pricing
{
    public interface IQuotePricingRule
    {
        QuotePriceResult Calculate(DocumentInfo document, QuotePricingSettings settings);
    }
}
