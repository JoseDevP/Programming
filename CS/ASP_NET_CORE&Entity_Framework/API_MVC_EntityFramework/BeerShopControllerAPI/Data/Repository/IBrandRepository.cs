using Backend.Data.Repository;
using Backend.Models;

namespace BeerShop.Data.Repository
{
    public interface IBrandRepository : IRepository<Brand>
    {
        public void Update(Brand entity);
    }
}
