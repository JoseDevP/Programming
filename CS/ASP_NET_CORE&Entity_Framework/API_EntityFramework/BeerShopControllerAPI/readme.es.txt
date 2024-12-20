En este proyecto se trabaja el backend de una ficticia tienda de compra de cervezas. Es una API que nos permite conectarnos a una base de datos de una tienda ficticia de cervezas, la cual tiene tablas para cada tipo de cerveza y cada tipo de marca de cerveza.

La base de datos no se puede incluir en GitHub pero gracias a EntityFramework se puede crear una a partir de aquí en tres pasos:
1.Abrir la consola de paquetes nugget
2.Add-Migration nombreMigracion
3.Update-Database

Los datos los tenemos en la carpeta "Models". Aquí tenemos Beer, representando la tabla Beers de la base de datos; Brand, representando la tabla Brands de la base de datos; y StoreContext, representando el contexto de la base de datos para inyectarlo desde Program al builder. En este caso se ha utilizado Entity Framework en el modo Code First. Por tanto, a partir del código se crean migraciones que se guardan en la carpeta "Migrations", y después, gracias a Entity Framework, se crea/actualiza la base de datos. Por otra parte, he inyectado el contexto en un repositorio, cosa de la que hablaré más tarde.

Para poder decidir la información que enviamos, tenemos una serie de Document Transfer Objects (DTO) para Beer, que se encuentran en la carpeta "DTO". Estos son BeerDTO, que usamos para devolver información general que incluye todos los parámetros; BeerInsertDTO, que lo usamos para cuando queramos añadir una nueva Beer; y BeerUpdateDTO, que lo usaremos cuando queramos modificar una Beer.

Los controladores (en la carpeta "Controllers") se encargan de recibir las solicitudes HTTP y devolver una respuesta. BeerController tiene una serie de métodos HTTP para gestionar solicitudes HTTP GET, POST, PUT y DELETE. Solo se encarga de recibir y devolver solicitudes, con un código de respuesta y con un cuerpo con DTO. Por tanto, la lógica del negocio y las validaciones no las hace directamente el controlador, sino que, gracias a que desde Program le inyectamos dependencias de estos sistemas, nos permite que tengamos las funcionalidades más repartidas.

Las validaciones las tenemos en la carpeta "Validators". En este caso he decidido usar una librería FluentValidation que permite separar las validaciones de los DTO. Tenemos dos clases para las validaciones: BeerInsertValidator para las validaciones de inserción, con una serie de condiciones, y BeerUpdateValidator para las validaciones de actualización. Las dependencias de validaciones se inyectan al controlador para que, si no pasan las validaciones, devuelva un código de error.

Después, lo que hace el controlador es ver si ha habido algún error. En este caso, en vez de gestionar los errores utilizando excepciones, he optado por un método alternativo que creo que puede gestionarlo mejor. En este caso, en el servicio de BeerService (implementa interfaz y clase), del cual hablaré más a profundidad más abajo, he creado una lista de strings llamada Errors, y dos métodos de validación que usarán, de una inyección del repositorio, el método Search, el cual recibe una expresión lambda indicándole que, si aparece esa condición que no queremos, nos devolverá un booleano y podremos añadir el correspondiente error a la lista de errores, la cual al obtenerla en el controlador indicaremos el tipo de error a quien consuma la API.

El siguiente paso que realiza el controlador es gestionar la lógica. Para esto, gracias a que ha sido inyectada la dependencia del servicio (encontrados en la carpeta "Servicios") BeerService, que, como había dicho antes, implementa la validación de errores, pero, aparte, tiene sus propios métodos para gestionar la lógica del negocio. En este caso, se suelen comunicar con un repositorio inyectado en esta, llamado BeerRepository, el cual se encargará de comunicarse con la base de datos.

Una vez hecho todo esto, los controladores, en base a si el proceso ha sido exitoso o no, devolverán el mensaje de una forma u otra.

Finalmente, explicar que para no tener que crear cada vez un DTO a partir de un objeto de la clase Beer o a la inversa, se han utilizado AutoMapper para simplificar este proceso.

Este mismo proceso es utilizado también con las marcas de cerveza.

Para acceder a los diferentes endpoints, muchos requieren de autorización.
Para ello al iniciar sesión se crea un token de acceso en base al rol que ha iniciado sesión.
Con este token al consumir la api utilizando Autorization bear {token} puedes entrar a los diferentes métodos.
Hay tres tipos de roles : Guest, User, y Admin
Guest solo es capaz de usar los GET
User es capaz de utilizar casi todos los metodos de los controladores y además es capaz de crear Users
Admin es capaz de utilizar todos los metodos de los controladores y además es capaz de crear Admins

Para iniciar sesión con una cuenta ya creada hay que poner la ruta http + /User/SignIn añdiendo en el body de la
solicitud el nombre de usuario y la contraseña

Para crear un nuevo usuario hay tres formas:
*ruta http + /User/SignUp añadiendo en el body de la solicitud el nombre de usuario, la contraseña y el email. -> Para crear Guest
*ruta http + /User/SignUp usando token de User y añadiendo en el body de la solicitud el nombre de usuario, la contraseña 
y el email. -> Para crear User
*ruta http + /User/SignUp usando token de Admin y añadiendo en el body de la solicitud el nombre de usuario, la contraseña 
y el email. -> Para crear Admin


