using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBase2
{
    public class Breed
    {
        public int ID { get; set; }
        public string Name { get; set; }

        public Breed(int id, string name) => (ID, Name) = (id, name);
        public Breed(string name) => (Name) = (name);
    }
}
