using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SetenciaFor
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] friends = new string[]
            {
                "Antonio",
                "Pedro",
                "Maite",
                "Antonia"
            };

            for (int i = 0; i < friends.Length; i++)
                Console.WriteLine(friends[i]);
        }
    }
}
