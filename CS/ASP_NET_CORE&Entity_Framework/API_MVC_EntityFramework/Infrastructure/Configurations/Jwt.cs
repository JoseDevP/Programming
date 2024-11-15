using Core.Interfaces;
using Microsoft.Extensions.Configuration;

namespace Infrastructure.Configurations
{
    public class Jwt : IJwt
    {
        public string Key { get; set; }
        public string Issuer { get; set; }
        public string Audience { get; set; }
        public string Subject { get; set; }

        public Jwt(IConfiguration configuration)
        {
            var jwtSection = configuration.GetSection("Jwt");
            Key = jwtSection["Key"];
            Issuer = jwtSection["Issuer"];
            Audience = jwtSection["Audience"];
            Subject = jwtSection["Subject"];
        }

        public Jwt(string key, string issuer, string audience, string subject)
        {
            Key = key;
            Issuer = issuer;
            Audience = audience;
            Subject = subject;
        }
    }
}
