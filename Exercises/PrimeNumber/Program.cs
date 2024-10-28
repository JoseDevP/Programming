using System;

class Program
{
    static bool IsPrime(int n)
    {
        if (n < 1)
            return false;
        else if (n == 2)
            return true;
        else if( n > 2 && ( n % 2 == 0 ))
            return false;
        
        for(int i = 3; i <= Math.Sqrt(n); i+=2)
        {
            if((n % i) == 0)
                return false;   
        }
        return true;
    }

    static void Main(string[] args)
    {
        int n;
        while(!int.TryParse(Console.ReadLine(), out n))
        {
            Console.WriteLine("Entrada no valida.");
        }
        Console.WriteLine(IsPrime(n) ? "Es Primo" : "No es primo");
        
    }
}