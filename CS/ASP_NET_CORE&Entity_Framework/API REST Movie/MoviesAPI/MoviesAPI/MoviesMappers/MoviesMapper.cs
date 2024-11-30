using AutoMapper;
using MoviesAPI.Models;
using MoviesAPI.Models.DTOs;

namespace MoviesAPI.MoviesMappers
{
    public class MoviesMapper : Profile
    {
        public MoviesMapper()
        {
            CreateMap<Category,CategoryDTO>().ReverseMap();
            CreateMap<Category,CategoryCreateDTO>().ReverseMap();

            CreateMap<Movie, MovieDTO>().ReverseMap();
            CreateMap<Movie, MovieCreateDTO>().ReverseMap();
        }
    }
}
