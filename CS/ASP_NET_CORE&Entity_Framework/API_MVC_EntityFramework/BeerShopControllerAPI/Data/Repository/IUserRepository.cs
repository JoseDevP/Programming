using Backend.Data.Repository;

namespace BeerShop.Data.Repository
{
    public interface IUserRepository : IRepository<User>
    {
        public void Update(User entity);
    }
}
