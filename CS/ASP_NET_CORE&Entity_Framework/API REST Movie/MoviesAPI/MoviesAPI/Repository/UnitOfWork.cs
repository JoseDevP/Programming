using MoviesAPI.Data;
using MoviesAPI.Repository.IRepository;

namespace MoviesAPI.Repository
{
    public class UnitOfWork : IUnitOfWork
    {
        public readonly ApplicationDbContext _db;
        public CategoryRepository CategoryRepository { get; }
        public MovieRepository MovieRepository { get; }
        public UnitOfWork(ApplicationDbContext db)
        {
            _db = db;
            CategoryRepository = new CategoryRepository(db);
            MovieRepository = new MovieRepository(db);
        }
        public void Dispose()
        {
            _db.Dispose();
        }

        public async Task<bool> Save()
        {
            return await _db.SaveChangesAsync() > 0;
        }
    }
}
