using AutoMapper;
using Backend.DTOs;
using Backend.DTOs.Beer;
using Backend.DTOs.Brand;
using Backend.Models;

namespace Backend.AutoMappers
{
    public class MappingProfile : Profile
    {
        public MappingProfile() 
        {
            //Beer
            CreateMap<BeerInsertDTO, Beer>();
            CreateMap<Beer, BeerDTO>()
                .ForMember(dto => dto.Id,
                m => m.MapFrom(b => b.BeerID));
            CreateMap<BeerUpdateDTO, Beer>();

            //Brand
            CreateMap<BrandInsertDTO, Brand>();
            CreateMap<Brand, BrandDTO>()
                .ForMember(dto => dto.Id,
                m => m.MapFrom(b => b.BrandID));
            CreateMap<BrandUpdateDTO, Brand>();

            //User
            CreateMap<UserLogingDTO, User>()
            .ForMember(dest => dest.LastToken, opt => opt.MapFrom(src => "ninguno")); 

            CreateMap<User, UserDTO>();

        }
    }
}
