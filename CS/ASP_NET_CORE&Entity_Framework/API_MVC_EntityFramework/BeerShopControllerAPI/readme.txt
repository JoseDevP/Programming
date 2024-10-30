En este Proyecto se trabaja el backend de una ficticia tienda de compra de cervezas.
Es una API que nos permite conectarnos a una DataBase de una tienda ficticia de cervezas, la cual tiene tablas para cada tipo de cerveza 
y cada tipo de marca de cerveza.

Los datos los tenemos en la carpeta "Models". Aqui tenemos Beer, representando la tabla Beers de la database, 
Brand, representando la tabla Brands de la database y StoreContext, representando el contexto de la database para inyectarlo desde program al builder.
En este caso se ha utilizado Entity Framework en el modo Code First. Por tanto a partir del codigo se crean migracion que se guardan en la carpeta
"Migrations" y después gracias a Entity Framework se crea/actualiza la db.

Los controladores (en la carpeta "Controllers"), se encargan de recibir las solicitudes HTTP y devolver una respuesta.
BeerController tiene una serie de metodos http para gestionar solicitudes http GET, POST, PUT y DELETE.
