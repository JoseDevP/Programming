public enum Coins
{
    Five = 5, Fifty = 50, Hundred = 100, TwoHundred = 200
};

public enum Products
{
    Potato = 5, OrangeJuice = 50, Fish = 100, Sushi = 200
};

public class VendingMachine
{
    private List<Coins> _coins;
    private List<Products> _products;
    public VendingMachine()
    {
        _coins = new List<Coins>();
        _products = new List<Products>();

        for (int i = 0; i < 100; i++)
        {
            _coins.Add(Coins.Five);
            _products.Add(Products.Potato);
        }
        for (int i = 0; i < 50; i++)
        {
            _coins.Add(Coins.Fifty);
            _products.Add(Products.OrangeJuice);
        }
        for (int i = 0; i < 25; i++)
        {
            _coins.Add(Coins.Hundred);
            _products.Add(Products.Fish);
        }
        for (int i = 0; i < 15; i++)
        {
            _coins.Add(Coins.TwoHundred);
            _products.Add(Products.Sushi);
        }
    }

    public void HowManyCoins()
    {
        int Five = 0;
        int Fifty = 0;
        int Hundred = 0;
        int TwoHundred = 0;
        foreach (Coins coins in _coins)
        {
            if(coins == Coins.Five)
                Five++;
            else if(coins == Coins.Fifty)
                Fifty++;
            else if(coins == Coins.Hundred)
                Hundred++;
            else if(coins == Coins.TwoHundred)
                TwoHundred++;
        }
        Console.WriteLine("Five quantity->" + Five + " Fifty quantity->" + Fifty + " Hundred quantity->" + Hundred + " TwoHundred quantity->" + TwoHundred);
    }
    public void HowManyProducts()
    {
        int Potato = 0;
        int OrangeJuice = 0;
        int Fish = 0;
        int Sushi = 0;
        foreach (Products product in _products)
        {
            if(product == Products.Potato)
                Potato++;
            else if(product == Products.OrangeJuice)
                OrangeJuice++;
            else if(product == Products.Fish)
                Fish++;
            else if(product == Products.Sushi)
                Sushi++;
        }
        Console.WriteLine("1. Potato quantity->" + Potato + " 2.OrangeJuice quantity->" + OrangeJuice + " 3.Fish quantity->" + Fish + " 4.Sushi quantity->" + Sushi);
    }

    public bool CanBuy(Products product, List<Coins> coins)
    {
        if(!_products.Contains(product))
            return false;

        int price = (int)product;
        int pay = 0;

        foreach(var coin in coins)
            pay += (int)coin;

        if(pay < price)
            return false;

        return true;
    }
    public void Buy(Products product, List<Coins> coins)
    {
        for(int i = 0; i < _products.Count; i++)
        {
            if(_products[i] == product)
            {
                int price = (int)product;
                while(price > 0)
                {
                    if(coins.Contains(Coins.TwoHundred))
                    {
                        AddCoins(Coins.TwoHundred);
                        coins.Remove(Coins.TwoHundred);
                        price -= (int)Coins.TwoHundred;
                    }
                    else if(coins.Contains(Coins.Hundred))
                    {
                        AddCoins(Coins.Hundred);
                        coins.Remove(Coins.Hundred);
                        price -= (int)Coins.Hundred;
                    }
                    else if(coins.Contains(Coins.Fifty))
                    {
                        AddCoins(Coins.Fifty);
                        coins.Remove(Coins.Fifty);
                        price -= (int)Coins.Fifty;
                    }
                    else if(coins.Contains(Coins.Five))
                    {
                        AddCoins(Coins.Five);
                        coins.Remove(Coins.Five);
                        price -= (int)Coins.Five;
                    }
                }

                _products.Remove(product);

                while(price < 0)
                {
                    if(price <= -200 && _coins.Contains(Coins.TwoHundred))
                    {
                        RemoveCoins(Coins.TwoHundred);
                        coins.Add(Coins.TwoHundred);
                        price += (int)Coins.TwoHundred;
                    }
                    else if(price <= -100 && _coins.Contains(Coins.Hundred))
                    {
                        RemoveCoins(Coins.Hundred);
                        coins.Add(Coins.Hundred);
                        price += (int)Coins.Hundred;
                    }
                    else if(price <= -50 && _coins.Contains(Coins.Fifty))
                    {
                        RemoveCoins(Coins.Fifty);
                        coins.Add(Coins.Fifty);
                        price += (int)Coins.Fifty;
                    }
                    else if(price <= -5 && _coins.Contains(Coins.Five))
                    {
                        RemoveCoins(Coins.Five);
                        coins.Add(Coins.Five);
                        price += (int)Coins.Five;
                    }
                }
                break;
            }
        }
    }

    
    public void AddCoins(Coins coin)
    {
        _coins.Add(coin);
    }
    public void AddProducts(Products product)
    {
        _products.Add(product);
    }
    public bool RemoveCoins(Coins coin)
    {
        if(_coins.Contains(coin))
        {
            _coins.Remove(coin);
            return true;
        }
        return false;
    }
    public bool RemoveProducts(Products product)
    {
        if(_products.Contains(product))
        {
            _products.Remove(product);
            return true;
        }
        return false;
    }

}

public class Person
{
    private List<Coins> _coins;
    private List<Products> _products;
    public Person()
    {
        _coins = new List<Coins>();
        _products = new List<Products>();
    }
    public void HowManyCoins()
    {
        int Five = 0;
        int Fifty = 0;
        int Hundred = 0;
        int TwoHundred = 0;
        foreach (Coins coins in _coins)
        {
            if(coins == Coins.Five)
                Five++;
            else if(coins == Coins.Fifty)
                Fifty++;
            else if(coins == Coins.Hundred)
                Hundred++;
            else if(coins == Coins.TwoHundred)
                TwoHundred++;
        }
        Console.WriteLine("1.Five quantity->" + Five + " 2.Fifty quantity->" + Fifty + " 3.Hundred quantity->" + Hundred + " 4.TwoHundred quantity->" + TwoHundred);
    }
    public void HowManyProducts()
    {
        int Potato = 0;
        int OrangeJuice = 0;
        int Fish = 0;
        int Sushi = 0;
        foreach (Products product in _products)
        {
            if(product == Products.Potato)
                Potato++;
            else if(product == Products.OrangeJuice)
                OrangeJuice++;
            else if(product == Products.Fish)
                Fish++;
            else if(product == Products.Sushi)
                Sushi++;
        }
        Console.WriteLine("Potato quantity->" + Potato + " OrangeJuice quantity->" + OrangeJuice + " Fish quantity->" + Fish + " Sushi quantity->" + Sushi);
    }

    public void AddCoins(Coins coin)
    {
        _coins.Add(coin);
    }
    public void AddProducts(Products product)
    {
        _products.Add(product);
    }
    public bool RemoveCoins(Coins coin)
    {
        if(_coins.Contains(coin))
        {
            _coins.Remove(coin);
            return true;
        }
        return false;
    }
    public bool RemoveProducts(Products product)
    {
        if(_products.Contains(product))
        {
            _products.Remove(product);
            return true;
        }
        return false;
    }
}



public class Program
{
    public static int optionsMenu(string[] options, int nOptions)
    {
        int i = 0;
        int option = 0;

        for (i = 0; i < nOptions; i++)
            Console.WriteLine((i+1) + ". " + options[i]);

        Console.WriteLine("Escoje una opcion->");
        do
        {
            int.TryParse(Console.ReadLine(), out option);
            if(option < 0 || option > nOptions)
                Console.WriteLine("Entrada no valida. Escoje una opcion->");
        }
        while (option < 0 || option > nOptions);

        return option;
    }


    public static void Main(string[] args)
    {
        string[] options = 
        {
            "Ver Productos Maquina Espendedora",
            "Comprar Producto",
            "Ver Dinero Actual",
            "Ver Productos Actuales",
            "Salir"
        };
        int nOptions = options.Length;

        Person person = new Person();
        VendingMachine vend = new VendingMachine();

        person.AddCoins(Coins.TwoHundred);
        person.AddCoins(Coins.Hundred);
        person.AddCoins(Coins.Fifty);
        person.AddCoins(Coins.Five);

        Products producto = new Products();

        int nProduct = 0;

        int opcion = 0;

        List<Coins> payList = new List<Coins>();


        do
        {
            switch (opcion = optionsMenu(options, nOptions))
            {
                case 1://"Ver Productos Maquina Espendedora"
                    Console.WriteLine("\n\n");
                    vend.HowManyProducts();
                    Console.WriteLine("\nPress any key to continue...");
                    Console.ReadKey();
                break;

                case 2://"Comprar Producto"
                    Console.WriteLine("\n\n");
                    Console.WriteLine("¿Que producto quieres comprar?");
                    vend.HowManyProducts();
                    do
                    {
                        int.TryParse(Console.ReadLine(), out nProduct);
                        if(nProduct < 0 || nProduct > 4)
                            Console.WriteLine("Entrada no valida. ¿Que producto quieres comprar?");
                    }
                    while (nProduct < 0 || nProduct > 4);

                    int price = 0;
                    
                    switch (nProduct)
                    {
                        case 1://Potato
                            price = (int)Products.Potato;
                            producto = Products.Potato;
                        break;

                        case 2://Orange Juice
                            price = (int)Products.OrangeJuice;
                            producto = Products.OrangeJuice;
                        break;

                        case 3://Fish
                            price = (int)Products.Fish;
                            producto = Products.Fish;
                        break;

                        case 4://Sushi
                            price = (int)Products.Sushi;
                            producto = Products.Sushi;
                        break;
                    }

                    Console.WriteLine("\n\nPrecio: " + price);
                    while (true)
                    {
                        Console.WriteLine("Dispones de:");
                        person.HowManyCoins();

                        Console.WriteLine("\nPon los billetes con los que quieres realizar el pago");
                        Console.WriteLine("Si lo dejas vacio se entiende que quieres cancelar el pago");

                        bool valido = false;
                        valido = int.TryParse(Console.ReadLine(), out opcion);

                        if(!valido)
                            break;

                        switch (opcion)
                        {
                            case 1://5
                                if(person.RemoveCoins(Coins.Five))
                                {
                                    payList.Add(Coins.Five);
                                }
                            break;

                            case 2://50
                                if(person.RemoveCoins(Coins.Fifty))
                                {
                                    payList.Add(Coins.Fifty);
                                }
                            break;

                            case 3://100
                                if(person.RemoveCoins(Coins.Hundred))
                                {
                                    payList.Add(Coins.Hundred);
                                }
                            break;

                            case 4://200
                                if(person.RemoveCoins(Coins.TwoHundred))
                                {
                                    payList.Add(Coins.TwoHundred);
                                }
                            break;                        
                        }                   

                        do
                        {
                            Console.WriteLine("\n1.Intentar pagar");
                            Console.WriteLine("2.Seguir añadiendo billetes");
                            Console.WriteLine("3.Salir");
                            Console.WriteLine("->");
                            int.TryParse(Console.ReadLine(), out opcion);
                            if(opcion < 1 || opcion > 3)
                                Console.WriteLine("Entrada no valida.");
                        }
                        while (opcion < 1 || opcion > 3);

                        if(opcion == 1 )
                        {
                            if(vend.CanBuy(producto, payList))
                            {
                                vend.Buy(producto, payList);
                                person.AddProducts(producto);
                                if(payList.Count > 0)
                                {
                                    foreach(var coin in payList)
                                    {
                                        person.AddCoins(coin);
                                    }
                                }
                                Console.WriteLine("Has podido comprarlo.");
                                Console.WriteLine("\nPress any key to continue...");
                                Console.ReadKey();  
                                break;
                            }
                            else
                            {
                                Console.WriteLine("No has podido comprarlo.");
                                if(payList.Count > 0)
                                {
                                    foreach(var coin in payList)
                                    {
                                        person.AddCoins(coin);
                                    }
                                }
                                Console.WriteLine("\nPress any key to continue...");
                                Console.ReadKey();  
                                continue;
                            }
                        }
                        if(opcion == 2)
                        {
                            continue;
                        }
                        if(opcion == 3)
                        {
                            if(payList.Count > 0)
                            {
                                foreach(var coin in payList)
                                {
                                    person.AddCoins(coin);
                                }
                            }
                            break;
                        }
                    }
                    
                    

                    
                break;
                
                case 3://"Ver Dinero Actual"
                    Console.WriteLine("\n\n");
                    person.HowManyCoins();
                    Console.WriteLine("\nPress any key to continue...");
                    Console.ReadKey();  
                break;
                
                case 4://"Ver Productos Actuales"
                    Console.WriteLine("\n\n");
                    person.HowManyProducts();
                    Console.WriteLine("\nPress any key to continue...");
                    Console.ReadKey();  
                break;

                case 5://Salir
                break;
            }
            Console.Clear();
        }
        while (opcion != 5);
        
    }
}