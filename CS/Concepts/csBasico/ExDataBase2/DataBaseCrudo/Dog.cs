using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBase2
{
    public class Dog
    {
        public int ID {  get; set; }
        public string Name { get; set; }
        public int BreedID { get; set; }

        public Dog(int id, string name, int breedId) => (ID, Name, BreedID) = (id,name,breedId);
        public Dog(string name, int breedId) => (Name, BreedID) = (name,breedId);
    }
}
