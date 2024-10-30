using System.Data.SqlClient;
using System.Collections.Generic;

namespace DataBase
{
    class Program
    {
        public static void Main(string[] args) 
        {
            //Para Entity Framework -> Scaffold-DbContext "Server=localhost\SQLEXPRESS;Database=CsharpDB;User ID=Jose;Password=1234;" Microsoft.EntityFrameworkCore.SqlServer -OutputDir Models
            //con windows Trusted_Connection=True;

            //Para actualizar mismo comando con -force

            try
            {
                BeerDB beerDB = new BeerDB(@"localhost\SQLEXPRESS", "CsharpDB", "Jose", "1234");
                bool again = true;
                int op = 0;

                do
                {
                    Console.WriteLine("Elije opcion 1 - 5");
                    ShowMenu();
                    op = int.Parse(Console.ReadLine());

                    switch (op)
                    {
                        case 1://mostrar
                            Show(beerDB);
                            break;

                        case 2://insert
                            Add(beerDB);
                            break;

                        case 3://editar
                            Edit(beerDB);
                            break;

                        case 4://delete
                            Delete(beerDB);
                            break;

                        case 5://salir
                            again = false;
                            break;
                    }
                }
                while (again);

                
            }
            catch (SqlException ex) 
            {
                Console.WriteLine(ex.Message);
            }
            
        }

        public static void ShowMenu()
        {
            Console.WriteLine("\n------------Menu------------------");
            Console.WriteLine("1.-Mostrar");
            Console.WriteLine("2.-Agregar");
            Console.WriteLine("3.-Editar");
            Console.WriteLine("4.-Eliminar");
            Console.WriteLine("5.-Salir");
        }

        public static void Show(BeerDB beerDB)
        {
            Console.Clear();
            Console.WriteLine("Cervezas de la DB\n");

            List<Beer> beers = beerDB.GetAll();

            foreach (var beer in beers)
                Console.WriteLine($"Id: {beer.Id}, Nombre: {beer.Name}");
        }

        public static void Add(BeerDB beerDB)
        {
            Console.Clear();
            Console.WriteLine("Agregar nueva cerveza");
            Console.WriteLine("Escribe el nombre:");
            string name = Console.ReadLine();
            Console.WriteLine("Escribe el id de la marca:");
            int brandId = int.Parse(Console.ReadLine());

            Beer beer = new Beer(name,brandId);

            beerDB.Add(beer);
        }

        public static void Edit(BeerDB beerDB)
        {
            Console.Clear();
            Show(beerDB);
            Console.WriteLine("Editar Cerveza");
            Console.WriteLine("Escribe el Id de tu cerveza a editar");
            int id = int.Parse(Console.ReadLine());

            Beer beer = beerDB.Get(id);
            if(beer != null )
            {
                Console.WriteLine("Escribe el nombre: ");
                string name = Console.ReadLine();
                Console.WriteLine("Escribe el id de la marca: ");
                int brandId = int.Parse(Console.ReadLine());

                beer.Name = name;
                beer.BrandId = brandId;

                beerDB.Edit(beer);

            }
            else { Console.WriteLine("La cerveza no existe"); }

        }

        public static void Delete(BeerDB beerDB)
        {
            Console.Clear();
            Show(beerDB);
            Console.WriteLine("Eliminar Cerveza");
            Console.WriteLine("Escribe el Id de tu cerveza a eliminar");
            int id = int.Parse(Console.ReadLine());

            Beer beer = beerDB.Get(id);
            if (beer != null)
                beerDB.Delete(id);
            else { Console.WriteLine("La cerveza no existe"); }

        }
    }
}