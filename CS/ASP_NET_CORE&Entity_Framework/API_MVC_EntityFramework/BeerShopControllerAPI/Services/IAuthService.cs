using Backend.DTOs;
using Backend.Models;
using System.IdentityModel.Tokens.Jwt;

namespace Backend.Services
{
    public interface IAuthService
    {
        public List<string> Errors { get; }

        public Task<IEnumerable<UserDTO>> Get();
        public Task<UserDTO> GetById(int id);

        public Task<UserDTO> SignIn(UserLogingDTO userInsertDTO);
        public Task<UserDTO> SignUp(UserRegisterDTO userRegisterDTO, string role);

        public Task<UserDTO> DeleteUser(int id);
        public Task<User> FindUserByCredentials(string username, string password);
        (string hash, string salt) CreatePasswordHash(string password);
        bool VerifyPasswordHash(string password, string storedHash, string storedSalt);

        public string GenerateToken(User user);

        bool validate(UserRegisterDTO user);
        bool validate(UserLogingDTO user);

    }
}
