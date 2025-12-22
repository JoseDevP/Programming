/* ***Fichero creación BD empresa
	Joan Pou
** */
/*Si la BD existe la elimina*/
DROP DATABASE IF EXISTS empresa;
/*Crea la BD empresa */
CREATE DATABASE empresa;
/* CREATE DATABASE IF NOT EXISTS empresa; */

USE empresa;

DROP TABLE IF EXISTS departamento; 

CREATE TABLE IF NOT EXISTS departamento ( 
numdep int not null auto_increment, 
nombredep varchar(20) not null unique, 
primary key (numdep)); 

INSERT INTO departamento VALUES ('1','Contabilidad'); 
INSERT INTO departamento VALUES ('2','Recursos Humanos'); 
INSERT INTO departamento VALUES ('3','Informática'); 
INSERT INTO departamento VALUES ('4','Comercial');
INSERT INTO departamento VALUES ('5','Facturación');

/*Tabla trabajadores */

DROP TABLE IF EXISTS trabajadores; 

CREATE TABLE IF NOT EXISTS trabajadores (
 dni  VARCHAR(9) PRIMARY KEY ,
 nombre  VARCHAR(50),
 ciudad VARCHAR(40),
 antiguedad   INT(2), 
 salario decimal (8,2),
 numdep int not null,
 constraint fk_departamento
 foreign key (numdep) REFERENCES departamento(numdep));

INSERT INTO trabajadores VALUES ("11112222A","Rojo Iglesias, Marta", "Barcelona",12, 60000, 2);
INSERT INTO trabajadores VALUES ("11112233A","Perez Carrillo, Iván","Bilbao",5, 48000, 2);
INSERT INTO trabajadores VALUES ("11112244B","Torres Marqués, Fernando","Madrid",11, 55000, 2);
INSERT INTO trabajadores VALUES ("11112255B","Rubio Sánchez, María","Sevilla",4, 36000, 3);
INSERT INTO trabajadores VALUES ("11112266C","Llamas Rocasolano, Isabel","Barcelona",13, 28000, 3);
INSERT INTO trabajadores VALUES ("11112222C","Gomez Corachán, Manuel","Madrid",15, 22000, 1);
INSERT INTO trabajadores VALUES ("22112222A","Roca Benítez, Elena","Sevilla",6, 35000, 4);
INSERT INTO trabajadores VALUES ("33112222A","Nualart Vives, Carlos", "Barcelona",10, 30000, 4);
INSERT INTO trabajadores VALUES ("22334455C","Perez Cano, Isabel", "Madrid",2, 36000, 3);
INSERT INTO trabajadores (dni, nombre, antiguedad, salario, numdep) VALUES ("33112222C","Muñoz Casas, Montse",7,40000, 5);

INSERT INTO trabajadores VALUES ("44556677C", "Augusto Santo, Salomé", "Segovia",5,60000,2);

SELECT * FROM departamento;
SELECT * FROM trabajadores;

SELECT t.dni, t.nombre, t.ciudad, d.nombredep
from trabajadores t
inner join departamento d
on t.numdep = d.numdep;

-- auto-increment
insert into departamento values(0,"Ventas");
insert into departamento (nombredep) values ("Marketing");
select * from departamento;



-- set
insert into trabajadores set dni="44556655C", 
nombre ="Oscar",
antiguedad= 1,
salario=50000,
numdep = 1;

select* from trabajadores;




-- conjunto de datos -> insert con select
create table trabajadores2 like trabajadores;

desc trabajadores2;

insert into trabajadores2 
select * from trabajadores where ciudad="Madrid";

select * from trabajadores2;



-- actualizar update
select * from trabajadores;
update trabajadores
set ciudad="Sevilla", salario=20000
where dni ="11112222A";

select * from departamento;
update departamento
set nombredep="Publicidad"
where nombredep="Marketing";




-- añadir calculos
select * from trabajadores;
update trabajadores
set salario = salario *1.1
where numdep=2;



-- añdir campo y rellenarlo
alter table trabajadores 
add dietas decimal(8.2) default 0;

update trabajadores
set dietas = 200
where ciudad="Sevilla";

select * from trabajadores;



-- borrar solo registros con delete
select * from departamento;

delete from departamento 
where numdep=7;

select * from trabajadores;
delete from trabajadores 
where nombre = "Oscar";


-- Integridad Referencial:
-- set null -> en vez de cargarse a los trabjadores les pone nulo
-- cascade -> borra todos los trabjadores de ese departamento
-- no action/restrict -> no puedes borra departamento con
-- trabajadores asociados (defecto)

delete from departamento
where numdep=6; -- correcta no trabjadores

delete from departamento
where numdep=2;-- restringido hay trabjadores

-- borro la foreign key
alter table trabajadores
drop foreign key fk_departamento;

-- la vuelvo a crear pero con restriccciones
alter table trabajadores
add constraint fk_departamento foreign key (numdep)
references departamento(numdep)
on delete cascade
on update cascade;

select  * from trabajadores;

update departamento 
set numdep=20
where numdep=2; 

select* from departamento;

delete from departamento 
where numdep = 20;




-- TRANSACCIONES PARA QUE NO SEA DEFINITIVO
-- 1.BEGIN
-- COMMMIT (GUARDA) //// ROLLBACK(DESHAGO)
show variables like 'autocommit';

create database test;
use test;

create table ciudades(
nombre varchar(30) primary key);

insert into ciudades values ("Barcelona");
insert into ciudades values ("Madrid");
insert into ciudades values ("Sevilla");

select * from ciudades;

-- descartada con rollback
begin;
insert into ciudades values ("Segovia");
delete from ciudades 
where nombre= "Barcelona";

rollback;

select * from ciudades;

-- transaccion guardada con commit
begin;
insert into ciudades values ("Segovia");
delete from ciudades 
where nombre= "Barcelona";

commit;

select * from ciudades;




-- puntos intermedios con savepoints

begin;
insert into ciudades values("Barcelona");
savepoint punto1;
insert into ciudades values("Burgos");
rollback to punto1;
select * from ciudades;
commit;


-- Bloqueo tablas
-- bloqueo write -> puede leer y escribir el cliente pero los demas no
lock tables ciudades WRITE;
select * from ciudades;
insert into ciudades values ("Vigo");
unlock tables;

-- bloqueo READ -> nadie puede modificar 
lock tables ciudades READ;
insert into ciudades values("Teruel");
unlock tables;