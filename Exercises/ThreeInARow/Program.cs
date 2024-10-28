public class Program
{
    public static string QuienGana(string[] tablero)
    {
        bool ComprobarSiGana(string ficha)
        {
            if( ((tablero[0] == ficha ) && (tablero[1] == ficha) && (tablero[2] == ficha)) ||
            ((tablero[3] == ficha ) && (tablero[4] == ficha) && (tablero[5] == ficha)) ||
            ((tablero[6] == ficha ) && (tablero[7] == ficha) && (tablero[8] == ficha)) ||
            ((tablero[0] == ficha ) && (tablero[4] == ficha) && (tablero[8] == ficha)) ||
            ((tablero[6] == ficha ) && (tablero[4] == ficha) && (tablero[2] == ficha)) 
            )
            {
                return true;
            }
            return false;
        }
        
        if(tablero == null || tablero.Length < 9 || tablero.Length > 9 ) 
            return "Mal construida";

        if(ComprobarSiGana("X"))
            return "Gana X";
        else if(ComprobarSiGana("O"))
            return "Gana O";
        else
            return "Empate";
    }

    public static void Main(string[] args)
    {
        string[] tablero = 
        { 
            "X", "X", "O",
            "O", "O", "X",
            "X", "O", "X",
        };
        Console.WriteLine(QuienGana(tablero));
    }
}