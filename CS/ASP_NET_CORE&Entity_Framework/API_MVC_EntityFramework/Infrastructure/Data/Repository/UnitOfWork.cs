using Core.Interfaces;
using Infrastructure.Data;

namespace Infrastructure.Data.Repository
{
    public class UnitOfWork : IUnitOfWork
    {
        private readonly StoreContext _storeContext;
        public IBrandRepository BrandRepository { get; private set; }

        public IBeerRepository BeerRepository { get; private set; }

        public IUserRepository UserRepository { get; private set; }

        public UnitOfWork(StoreContext storeContext)
        {
            _storeContext = storeContext;
            BeerRepository = new BeerRepository(_storeContext);
            BrandRepository = new BrandRepository(_storeContext);
            UserRepository = new UserRepository(_storeContext);
        }

        public void Dispose() => _storeContext.Dispose();


        public async Task Save() => await _storeContext.SaveChangesAsync();
    }
}
