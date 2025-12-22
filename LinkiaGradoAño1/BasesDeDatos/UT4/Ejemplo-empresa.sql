
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
 departamento int not null,
 constraint fk_departamento
 foreign key (departamento) REFERENCES departamento(numdep));

INSERT INTO trabajadores VALUES ("11112222A","Rojo Iglesias, Marta", "Barcelona",12, 60000, 2);
INSERT INTO trabajadores VALUES ("11112233A","Perez Carrillo, Iván","Bilbao",5, 48000, 2);
INSERT INTO trabajadores VALUES ("11112244B","Torres Marqués, Fernando","Madrid",11, 55000, 2);
INSERT INTO trabajadores VALUES ("11112255B","Rubio Sánchez, María","Sevilla",4, 36000, 3);
INSERT INTO trabajadores VALUES ("11112266C","Llamas Rocasolano, Isabel","Barcelona",13, 28000, 3);
INSERT INTO trabajadores VALUES ("11112222C","Gomez Corachán, Manuel","Madrid",15, 22000, 1);
INSERT INTO trabajadores VALUES ("22112222A","Roca Benítez, Elena","Sevilla",6, 35000, 4);
INSERT INTO trabajadores VALUES ("33112222A","Nualart Vives, Carlos", "Barcelona",10, 30000, 4);
INSERT INTO trabajadores VALUES ("22334455C","Perez Cano, Isabel", "Madrid",2, 36000, 3);
INSERT INTO trabajadores (dni, nombre, antiguedad, salario, departamento) VALUES ("33112222C","Muñoz Casas, Montse",7,40000, 5);

-- Seleccionar todos
select * from departamento;
select * from trabajadores;

-- Que salgan soolo las caracteristicaas que queremos
select nombre, salario from trabajadores;

-- Que salgan sin repetidos 
select distinct ciudad from trabajadores;

-- where -> filtrar los datos (condicion)
select * from trabajadores where ciudad="Sevilla";
select * from trabajadores where salario>40000;
select * from trabajadores where salario<40000 and antiguedad>10;
select * from trabajadores where ciudad="Madrid" or ciudad="Sevilla";
select * from trabajadores where ciudad in ("Madrid","Sevilla");
-- between-> rango
select * from trabajadores where salario between 30000 and 40000;

-- like -> consulta cuando no esta entero %(falta algo)
select * from trabajadores where nombre like "Perez%";
select * from trabajadores where nombre like "%roca%";

-- is (not) null -> nulos o no nulos
select * from trabajadores where ciudad is null;
select * from trabajadores where ciudad is not null;


/* ordenaciones*/
-- order by (desc -> al reves) -> ordenar
select * from trabajadores order by nombre;
select * from trabajadores order by salario desc;
-- si en el primer caampo empataan se decide con el seguundo
select * from trabajadores order by ciudad desc, salario;




/* Campos calculados */
select dni,nombre,salario,salario*1.05 as "Salario Nuevo" 
from trabajadores;

select dni,nombre,salario,salario/14 as "Salario Mensual" 
from trabajadores;

-- avg -> media
select avg(salario) from trabajadores where ciudad="Madrid";
select avg(salario) as "Salario Medio" from trabajadores where ciudad="Madrid";

-- count -> contar
select count(dni) from trabajadores where departamento=2;

-- sum -> sumar

-- max -> maximo

-- min -> minimo




/* Funciones de cadena */
select nombre, left(nombre,5), right(nombre,5),
length(nombre) from trabajadores;

select dni, left(dni,8) as "numeros", right(dni,1) 
as letra from trabajadores;

select upper(nombre), lower(nombre) from trabajadores;





/*Trabjar con maas de una tabla inner join*/
-- inner solo registros de las dos tablas
select trabajadores.nombre, trabajadores.salario,
departamento.nombredep from trabajadores inner join departamento
on trabajadores.departamento = departamento.numdep 
where d.nombredep = "Recursos Humanos";

-- acortar
select t.nombre, t.salario,
d.nombredep from trabajadores t inner join departamento d
on t.departamento = d.numdep 
where d.nombredep = "Recursos Humanos";



-- left join or right join -> obligo a que salgan los datos
INSERT INTO departamento VALUES ('6','Marketing');
INSERT INTO departamento VALUES ('7','Logística');

-- right todos los daatos derecha aunque no tengan izquierda
select t.nombre, t.salario,
d.nombredep from trabajadores t right join departamento d
on t.departamento = d.numdep ;

-- left todos los datos izquierda aunque no tengan derecha
select t.nombre, t.salario,
d.nombredep from trabajadores t left join departamento d
on t.departamento = d.numdep ;


/*Funciones de aagregado group by*/ 
select avg(salario) from trabajadores where ciudad="Madrid";

select ciudad, avg(salario) from trabajadores
group by ciudad;

select d.nombredep, count(t.dni) from trabajadores t
right join departamento d
on t.departamento = numdep
group by d.nombredep;





/* filtro en las funciones de agregado having */
-- cuando no podemos usar where en count, avg ...
select d.nombredep, count(t.dni) from trabajadores t
right join departamento d
on t.departamento = numdep
group by d.nombredep
having count(t.dni)>2;

select ciudad, avg(salario) from trabajadores
group by ciudad
having avg(salario)<40000;

/*Resumen->
Select -lista selccion- 
from - origne daatos-
where -condicion-
group by -agrupaacion-
having -condicion de selecion-
order by -ordenacion-




/*SUBCONSULTAS*/

/*monoregistro ->solo devuelve un valor*/
-- lista todos los trabajadores que su salario esta por encima de la media
select * from trabajadores 
where salario>(select avg(salario) from trabajadores);

-- todos los trabajadores que tienen mas antiguedad que el traabjador
-- torres marques

select * from trabajadores 
where antiguedad>(select antiguedad from trabajadores 
where nombre like "torres mar%");

/*multiregistro->puede devuelver mas de un valor*/
-- all(todos los valores) o any(que alguno de los valores)

-- todos traabjaadores cobren + que trabjaadores del departaamento 3
select nombre, salario from trabajadores
where salario>all(select salario from trabajadores where departamento=3);


/*Vistas -> consulta almaacenada*/

create view currantes as
select t.*, d.* from trabajadores t
inner join departamento d
on t.departamento=d.numdep;

select * from currantes 
where nombredep="Recursos Humanos" and ciudad="Madrid";