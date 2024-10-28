public class Program
{
    public static void Main(string[] args)
    {
        string texto ="Hola que tal, digo hola por si que tal, pero si tal  cosa nom fuera Que no seria buen que tal";
        string[] palabras = texto.Split(new char[] { ' ', ',', '.', '!', '?' }, StringSplitOptions.RemoveEmptyEntries);

        Dictionary<string,int> words = new Dictionary<string,int>();

        foreach (string palabra in palabras)
        {
            string palabraLower = palabra.ToLower();
            if (words.ContainsKey(palabraLower))
            {
                words[palabraLower]++;
            }
            else
            {
                words.Add(palabraLower, 1);
            }
        }

        foreach (var pair in words)
        {
            Console.WriteLine($"{pair.Key}: {pair.Value}");
        }
    }
}