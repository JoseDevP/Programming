using System;
using System.Collections.Generic;
using System.Linq;

namespace LINQ
{
    class Program
    {
        public static void Main(string[] args)
        {
            List<Beer> beers = new List<Beer>()
            {
                new Beer()
                {
                    Name = "Corona", Country ="México"
                },
                new Beer()
                {
                    Name = "Delirium", Country ="Bélgica"
                },
                new Beer()
                {
                    Name = "Erdinger", Country ="Alemania"
                },
            };

            foreach (Beer beer in beers)
                Console.WriteLine(beer);

            Console.WriteLine("------------------------------");

            //Select

            var beersName = from b in beers select new {Name = b.Name, Letters = b.Name.Length};

            foreach (var beer in beersName)
                Console.WriteLine($"Name: {beer.Name}, Letters: {beer.Letters}");

            Console.WriteLine("------------------------------");

            var beersNameReal = from b in beers select new { Name = b.Name };
            foreach (var beer in beersNameReal)
                Console.WriteLine($"Name: {beer.Name}");

            Console.WriteLine("------------------------------");

            var beersMexico = from b in beers where b.Country == "México" || b.Country == "Alemania" select b;
            foreach (var beer in beersMexico)
                Console.WriteLine(beer);

            Console.WriteLine("------------------------------");
            var orderedBeers = from b in beers orderby b.Country select b;
            foreach (var beer in orderedBeers)
                Console.WriteLine(beer);
        }
    }

    class Beer
    {
        public string Name { get; set; }
        public string Country { get; set; }
        public override string ToString()
        {
            return $"Nombre: {Name}, Pais: {Country}";
        }

    }
}