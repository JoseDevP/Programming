using BeerShop.Core.Interfaces;
using BeerShop.Core.Models;
using Microsoft.EntityFrameworkCore;

namespace BeerShop.Infrastructure.Data.Repository
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
