using AutoMapper;
using Core.DTOs;
using Core.DTOs.Beer;
using Core.DTOs.Brand;
using Core.Models;

namespace BeerShop.Aplication.AutoMappers
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
