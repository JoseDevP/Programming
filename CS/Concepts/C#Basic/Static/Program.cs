using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Static
{
    class Program
    {
        static void Main(string[] args)
        {
            People people = new People("Jose",26);
            People Juan = new People("Jose",26);
            Console.WriteLine(People.GetCount());

        }
    }

    public class People
    {
        public static int Count = 0;
        private string _name;
        private int _age;

        public People(string name, int age)
        {
            _name = name;
            _age = age;
            Count++;
        }
        public string GetInfo() => _name + " " + _age;

        public static string GetCount()
        {
            return $"Esta clase se ha utilizado {Count} veces.";
        }
    }

}
