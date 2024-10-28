public class Program
{
    public static double MaximoComunDivisor(double a, double b)
    {
        double res = a % b;
        if(res == 0)
            return b;
        else
            return MaximoComunDivisor(b,res);
    }

    public static double MinimoComunMultiple(double a, double b)
    {
        return (a * b) / MaximoComunDivisor(a,b);
    }

    public static void Main(string[] args)
    {
        Console.WriteLine(MaximoComunDivisor(60,36));
        Console.WriteLine(MinimoComunMultiple(60,36));
    }
}