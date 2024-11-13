using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public interface IWorkContainer : IDisposable
    {
        //Repositorios
        ICategoryRepository _categoryRepository { get; }
        Task Save();
    }
}
