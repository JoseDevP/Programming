public class Program
{
    public static bool IsOrthogonal(int[] vectorA, int[] vectorB)
    {
        int productoEscalar = (vectorA[0] * vectorB[0]) + (vectorA[1] * vectorB[1]);
        return productoEscalar == 0;
    }

    public static void Main(string[] args)
    {
        int[] a = { 1, 0,};
        int[] b = { 0, 1,};
        Console.WriteLine(IsOrthogonal(a,b) ? "Si" : "No");
    }
}