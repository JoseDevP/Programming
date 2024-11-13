using Backend.Data.Repository;
using Backend.Models;

namespace BeerShop.Data.Repository
{
    public interface IUnitOfWork : IDisposable
    {
        IBrandRepository BrandRepository { get; }
        IBeerRepository BeerRepository { get; }
        IUserRepository UserRepository { get; }
        Task Save();
    }
}
