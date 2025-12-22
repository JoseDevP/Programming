-- creo la db
create database empresa;

-- uso use para trabjar en esta base de datos 
use empresa;

-- departamentos
create table departamentos(
idDepartamento integer auto_increment primary key,
nombre varchar(20) not null,
ubicacion varchar(50)
);

-- empleados
create table empleados(
idEmpleado integer auto_increment primary key,
nombre varchar(10) not null,
apellidos varchar(25) not null,
dni varchar(15) not null unique,
fechaNacimiento date,
email varchar(30) unique,
telefono varchar(15),
direccion varchar(50),
fecha_ingreso date,
salario double,
idDepartamento integer,
-- foreign key de departamentos
constraint fk_empleados_departamento foreign key (idDepartamento)
references departamentos(idDepartamento)
);

-- proyectos
create table proyectos(
idProyecto integer auto_increment primary key,
nombre varchar(10) not null,
descripcion varchar(50) not null,
fechaInicio date,
fechaFin date,
presupuesto decimal(14,2),
duracionMaximaDias integer,
idResponsable integer,
-- foreign key de empleados
constraint fk_proyectos_empleados foreign key (idResponsable)
references empleados(idEmpleado)
);

-- asignaciones tabla intermedia
create table asignaciones(
idEmpleado integer,
idProyecto integer,
fechaAsignacion date,
rolEnProyecto varchar(20),
-- primary key
constraint pk_asignaciones primary key (idEmpleado,idProyecto),
-- foreign key de empleados y proyectos
constraint fk_asignaciones_empleados foreign key (idEmpleado)
references empleados(idEmpleado),
constraint fk_asignaciones_proyectos foreign key (idProyecto)
references proyectos(idProyecto)
);

-- Alteraciones
-- Añadir columna género a empleados. 
alter table empleados
add column genero varchar(10) not null after apellidos;

-- Añade campo `estado` con valor por defecto ‘activo’
-- a empleados. 
alter table empleados
add column estado varchar(10) default "activo";

-- Establece la restricción de que el salario debe ser 
-- superior a 1000. 
alter table empleados
add constraint chk_salario check (salario > 100);

-- Amplia el campo dirección a 100 caracteres.
alter table empleados
modify column direccion varchar(100);

-- Añade campo `activo` a departamentos; elimina `ubicacion`, 
-- valor por defecto true. 
alter table departamentos
add column activo boolean default true,
drop column ubicacion;

--  Restricciones en `duracionMaximaDias` y presupuesto 
-- que deben ser superiores a 0. 
alter table proyectos
add constraint chl_duracionMaximaDias check (duracionMaximaDias > 0),
add constraint chl_presupuesto check (presupuesto > 0);

-- En asignaciones, añade `horasAsignadasDia` con una 
-- restricción superior a 0 y inferior o igual a 8. 
alter table asignaciones
add column horasAsignadasDia integer,
add constraint chk_horasAsignadasDia check (horasAsignadasDia > 0 and horasAsignadasDia <= 8);

-- El campo rolEnProyecto puede tener los valores: 
-- Desarrollador, Analista, Jefe de Proyecto o Tester, 
-- por defecto Desarrollador.

-- He tenido que eliminar los de antes porque no cumplia el check
SET SQL_SAFE_UPDATES = 0;

DELETE FROM asignaciones
WHERE rolEnProyecto NOT IN ('Desarrollador', 'Analista', 'Jefe de Proyecto', 'Tester');

SET SQL_SAFE_UPDATES = 1;


alter table asignaciones
modify column  rolEnProyecto VARCHAR(20) default 'Desarrollador',
add constraint chk_rolEnProyecto check (rolEnProyecto =
"Desarrollador" or  rolEnProyecto ="Analista" or
rolEnProyecto ="Jefe de Proyecto" or rolEnProyecto ="Tester");

-- Índices: 
-- 1. Índice simple sobre dni en empleados. Crea una restricción 
-- UNIQUE en el correo electrónico. 

create index idx_dni on empleados(dni);

alter table empleados
add constraint unq_email unique (email);

-- 2. Crea dos índices más en los campos que creas convenientes.
-- Justifica tu elección. 

create index idx_nombreDepartamento on departamentos(nombre);
create index idx_nombreProyecto on proyectos(nombre);
