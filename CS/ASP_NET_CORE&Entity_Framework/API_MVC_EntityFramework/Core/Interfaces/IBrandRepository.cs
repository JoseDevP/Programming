using Core.Models;

namespace Core.Interfaces
{
    public interface IBrandRepository : IRepository<Brand>
    {
        public void Update(Brand entity);
    }
}
