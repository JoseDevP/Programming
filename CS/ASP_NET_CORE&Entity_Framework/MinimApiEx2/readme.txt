Objetivo
Implementa una API en ASP.NET Core que gestione una biblioteca digital. Deberás crear 
endpoints para manejar libros, autores y categorías. Usa DTOs para transferir los datos y 
asegúrate de relacionar libros con autores y categorías.

Requisitos:

Entidad Book:
Propiedades: Id, Title, PublishedYear, AuthorId, CategoryId
Relación con las entidades Author y Category.


Entidad Author:
Propiedades: Id, Name, DateOfBirth, Books (colección de libros)

Entidad Category:
Propiedades: Id, Name, Books (colección de libros)

DTOs:
BookDTO: Incluye Title, PublishedYear, AuthorName, y CategoryName.
AuthorDTO: Incluye Name y DateOfBirth.

Endpoints:
GET /books: Devuelve todos los libros con su información completa (usando el BookDTO).
POST /books: Crea un nuevo libro.
PUT /books/{id}: Actualiza un libro.
DELETE /books/{id}: Elimina un libro.
GET /authors: Devuelve una lista de autores.
POST /authors: Crea un nuevo autor.
GET /categories: Devuelve una lista de categorías.
POST /categories: Crea una nueva categoría.
Relaciones: Un libro debe tener un autor y una categoría.

Extras:
Agrega validación de entrada para asegurarte de que los libros tienen un título, y los 
autores tienen un nombre.
Asegúrate de que no se puedan eliminar autores o categorías si tienen libros asociados.