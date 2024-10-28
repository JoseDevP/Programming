namespace Interfaces
{
    class Program
    {
        static void Main(string[] args)
        {
            Shark[] sharks = new Shark[]
            {
            new Shark("Tiburon", 56),
            new Shark("Jaws", 65),
            };

            IFish[] fishs = new IFish[]
            {
            new Siren(100),
            new Shark("Tiburoncin",56)
            };

            foreach (IFish fish in fishs)
                fish.Swim();
            //no puedo acceder a name ya que es de IAnimal

            //ShowAnimals(sharks);
            //ShowFish(sharks);
        }

        public static void ShowAnimals(IAnimal[] animal)
        {
            Console.WriteLine("Mostramos los animales:");
            int i = 0;
            while (i < animal.Length)
            {
                Console.WriteLine(animal[i].Name);
                i++;
            }
        }

        public static void ShowFish(IFish[] fishs)
        {
            Console.WriteLine("Mostramos los peces:");
            int i = 0;
            while (i < fishs.Length)
            {
                Console.WriteLine(fishs[i].Swim());
                i++;
            }
        }

    }

    public class Siren : IFish
    {
        public int Speed { get; set; }

        public Siren(int speed) => Speed = speed;

        public string Swim()
        {
            return $"La sirena nada a {Speed} km/h";
        }
    }

    public class Shark : IAnimal, IFish
    {
        public string Name { get; set; }
        public int Speed { get; set; }

        public Shark(string name, int speed) => (Name, Speed) = (name, speed);

        public string Swim() { return $"{Name} Nada {Speed} km/h"; }

    }

    public interface IAnimal
    {
        public string Name { get; set; }
    }

    public interface IFish
    {
        public int Speed { get; set; }
        public string Swim();
    }
}
