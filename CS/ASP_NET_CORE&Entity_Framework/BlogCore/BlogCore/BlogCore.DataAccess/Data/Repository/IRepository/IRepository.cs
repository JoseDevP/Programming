using System.Linq.Expressions;


namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public interface IRepository<T> where T : class
    {
        Task<T?> GetById(int id);
        Task<IEnumerable<T>> GetAll(
            Expression<Func<T, bool>>? filter = null,
            Func<IQueryable<T>, IOrderedQueryable<T>>? orderBy = null,
            string? includeProperties = null
            );

        Task<T?> GetFirstOrDefault(
            Expression<Func<T, bool>>? filter = null,
            string? includeProperties = null
            );

        Task Add( T entity );

        Task Remove(int id);

        void Remove(T entity );
    }
}
