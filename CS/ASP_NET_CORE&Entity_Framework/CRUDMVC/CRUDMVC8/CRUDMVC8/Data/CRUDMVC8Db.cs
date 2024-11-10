using CRUDMVC8.Models;
using Microsoft.EntityFrameworkCore;

namespace CRUDMVC8.Data
{
    public class CRUDMVC8Db : DbContext
    {
        public CRUDMVC8Db(DbContextOptions dbContextOptions) : base(dbContextOptions) 
        {

        }

        public DbSet<Person> _persons {  get; set; }
    }
}
