using MoviesAPI.Models;
using MoviesAPI.Models.DTOs;
using System.Linq.Expressions;

namespace MoviesAPI.Repository.IRepository
{
    public interface IUserRepository : IRepository<User>
    {
        void UpdateUser(User user);
        Task<bool> ElementExist(string name);
        Task<bool> IsUniqueUser(string name);
        Task<UserLogingResponseDTO> Login(UserLoggingDTO userLoggingDTO);
        Task<User> Register(UserRegisterDTO userRegisterDTO);
    }
}
