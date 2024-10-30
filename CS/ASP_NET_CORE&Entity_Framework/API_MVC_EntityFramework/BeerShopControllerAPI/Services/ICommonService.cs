using Backend.DTOs;
using Backend.Models;
using Microsoft.AspNetCore.Mvc;

namespace Backend.Services
{
    public interface ICommonService<T, TI, TU>
    {
        public List<string> Errors { get; }
        Task<IEnumerable<T>> Get();
        Task<T> GetByID(int id);

        Task<T> Add(TI beerInsertDTO);

        Task<T> Update(int id, TU beerUpdateDTO);

        Task<T> Delete(int id);

        bool Validate(TI dto);
        bool Validate(TU dto);

    }
}
