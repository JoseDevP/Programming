using System;

namespace TiposAnonimos
{
    class Program
    {
        static void Main(string[] args)
        {
            var jose = new  // solo readonly
            {
                Name = "Jose",
                Country = "Spain"
            };

            Console.WriteLine($"Nombre: {jose.Name}, Pais: {jose.Country}");

            var beers = new[]
            {
                new {Name = "Red",  Brand = "Delirium"},
                new {Name = "London Porter", Brand = "Fullers"}
            };

            foreach ( var b in beers)
            {
                Console.WriteLine($"Nombre: {b.Name}, Brand: {b.Brand}");
            }
        }
    }
}