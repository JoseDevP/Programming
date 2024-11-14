using BeerShop.Core.Models;
using Microsoft.EntityFrameworkCore;

namespace BeerShop.Core.Interfaces
{
    public interface IBeerRepository : IRepository<Beer>
    {
        public void Update(Beer entity);
    }
}
