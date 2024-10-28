public class Program
{
    static bool IsAnAnagram(string w1, string w2)
    {
        if(w1 == w2) 
            return false;

        w1 = w1.ToLower();
        w2 = w2.ToLower();

        var w1ord = from w in w1 orderby w select w;
        var w2ord = from w in w2 orderby w select w;
        
        return w1ord.SequenceEqual(w2ord);
    }

    static void Main(string[] args)
    {
        string? w1 = "";
        string? w2 = "";

        do 
        {
            Console.WriteLine("Palabra 1");
            w1 = Console.ReadLine();
            Console.WriteLine("Palabra 2");
            w2 = Console.ReadLine();
        }
        while(string.IsNullOrEmpty(w1) || string.IsNullOrEmpty(w2));

        Console.WriteLine(IsAnAnagram(w1, w2) ?  "Is an Anagram" : "Is not an Anagram");
    }
}