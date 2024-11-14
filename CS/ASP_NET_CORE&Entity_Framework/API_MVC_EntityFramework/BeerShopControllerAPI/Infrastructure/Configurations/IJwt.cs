namespace BeerShop.Infrastructure.Configurations
{
    public interface IJwt
    {
        public string Key { get; set; }
        public string Issuer { get; set; }
        public string Audience { get; set; }
        public string Subject { get; set; }
    }
}
