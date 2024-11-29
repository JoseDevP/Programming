namespace MoviesAPI.Repository.IRepository
{
    public interface IUnitOfWork : IDisposable
    {
        CategoryRepository CategoryRepository { get; }
        Task<bool> Save();
    }
}
