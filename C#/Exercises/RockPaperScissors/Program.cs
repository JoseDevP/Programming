public class Program
{
    public static async Task<string> ChooseOne()
    {
        Random random = new Random();
        int rdm = random.Next(1,4);

        string resultado = "";

        switch (rdm)
        {
            case 1:
                resultado = "piedra";
            break;

            case 2:
                resultado = "papel";
            break;

            case 3:
                resultado = "tijeras";
            break;

        }

        return resultado;
    }

    public static void RockPaperScissors(string player, string machine)
    {
        if(player == "piedra")
        {
            if(machine == "piedra")
                Console.WriteLine("Empate");
            else if(machine == "papel")
                Console.WriteLine("Gana máquina");
            else if(machine == "tijeras")
                Console.WriteLine("Gana Jugador");
        }
        else if(player == "papel")
        {
            if(machine == "piedra")
                Console.WriteLine("Gana Jugador");
            else if(machine == "papel")
                Console.WriteLine("Empate");
            else if(machine == "tijeras")
                Console.WriteLine("Gana máquina");
        }
        else if(player == "tijeras")
        {
            if(machine == "piedra")
                Console.WriteLine("Gana máquina");
            else if(machine == "papel")
                Console.WriteLine("Gana Jugador");
            else if(machine == "tijeras")
                Console.WriteLine("Empate");
        }

    }
    //&& -> dos verdderos
    //|| -> mientras uno sea verdadero es verdadero
    public static async Task Main(string[] args) //!piedra || !papel -> papel
    {
        Task<string> task = ChooseOne();

        Console.WriteLine("Que quieres escojer: (piedra / papel / tijeras)");

        string player = "";
        do
        {
            player = Console.ReadLine();
            if(player != "piedra" && player != "papel" && player != "tijeras")
            {
                Console.WriteLine("Entrada no válida. Vuelve a escojer: ");
            }
        }
        while(string.IsNullOrEmpty(player) || player != "piedra" && player != "papel" && player != "tijeras");

        Console.WriteLine($"El jugador ha escojido {player}");
        
        string machine = await task;

        Console.WriteLine($"La maquina ha escojido {machine}");

        await Task.Delay(3000);

        RockPaperScissors(player, machine);
    }
}