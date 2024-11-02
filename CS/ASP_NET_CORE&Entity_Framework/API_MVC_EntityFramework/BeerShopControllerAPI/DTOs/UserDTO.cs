using System.IdentityModel.Tokens.Jwt;

namespace Backend.DTOs
{
    public class UserDTO
    {
        public int IdUser { get; set; }

        public string UserName { get; set; }

        public string PasswordHash { get; set; }

        public string PasswordSalt { get; set; }

        public string Role { get; set; }
        public string Email { get; set; }

        public string LastToken { get; set; }

    }
}
