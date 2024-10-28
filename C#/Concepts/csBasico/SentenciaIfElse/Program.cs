using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SentenciaIfElse
{
    class Program
    {
        static void Main(string[] args)
        {
            bool areYouHungry = true;
            bool youHaveMoney = false;
        }

        static bool CanEat(bool hungry, bool money)
        {
            if (hungry == true && money == true)
                return true;
            return false;
        }
    }
}
