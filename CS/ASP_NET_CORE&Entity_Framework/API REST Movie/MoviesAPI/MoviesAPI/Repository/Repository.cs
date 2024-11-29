using Microsoft.EntityFrameworkCore;
using MoviesAPI.Data;
using MoviesAPI.Models;
using MoviesAPI.Repository.IRepository;
using System.Linq.Expressions;
using System.Xml.Linq;

namespace MoviesAPI.Repository
{
    public class Repository<T> : IRepository<T> where T : class
    {
        private readonly ApplicationDbContext _db;
        private readonly DbSet<T> _elements;

        public Repository(ApplicationDbContext db)
        {
            _db = db;
            _elements = db.Set<T>();
        }

        public async Task<bool> ElementExist(int idElement)
        {
            var element = await _elements.FindAsync(idElement);

            return element != null;
        }

        public async Task CreateElement(T element)
        {
            await _elements.AddAsync(element);
        }

        public void DeleteElement(T element)
        {
            _elements.Remove(element);
        }

        public async Task<IEnumerable<T>> GetAllElements(
            Expression<Func<T, bool>> filter = null,
            Func<IQueryable<T>, IOrderedQueryable<T>> order = null,
            string includeValues = null)
        {
            IQueryable<T> query = _elements.AsQueryable();

            if(filter != null)
            {
                query = query.Where(filter);
            }

            if(includeValues != null)
            {
                foreach(var value in includeValues.Split(new char[] {','},StringSplitOptions.RemoveEmptyEntries))
                {
                    query = query.Include(value);
                }
            }

            if(order != null)
            {
                return await order(query).ToListAsync();
            }

            return await query.ToListAsync();
        }

        public async Task<T> GetById(int idElement)
        {
            return await _elements.FindAsync(idElement);
        }

        
    }
}
