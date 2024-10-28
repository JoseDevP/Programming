using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClasesYObjetos
{
    class Program
    {
        static void Main(string[] args)
        {
            Sale sale = new Sale(100, DateTime.Now);
            Console.WriteLine(sale.GetInfo());
        }
    }

    class Sale
    {
        int total;
        DateTime date;

        public Sale(int total, DateTime date) =>(this.total, this.date) = (total, date);
        public string GetInfo()
        {
            return total + " " + date.ToLongDateString();
        }
    }
}
