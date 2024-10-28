using System.Xml.Linq;

namespace Generic
{
    class Program
    {
        static void Main(string[] args)
        {
            MyList<int> numbers = new MyList<int>(10);
            numbers.Add(10);
            numbers.Add(6);


            MyList<string> strings = new MyList<string>(10);
            strings.Add("Patata");
            strings.Add("Zanahoria");

            

            MyList<People> people = new MyList<People>(10);
            people.Add(new People() { Name = "Jose", LastName="Cazorla" });
            people.Add(new People() { Name = "Juan", LastName="Villalba" });

            Console.WriteLine(numbers.GetString());
            Console.WriteLine(strings.GetString());
            Console.WriteLine(people.GetString());

        }
    }

    class People
    {
        public string Name { get; set; }
        public string LastName { get; set; }

        public override string ToString()
        {
            return Name + " " + LastName; 
        }
    }

    public class MyList<T>
    {
        public T[] _elements;
        private int _index = 0;

        public MyList(int n) => _elements = new T[n];

        public void Add(T e) 
        {
            if(_index < _elements.Length)
            {
                _elements[_index++] = e;
            }
        }

        public T GetElement(int i) 
        {
            if(i <= _index && i>= 0)
            {
                return _elements[i];
            }
            return default(T);
        }

        public string GetString()
        {
            int i = 0;
            string result = "";
            while(i < _index) 
            {
                result += _elements[i].ToString() + "|";
                i++;
            }
            return result;
        }
    }
}
