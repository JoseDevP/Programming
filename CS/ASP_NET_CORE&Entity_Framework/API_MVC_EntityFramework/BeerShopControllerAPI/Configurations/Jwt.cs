using Microsoft.Extensions.Configuration;

namespace Backend.Configurations
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
    }
}
