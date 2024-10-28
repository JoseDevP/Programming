using System;

public class Program
{
    public static string Binary(int n)
{
    string numBi = "";

    while (n > 0)
    {
        numBi = (n % 2) + numBi; //bit menos signficativo
        n /= 2; //desplazar derecha
    }

    if (numBi == "")
        numBi = "0";

    return numBi;
}

    public static void Main(string[] args)
    {
        Console.WriteLine(Binary(5));
    }
}