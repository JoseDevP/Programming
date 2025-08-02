using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Core.Interfaces
{
    public interface IRepository<T> where T : class
    {
        public Task<bool> ElementExist(int id);
        public Task<T>? GetElementById(int id);
        public Task<IEnumerable<T>>? GetAllElements(
            Expression<Func<T, bool>>? filter = null,
            Func<IQueryable<T>,IOrderedQueryable<T>>? orderBy = null,
            string? includeValues = null
            );
        public Task CreateElement(T element);
        public void DeleteElement(T element);
        public Task<T> FirstOrDefaultAsync(Expression<Func<T, bool>> predicate);
    }
}
