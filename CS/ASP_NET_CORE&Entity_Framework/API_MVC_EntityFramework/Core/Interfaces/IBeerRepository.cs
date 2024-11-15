using Core.Models;

namespace Core.Interfaces
{
    public interface IBeerRepository : IRepository<Beer>
    {
        public void Update(Beer entity);
    }
}
