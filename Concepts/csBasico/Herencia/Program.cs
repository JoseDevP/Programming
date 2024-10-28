using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Herencia
{
    class Program
    {
        static void Main(string[] args)
        {
            Doctor doctor1 = new Doctor("Jose",26,"Cirujano");
            Console.WriteLine(doctor1.GetData());
            Programmer programador1 = new Programmer("Antonio", 34, "C#");
            Console.WriteLine(programador1.GetData());
        }
    }

    abstract class People
    {
        private string _name;
        private int _age;

        public People(string name, int age) => (_name, _age) = (name,age);
        public string GetInfo() => _name + " " + _age;
    }

    class Doctor : People
    {
        private string _speciality;
        public Doctor(string name, int age, string speciality) : base(name, age) => _speciality = speciality;

        public string GetData() => GetInfo() + " " + _speciality;
    }

    class Programmer : People
    {
        private string _language;
        public Programmer(string name, int age, string language) : base(name, age) => _language = language;
        public string GetData() => GetInfo() + " " + _language;
    }

}
