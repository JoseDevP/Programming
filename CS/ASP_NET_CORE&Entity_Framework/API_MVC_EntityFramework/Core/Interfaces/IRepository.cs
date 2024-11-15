using System.Linq.Expressions;

namespace Core.Interfaces
{
    public interface IRepository<TEntity> where TEntity : class
    {
        Task<IEnumerable<TEntity>> Get(Expression<Func<TEntity, bool>>? filter = null,
            Func<IQueryable<TEntity>, IOrderedQueryable<TEntity>>? orderby = null,
            string? includeProperties = null);
        Task<TEntity?> GetById(int id);

        Task<TEntity?> GetFirstOrDefault(Expression<Func<TEntity, bool>>? filter = null,
            string? includeProperties = null);

        Task Add(TEntity entity);
        void Delete(TEntity entity);
        public IEnumerable<TEntity> Search(Expression<Func<TEntity, bool>> filter);
    }
}
