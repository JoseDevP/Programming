using AutoMapper;
using Backend.DTOs;
using Backend.Models;
using Backend.Repository;
using Microsoft.EntityFrameworkCore;

namespace Backend.Services
{
    public class BeerService : ICommonService<BeerDTO, BeerInsertDTO, BeerUpdateDTO>
    {
        private IRepository<Beer> _beerRepository;
        private IMapper _mapper;

        public List<string> Errors { get; }

        public BeerService([FromKeyedServices("BeerRepository")]IRepository<Beer> beerRepository, IMapper mapper)
        {
            _beerRepository = beerRepository;
            _mapper = mapper;
            Errors = new List<string>();
        }
        public async Task<IEnumerable<BeerDTO>> Get()
        {
            var beers = await _beerRepository.Get();

            return beers.Select(beer => _mapper.Map<BeerDTO>(beer));
        }

        public async Task<BeerDTO> GetByID(int id)
        {
            var beer = await _beerRepository.GetById(id);

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

            await _beerRepository.Add(beer);
            await _beerRepository.Save();

            var beerDTO = _mapper.Map<BeerDTO>(beer);

            return beerDTO;
        }
        public async Task<BeerDTO> Update(int id, BeerUpdateDTO beerUpdateDTO)
        {
            var beer = await _beerRepository.GetById(id);

            if (beer != null)
            {
                beer = _mapper.Map<BeerUpdateDTO, Beer>(beerUpdateDTO,beer);

                _beerRepository.Update(beer);
                await _beerRepository.Save();

                var beerDTO = _mapper.Map<BeerDTO>(beer);

                return beerDTO;
            }

               return null;
        }

        public async Task<BeerDTO> Delete(int id)
        {
            var beer = await _beerRepository.GetById(id);

            if (beer != null)
            {
                var beerDTO = _mapper.Map<BeerDTO>(beer);

                _beerRepository.Delete(beer);
                await _beerRepository.Save();

                return beerDTO;
            }

            return null;
        }

        public bool Validate(BeerInsertDTO beerInsertDTO)
        {
            if(_beerRepository.Search(b => b.Name == beerInsertDTO.Name).Count() > 0)
            {
                Errors.Add("No puede existir una cerveza con un nombre ya existente");
                return false;
            }

            return true;
        }

        public bool Validate(BeerUpdateDTO beerUpdateDTO)
        {
            if (_beerRepository.Search(b => b.Name == beerUpdateDTO.Name && b.BeerID != beerUpdateDTO.Id).Count() > 0)
            {
                Errors.Add("No puede existir una cerveza con un nombre ya existente");
                return false;
            }
            return true;
        }
    }
}
