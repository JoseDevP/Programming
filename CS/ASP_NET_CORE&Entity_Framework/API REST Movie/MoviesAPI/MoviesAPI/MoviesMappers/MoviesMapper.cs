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

            CreateMap<User, UserDataDTO>().ReverseMap();
            CreateMap<User, UserDTO>().ReverseMap();
            CreateMap<User, UserLoggingDTO>().ReverseMap();
            CreateMap<User, UserLogingResponseDTO>().ReverseMap();
            CreateMap<User, UserRegisterDTO>().ReverseMap();
        }
    }
}
