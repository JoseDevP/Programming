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

-- Ejemplo Variables de usuario.

SET @salario_medio = (SELECT AVG(salario) FROM trabajadores);
SELECT @salario_medio;

-- Ejemplo Variables locales
DELIMITER //
CREATE PROCEDURE mostrar_max_salario()
BEGIN
    DECLARE max_sal DECIMAL(8,2);
    SELECT MAX(salario) INTO max_sal FROM trabajadores;
    SELECT max_sal AS salario_maximo;
END;
//
DELIMITER ;
CALL mostrar_max_salario();

-- Procedimiento almacenado. Subir salario de un departamento.
select * from trabajadores;
DELIMITER //
CREATE PROCEDURE subir_salario_departamento(
    IN p_dep INT,
    IN p_porcentaje DECIMAL(5,2)
)
BEGIN
    UPDATE trabajadores
    SET salario = salario * (1 + p_porcentaje/100)
    WHERE numdep = p_dep;
END;
//
DELIMITER ;
CALL subir_salario_departamento(2,5);
select * from trabajadores;

-- Estructura IF
DELIMITER //
CREATE PROCEDURE clasificar_salario(IN p_dni VARCHAR(9))
BEGIN
    DECLARE s DECIMAL(8,2);

    SELECT salario INTO s
    FROM trabajadores
    WHERE dni = p_dni;

    IF s >= 50000 THEN SELECT 'Salario alto' AS categoria;
    ELSEIF s >= 30000 THEN SELECT 'Salario medio' AS categoria;
    ELSE SELECT 'Salario bajo' AS categoria;
    END IF;
END;
//
DELIMITER ;
CALL clasificar_salario('11112222A');

-- Instrucción CASE
SELECT nombre, antiguedad,
    CASE
        WHEN antiguedad >= 10 THEN 'Muy veterano'
        WHEN antiguedad >= 5 THEN 'Veterano'
        ELSE 'Nuevo'
    END AS categoria
FROM trabajadores;

-- Bucles While
DELIMITER //
CREATE PROCEDURE contar_hasta(IN limite INT)
BEGIN
    DECLARE c INT DEFAULT 1;

    WHILE c <= limite DO
        SELECT c;
        SET c = c + 1;
    END WHILE;
END;
//
DELIMITER ;
call contar_hasta(10);

-- ejemplo funciones
DELIMITER //
CREATE FUNCTION salario_con_bonus(sal DECIMAL(8,2), antig INT)
RETURNS DECIMAL(8,2)
DETERMINISTIC
BEGIN
    IF antig >= 10 THEN RETURN sal * 1.10;
    ELSEIF antig >= 5 THEN RETURN sal * 1.05;
    ELSE RETURN sal;
    END IF;
END;
//
DELIMITER ;
SELECT nombre, salario, antiguedad,
       salario_con_bonus(salario, antiguedad) AS salario_final
FROM trabajadores;

-- ejemplo cursor
DELIMITER //
CREATE PROCEDURE trabajadores_por_ciudad(IN p_ciudad VARCHAR(40))
BEGIN
    DECLARE v_nombre VARCHAR(50);
    DECLARE v_antig INT;
    DECLARE v_sal DECIMAL(8,2);
    DECLARE fin_cursor BOOL DEFAULT FALSE;

    -- Cursor para seleccionar trabajadores de una ciudad concreta
    DECLARE cur CURSOR FOR
        SELECT nombre, antiguedad, salario
        FROM trabajadores WHERE ciudad = p_ciudad;
    -- Handler para detectar que ya no hay más filas
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET fin_cursor = TRUE;

    OPEN cur;
    bucle: LOOP
        FETCH cur INTO v_nombre, v_antig, v_sal;
        IF fin_cursor THEN LEAVE bucle;
        END IF;

        SELECT v_nombre AS nombre, v_antig AS antiguedad,
            v_sal AS salario;
    END LOOP;
    CLOSE cur;
END;
//
DELIMITER ;

CALL trabajadores_por_ciudad('Madrid');

-- ejemplo trigger

CREATE TABLE trabajadores_log (
    id INT AUTO_INCREMENT PRIMARY KEY,
    dni VARCHAR(9),
    nombre VARCHAR(50),
    salario_anterior DECIMAL(8,2),
    salario_nuevo DECIMAL(8,2),
    fecha DATETIME
);

DELIMITER //
CREATE TRIGGER trg_salario_log
AFTER UPDATE ON trabajadores
FOR EACH ROW
BEGIN
    IF OLD.salario <> NEW.salario THEN
        INSERT INTO trabajadores_log
        VALUES ( NULL, OLD.dni, OLD.nombre, OLD.salario, NEW.salario, NOW() );
    END IF;
END;
//
DELIMITER ;

-- ejecución del trigger
UPDATE trabajadores
SET salario = salario + 1000
WHERE ciudad = "Madrid";

select * from trabajadores_log;




