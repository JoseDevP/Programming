using BlogCore.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public class WorkContainer : IWorkContainer
    {
        private readonly ApplicationDbContext _db;
        public ICategoryRepository _categoryRepository { get; private set; }

        public WorkContainer(ApplicationDbContext db)
        {
            _db = db;
            _categoryRepository = new CategoryRepository(_db);
        }


        public void Dispose()
        {
            _db.Dispose();
        }

        public async Task Save()
        {
            await _db.SaveChangesAsync();
        }
    }
}
