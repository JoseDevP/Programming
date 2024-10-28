
Aquí tienes una idea más avanzada para un ejercicio con una base de datos:

Crea una API mínima que gestione una lista de tareas pendientes, conectada a una base de datos SQLite.

Funcionalidades:
Rutas básicas:

GET /tasks: Obtiene todas las tareas de la base de datos.
GET /tasks/{id}: Obtiene una tarea específica por su Id.
POST /tasks: Crea una nueva tarea y la guarda en la base de datos.
PUT /tasks/{id}: Actualiza una tarea existente.
DELETE /tasks/{id}: Elimina una tarea por su Id.
Tareas:

Cada tarea debe tener un Id, Title, y IsCompleted.
Requerimientos:
Base de datos SQLite: Usa Entity Framework Core con una base de datos SQLite.
Migraciones: Usa migraciones para crear las tablas necesarias en la base de datos.
Inyección de dependencias: Registra DbContext en el contenedor de dependencias.