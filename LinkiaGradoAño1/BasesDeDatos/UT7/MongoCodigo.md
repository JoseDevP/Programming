>\_MONGOSH



**show dbs;**

admin   40.00 KiB

config  12.00 KiB

local   40.00 KiB

**use biblioteca**

switched to db biblioteca 





**Crear tablas:**

**Explicita:**



**db.createCollection("autores")**

{ ok: 1 }



**Crear directamente algún elemento en la tabla crea la tabla**



**db.libros.insertOne({titulo: "Cien años de soledad", autor: "Gabriel García Marquez"})**

{

&nbsp; acknowledged: true,

&nbsp; insertedId: ObjectId('6935c1d9bbd5db8708dc7182')

}











**Ver tablas**



**show collections**

autores

libros



**Ver base datos activa**

db







**Insertar uno o mas registros**

**db.usuarios.insertOne({**

**nombre: "Laura", edad: 25, ciudad:"Madrid" });**





**db.usuarios.insertMany(\[**

**{nombre: "Antonio", edad: 30, ciudad:"Barcelona" },**

**{nombre: "Pedro", edad: 18, ciudad:"Córdova" }**

**]);**





**Mirar todo de una tabla** 

**db.usuarios.find();**

**db.usuarios.find().pretty();**





**Mirar campos**

**db.usuarios.find({condicion}, {campos a ver});**

**db.usuarios.find({}, { nombre: 1, edad: 1 ,ciudad: 1, \_id :0});**

**db.usuarios.find({}, { nombre: 1 ,ciudad: 1, \_id :0});**









**Ordenar datos:**

**db.usuarios.find().sort({nombre: -1});  ->descendente -1** 

**db.usuarios.find().sort({nombre: 1});  ->ascendente 1**





**Filtrar sifht 4**

**$eq -> igual a // valor:"Asfdas"**

**$ne -> distinto de**

**$gt -> mayor que**

**$gte -> mayor o igual**

**$lt -> menor que**

**$lte ->menor o igual**

**$in ->campo puede tener varios valores**

**$nin ->no esta en conjunto**

**$or -> condicion o condicion**

**$regex -> contenga la palabta**



**db.usuarios.find({$lt:"Madrid"})**

**db.usuarios.find({edad:{$lt: 30}} )**







**Actualizar**

**db.usuarios.updateOne({**

**nombre: "Laura"}, {$set: {edad: 26}});**





**lo mismo con Many para varios**









**Borrar**

**igual con delete**

**db.usuarios.deleteOne({**

**nombre: "Laura"});**





**db.usuarios.deleteMany({edad: {$lt: 25} });**











**Agrupamientos**



**$sum: 1 -> contar**

**$sum: nombrecampo -> sumar**

**$avg**





**db.trabajadores.aggregate(\[**

**{ $group: { \_id: "$departamento", totalTrabajadores: {$sum:1} } }**

**]);**





**db.trabajadores.aggregate(\[**

**{ $group: { \_id: "$departamento", salarioMedio: {$avg:"$salario"} } }**

**]);**









