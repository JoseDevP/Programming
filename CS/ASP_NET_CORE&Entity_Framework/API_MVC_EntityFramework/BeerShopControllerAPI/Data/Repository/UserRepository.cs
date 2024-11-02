
using Backend.Models;
using Microsoft.EntityFrameworkCore;

namespace Backend.Data.Repository
{
    public class UserRepository : IRepository<User>
    {
        private StoreContext _storeContext;

        public UserRepository(StoreContext storeContext)
        {
            _storeContext = storeContext;
        }

        public async Task Add(User entity) => await _storeContext.Users.AddAsync(entity);

        public void Delete(User entity) => _storeContext.Users.Remove(entity);
        

        public async Task<IEnumerable<User>> Get() => await _storeContext.Users.ToListAsync();

        public async Task<User> GetById(int id) => await _storeContext.Users.FindAsync(id);

        public async Task Save() => await _storeContext.SaveChangesAsync();

        public IEnumerable<User> Search(Func<User, bool> filter) => _storeContext.Users.Where(filter).ToList();

        public void Update(User entity)
        {
            _storeContext.Users.Attach(entity);
            _storeContext.Users.Entry(entity).State = EntityState.Modified;
        }
    }
}
