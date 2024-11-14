using AutoMapper;
using BeerShop.Aplication.DTOs.Beer;
using BeerShop.Core.Interfaces;
using BeerShop.Core.Models;
using Microsoft.EntityFrameworkCore;

namespace BeerShop.Aplication.Services
{
    public class BeerService : ICommonService<BeerDTO, BeerInsertDTO, BeerUpdateDTO>
    {
        private IUnitOfWork _unitOfWork;
        private IMapper _mapper;

        public List<string> Errors { get; }

        public BeerService(IUnitOfWork unitOfWork, IMapper mapper)
        {
            _unitOfWork = unitOfWork;
            _mapper = mapper;
            Errors = new List<string>();
        }
        public async Task<IEnumerable<BeerDTO>> Get()
        {
            var beers = await _unitOfWork.BeerRepository.Get();

            return beers.Select(beer => _mapper.Map<BeerDTO>(beer));
        }

        public async Task<BeerDTO> GetByID(int id)
        {
            var beer = await _unitOfWork.BeerRepository.GetById(id);

            if (beer != null)
            {
                var beerDTO = _mapper.Map<BeerDTO>(beer);

                return beerDTO;
            }

            return null;
        }

        public async Task<BeerDTO> Add(BeerInsertDTO beerInsertDTO)
        {
            var beer = _mapper.Map<Beer>(beerInsertDTO);

            await _unitOfWork.BeerRepository.Add(beer);
            await _unitOfWork.Save();

            var beerDTO = _mapper.Map<BeerDTO>(beer);

            return beerDTO;
        }
        public async Task<BeerDTO> Update(int id, BeerUpdateDTO beerUpdateDTO)
        {
            var beer = await _unitOfWork.BeerRepository.GetById(id);

            if (beer != null)
            {
                beer = _mapper.Map(beerUpdateDTO, beer);

                _unitOfWork.BeerRepository.Update(beer);
                await _unitOfWork.Save();

                var beerDTO = _mapper.Map<BeerDTO>(beer);

                return beerDTO;
            }

            return null;
        }

        public async Task<BeerDTO> Delete(int id)
        {
            var beer = await _unitOfWork.BeerRepository.GetById(id);

            if (beer != null)
            {
                var beerDTO = _mapper.Map<BeerDTO>(beer);

                _unitOfWork.BeerRepository.Delete(beer);
                await _unitOfWork.Save();

                return beerDTO;
            }

            return null;
        }

        public bool Validate(BeerInsertDTO beerInsertDTO)
        {
            if (_unitOfWork.BeerRepository.Search(b => b.Name == beerInsertDTO.Name).Count() > 0)
            {
                Errors.Add("No puede existir una cerveza con un nombre ya existente");
                return false;
            }

            return true;
        }

        public bool Validate(BeerUpdateDTO beerUpdateDTO)
        {
            if (_unitOfWork.BeerRepository.Search(b => b.Name == beerUpdateDTO.Name && b.BeerID != beerUpdateDTO.Id).Count() > 0)
            {
                Errors.Add("No puede existir una cerveza con un nombre ya existente");
                return false;
            }
            return true;
        }
    }
}
