using System;
using System.Collections.Generic;

namespace ListCommonMethods
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> numbers = new List<int>()
            {
                4,3,5,19
            };

            //Insert
            numbers.Insert(1, 6);

            //Contains

            if (numbers.Contains(3))
                Console.WriteLine("Existe");
            else
                Console.WriteLine("No Existe");

            //IndexOf

            int pos = numbers.IndexOf(100);

            Console.WriteLine(pos);

            //Sort

            numbers.Sort();


            //AddRange
            numbers.AddRange(new List<int>()
            {
                200,300,400
            });

            Show(numbers);
        }

        public static void Show(List<int> numbers)
        {
            Console.WriteLine("-- Numeros --\n");

            foreach (int i in numbers)
            {
                Console.WriteLine($"{i}");
            }
        }
    }
}