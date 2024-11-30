using Microsoft.EntityFrameworkCore;
using MoviesAPI.Data;
using MoviesAPI.Models;
using MoviesAPI.Repository.IRepository;
using System.Linq.Expressions;
using System.Xml.Linq;

namespace MoviesAPI.Repository
{
    public class MovieRepository : Repository<Movie>, IMovieRepository
    {
        private readonly ApplicationDbContext _db;

        public MovieRepository(ApplicationDbContext db) : base(db)
        {
            _db = db;
        }

        public void UpdateMovie(Movie movie)
        {
            movie.CreationDate = DateTime.Now;
            _db.Movie.Update(movie);
        }

        public async Task<bool> ElementExist(string name)
        {
            return await _db.Movie.AnyAsync(e => e.Name == name);
        }

        public async Task<ICollection<Movie>> GetMoviesInCategory(int catId)
        {
            return await _db.Movie.Include(e => e.Category).Where(ca=>ca.CategoryId == catId).ToListAsync();
        }

        public async Task<IEnumerable<Movie>> SearchMovie(string name)
        {
            IQueryable<Movie> query = _db.Movie;
            if (!string.IsNullOrEmpty(name))
            {
                query = query.Where(e => e.Name.Contains(name) || e.Description.Contains(name));
            }
            return await query.ToListAsync();
        }
    }
}
