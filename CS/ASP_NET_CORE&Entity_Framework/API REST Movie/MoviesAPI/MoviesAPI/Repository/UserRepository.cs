using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using MoviesAPI.Data;
using MoviesAPI.Models;
using MoviesAPI.Models.DTOs;
using MoviesAPI.Repository.IRepository;
using System.IdentityModel.Tokens.Jwt;
using System.Linq.Expressions;
using System.Security.Claims;
using System.Text;
using System.Xml.Linq;
using XSystem.Security.Cryptography;

namespace MoviesAPI.Repository
{
    public class UserRepository : Repository<User>, IUserRepository
    {
        private readonly ApplicationDbContext _db;
        private string secretKey;

        public UserRepository(ApplicationDbContext db, IConfiguration config) : base(db)
        {
            _db = db;
            secretKey = config.GetValue<string>("ApiSettings:SecretKey");
        }

        public void UpdateCategory(Category category)
        {
            category.CreationDate = DateTime.Now;
            _db.Category.Update(category);
        }

        public async Task<bool> ElementExist(string name)
        {
            return await _db.Category.AnyAsync(e => e.Name == name);
        }

        public void UpdateUser(User user)
        {
            throw new NotImplementedException();
        }

        public async Task<bool> IsUniqueUser(string name)
        {
            var userDb = await _db.User.FirstOrDefaultAsync(u=> u.UserName == name);
            if ((userDb == null))
                return true;
            return false;
        }

        public async Task<UserLogingResponseDTO> Login(UserLoggingDTO userLoggingDTO)
        {
            var encryptablePassword = ObtainMD5(userLoggingDTO.Password);
            var user = await _db.User.FirstOrDefaultAsync(
                u => u.UserName.ToLower() == userLoggingDTO.UserName.ToLower()
                && u.Password == encryptablePassword
                );

            if(user == null) 
                return new UserLogingResponseDTO() { 
                    Token = "",
                    User = null
                };

            var tokenManager = new JwtSecurityTokenHandler();
            var key = Encoding.ASCII.GetBytes(secretKey);

            var tokenDescriptor = new SecurityTokenDescriptor
            {
                Subject = new ClaimsIdentity(new Claim[]
                {
                    new Claim(ClaimTypes.Name, user.UserName.ToString()),
                    new Claim(ClaimTypes.Role, user.Role)
                }),
                Expires = DateTime.UtcNow.AddDays(7),
                SigningCredentials = new(new SymmetricSecurityKey(key), SecurityAlgorithms.HmacSha256Signature)
            };

            var token = tokenManager.CreateToken(tokenDescriptor);

            UserLogingResponseDTO userLogingResponseDTO = new UserLogingResponseDTO()
            {
                Token = tokenManager.WriteToken(token),
                User = user,
                Role = user.Role
            };

            return userLogingResponseDTO;
        }

        public async Task<User> Register(UserRegisterDTO userRegisterDTO)
        {
            var encryptablePassword = ObtainMD5(userRegisterDTO.Password);

            User user = new User()
            {
                UserName = userRegisterDTO.UserName,
                Password = encryptablePassword,
                Name = userRegisterDTO.Name,
                Role = userRegisterDTO.Role
            };

            _db.User.Add(user);
            await _db.SaveChangesAsync();

            user.Password = encryptablePassword;
            return user;
        }

        public static string ObtainMD5(string password)
        {
            MD5CryptoServiceProvider x = new MD5CryptoServiceProvider();
            byte[] data = System.Text.Encoding.UTF8.GetBytes(password);
            data = x.ComputeHash(data);
            string resp = "";
            for (int i = 0; i < data.Length; i++)
                resp += data[i].ToString("x2").ToLower();
            return resp;
        }
    }
}
