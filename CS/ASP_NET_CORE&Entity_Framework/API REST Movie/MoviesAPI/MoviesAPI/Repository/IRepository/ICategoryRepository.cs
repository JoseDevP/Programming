using MoviesAPI.Models;
using System.Linq.Expressions;

namespace MoviesAPI.Repository.IRepository
{
    public interface ICategoryRepository
    {
        void UpdateCategory(Category category);
        Task<bool> ElementExist(string name);
    }
}
