En este Proyecto se trabaja el backend de una ficticia tienda de compra de cervezas.
Es una API que nos permite conectarnos a una DataBase de una tienda ficticia de cervezas, la cual tiene tablas para cada tipo de cerveza 
y cada tipo de marca de cerveza.

Los datos los tenemos en la carpeta "Models". Aqui tenemos Beer, representando la tabla Beers de la database, 
Brand, representando la tabla Brands de la database y StoreContext, representando el contexto de la database para inyectarlo desde program al builder.
En este caso se ha utilizado Entity Framework en el modo Code First. Por tanto a partir del codigo se crean migracion que se guardan en la carpeta
"Migrations" y después gracias a Entity Framework se crea/actualiza la db. Por otra parte he inyectado el context en un respositorio, cosa que hablaré más tarde de eso.

Para poder decidir la información que enviamos tenemos una serie de Document Transfer Objects(DTO) para Beer, que se encuentran en la carpeta "DTO".
Estos son el BeerDTO, que usamos para devolver general que incluye todos los parametros, BeerInsertDTO que lo usamos para cuando querramos añadir un nuevo Beer,
y BeerUpdateDTO que lo usarermos cuando queramos modificar un Beer.

Los controladores (en la carpeta "Controllers"), se encargan de recibir las solicitudes HTTP y devolver una respuesta.
BeerController tiene una serie de metodos http para gestionar solicitudes http GET, POST, PUT y DELETE.
Solo se encarga de recibir y devolver solicitudes, con un response code y con un body con DTO.
Por tanto la lógica del negocio y las validaciones no las hace directamente el controlador sino que gracias a que desde program le inyectamos depencias de 
estos sistemas, nos permite que tengamos las funcionalidades más repartidas.

Las validaciones las tenemos en la carpeta "Validators". En este caso he decido usar una libreria FluentValidator que permite separar las validaciones
de los DTO. Tenemos dos clases para las validaciones: BeerInsertValidator para las validaciones de inserción con una serie de condiciones y 
BeerUpdateValidator para las validaciones de actualización. Las dependencias de validaciones, se inyectan al controlador para que si no pasan las validaciones
devuelva un codigo de error.

Después lo que hace el controlador es ver si ha habido algun error. En este caso en vez de gestionar los errores utilizando excepciones, he optado por un 
metodo alternativo que creo que puede gestionarlo mejor. En este caso en el servicio de BeerService (implementa interfaz y clase), del cual hablare más a aprofundidad
más abajo, he creado una lista de strings llamada Errors, y dos métodos de validación que usaran de una inyeccion del del repositorio el metodo search el cual recibe
una expresión lambda indicandole que si aparece esa condicion que no queremos nos devolvera un booleano y podremos añadir el correspondiente error a la lista de errores,
la cual al obtenerla en el controlador indicaremos el tipo de error a quien consuma la API.

El siguiente paso que realiza el controlador es gestionar la lógica. Para esto, gracias a que ha sido inyectada la dependencia del servicio (Encontrados en la carpeta "Servicios")
BeerService que como habia dicho antes implementa la validacion de errores, pero a parte tiene sus propios metodos para gestionar la lógica del negocio.
En este caso se suelen comunicar con un repository inyectado en esta, llamado BeerRepository el cual se encargará de comunicarse con la database.

Una vez hecho todo esto los controladores, en base a si el proceso haya sido exitoso o no devolverá el mensaje de una forma u otra. 

Finalmente explicar que para no tener cada vez que se crea un dto a partir de un objeto de la clase beer o a la inversa, se han utilizado los automapper para simplificar este proceso. 

