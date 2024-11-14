using BeerShop.Core.Interfaces;
using Microsoft.EntityFrameworkCore;
using System.Linq.Expressions;

namespace BeerShop.Infrastructure.Data.Repository
{
    public class Repository<TEntity> : IRepository<TEntity> where TEntity : class
    {
        protected DbContext _dbContext;
        internal DbSet<TEntity> _dbSet;

        public Repository(DbContext dbContext)
        {
            _dbContext = dbContext;
            _dbSet = dbContext.Set<TEntity>();
        }

        public async Task<IEnumerable<TEntity>> Get(Expression<Func<TEntity, bool>>? filter = null,
            Func<IQueryable<TEntity>, IOrderedQueryable<TEntity>>? orderby = null,
            string? includeProperties = null)
        {
            IQueryable<TEntity> query = _dbSet;

            if (filter != null)
                query = query.Where(filter);

            if (includeProperties != null)
                foreach (var property in includeProperties.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries))
                    query = query.Include(property);

            if (orderby != null)
                return await orderby(query).ToListAsync();

            return await query.ToListAsync();
        }

        public async Task<TEntity?> GetById(int id) => await _dbSet.FindAsync(id);

        public async Task<TEntity?> GetFirstOrDefault(Expression<Func<TEntity, bool>>? filter = null,
            string? includeProperties = null)
        {
            IQueryable<TEntity> query = _dbSet;

            if (filter != null)
                query = query.Where(filter);

            if (includeProperties != null)
                foreach (var property in includeProperties.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries))
                    query = query.Include(property);

            return await query.FirstOrDefaultAsync();
        }

        public async Task Add(TEntity entity) => await _dbSet.AddAsync(entity);

        public void Delete(TEntity entity) => _dbSet.Remove(entity);


        public IEnumerable<TEntity> Search(Expression<Func<TEntity, bool>> filter)
        {
            IQueryable<TEntity> query = _dbSet;
            query = query.Where(filter);
            return query.ToList();
        }
    }
}
