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

insert into departamentos values (1,"RecursosHumanos","Sala1");
select * from departamentos;
insert into empleados values (1,"Juan","Nieto Pedriscola",
"42569357X", "2000-10-10", "asd@gmail.com", 645928321, 
"Gran Via", "2024-12-07", 2050.3, 1);
select * from empleados;
insert into proyectos values(1,"Proyecto1","Este es el primer
proyecto", "2024-12-07", "2030-05-02", 2000.100, 30, 1);
select * from proyectos;
insert into asignaciones values(1, 1, "2024-12-07", 
"administrador");
select * from asignaciones;