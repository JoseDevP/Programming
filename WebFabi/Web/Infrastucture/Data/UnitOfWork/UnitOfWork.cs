using Core.Interfaces;
using Infrastucture.Data.UnitOfWork.Repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Web.Data;

namespace Infrastucture.Data.UnitOfWork
{
    public class UnitOfWork : IUnitOfWork
    {
        private readonly ApplicationDbContext _applicationDbContext;
        public ICategoriesRepository _categoriesRepository { get; }


        public UnitOfWork(ApplicationDbContext applicationDbContext) 
        {
            _applicationDbContext = applicationDbContext;
            _categoriesRepository = new CategoriesRepository(_applicationDbContext);
        }

        public void Dispose()
        {
            _applicationDbContext.Dispose();
        }

        public async Task<bool> Save()
        {
            return await _applicationDbContext.SaveChangesAsync() > 0;
        }
    }
}
