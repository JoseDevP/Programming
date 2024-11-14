using BeerShop.Core.Interfaces;
using Microsoft.EntityFrameworkCore;

namespace BeerShop.Infrastructure.Data.Repository
{
    public class UserRepository : Repository<User>, IUserRepository
    {
        private StoreContext _storeContext;

        public UserRepository(StoreContext storeContext) : base(storeContext)
        {
            _storeContext = storeContext;
        }

        public void Update(User entity) => _dbSet.Update(entity);

    }
}
