public class Program
{
    public static bool EvaluarCarrera(string[] acciones, string pista)
    {
        char[] pistaArray = pista.ToCharArray();
        bool esCorrecto = true;

        for (int i = 0; i < acciones.Length; i++)
        {
            if (acciones[i] == "run" && pistaArray[i] == '|')
            {
                pistaArray[i] = '/';  
                esCorrecto = false;
            }
            else if (acciones[i] == "jump" && pistaArray[i] == '_')
            {
                pistaArray[i] = 'x';  
                esCorrecto = false;
            }
        }

        Console.WriteLine(new string(pistaArray));
        return esCorrecto;
    }
    
    public static void Main(string[] args)
    {
        string[] acciones = { "run","jump","jump"};
        EvaluarCarrera(acciones,"_|_");
    }
}