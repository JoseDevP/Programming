public class Program
{
    public static async Task Suma(int n1, int n2)
    {
        await Task.Delay(3000);
        Console.WriteLine((n1 + n2));
    } 
    public static Task Main(string[] args)
    {
        int n1 = 2, n2 =3;
        Suma(n1,n2);
        Console.ReadLine();
        return Task.CompletedTask;
    }
}