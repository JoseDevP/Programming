namespace MoviesAPI.Repository.IRepository
{
    public interface IUnitOfWork : IDisposable
    {
        CategoryRepository CategoryRepository { get; }
        MovieRepository MovieRepository { get; }
        UserRepository UserRepository { get; }
        Task<bool> Save();
    }
}
