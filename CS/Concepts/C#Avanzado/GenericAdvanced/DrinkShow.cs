using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericAdvanced
{
    public class DrinkShow :IShow<Drink>
    {
        public void Show(Drink drink) => Console.WriteLine("cantidad " + drink.Quantity + "ml");

    }
}
