/*4. Calcular la suma de valores de una propiedad
Objetivo: Calcula el total de ventas realizadas.
Ejercicio: Dado el listado:
List<Sale> sales = new List<Sale> {
    new Sale { Item = "Book", Amount = 19.99 },
    new Sale { Item = "Pen", Amount = 2.50 },
    new Sale { Item = "Notebook", Amount = 5.99 }
};
Usa LINQ para obtener la suma de todas las ventas (propiedad Amount).
*/

List<Sale> sales = new List<Sale> {
    new Sale { Item = "Book", Amount = 19.99 },
    new Sale { Item = "Pen", Amount = 2.50 },
    new Sale { Item = "Notebook", Amount = 5.99 }
};

double result = sales.Sum(s => s.Amount);

Console.WriteLine(result);

class Sale
{
    public string? Item { get; set; }
    public double Amount { get; set; }
}