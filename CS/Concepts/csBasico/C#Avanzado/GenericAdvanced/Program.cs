using GenericAdvanced;

var box = new Box<int>(12);
box.Set(15);
//Console.WriteLine(box.GetContent());

var box2 = new Box<bool>(false);
//Console.WriteLine(box2.GetContent());

var b = box2.Get();

var beerRepository = new BeerRepository();

beerRepository.Add("Delirium");
beerRepository.Add("Celebrator");

//Show(beerRepository);  

void Show<T>(IRepository<T> repository)
{
    foreach (var item in repository.GetAll())
    {
        Console.WriteLine(item);
    }
}

void ShowQuantity<T>(T drink) where T : Drink
{
    Console.WriteLine(drink.Quantity);
}

void ShowInfo<T>(T element) where T : IInfo
{
    Console.WriteLine(element.GetInfo());
}

void ShowInfoAndQuantity<T>(T element) where T : Drink, IInfo
{
    Console.WriteLine(element.Quantity);
    Console.WriteLine(element.GetInfo());
}

Operation<int> add = (a,b) => a + b;
Operation<double> addDouble = (a,b) => a + b;
Operation<string> concatenate = (a,b) => a + " " + b;

Action<IRepository<string>> s = Show;
//s(beerRepository);

//Console.WriteLine(add(1,2));
//Console.WriteLine(addDouble(1.7f,2.8f));
//Console.WriteLine(concatenate("Hola","Jose"));

var drink = new Drink(550);
var beer = new Beer("Erdinguer",500);

//ShowQuantity(drink);
//ShowQuantity(beer);
//ShowInfo(beer);

ShowInfoAndQuantity(beer);

//var pool = new ObjectPool<Randoms>(3);
//
//while (pool.Count > 0)
//{
//    var number = pool.Get();
//    Console.WriteLine(number.Number);
//}

IDrinkCreator<Drink> drinkCreator = new IPABeerCreator(); //Covarianza, como cerveza deriva de drink, Create devuelve cerveza convertida en drink
var drink2 = drinkCreator.Create(500);

IShow<Beer> beerShow = new DrinkShow();
var deliriumBeer = new Beer("Delirium Christmas", 1200);
beerShow.Show(deliriumBeer);


delegate T Operation<T>(T element1, T element2);
