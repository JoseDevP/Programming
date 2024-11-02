using AutoMapper;
using Backend.Configurations;
using Backend.Data.Repository;
using Backend.DTOs;
using Backend.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using Newtonsoft.Json.Linq;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;

namespace Backend.Services
{
    public class AuthService : IAuthService
    {
        public List<string> Errors { get; }

        //Roles -> Admin, User, Guest

        IRepository<User> _userRepository;
        private IMapper _mapper;
        public IConfiguration _configuration;
        public IJwt _jwt;
        public StoreContext _storeContext;
        public AuthService(IMapper mapper,
            IConfiguration configuration,
            IJwt jwt,
            StoreContext storeContext,
            [FromKeyedServices("UserRepository")]IRepository<User> userRepository
            )
        {
            _mapper = mapper;
            _configuration = configuration;
            _jwt = jwt;
            _storeContext = storeContext;
            _userRepository = userRepository;
            Errors = new List<string>();
        }


        public async Task<UserDTO> SignIn(UserLogingDTO userLogingDTO)
        {
            User user = _userRepository.Search(u => u.UserName == userLogingDTO.UserName).FirstOrDefault();

            string tokenString = GenerateToken(user);
            user.LastToken = tokenString;

            await _userRepository.Save();

            var userDTO = _mapper.Map<UserDTO>(user);
            userDTO.LastToken = tokenString;
            return userDTO;
        }

        public async Task<UserDTO> SignUp(UserRegisterDTO userRegisterDTO, string role)
        {
            var (hash, salt) = CreatePasswordHash(userRegisterDTO.Password);
            var user = new User
            {
                UserName = userRegisterDTO.Username,
                PasswordHash = hash,
                PasswordSalt = salt, 
                Role = role,
                Email = userRegisterDTO.Email,
                LastToken = ""
            };

            string tokenString  = GenerateToken(user);
            user.LastToken = tokenString;

            await _userRepository.Add(user);
            await _userRepository.Save();


            var userDTO = _mapper.Map<UserDTO>(user);
            userDTO.LastToken = tokenString;

            return userDTO;
        }

        public (string hash, string salt) CreatePasswordHash(string password)
        {
            using (var hmac = new HMACSHA512())
            {
                var salt = Convert.ToBase64String(hmac.Key);
                var hash = Convert.ToBase64String(hmac.ComputeHash(Encoding.UTF8.GetBytes(password)));
                return (hash, salt);
            }
        }

        public bool VerifyPasswordHash(string password, string storedHash, string storedSalt)
        {
            using (var hmac = new HMACSHA512(Convert.FromBase64String(storedSalt)))
            {
                var computedHash = Convert.ToBase64String(hmac.ComputeHash(Encoding.UTF8.GetBytes(password)));
                return computedHash == storedHash;
            }
        }


        public async Task<User> FindUserByCredentials(string username, string password)
        {
            var user = await _storeContext.Users
                .FirstOrDefaultAsync(u => u.UserName == username);

            if (user == null)
            {
                return null;
            }

            if (!VerifyPasswordHash(password, user.PasswordHash, user.PasswordSalt))
            {
                return null;
            }

            return user; 
        }

        public string GenerateToken(User user)
        {
            var claims = new[]
            {
                new Claim(JwtRegisteredClaimNames.Sub, user.UserName),
                new Claim(JwtRegisteredClaimNames.Jti, Guid.NewGuid().ToString()),
                new Claim(ClaimTypes.Role, user.Role),
            };

            var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_jwt.Key));
            var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

            var token = new JwtSecurityToken(
                issuer: _jwt.Issuer,
                audience: _jwt.Audience,
                claims: claims,
                expires: DateTime.Now.AddMinutes(5),
                signingCredentials: creds);

            return new JwtSecurityTokenHandler().WriteToken(token);
        }

        public bool validate(UserRegisterDTO userRegisterDTO)
        {
            if(_userRepository.Search(u => u.UserName == userRegisterDTO.Username).Count() > 0)
            {
                Errors.Add("Ya existe un usuario con ese nombre");
                return false;
            }

            return true;
        }

        public bool validate(UserLogingDTO userLogingDTO)
        {
            var user = _userRepository.Search(u => u.UserName == userLogingDTO.UserName).FirstOrDefault();

            if (user == null)
            {
                Errors.Add("No existe un usuario con ese nombre");
                return false;
            }

            if (!VerifyPasswordHash(userLogingDTO.Password, user.PasswordHash, user.PasswordSalt))
            {
                Errors.Add("La contraseña es erronea");
                return false;
            }

            if (!string.IsNullOrEmpty(user.LastToken))
            {

            }

            return true;
        }
    }
}
