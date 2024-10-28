
using DB.Models;
using Microsoft.EntityFrameworkCore;

namespace EmptityFrameworkDB
{
    class Program
    {
        public static void Main(string[] args)
        {
            DbContextOptions<DogDBContext> dbContextOptions = new DbContextOptions<DogDBContext>();
            int op = 0;
            bool again = true;

            do
            {
                Console.WriteLine("Elije opcion 1 - 6");
                ShowMenu();
                op = int.Parse(Console.ReadLine());

                switch (op)
                {
                    case 1://mostrar
                        Show(dbContextOptions);
                        break;

                    case 2://insert dog
                        AddDog(dbContextOptions);
                        break;

                    case 3://inser breed
                        AddBreed(dbContextOptions);
                        break;

                    case 4://editar
                        Edit(dbContextOptions);
                        break;

                    case 5://delete
                        Delete(dbContextOptions);
                        break;

                    case 6://salir
                        again = false;
                        break;
                }
            }
            while (again);
        }

        public static void ShowMenu()
        {
            Console.WriteLine("\n------------Menu------------------");
            Console.WriteLine("1.-Mostrar");
            Console.WriteLine("2.-Agregar Perro");
            Console.WriteLine("3.-Agregar Raza");
            Console.WriteLine("4.-Editar");
            Console.WriteLine("5.-Eliminar");
            Console.WriteLine("6.-Salir");
        }

        public static void Show(DbContextOptions<DogDBContext> dbContextOptions)
        {
            try
            {
                Console.Clear();

                using (var context = new DogDBContext(dbContextOptions))
                {
                    Console.WriteLine("Perros:");
                    List<Dog> dogList = context.Dogs.Include(d => d.Breed).ToList();
                    if (dogList.Count > 0)
                    {
                        foreach (Dog dog in dogList)
                            Console.WriteLine($"Id: {dog.Id}, Nombre: {dog.Name}, Raza: {dog.Breed.Name}");
                    }
                    else { Console.WriteLine("No hay perros aún"); }

                    Console.WriteLine("Razas:");
                    List<Breed> breedList = context.Breeds.ToList();
                    if (breedList.Count > 0)
                    {
                        foreach (Breed breed in breedList)
                            Console.WriteLine($"Id: {breed.Id}, Nombre: {breed.Name}");
                    }
                    else { Console.WriteLine("No hay razas aún"); }

                    Console.WriteLine("\n");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            
        }

        public static void AddDog(DbContextOptions<DogDBContext> dbContextOptions)
        {
            try
            {
                Console.Clear();

                using (var context = new DogDBContext(dbContextOptions))
                {
                    Console.WriteLine("Nuevo Perro:");
                    Console.WriteLine("Nombre:");
                    string name = Console.ReadLine();
                    Console.WriteLine("Id de Raza:");
                    int breedId = int.Parse(Console.ReadLine());
                    Dog dog = new Dog() { Name = name, BreedId = breedId };

                    context.Dogs.Add(dog);
                    context.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            
        }
        public static void AddBreed(DbContextOptions<DogDBContext> dbContextOptions)
        {
            try
            {
                Console.Clear();
                using (var context = new DogDBContext(dbContextOptions))
                {
                    Console.WriteLine("Nueva Raza:");
                    Console.WriteLine("Nombre:");
                    string name = Console.ReadLine();

                    Breed breed = new Breed() { Name = name };

                    context.Breeds.Add(breed);
                    context.SaveChanges(); ;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            
        }

        public static void Edit(DbContextOptions<DogDBContext> dbContextOptions)
        {
            try
            {
                Console.Clear();

                using (var context = new DogDBContext(dbContextOptions))
                {
                    Show(dbContextOptions);
                    Console.WriteLine("\nQuieres editar un perro o una raza");
                    string type = "";
                    do
                    {
                        type = Console.ReadLine();
                    }
                    while (type != "perro" && type != "raza");

                    Console.WriteLine("Introduce el id:");
                    int id = int.Parse(Console.ReadLine());

                    if (type == "perro")
                    {
                        Dog dog = context.Dogs.Find(id);
                        if (dog != null)
                        {
                            Console.WriteLine("Introduce el nuevo nombre:");
                            dog.Name = Console.ReadLine();
                            Console.WriteLine("Introduce el nuevo id de su raza:");
                            dog.BreedId = int.Parse(Console.ReadLine());

                            context.Entry(dog).State = EntityState.Modified;
                            context.SaveChanges();

                        }
                        else
                            Console.WriteLine("No existe");
                    }
                    else if (type == "raza")
                    {
                        Breed breed = context.Breeds.Find(id);
                        if (breed != null)
                        {
                            Console.WriteLine("Introduce el nuevo nombre:");
                            breed.Name = Console.ReadLine();

                            context.Entry(breed).State = EntityState.Modified;
                            context.SaveChanges();

                        }
                        else
                            Console.WriteLine("No existe");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            
        }

        public static void Delete(DbContextOptions<DogDBContext> dbContextOptions)
        {
            try
            {
                Console.Clear();
                using (var context = new DogDBContext(dbContextOptions))
                {
                    Show(dbContextOptions);
                    Console.WriteLine("\nQuieres eliminar un perro o una raza");
                    string type = "";
                    do
                    {
                        type = Console.ReadLine();
                    }
                    while (type != "perro" && type != "raza");

                    Console.WriteLine("Introduce el id:");
                    int id = int.Parse(Console.ReadLine());

                    if (type == "perro")
                    {
                        Dog dog = context.Dogs.Find(id);
                        if (dog != null)
                        {
                            context.Dogs.Remove(dog);
                            context.SaveChanges();
                        }
                        else Console.WriteLine("No encontrado");

                    }
                    else if (type == "raza")
                    {
                        Breed breed = context.Breeds.Find(id);
                        if (breed != null)
                        {
                            context.Breeds.Remove(breed);
                            context.SaveChanges();
                        }
                        else Console.WriteLine("No encontrado");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            

        }
    }
}