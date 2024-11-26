namespace Core.Interfaces
{
    public interface IUnitOfWork : IDisposable
    {
        IBrandRepository BrandRepository { get; }
        IBeerRepository BeerRepository { get; }
        IUserRepository UserRepository { get; }
        Task Save();
    }
}
