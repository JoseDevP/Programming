using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBase
{
    public class Beer
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int BrandId { get; set; }

        public Beer(int id, string name, int brandID) => (Id,Name,BrandId) = (id,name,brandID);

        public Beer(string name, int brandID) => (Name, BrandId) = (name, brandID);
    }
}
