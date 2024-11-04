using AutoMapper;
using Backend.AutoMappers;
using Backend.Data.Repository;
using Backend.DTOs.Brand;
using Backend.Models;

namespace Backend.Services
{
    public class BrandService : ICommonService<BrandDTO, BrandInsertDTO, BrandUpdateDTO>
    {
        public List<string> Errors { get; }

        IRepository<Brand> _repository;
        IMapper  _mappingProfile;

        public BrandService([FromKeyedServices("BrandRepository")] IRepository<Brand> repository, IMapper mappingProfile)
        {
            Errors = new List<string>();
            _repository = repository;
            _mappingProfile = mappingProfile;
        }


        public async Task<IEnumerable<BrandDTO>> Get()
        {
            var brands = await _repository.Get();
            return brands.Select(brand => _mappingProfile.Map<BrandDTO>(brand));
        }

        public async Task<BrandDTO> GetByID(int id)
        {
            var brand = await _repository.GetById(id);
            return _mappingProfile.Map<BrandDTO>(brand);
        }

        public async Task<BrandDTO> Add(BrandInsertDTO brandInsertDTO)
        {
            var brand = _mappingProfile.Map<Brand>(brandInsertDTO);

            await _repository.Add(brand);
            await _repository.Save();
             
            var brandDTO = _mappingProfile.Map<BrandDTO>(brand);
            return brandDTO;
        }
        public async Task<BrandDTO> Update(int id, BrandUpdateDTO brandUpdateDTO)
        {
            var brand = await _repository.GetById(id);
            
            if(brand != null)
            {
                brand = _mappingProfile.Map<BrandUpdateDTO, Brand>(brandUpdateDTO,brand);

                _repository.Update(brand);
                await _repository.Save();

                var brandDTO = _mappingProfile.Map<BrandDTO>(brand);
                return brandDTO;
            }

            return null;
        }

        public async Task<BrandDTO> Delete(int id)
        {
            var brand = await _repository.GetById(id);
            if(brand != null)
            {
                _repository.Delete(brand);
                var brandDTO = _mappingProfile.Map<BrandDTO>(brand);
                await _repository.Save();

                return brandDTO;
            }

            return null;
        }

        public bool Validate(BrandInsertDTO dto)
        {
            if(_repository.Search(b => b.Name == dto.Name).Count() > 0)
            {
                Errors.Add("Este nombre ya existe en otro registro");
                return false;
            }

            return true;
        }

        public bool Validate(BrandUpdateDTO dto)
        {
            if(_repository.Search(b => b.Name == dto.Name && b.BrandID != dto.Id).Count() > 0)
            {
                Errors.Add("Este nombre ya existe en otro registro");
                return false;
            }

            return true;
        }
    }
}
