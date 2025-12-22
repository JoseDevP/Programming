show databases;

-- Ejemplo escuela n - m
-- create, use, desc, insert, select, check(restriccion)

create database escuela;

show databases;
-- Trabajar en base de datos escuela

use escuela;

-- creaar tabla
create table alumnos (
cod_alumno integer auto_increment primary key,
nombre_alumno varchar(45) not null,
curso varchar(10),
fecha_nacimiento date
);

show tables; 

-- descomponer tabla
desc alumnos;

-- mostrar como se ha creado
show create table alumnos;

create table asignaturas (
cod_asignatura varchar(5) primary key,
nombre_asignatura varchar(40) not null,
profesor varchar(45)
);

show tables;
desc asignaturas;

create table cursa(
cod_alumno integer,
cod_asignatura varchar(5),
semestre varchar(10) not null,
-- en total puedo poner 4 numeros y dos son decimales 
nota decimal(4,2),
-- constraint indica nombre de laa primary key
constraint pk_cursa primary key (cod_alumno, cod_asignatura),
-- claves foraneas
constraint fk_cursa_alumnos foreign key (cod_alumno) references alumnos(cod_alumno),
constraint fk_cursa_asignaturas foreign key (cod_asignatura) references asignaturas(cod_asignatura)
);

-- insertar
insert into alumnos values (1,'Aaron', 'DAM', '2000-10-10');
insert into asignaturas values ('0484','Bases de datos', 'Joan');
insert into cursa values(1, '0484', '2526', 9);

-- select es para ver los datos
select * from alumnos;

create table aula (
num_aula varchar(20) primary key,
num_plazas integer,
piso integer default 1,
tipo varchar(15) not null,
-- check paara restricion
constraint chk_tipo check (tipo='teoria' or tipo='taller' or tipo='laaboratorio'),
constraint chk_piso check (piso>0 and piso<5)
);

insert into aula values('1',30,1,'teoria');
-- Error no cumple piso
insert into aula values('1',30,8,'teoria');
-- Error no cumple tipo
insert into aula values('1',30,1,'informatica');

select * from aula;

-- ver tablas dibujadas en Dtabase Reverse Enginery