using BlogCore.Models;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public class Repository<T> : IRepository<T> where T : class
    {
        protected readonly DbContext _dbContext;
        internal DbSet<T> _dbSet;

        public Repository(DbContext dbContext)
        {
            _dbContext = dbContext;
            this._dbSet = dbContext.Set<T>();
        }


        public async Task<T?> GetById(int id) => await _dbSet.FindAsync(id);

        public async Task<IEnumerable<T>> GetAll(Expression<Func<T, bool>>? filter = null, Func<IQueryable<T>, IOrderedQueryable<T>>? orderBy = null, string? includeProperties = null)
        {
            IQueryable<T> query = _dbSet;

            if(filter != null)
                query = query.Where(filter);

            if(includeProperties != null)
                foreach (var property in includeProperties.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries))
                    query = query.Include(property);
            
            if(orderBy != null)
                return await orderBy(query).ToListAsync();

            return await query.ToListAsync();
        }


        public async Task<T?> GetFirstOrDefault(Expression<Func<T, bool>>? filter = null, string? includeProperties = null)
        {
            IQueryable<T> query = _dbSet;

            if (filter != null)
                query = query.Where(filter);

            if(includeProperties != null)
                foreach (var property in includeProperties.Split(new char[] {','}, StringSplitOptions.RemoveEmptyEntries))
                    query = query.Include(property);

            return await query.FirstOrDefaultAsync();
        }

        public async Task Add(T entity) => await _dbSet.AddAsync(entity);
        

        public async Task Remove(int id)
        {
            T? entityToRemove = await _dbSet.FindAsync(id);

            if (entityToRemove != null)
                Remove(entityToRemove);
        }

        public void Remove(T entity) => _dbSet.Remove(entity);
        
    }
    
}
