using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Funciones
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Sumar(2, 3));
            Console.WriteLine(Restar(2, 3));
            Console.WriteLine(Multiplicar(2, 3));
        }

        static int Sumar(int a, int b)
        {
            return a + b;
        }

        static int Restar(int a, int b)
        {
            return a - b;
        }

        static int Multiplicar(int a, int b)
        {
            return a * b;
        }
    }
}
