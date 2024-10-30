using AutoMapper;
using Backend.DTOs;
using Backend.Models;

namespace Backend.AutoMappers
{
    public class MappingProfile : Profile
    {
        public MappingProfile() 
        {
            CreateMap<BeerInsertDTO, Beer>();
            CreateMap<Beer, BeerDTO>()
                .ForMember(dto => dto.Id,
                m => m.MapFrom(b => b.BeerID));
            CreateMap<BeerUpdateDTO, Beer>();

            CreateMap<BrandInsertDTO, Brand>();
            CreateMap<Brand, BrandDTO>()
                .ForMember(dto => dto.Id,
                m => m.MapFrom(b => b.BrandID));
            CreateMap<BrandUpdateDTO, Brand>();
        }
    }
}
