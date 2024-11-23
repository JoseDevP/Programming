using BlogCore.Data;
using BlogCore.Models;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public class UserRepository : Repository<ApplicationUser>, IUserRepository
    {
        private readonly ApplicationDbContext _applicationDbContext;

        public UserRepository(ApplicationDbContext applicationDbContext) : base(applicationDbContext)
        {
            _applicationDbContext = applicationDbContext;
        }

        public async Task BlockUser(string idUser)
        {
            var userFromDb = await _applicationDbContext.ApplicationUsers.FirstOrDefaultAsync(u => u.Id == idUser);
            userFromDb.LockoutEnd = DateTime.Now.AddYears(1000);
            await _applicationDbContext.SaveChangesAsync();

        }

        public async Task UnBlockUser(string idUser)
        {
            var userFromDb = await _applicationDbContext.ApplicationUsers.FirstOrDefaultAsync(u => u.Id == idUser);
            userFromDb.LockoutEnd = DateTime.Now;
            await _applicationDbContext.SaveChangesAsync();
        }
    }
}
