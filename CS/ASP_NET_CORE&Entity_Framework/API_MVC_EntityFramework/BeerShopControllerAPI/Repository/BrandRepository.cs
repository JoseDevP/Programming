using Backend.Models;
using Microsoft.EntityFrameworkCore;

namespace Backend.Repository
{
    public class BrandRepository : IRepository<Brand>
    {
        StoreContext _storeContext;
        public BrandRepository(StoreContext storeContext) 
        {
            _storeContext = storeContext;
        }

        public async Task<IEnumerable<Brand>> Get() => await _storeContext.Brands.ToListAsync();

        public async Task<Brand> GetById(int id) => await _storeContext.Brands.FindAsync(id);

        public async Task Add(Brand entity) => await _storeContext.Brands.AddAsync(entity);

        public void Update(Brand entity)
        {
            _storeContext.Brands.Attach(entity);
            _storeContext.Brands.Entry(entity).State = EntityState.Modified;
        }

        public void Delete(Brand entity) => _storeContext.Brands.Remove(entity);
        public async Task Save() => await _storeContext.SaveChangesAsync();

        public IEnumerable<Brand> Search(Func<Brand, bool> filter) => _storeContext.Brands.Where(filter).ToList();
    }
}
