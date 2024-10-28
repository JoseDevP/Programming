using System.Data.SqlClient;
using System.Collections.Generic;

namespace DataBase2
{
    class Program
    {
        public static void Main(string[] args)
        {
            try
            {
                DogDB dogDB = new DogDB(@"localhost\SQLEXPRESS", "Prueba", "Jose", "1234");
                bool again = true;
                int op = 0;

                do
                {
                    Console.WriteLine("Elije opcion 1 - 6");
                    ShowMenu();
                    op = int.Parse(Console.ReadLine());

                    switch (op)
                    {
                        case 1://mostrar
                            Show(dogDB);
                            break;

                        case 2://insert dog
                            AddDog(dogDB);
                            break;

                        case 3://inser breed
                            AddBreed(dogDB);
                            break;

                        case 4://editar
                            Edit(dogDB);
                            break;

                        case 5://delete
                            Delete(dogDB);
                            break;

                        case 6://salir
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
            Console.WriteLine("2.-Agregar Perro");
            Console.WriteLine("3.-Agregar Raza");
            Console.WriteLine("4.-Editar");
            Console.WriteLine("5.-Eliminar");
            Console.WriteLine("6.-Salir");
        }

        public static void Show(DogDB dogDB)
        {
            Console.Clear();

            Console.WriteLine("Perros:");
            List<Dog> dogList = dogDB.ShowAllDogs();
            if(dogList.Count > 0)
            {
                foreach (Dog dog in dogList)
                    Console.WriteLine($"Id: {dog.ID}, Nombre: {dog.Name}, Id de Raza: {dog.BreedID}");
            }
            else { Console.WriteLine("No hay perros aún"); }

            Console.WriteLine("Razas:");
            List<Breed> breedList = dogDB.ShowAllBreeds();
            if (breedList.Count > 0)
            {
                foreach (Breed breed in breedList)
                    Console.WriteLine($"Id: {breed.ID}, Nombre: {breed.Name}");
            }
            else { Console.WriteLine("No hay razas aún"); }

            Console.WriteLine("\n");
        }

        public static void AddDog(DogDB dogDB)
        {
            Console.Clear();
            Console.WriteLine("Nuevo Perro:");
            Console.WriteLine("Nombre:");
            string name = Console.ReadLine();
            Console.WriteLine("Id de Raza:");
            int breedId = int.Parse(Console.ReadLine());
            Dog dog = new Dog(name, breedId);

            dogDB.AddDog(dog);

        }
        public static void AddBreed(DogDB dogDB)
        {
            Console.Clear();
            Console.WriteLine("Nueva Raza:");
            Console.WriteLine("Nombre:");
            string name = Console.ReadLine();

            Breed breed = new Breed(name);

            dogDB.AddBreed(breed);
        }

        public static void Edit(DogDB dogDB)
        {
            Console.Clear();
            Show(dogDB);
            Console.WriteLine("\nQuieres editar un perro o una raza");
            string type = "";
            do
            {
                type = Console.ReadLine();
            }
            while(type != "perro" && type != "raza");

            Console.WriteLine("Introduce el id:");
            int id = int.Parse(Console.ReadLine());

            if(type == "perro")
            {
                Dog dog = dogDB.GetDog(id);
                if (dog != null)
                {
                    Console.WriteLine("Introduce el nuevo nombre:");
                    dog.Name = Console.ReadLine();
                    Console.WriteLine("Introduce el nuevo id de su raza:");
                    dog.BreedID = int.Parse(Console.ReadLine());

                    dogDB.EditDog(dog);

                }
                else
                    Console.WriteLine("No existe");
            }
            else if(type == "raza")
            {
                Breed breed = dogDB.GetBreed(id);
                if (breed != null)
                {
                    Console.WriteLine("Introduce el nuevo nombre:");
                    breed.Name = Console.ReadLine();

                    dogDB.EditBreed(breed);

                }
                else
                    Console.WriteLine("No existe");
            }

        }

        public static void Delete(DogDB dogDB)
        {
            Console.Clear();
            Show(dogDB);
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
                dogDB.DeleteDog(id);
            }
            else if(type == "raza")
            {
                dogDB.DeleteBreed(id);
            }
        }
    }
}