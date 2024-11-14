/*2. Seleccionar y transformar una lista de strings
Objetivo: Encuentra las palabras que contienen la letra 'a' y conviérte la a a mayúsculas.
Ejercicio: Dada la lista List<string> words = new List<string> { "apple", "banana", "cherry", "date", "fig" }, 
selecciona solo las palabras que contienen la letra 'a' y cambia todas las letras a mayúsculas.*/

List<string> words = new List<string> { "apple", "banana", "cherry", "date", "fig" };

var result = words
            .Select(x => x.Contains('a') ? x.Replace('a', 'A') : x);

foreach (var word in result)
    Console.WriteLine(word);

