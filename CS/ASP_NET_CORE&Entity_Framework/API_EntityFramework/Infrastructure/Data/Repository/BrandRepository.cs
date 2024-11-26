using Core.Interfaces;
using Core.Models;
using Infrastructure.Data;
using Microsoft.EntityFrameworkCore;

namespace Infrastructure.Data.Repository
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
