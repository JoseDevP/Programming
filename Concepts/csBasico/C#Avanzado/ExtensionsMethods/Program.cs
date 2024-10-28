using ExtensionsMethods;

int number = 10;
int number2 = number.pow();
//Console.WriteLine(number2);

var sale = new Sale(15);
//Console.WriteLine(sale.GetInfo());

int number3 = number.Mul(2);
//Console.WriteLine(number3);

List<int> numbers = new List<int>()
{
    15,20,30,55
};

Console.WriteLine(15.Exists(numbers));

string name = "Antonio";
List<string> names = new List<string>() { "Jose", "Juan", "Pedro" };

//Console.WriteLine(name.Exists(names));
//Console.WriteLine(name.IsOn(names));


var beer = new Beer() { Quantity = 500 };
var wine = new Wine() { Quantity = 300 };

Console.WriteLine(beer.GetDescription());
Console.WriteLine(wine.GetDescription());

beer.SetBrand("Fuller")
    .SetName("London Porter")
    .SetQuantity(50);

public static class IntOperations
{
    public static int pow(this int number) => number * number;

    public static int Mul(this int number, int x) => number * x;
}

public static class SaleExtensions
{
    public static string GetInfo(this Sale sale) => "El monto es $ " + sale.Amount;
}

public static class ListExtensions
{
    public static bool Exists<T>(this T element,List<T> list)
    {
        foreach (T item in list)
        {
            if(item.Equals(element))
                return true;
        }
        return false;
    }

    public static bool IsOn<T>(this T element, List<T> list) where T : class
    {
        foreach (T item in list)
        {
            if (item.Equals(element))
                return true;
        }
        return false;
    }
}

public interface IDrink
{
    public decimal Quantity { get; set; }

}

public static class DrinkExtensions
{
    public static string GetDescription(this IDrink drink) => $"La bebida tiene {drink.Quantity} ml";
}

public class Beer :IDrink
{
    public decimal Quantity { get; set; }

    public string Name { get; set; }
    public string Brand { get; set; }
}

public class Wine : IDrink
{
    public decimal Quantity { get; set; }

}
public static class BeerExtension
{
    public static Beer SetQuantity(this Beer beer, decimal quantity)
    {
        beer.Quantity = quantity;
        return beer;
    }

    public static Beer SetName(this Beer beer, string name)
    {
        beer.Name = name;
        return beer;
    }

    public static Beer SetBrand(this Beer beer, string brand)
    {
        beer.Brand = brand;
        return beer;
    }
}