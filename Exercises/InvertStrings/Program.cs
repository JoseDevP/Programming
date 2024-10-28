using System;
using System.Linq;

public class Program
{
    public static void Main(string[] args)
    {
        string? str = Console.ReadLine();

        if (!string.IsNullOrEmpty(str))
        {
            string strOrd = new string(str.OrderBy(c => c).ToArray());
            
            char firstChar = strOrd.FirstOrDefault(c => char.IsUpper(c));
            if (firstChar != '\0')
            {
                strOrd = strOrd.Replace(firstChar.ToString(), "", StringComparison.OrdinalIgnoreCase) + firstChar;
            }
            Console.WriteLine(strOrd);
        }
        else
        {
            Console.WriteLine("No válido");
        }
    }
}
