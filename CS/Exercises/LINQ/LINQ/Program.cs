/*
1. Filtrar y ordenar una lista de números
Objetivo: Filtra todos los números mayores a 10 y ordénalos en orden descendente.
Ejercicio: Dada la lista List<int> numbers = new List<int> { 5, 12, 15, 2, 8, 23, 7 }, obtén todos los números mayores a 10 y ordénalos.
 */

List<int> intList = new List<int>()
{
    2,6,89,56,57,34,22,55
};

//var filter = intList.Where(x => x > 10).OrderByDescending(x => x).ToList();
var filter = from i in intList where i > 10 orderby i descending select i;

foreach (var i  in filter)
    Console.WriteLine(i);