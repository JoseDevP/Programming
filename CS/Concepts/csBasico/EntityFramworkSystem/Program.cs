using BD;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Options;
using System.Linq;

namespace EntityFramework
{
    class Program
    {
        public static void Main(string[] args)
        {
            try
            {
                DbContextOptionsBuilder<CsharpDBContext> optionsBuilder = new DbContextOptionsBuilder<CsharpDBContext>();

                optionsBuilder.UseSqlServer("Server=localhost\\SQLEXPRESS;Database=CsharpDB;User ID=Jose;Password=1234;");

                bool again = true;
                int op = 0;

                do
                {
                    ShowMenu();
                    Console.WriteLine("Elije la opción:");
                    op = int.Parse(Console.ReadLine());

                    switch (op)
                    {
                        case 1://Mostrar todos
                            Show(optionsBuilder);
                            break;
                        case 2:
                            Add(optionsBuilder);
                            break;
                        case 3://Edit
                            Edit(optionsBuilder);
                            break;
                        case 4://Borrar
                            Delete(optionsBuilder);
                            break;
                        case 5://Salir
                            again = false;
                            break;
                    }
                } while (again);

            }
            catch (Exception ex) { Console.WriteLine(ex.Message); }

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

        public static void Show(DbContextOptionsBuilder<CsharpDBContext> optionsBuilder)
        {
            Console.Clear();
            Console.WriteLine("Cervezas en la base de datos:");
            using (var context = new CsharpDBContext(optionsBuilder.Options))
            {
                List<Beer> beers = context.Beers.OrderBy((b) => b.Name).Include(b => b.Brand).ToList();
                List<Beer> beers2 = (from b in context.Beers
                                     where b.BrandId == 2
                                     orderby b.Name
                                     select b).Include(b => b.Brand).ToList();
                foreach (var beer in beers)
                {
                    Console.WriteLine($"Id: {beer.Id}, Beer: {beer.Name}, Marca: {beer.Brand.Name}");
                }
            }
        }

        public static void Add(DbContextOptionsBuilder<CsharpDBContext> optionsBuilder)
        {
            Console.Clear();
            Console.WriteLine("Agregar nueva cerveza");
            Console.WriteLine("Escribe el nombre:");
            string name = Console.ReadLine();
            Console.WriteLine("Escribe el id de la marca");
            int brandId = int.Parse(Console.ReadLine());

            using (var context = new CsharpDBContext(optionsBuilder.Options))
            {
                Beer beer = new Beer()
                {
                    Name = name,
                    BrandId = brandId
                };
                context.Beers.Add(beer);
                context.SaveChanges();
            }
        }

        public static void Edit(DbContextOptionsBuilder<CsharpDBContext> optionsBuilder)
        {
            Console.Clear();
            Show(optionsBuilder);
            Console.WriteLine("Editar Cerveza");
            Console.WriteLine("Escribe el id");
            int id = int.Parse(Console.ReadLine());

            using (var context = new CsharpDBContext(optionsBuilder.Options))
            {
                Beer beer = context.Beers.Find(id);
                if (beer != null)
                {
                    Console.WriteLine("Escribe el nombre");
                    string name = Console.ReadLine();
                    Console.WriteLine("Escribe el id de la marca");
                    int brandId = int.Parse(Console.ReadLine());

                    beer.Name = name;
                    beer.BrandId = brandId;

                    context.Entry(beer).State = EntityState.Modified;
                    context.SaveChanges();

                }
                else Console.WriteLine("No existe");
            }
        }

        public static void Delete(DbContextOptionsBuilder<CsharpDBContext> optionsBuilder)
        {
            Console.Clear();
            Show(optionsBuilder);
            Console.WriteLine("Eliminar Cerveza");
            Console.WriteLine("Escribe el id");
            int id = int.Parse(Console.ReadLine());

            using (var context = new CsharpDBContext(optionsBuilder.Options))
            {
                Beer beer = context.Beers.Find(id);
                if (beer != null)
                {
                    context.Beers.Remove(beer);
                    context.SaveChanges();

                }
                else Console.WriteLine("No existe");
            }
        }
    }
}