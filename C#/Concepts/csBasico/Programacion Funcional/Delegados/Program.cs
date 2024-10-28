Operation mySum = Functions.Sum;
mySum = Functions.Mult;

Show cw = Console.WriteLine;
cw += Functions.ConsoleShow;

//Functions.Some("Jose", "Cazorla", cw);

//delegados genericos
#region Action_Lambda

//recibe parametros, pero no regresa nada
Action<string> showMessage = Console.WriteLine;
//Functions.SomeAction("Jose", "Cazorla", showMessage);

//Action con Lambda
string s = "Hola";
Action<string,string> showMessage2 = (a,b) => Console.WriteLine($"{s} {a} {b}");
//showMessage2("Jose", "cazorla");

Action<string,string,string> showMessage3 = (a,b,c) => Console.WriteLine($"{a} {b} {c}");
//showMessage3("Jose", "cazorla", "Dev");


#endregion

#region Func

Func<int> numberRandom = () => new Random().Next(0,101);
Func<int,int> numberRandomLimit = (limit) => new Random().Next(0,limit+1); 
//Console.WriteLine(numberRandomLimit(3));

#endregion

#region Predicate

Predicate<string> hasSpace = (word) => word.Contains(" ") || word.ToUpper().Contains("A");
Console.WriteLine(hasSpace("HolaAtun"));

var words = new List<string>()
{
    "beer",
    "patito",
    "sandia",
    "hola mundo",
    "c#"
};

var wordsNew = words.FindAll(hasSpace);

#endregion

#region Delegados
public delegate int Operation(int a, int b);
public delegate void Show(string message);
public delegate void Show2(string message, string message2);
public delegate void Show3(string message, string message2, string message3);
#endregion

public class Functions
{
    public static int Sum(int x, int y) => x + y;
    public static int Mult(int x, int y) => x * y;
    
    public static void ConsoleShow(string message) => Console.WriteLine(message.ToUpper());

    public static void Some(string name, string lastName, Show fn) 
    {
        Console.WriteLine("Hago algo al inicio");
        fn($"Hola {name} {lastName}");
        Console.WriteLine("Hago algo al final");
    }
    public static void SomeAction(string name, string lastName, Action<string> fn)
    {
        Console.WriteLine("Hago algo al inicio");
        fn($"Hola {name} {lastName}");
        Console.WriteLine("Hago algo al final");
    }
}