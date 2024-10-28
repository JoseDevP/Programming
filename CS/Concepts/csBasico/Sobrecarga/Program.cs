using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sobrecarga
{
    class Program
    {
        static void Main(string[] args)
        {
            Math math = new Math();
            Console.WriteLine(math.Sum(1, 2));
            Console.WriteLine(math.Sum("1", "2"));
            int[] arrayInt = new int[] { 1, 2, 5 };
            Console.WriteLine(math.Sum(arrayInt));
        }
    }

    class Math
    {
        public int Sum(int a, int b) => a + b;
        public int Sum(string a, string b) => int.Parse(a) + int.Parse(b);
        public int Sum(int[] numbers)
        {
            int result = 0;
            int i = 0;

            while(i < numbers.Length)
            {
                result += numbers[i];
                i++;
            }

            return result;
        }
    }
}
