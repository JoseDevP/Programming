using BeerShop.Core.Models;

namespace BeerShop.Core.Interfaces
{
    public interface IBrandRepository : IRepository<Brand>
    {
        public void Update(Brand entity);
    }
}
