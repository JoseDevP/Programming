using MoviesAPI.Models;
using System.Linq.Expressions;

namespace MoviesAPI.Repository.IRepository
{
    public interface IMovieRepository : IRepository<Movie>
    {
        void UpdateMovie(Movie movie);
        Task<bool> ElementExist(string name);
        Task<ICollection<Movie>> GetMoviesInCategory(int catId);
        Task<IEnumerable<Movie>> SearchMovie(string name);
    }
}
