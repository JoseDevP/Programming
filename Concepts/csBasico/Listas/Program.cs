using System;
using System.Collections.Generic;
using System.Text.Json;

namespace SerializacionJson
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> numbers2 = new List<int>()
            {
                    1,2,3,4,5
            };

            numbers2.Add(55);

            Console.WriteLine(numbers2.Count);

            numbers2.Clear();

            Console.WriteLine(numbers2.Count);


            List<string> countries = new List<string>()
            {
                "México", "Argentina", "España"
            };

            Console.WriteLine(countries.Count);

        }

    }
}