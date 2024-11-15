using AutoMapper;
using Core.DTOs.Brand;
using Core.Interfaces;
using Core.Models;

namespace BeerShop.Aplication.Services
{
    public class BrandService : ICommonService<BrandDTO, BrandInsertDTO, BrandUpdateDTO>
    {
        public List<string> Errors { get; }

        private IUnitOfWork _unitOfWork;
        IMapper _mappingProfile;

        public BrandService(IUnitOfWork unitOfWork, IMapper mappingProfile)
        {
            Errors = new List<string>();
            _unitOfWork = unitOfWork;
            _mappingProfile = mappingProfile;
        }


        public async Task<IEnumerable<BrandDTO>> Get()
        {
            var brands = await _unitOfWork.BrandRepository.Get();
            return brands.Select(brand => _mappingProfile.Map<BrandDTO>(brand));
        }

        public async Task<BrandDTO> GetByID(int id)
        {
            var brand = await _unitOfWork.BrandRepository.GetById(id);
            return _mappingProfile.Map<BrandDTO>(brand);
        }

        public async Task<BrandDTO> Add(BrandInsertDTO brandInsertDTO)
        {
            var brand = _mappingProfile.Map<Brand>(brandInsertDTO);

            await _unitOfWork.BrandRepository.Add(brand);
            await _unitOfWork.Save();

            var brandDTO = _mappingProfile.Map<BrandDTO>(brand);
            return brandDTO;
        }
        public async Task<BrandDTO> Update(int id, BrandUpdateDTO brandUpdateDTO)
        {
            var brand = await _unitOfWork.BrandRepository.GetById(id);

            if (brand != null)
            {
                brand = _mappingProfile.Map(brandUpdateDTO, brand);

                _unitOfWork.BrandRepository.Update(brand);
                await _unitOfWork.Save();

                var brandDTO = _mappingProfile.Map<BrandDTO>(brand);
                return brandDTO;
            }

            return null;
        }

        public async Task<BrandDTO> Delete(int id)
        {
            var brand = await _unitOfWork.BrandRepository.GetById(id);
            if (brand != null)
            {
                _unitOfWork.BrandRepository.Delete(brand);
                var brandDTO = _mappingProfile.Map<BrandDTO>(brand);
                await _unitOfWork.Save();

                return brandDTO;
            }

            return null;
        }

        public bool Validate(BrandInsertDTO dto)
        {
            if (_unitOfWork.BrandRepository.Search(b => b.Name == dto.Name).Count() > 0)
            {
                Errors.Add("Este nombre ya existe en otro registro");
                return false;
            }

            return true;
        }

        public bool Validate(BrandUpdateDTO dto)
        {
            if (_unitOfWork.BrandRepository.Search(b => b.Name == dto.Name && b.BrandID != dto.Id).Count() > 0)
            {
                Errors.Add("Este nombre ya existe en otro registro");
                return false;
            }

            return true;
        }
    }
}
