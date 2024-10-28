using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtensionsMethods
{
    public class Sale
    {
        public decimal Amount { get; set; }

        public Sale(decimal amount) => Amount = amount;
    }
}
