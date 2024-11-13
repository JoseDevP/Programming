using Backend.Models;
using BeerShop.Data.Repository;
using Microsoft.EntityFrameworkCore;

namespace Backend.Data.Repository
{
    public class BrandRepository : Repository<Brand>, IBrandRepository
    {
        StoreContext _storeContext;
        public BrandRepository(StoreContext storeContext) : base(storeContext)
        {
            _storeContext = storeContext;
        }

        public void Update(Brand entity) => _dbSet.Update(entity);
    }
}
