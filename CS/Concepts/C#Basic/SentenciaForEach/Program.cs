using System;
using System.Collections.Generic;

namespace SentenciaForEach
{
    class Program
    {
        static void Main(string[] args)
        {
            var numbers = new List<int>()
            {
                23,3,5,10,22,12
            };

            foreach (var number in numbers)
            {
                Console.WriteLine(number);
            }

            var students = new List<People>()
            {
                new People{Name = "Hector", Country = "Mexico"},
                new People{Name = "Roberto", Country = "Argentina"},
                new People{Name = "Ana", Country = "Estados Unidos"},
            };

            Show(students);

            students.RemoveAt(0);

            Show(students);

        }

        static void Show(List<People> students)
        {
            Console.Write("-- Personas --\n");
            foreach (var people in students)
            {
                Console.WriteLine($"Nombre: {people.Name}, País: {people.Country}");
            }
        }
    }

    class People
    {
        public string Name { get; set; }
        public string Country { get; set; }
    }
}