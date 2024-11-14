namespace BeerShop.Core.Interfaces
{
    public interface IUserRepository : IRepository<User>
    {
        public void Update(User entity);
    }
}
