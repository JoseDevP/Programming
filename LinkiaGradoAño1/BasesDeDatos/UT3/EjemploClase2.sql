create database empresa0484;
-- relacion 1 n
-- alter, drop table
use empresa0484;

create table departamento(
num_departamento integer primary key,
-- unique hace que no se pueda repetir
nombre_departamento varchar(30) not null unique
);

insert into departamento values('1','Contabilidad');
insert into departamento values('2','Recursos Humanos');
insert into departamento values('3','Informática');
insert into departamento values('4','Comercial');

create table trabajadores (
dni varchar(10) primary key,
nombre varchar(40) not null,
antiguedad integer not null,
num_departamento integer,
-- foreign key
constraint fk_trabajadores_departamento foreign key (num_departamento) references departamento(num_departamento)
);

insert into trabajadores values ('1111111A', 'Marta', 2, 1);
insert into trabajadores values ('1324235B', 'Antonio', 4, 1);
insert into trabajadores values ('2342342C', 'Pedro',3, 3);

select * from trabajadores;

-- alter borrar campo
alter table trabajadores
drop column antiguedad;

-- alter añadir
alter table trabajadores
add column salario decimal(6,2) after nombre;

-- alter modificar
alter table trabajadores 
modify column nombre varchar(100);

desc trabajadores;