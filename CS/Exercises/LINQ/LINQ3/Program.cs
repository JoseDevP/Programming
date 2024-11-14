/*
 3. Buscar personas mayores de cierta edad
Objetivo: Filtra a las personas mayores de 30 años y ordénalas por nombre.
Ejercicio: Dado el listado:
List<Person> people = new List<Person> {
    new Person { Name = "Alice", Age = 32 },
    new Person { Name = "Bob", Age = 25 },
    new Person { Name = "Charlie", Age = 35 },
    new Person { Name = "David", Age = 29 }
};
Obtén una lista de personas mayores de 30 años ordenadas alfabéticamente por nombre.
*/

using System;

List<Person> people = new List<Person> {
    new Person { Name = "Alice", Age = 32 },
    new Person { Name = "Charlie", Age = 35 },
    new Person { Name = "David", Age = 29 },
    new Person { Name = "Bob", Age = 80 }
};

var filter = people
            .Where(x => x.Age > 30)
            .OrderBy(x => x.Name)
            .ToList();

foreach (var person in filter)
    Console.WriteLine(person.Name);


class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
}