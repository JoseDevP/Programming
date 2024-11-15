using Core.Interfaces;
using Core.Models;
using Microsoft.EntityFrameworkCore;

namespace BeerShop.Infrastructure.Data.Repository
{
    public class BeerRepository : Repository<Beer>, IBeerRepository
    {
        private StoreContext _storeContext;

        public BeerRepository(StoreContext storeContext) : base(storeContext)
        {
            _storeContext = storeContext;
        }

        public void Update(Beer entity) => _dbSet.Update(entity);

    }
}
