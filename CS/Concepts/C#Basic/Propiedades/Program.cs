using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Propiedades
{
    class Program
    {
        static void Main(string[] args)
        {
            Sale sale = new Sale(100, DateTime.Now);
            Console.WriteLine(sale.Total);
        }
    }

    class Sale
    {
        private int total;
        private DateTime date;

        public string Date
        {
            get
            {
                return date.ToLongDateString();
            }
        }
        public int Total
        {
            get
            {
                return total;
                //return total.ToString("#.00");
            }
            set
            {
                if (value < 0)
                    value = 0;
                total = value;
            }
        }

        public Sale(int total, DateTime date) => (this.total, this.date) = (total, date);
        public string GetInfo() => total + " " + date.ToLongDateString();
        
    }
}
