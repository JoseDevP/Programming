using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericAdvanced
{
    public class Randoms
    {
        private double _number;
        public double Number => _number;

        public Randoms() 
        {
            _number = new Random().NextDouble();
        }
    }
}
