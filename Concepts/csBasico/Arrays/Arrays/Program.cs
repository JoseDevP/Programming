using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arrays
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] friends = new string[6] 
            {
                "Antonio",
                "Pedro",
                "Juan",
                "Maite",
                "Juana",
                "Lana",
            };

            foreach (var f in friends)
                Console.WriteLine(f);
        }
    }
}
