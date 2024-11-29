using MoviesAPI.Models;
using System.Linq.Expressions;

namespace MoviesAPI.Repository.IRepository
{
    public interface IRepository<T> where T : class
    {
        Task<IEnumerable<T>> GetAllElements(
            Expression<Func<T, bool>> filter = null,
            Func<IQueryable<T>, IOrderedQueryable<T>> orderBy = null,
            string includeValues = null);
        Task<T> GetById(int idelement);
        Task<bool> ElementExist(int idElement);
        Task CreateElement(T element);
        void DeleteElement(T element);
    }
}
