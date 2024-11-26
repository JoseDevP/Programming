using Core.Interfaces;
using Infrastructure.Data;
using Microsoft.EntityFrameworkCore;

namespace Infrastructure.Data.Repository
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
