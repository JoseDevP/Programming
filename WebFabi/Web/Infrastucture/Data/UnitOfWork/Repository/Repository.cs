using Core.Interfaces;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using Web.Data;

namespace Infrastucture.Data.UnitOfWork.Repository
{
    public class Repository<T> : IRepository<T> where T : class
    {
        private readonly ApplicationDbContext _applicationDbContext;
        private readonly DbSet<T> _dbSet;

        public Repository(ApplicationDbContext applicationDbContext)
        {
            _applicationDbContext = applicationDbContext;
            _dbSet = applicationDbContext.Set<T>();
        }


        public async Task CreateElement(T element) => await _dbSet.AddAsync(element);

        public void DeleteElement(T element) => _dbSet.Remove(element);

        public async Task<bool> ElementExist(int id)
        {
            var element = await _dbSet.FindAsync(id);
            if (element == null)
                return false;
            return true;
        }

        public async Task<T> FirstOrDefaultAsync(Expression<Func<T, bool>> predicate)
        {
            return await _dbSet.FirstOrDefaultAsync(predicate);
        }

        public async Task<IEnumerable<T>>? GetAllElements(Expression<Func<T, bool>>? filter = null, Func<IQueryable<T>, IOrderedQueryable<T>>? orderBy = null, string? includeValues = null)
        {
            IQueryable<T> query = _dbSet.AsQueryable();

            if(filter != null)
                query = query.Where(filter);

            if (includeValues != null)
                foreach (var value in includeValues.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries))
                    query = query.Include(value);

            if (orderBy != null)
                return await orderBy(query).ToListAsync();

            return await query.ToListAsync();
        }

        public async Task<T>? GetElementById(int id)
        {
            return await _dbSet.FindAsync(id);
        }
    }
}
