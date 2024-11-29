using Microsoft.EntityFrameworkCore;
using MoviesAPI.Data;
using MoviesAPI.Models;
using MoviesAPI.Repository.IRepository;
using System.Linq.Expressions;
using System.Xml.Linq;

namespace MoviesAPI.Repository
{
    public class CategoryRepository : Repository<Category>, IRepository<Category>
    {
        private readonly ApplicationDbContext _db;

        public CategoryRepository(ApplicationDbContext db) : base(db)
        {
            _db = db;
        }

        public void UpdateCategory(Category category)
        {
            category.CreationDate = DateTime.Now;
            _db.Category.Update(category);
        }

        public async Task<bool> ElementExist(string name)
        {
            return await _db.Category.AnyAsync(e => e.Name == name);
        }
    }
}
