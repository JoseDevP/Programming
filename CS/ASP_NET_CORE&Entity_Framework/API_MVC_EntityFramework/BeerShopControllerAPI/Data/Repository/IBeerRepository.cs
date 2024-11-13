using Backend.Data.Repository;
using Backend.Models;
using Microsoft.EntityFrameworkCore;

namespace BeerShop.Data.Repository
{
    public interface IBeerRepository : IRepository<Beer>
    {
        public void Update(Beer entity);
    }
}
