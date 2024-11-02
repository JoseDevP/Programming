using Backend.DTOs;
using Backend.Models;
using System.IdentityModel.Tokens.Jwt;

namespace Backend.Services
{
    public interface IAuthService
    {
        public Task<UserDTO> SignIn(UserLogingDTO userInsertDTO);
        public Task<UserDTO> SignUp(UserRegisterDTO userRegisterDTO, string role);
        public Task<User> FindUserByCredentials(string username, string password);
        (string hash, string salt) CreatePasswordHash(string password);
        bool VerifyPasswordHash(string password, string storedHash, string storedSalt);

        public string GenerateToken(User user);

    }
}
