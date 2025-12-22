/* Fichero creación BD escuela
	Joan Pou
	Octubre 2025
*/
/*Si la BD existe la elimina*/
DROP DATABASE IF EXISTS escuela;
/*Crea la BD escuela */
CREATE DATABASE escuela;
/* CREATE DATABASE IF NOT EXISTS escuela; */
USE escuela; 
/*Tabla alumnos */
DROP TABLE IF EXISTS alumnos;

CREATE TABLE IF NOT EXISTS alumnos (
 numexp  VARCHAR(4) PRIMARY KEY ,
 nombre  VARCHAR(50),
 ciudad VARCHAR(40),
 edad   INT(2)) ;
 
 DROP TABLE IF EXISTS profesores;
 CREATE TABLE IF NOT EXISTS profesores (
 dniprofe  VARCHAR(9) PRIMARY KEY ,
 nombre  VARCHAR(50),
 fechaalta Date);

 DROP TABLE IF EXISTS asignaturas;
 CREATE TABLE IF NOT EXISTS asignaturas (
 codiasig  VARCHAR(6) PRIMARY KEY ,
 nombre  VARCHAR(50),
 aula varchar(10),
 dniprofe varchar(9) not null,
 foreign key (dniprofe) references profesores(dniprofe));
 
 DROP TABLE IF EXISTS notas;
 CREATE TABLE IF NOT EXISTS notas (
 semestre varchar(6),
 codiasig  VARCHAR(6),
 numexp  VARCHAR(4),
 nota decimal(4,2),
 primary key (semestre, codiasig, numexp),
 foreign key (numexp) references alumnos(numexp),
 foreign key (codiasig) references asignaturas(codiasig));
 
INSERT INTO alumnos VALUES ("0001","Rojo Iglesias, Marta", "Barcelona",18);
INSERT INTO alumnos VALUES ("0002","Perez Carrillo, Iván","Bilbao",20);
INSERT INTO alumnos VALUES ("0003","Torres Marqués, Fernando","Madrid",19);
INSERT INTO alumnos VALUES ("0004","Rubio Sánchez, María","Sevilla",32);
INSERT INTO alumnos VALUES ("0005","Llamas Rocasolano, Isabel","Barcelona",25);
INSERT INTO alumnos VALUES ("0006","Comas Prieto, Marta", "Barcelona",18);
INSERT INTO alumnos VALUES ("0007","Gutierrez Saez, Jose","Bilbao",20);
INSERT INTO alumnos VALUES ("0008","Marcos Rico, Fernando","Madrid",19);
INSERT INTO alumnos VALUES ("0009","Villa Bueno, Sandra","Sevilla",32);
INSERT INTO alumnos VALUES ("0010","Tebar Mateos, Eva","Barcelona",25);

INSERT INTO profesores VALUES ("11112222A","Valle Roca, Ramon","12-10-01");
INSERT INTO profesores VALUES ("11113333B","Garcia Gomez, Jose","00-09-01");
INSERT INTO profesores VALUES ("11114444C","Martin Ayuso, Montse","01-10-25");
INSERT INTO profesores VALUES ("11115555D","Royes Zarate, Jordi","99-01-01");

INSERT INTO asignaturas VALUES ("ING1E","Inglés","12","11112222A");
INSERT INTO asignaturas VALUES ("MAT1E","Matemáticas","10","11113333B");
INSERT INTO asignaturas VALUES ("NAT1E","Naturales","11","11113333B");
INSERT INTO asignaturas VALUES ("SOC1E","Sociales","14","11114444C");

INSERT INTO notas VALUES ("1617-1","ING1E","0001",9.3);
INSERT INTO notas VALUES ("1617-1","ING1E","0002",4.5);
INSERT INTO notas VALUES ("1617-1","ING1E","0003",8.2);
INSERT INTO notas VALUES ("1617-1","ING1E","0004",7.5);
INSERT INTO notas VALUES ("1617-1","ING1E","0005",4.0);
INSERT INTO notas VALUES ("1617-1","ING1E","0006",6.0);
INSERT INTO notas VALUES ("1617-1","ING1E","0007",9.0);
INSERT INTO notas VALUES ("1617-1","ING1E","0008",9.7);
INSERT INTO notas VALUES ("1617-1","ING1E","0009",2.3);
INSERT INTO notas VALUES ("1617-1","ING1E","0010",6.5);

INSERT INTO notas VALUES ("1617-1","MAT1E","0001",5.3);
INSERT INTO notas VALUES ("1617-1","MAT1E","0002",7.5);
INSERT INTO notas VALUES ("1617-1","MAT1E","0003",4.2);
INSERT INTO notas VALUES ("1617-1","MAT1E","0004",5.5);
INSERT INTO notas VALUES ("1617-1","MAT1E","0005",3.0);
INSERT INTO notas VALUES ("1617-1","MAT1E","0006",7.0);
INSERT INTO notas VALUES ("1617-1","MAT1E","0007",9.0);
INSERT INTO notas VALUES ("1617-1","MAT1E","0008",9.1);
INSERT INTO notas VALUES ("1617-1","MAT1E","0009",4.3);
INSERT INTO notas VALUES ("1617-1","MAT1E","0010",7.5);

INSERT INTO notas VALUES ("1617-2","NAT1E","0001",8.3);
INSERT INTO notas VALUES ("1617-2","NAT1E","0002",2.5);
INSERT INTO notas VALUES ("1617-2","NAT1E","0003",3.2);
INSERT INTO notas VALUES ("1617-2","NAT1E","0004",6.5);
INSERT INTO notas VALUES ("1617-2","NAT1E","0005",4.0);
INSERT INTO notas VALUES ("1617-2","NAT1E","0006",10.0);
INSERT INTO notas VALUES ("1617-2","NAT1E","0007",9.5);
INSERT INTO notas VALUES ("1617-2","NAT1E","0008",9.3);
INSERT INTO notas VALUES ("1617-2","NAT1E","0009",5.3);
INSERT INTO notas VALUES ("1617-2","NAT1E","0010",8.5);

INSERT INTO notas VALUES ("1617-2","SOC1E","0001",7.3);
INSERT INTO notas VALUES ("1617-2","SOC1E","0002",2.5);
INSERT INTO notas VALUES ("1617-2","SOC1E","0003",6.2);
INSERT INTO notas VALUES ("1617-2","SOC1E","0004",7.5);
INSERT INTO notas VALUES ("1617-2","SOC1E","0005",5.0);
INSERT INTO notas VALUES ("1617-2","SOC1E","0006",10.0);
INSERT INTO notas VALUES ("1617-2","SOC1E","0007",10.0);
INSERT INTO notas VALUES ("1617-2","SOC1E","0008",8.6);
INSERT INTO notas VALUES ("1617-2","SOC1E","0009",7.3);
INSERT INTO notas VALUES ("1617-2","SOC1E","0010",6.5);

select * from alumnos;
select * from profesores;

create view expedientes as 
select a.nombre as "nombre alumno",n.nota, s.nombre as "Asignatura",
p.nombre as "profe"
from alumnos a 
inner join notas n 
on a.numexp = n.numexp
inner join asignaturas s
on n.codiasig = s.codiasig
inner join profesores p
on s.dniprofe = p.dniprofe;


select * from expedientes;

