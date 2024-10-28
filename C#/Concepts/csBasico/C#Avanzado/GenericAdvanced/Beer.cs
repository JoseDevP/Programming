using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericAdvanced
{
    public class Beer : Drink, IInfo
    {
        private string _name;

        public string Name
        {
            get => _name;
        }

        public Beer(string name, double quanitty) : base(quanitty) => _name = name;

        public string GetInfo() => _name +" " + Quantity + " ml";

        
    }
}
