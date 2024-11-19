using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public interface IUnitOfWork : IDisposable
    {
        //Repositorios
        ICategoryRepository CategoryRepository { get; }
        IArticleRepository ArticleRepository { get; }
        Task Save();
    }
}
