-- Parte 1
show databases;

create database empresa_examen;

use empresa_examen;

create table if not exists  departamento(
numdep int auto_increment primary key,
nombredep varchar(50) not null,
ciudad varchar(40)
);

create table if not exists  trabajadores(
dni varchar(9) primary key,
nombre varchar(50) not null,
salario decimal(8,2),
antiguedad int,
ciudad varchar(40),
departamento int,
constraint fk_trabajadores_departamento
	foreign key (departamento) 
	references departamento(numdep)
	on delete set null
	on update cascade
);

create table if not exists trabajadores_log (
id int auto_increment primary key,
dni varchar(9),
nombre varchar(50),
salario_antiguo decimal(8,2),
salario_nuevo decimal(8,2),
fecha datetime
);


-- Parte 2
alter table trabajadores
add column email varchar(100) after departamento;

alter table trabajadores
modify column ciudad varchar(60);

alter table trabajadores
drop column email;


-- Parte 3
select * from trabajadores;

insert into departamento (nombredep,ciudad)
values ("departamento1","Barcelona");

insert into departamento set nombredep="departamento2",
ciudad="Madrid";

insert into departamento (nombredep,ciudad)
values ("departamento3","Barcelona");


insert into trabajadores (dni,nombre,salario,antiguedad,
ciudad,departamento)
values ("41012782X", "Jose", 2000, 20, "Barcelona", 1);

insert into trabajadores set dni="42053752X",
nombre="Juana", salario=10000, antiguedad=10, 
ciudad= "Madrid", departamento=2;


insert into trabajadores (dni,nombre,salario,antiguedad,
ciudad,departamento)
values ("85236914Y", "Antonia", 15000, 15, "Barcelona", 3);

insert into trabajadores set dni="45721236Z",
nombre="Maite", salario=12000, antiguedad=5, 
ciudad= "Madrid", departamento=2;


insert into trabajadores (dni,nombre,salario,antiguedad,
ciudad,departamento)
values ("78945612W", "Pedro", 30000, 20, "Barcelona", 1);

insert into trabajadores set dni="12345678Y",
nombre="Matilde", salario=20000, antiguedad=5, 
ciudad= "Barcelona", departamento=3;



-- Parte 4
select * from trabajadores;

select nombre,salario from trabajadores;

select * from trabajadores
where nombre like "A%";

select * from trabajadores
where departamento = 0;

select * from trabajadores
where salario between 20000 and 40000;

select * from trabajadores
order by salario desc, nombre asc;



-- Parte 5

select 
	nombre, 
	salario, 
	salario * 1.05 as salario_incrementado
from trabajadores;

select 
	ciudad,
    avg(salario) as salario_medio_ciudad
from trabajadores
group by ciudad;    

select 
	max(salario) as salario_maximo,
    min(salario) as salario_minimo
from trabajadores;
 
 
-- Parte 6
select 
	t.nombre,
    t.salario,
    d.nombredep
from trabajadores t
left join departamento d
on t.departamento = d.numdep;

select 
    d.numdep,
    d.nombredep,
    count(t.dni) as num_trabajadores
from departamento d
left join trabajadores t
on d.numdep = t.departamento
group by d.numdep, d.nombredep;

select t.*
from trabajadores t
inner join departamento d
on t.departamento = d.numdep
where d.nombredep = "departamento3";
 

-- Parte 7
select 
	d.nombredep, 
    count(t.dni) as num_trabajadores
from departamento d
left join trabajadores t 
on d.numdep = t.departamento
group by d.nombredep
having count(t.dni) > 1;

select 
    ciudad,
    avg(salario) as salario_medio
from trabajadores
group by ciudad
having avg(salario) > 10000;
    

-- Parte 8

select 
	nombre,
    salario
from trabajadores
where salario > 
(select avg(salario) from trabajadores);

select 
	nombre,
    salario
from trabajadores
where salario > all (select salario from trabajadores 
where departamento = 2);

select 
	nombre,
    salario
from trabajadores
where salario > any (select salario from trabajadores 
where departamento = 1);


-- Parte 9
create view vista_trabajadores  as
select 
	t.nombre,
    t.salario,
    t.ciudad,
    d.nombredep
from trabajadores t
left join departamento d
on t.departamento = d.numdep;

select * from vista_trabajadores;


-- Parte 10
SHOW VARIABLES LIKE 'autocommit';
set autocommit= 0;

begin;

insert into trabajadores (dni,nombre,salario,antiguedad,
ciudad,departamento)
values ("75324185D", "Fabiana", 1000, 1, "Barcelona", 1);

savepoint puntoGuardado1;

insert into trabajadores (dni,nombre,salario,antiguedad,
ciudad,departamento)
values ("78912354X", "Aurora", 50000, 3, "Barcelona", 3);

rollback to puntoGuardado1;

commit;

select * from departamento;
select * from trabajadores;


-- Parte 11
DELIMITER //

CREATE PROCEDURE aumentar_salario_departamento(
    IN p_numero_departamento INT,
    IN porcentaje DECIMAL(5,2)
)
BEGIN
    UPDATE trabajadores
    SET salario = salario * (1 + porcentaje / 100)
    WHERE departamento = p_numero_departamento;
END//

DELIMITER ;

call aumentar_salario_departamento(2, 5)


DELIMITER //

create procedure tipo_salario( in p_dni varchar(9) )
begin
	declare p_salario decimal(8,2);
    
    select salario 
    into p_salario
    from trabajadores
    where dni = p_dni;
    
    if p_salario < 10000 
    then select 'Salario Bajo' as categoria;
    
    elseif p_salario >= 10000 and p_salario < 20000
    then select 'Salario Medio' as categoria;
    
    else select 'Salario Alto' as categoria;
    
    end if;
    
end;
//

DELIMITER ;

call tipo_salario('75324185D');

select * from trabajadores;



-- Parte 12
DELIMITER //
create function salario_final(
p_salario decimal(8,2),
p_antiguedad INT
)
returns decimal(8,2)
deterministic
begin
	if p_antiguedad >= 10 
    then return p_salario * 1.10;
    
	elseif p_antiguedad >= 5 
    then return p_salario * 1.05;
    
    else return p_salario;
    
    end if;
end;
// 
DELIMITER ;

SELECT 
    nombre,
    salario,
    antiguedad,
    salario_final(salario, antiguedad) AS salario_calculado
FROM trabajadores;


-- Parte 13
DELIMITER //
create procedure procedimiento_ciudad(in p_ciudad varchar(40) )
begin
	DECLARE v_nombre VARCHAR(50);
    DECLARE v_antiguedad INT;
    DECLARE v_salario DECIMAL(8,2);
    DECLARE fin_cursor BOOLEAN DEFAULT FALSE;

	declare cur cursor for 
		select 
			nombre,
            antiguedad,
            salario
		from trabajadores
        where ciudad = p_ciudad;
        
	declare continue handler for not found 
		set fin_cursor = true;
    
    open cur;
    
	bucle:loop
		fetch cur into v_nombre, v_antiguedad, v_salario;
        
        if fin_cursor then
			leave bucle;
		end if;

        select 
            v_nombre as nombre,
            v_antiguedad as antiguedad,
            v_salario as salario;                
	end loop;
        
	close cur;
end;
//
DELIMITER ;


-- Parte 14



