 -- Tabla para almacenar la información de los candidatos

create database ofertastrabajo;
use ofertastrabajo;

-- Tabla para almacenar la información de las empresas
CREATE TABLE Empresas (
    id_empresa INT AUTO_INCREMENT PRIMARY KEY,
    nombre_empresa VARCHAR(100) NOT NULL,
    direccion VARCHAR(50),
    ciudad VARCHAR(50),
    telefono VARCHAR(15),
    email VARCHAR(100) NOT NULL
);

-- Tabla para almacenar las ofertas de trabajo
CREATE TABLE Ofertas (
    id_oferta INT AUTO_INCREMENT PRIMARY KEY,
    id_empresa INT,
    titulo VARCHAR(100) NOT NULL,
    descripcion TEXT,
    salario DECIMAL(10, 2),
    ubicacion VARCHAR(100),
    fecha_publicacion DATE,
    fecha_cierre DATE,
    CONSTRAINT fk_empresa_oferta 
    FOREIGN KEY (id_empresa) REFERENCES Empresas(id_empresa)
);

CREATE TABLE Candidatos (
    id_candidato INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    dni VARCHAR(15) NOT NULL UNIQUE,
    fecha_nacimiento DATE,
    correo_electronico VARCHAR(100),
    sexo CHAR(1),
    ciudad VARCHAR(50)
);



CREATE TABLE Candidato_Oferta (
    id_candidato INT,
    id_oferta INT,
    fecha_postulacion DATE,
    PRIMARY KEY (id_candidato, id_oferta),
    FOREIGN KEY (id_candidato) REFERENCES Candidatos(id_candidato),
    FOREIGN KEY (id_oferta) REFERENCES Ofertas(id_oferta)
);

INSERT INTO Empresas (nombre_empresa, direccion,ciudad, telefono, email)
VALUES
('Tech Solutions', 'Calle Alcalá, 100', 'Madrid', '912345678', 'contacto@techsolutions.com'),
('Innovatech', 'Calle Goya, 45', 'Madrid', '912678345', 'info@innovatech.com'),
('Digital Dreams', 'Avenida Diagonal, 300', 'Barcelona', '932123456', 'info@digitaldreams.com'),
('Barcelona Labs', 'Carrer de Casanova, 123', 'Barcelona', '932654789', 'contacto@bcnlabs.com'),
('Bizkaia Soft', 'Calle Ercilla, 70', 'Bilbao', '944123456', 'info@bizkaiasoft.com'),
('Bilbao Innovación', 'Calle Iparraguirre, 5', 'Bilbao', '944789321', 'contacto@bilbaoinnovacion.com'),
('Sevilla Tech', 'Avenida de la Palmera, 40', 'Sevilla', '954123456', 'info@sevillatech.com'),
('Innovación Sur', 'Calle San Fernando, 12', 'Sevilla', '954678345', 'contacto@innovacionsur.com'),
('Madrid Solutions', 'Paseo de la Castellana, 85', 'Madrid', '911234567', 'info@madridsolutions.com'),
('Barcelona Digital', 'Carrer de Balmes, 200', 'Barcelona', '933123456', 'contacto@barcelonadigital.com');



INSERT INTO Ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
VALUES
(1, 'Desarrollador Full Stack', 'Desarrollo de aplicaciones web con tecnologías modernas como React y Node.js.', 35000.00, 'Madrid', '2025-09-01', '2025-10-01'),
(2, 'Analista de Datos', 'Responsable de analizar grandes volúmenes de datos para apoyar la toma de decisiones.', 40000.00, 'Barcelona', '2025-08-25', '2025-09-25'),
(3, 'Ingeniero de Software', 'Desarrollo de software a medida para diferentes sectores, utilizando Python y C#.', 45000.00, 'Valencia', '2025-09-05', '2025-10-05'),
(4, 'Administrador de Sistemas', 'Gestión y mantenimiento de la infraestructura IT, servidores y redes.', 38000.00, 'Sevilla', '2025-09-10', '2025-10-10'),
(4, 'Desarrollador Mobile', 'Creación de aplicaciones móviles nativas para iOS y Android.', 42000.00, 'Barcelona', '2025-08-30', '2025-09-30'),
(6, 'Project Manager', 'Gestión de proyectos de desarrollo tecnológico, liderando equipos multidisciplinares.', 50000.00, 'Bilbao', '2025-09-01', '2025-09-30'),
(7, 'Ingeniero de Cloud', 'Diseño y mantenimiento de soluciones en la nube utilizando AWS y Azure.', 46000.00, 'Madrid', '2025-09-03', '2025-10-03'),
(7, 'Especialista en Ciberseguridad', 'Implementación de medidas de seguridad informática y análisis de vulnerabilidades.', 48000.00, 'Madrid', '2025-09-07', '2025-10-07'),
(9, 'Consultor de Energía Renovable', 'Asesoría técnica y financiera en proyectos de energía solar y eólica.', 43000.00, 'Sevilla', '2025-08-28', '2025-09-28'),
(10, 'Diseñador UX/UI', 'Diseño de interfaces de usuario y experiencia de usuario para aplicaciones web y móviles.', 37000.00, 'Barcelona', '2025-09-05', '2025-10-05');
INSERT INTO Ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
VALUES
(1, 'Consultor SAP', 'Implementación de soluciones SAP para mejorar los procesos empresariales.', 55000.00, 'Madrid', '2025-09-10', '2025-10-10'),
(2, 'Especialista en Marketing Digital', 'Diseño e implementación de campañas de marketing digital en redes sociales y SEO.', 38000.00, 'Barcelona', '2025-09-12', '2025-10-12'),
(2, 'Desarrollador Backend', 'Desarrollo de servicios backend utilizando Node.js y bases de datos NoSQL.', 40000.00, 'Sevilla', '2025-09-15', '2025-10-15'),
(4, 'Analista Financiero', 'Análisis de estados financieros y elaboración de reportes para la toma de decisiones.', 45000.00, 'Sevilla', '2025-09-17', '2025-10-17'),
(1, 'Ingeniero DevOps', 'Automatización de procesos de desarrollo y despliegue utilizando Docker y Kubernetes.', 47000.00, 'Zaragoza', '2025-09-18', '2025-10-18'),
(6, 'Especialista en Inteligencia Artificial', 'Desarrollo de modelos de machine learning y análisis de datos con Python.', 60000.00, 'Bilbao', '2025-09-20', '2025-10-20'),
(1, 'Diseñador Gráfico', 'Creación de piezas gráficas y contenido visual para campañas publicitarias.', 35000.00, 'Madrid', '2025-09-21', '2025-10-21'),
(8, 'Técnico en Soporte IT', 'Resolución de incidencias técnicas y mantenimiento de la infraestructura informática.', 30000.00, 'Madrid', '2025-09-22', '2025-10-22'),
(9, 'Director de Recursos Humanos', 'Gestión y dirección del departamento de recursos humanos, reclutamiento y selección.', 65000.00, 'Barcelona', '2025-09-23', '2025-10-23'),
(10, 'Arquitecto de Soluciones Cloud', 'Diseño de arquitecturas en la nube para proyectos empresariales con AWS y Azure.', 62000.00, 'Barcelona', '2025-09-24', '2025-10-24');




INSERT INTO Candidatos (nombre, dni, fecha_nacimiento, correo_electronico, sexo, ciudad) VALUES
('Carlos Ruiz', '12345678A', '1989-04-12', 'carlos.ruiz@mail.com', 'M', 'Madrid'),
('Laura Gómez', '23456789B', '1992-08-25', 'laura.gomez@mail.com', 'F', 'Barcelona'),
('Andrés Pérez', '34567890C', '1985-02-18', 'andres.perez@mail.com', 'M', 'Sevilla'),
('Marta Sánchez', '45678901D', '1990-11-30', 'marta.sanchez@mail.com', 'F', 'Valencia'),
('Javier Ortega', '56789012E', '1994-06-05', 'javier.ortega@mail.com', 'M', 'Zaragoza'),
('Nuria Martín', '67890123F', '1988-01-22', 'nuria.martin@mail.com', 'F', 'Bilbao'),
('Pablo López', '78901234G', '1991-09-17', 'pablo.lopez@mail.com', 'M', 'Granada'),
('Lucía Ramos', '89012345H', '1987-07-03', 'lucia.ramos@mail.com', 'F', 'Málaga'),
('Manuel Torres', '90123456I', '1993-03-14', 'manuel.torres@mail.com', 'M', 'Alicante'),
('Sara Vidal', '01234567J', '1995-12-08', 'sara.vidal@mail.com', 'F', 'Santander');

INSERT INTO Candidato_Oferta (id_candidato, id_oferta, fecha_postulacion) VALUES
(1, 9, '2025-09-17'),
(3, 10, '2025-08-29'),
(3, 16, '2025-08-07'),
(3, 13, '2025-08-17'),
(4, 7, '2025-09-15'),
(4, 11, '2025-09-25'),
(5, 9, '2025-08-25'),
(6, 11, '2025-08-29'),
(7, 1, '2025-09-12'),
(7, 12, '2025-09-20'),
(9, 6, '2025-08-28'),
(9, 8, '2025-08-10'),
(9, 17, '2025-09-01'),
(10, 13, '2025-08-15');


/*• Inserta 2 nuevas ofertas de trabajo, incluyendo todos los
 campos requeridos como: id_oferta, titulo, empresa, ciudad,
 fecha_publicacion, salario, descripcion. */
 
 select * from ofertas;
 
 insert into ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
 values
 (8, 'Asistente', 'Deberá encargarse de todo lo relacionado al proyecto.', 21000.00, 'Sevilla', '2025-01-01', '2025-10-24');

 insert into ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
 values
 (4, 'Ingeniero de la nube', 'Diseño y mantenimiento de soluciones en la nube utilizando AWS.', 40000.00, 'Barcelona', '2023-05-29', '2023-07-26');



/* Actualiza el salario de las ofertas ubicadas en Barcelona, 
incrementándolo en un 5%. */

update ofertas 
set salario = salario * 1.05
where ubicacion = 'Barcelona';

select * from ofertas;



/* Elimina las ofertas de trabajo cuyo salario sea inferior
a 27.000 € y cuya ciudad no sea Madrid. 
*/

delete from ofertas 
where salario < 27000
and ubicacion  != 'Madrid';

select * from ofertas;


/*Cambia la ciudad de todas las ofertas de Diseño a ‘Zaragoza’.
 (título de la oferta).*/

update ofertas 
set ubicacion  = 'Zaragoza'
where titulo like '%Diseñador%';

select * from ofertas;


/*Elimina las ofertas publicadas el mes de Agosto de 2025
 (Usa el campo fecha_publicacion).
*/

alter table candidato_oferta
drop foreign key candidato_oferta_ibfk_2;

alter table candidato_oferta
add constraint fk_candidato_oferta
foreign key (id_oferta) references ofertas(id_oferta)
on delete cascade;

delete from ofertas
where fecha_publicacion like '2025-08-%';


/* Cambia el dominio del correo de contacto de la empresa 
innovatech a gmail. 
*/

update empresas
set email = 'info@gmail.com'
where nombre_empresa = 'Innovatech';

select * from empresas;


/*Inserta una nueva oferta de trabajo con el campo salario en 
valor NULL. Explica cómo se comporta la base de 
datos (¿lo permite?, ¿lo reemplaza con un valor por defecto?, 
¿lanza error?). */

 insert into ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
 values
 (7, 'Ingeniero de la nube', 'Diseño y mantenimiento de soluciones en la nube utilizando AWS.', null, 'Barcelona', '2023-05-29', '2023-07-26');

select * from ofertas;



/*Elimina las ofertas ubicadas en Valencia que no tengan
 ningún candidato asignado. */
 
 delete from ofertas 
 where ubicacion = 'Valencia'
 and id_oferta not in (
	select id_oferta from candidato_oferta);
 

/* Aumenta un 10% el salario de las ofertas de trabajo
 en Madrid que correspondan al sector ‘Desarrollo de software’.
*/

update ofertas 
set salario = salario * 1.10
where ubicacion = 'Madrid' 
and titulo like 'Desarrollador%';

/* Inserta múltiples ofertas de trabajo en una sola sentencia 
INSERT, asegurando que todas pertenezcan al mismo sector 
(por ejemplo, ‘Marketing Digital’). */

INSERT INTO ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
VALUES
(2, 'Especialista en Marketing', 'Optimización de sitios web .', 12000.00, 'Barcelona', '2023-02-11', '2024-12-01'),
(4, 'Analista de Marketing Digital', 'Análisis de campañas publicitarias.', 52000.00, 'Sevilla', '2025-01-01', '2025-05-05'),
(3, 'Community Manager de Marketing', 'Gestión de redes sociales.', 36000.00, 'Bilbao', '2025-09-02', '2025-12-25');



/*Actividad 3*/
/*Simula el proceso de publicación de una nueva oferta 
y la asignación inmediata de tres candidatos a dicha oferta. 
Confirma la transacción.
*/

select * from Candidato_Oferta;

begin;

INSERT INTO ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
VALUES
(6, 'Manager', 'Gestións.', 40000.00, 'Barcelona', '2025-10-02', '2025-11-22');

INSERT INTO Candidatos (nombre, dni, fecha_nacimiento, correo_electronico, sexo, ciudad) 
VALUES
('Jose Jix', '23346678A', '1989-04-12', 'jose@mail.com', 'M', 'Madrid'),
('Antonio Vidal', '45456159B', '1992-08-25', 'antonio@mail.com', 'M', 'Barcelona');

INSERT INTO Candidato_Oferta (id_candidato, id_oferta, fecha_postulacion) 
VALUES
(11, 27, '2025-09-17'),
(12, 27, '2025-05-20');

commit;



/*Realiza una transacción que actualice el salario de todas 
las ofertas del sector 'Tecnología' en un 15%. 
Descarta la transacción utilizando un ROLLBACK 
*/

begin;

update ofertas 
set salario = salario * 1.15
where sector = 'Tecnología';

rollback;


/* Inserta dos nuevas ofertas y luego elimina una empresa 
relacionada. Utiliza puntos intermedios para revertir 
parcialmente la transacción. Documenta todo el proceso
*/

begin;

INSERT INTO ofertas (id_empresa, titulo, descripcion, salario, ubicacion, fecha_publicacion, fecha_cierre)
VALUES
(3, 'Consultor SAP', 'Implementar Soluciones.', 40000.00, 'Barcelona', '2025-10-02', '2025-11-22'),
(1, 'Ingeniero de Software', 'Desarrollo de software.', 30000.00, 'Bilbao', '2025-10-02', '2025-11-22');

select * from ofertas;

savepoint punto1;

ALTER TABLE ofertas
DROP FOREIGN KEY fk_empresa_oferta;

ALTER TABLE ofertas
ADD CONSTRAINT fk_empresa_oferta
FOREIGN KEY (id_empresa) REFERENCES empresas(id_empresa)
ON DELETE CASCADE;

delete from empresas
where id_empresa = 1 or id_empresa = 3;

select * from ofertas;

rollback to punto1;

select * from ofertas;

commit;

/*Inicia una transacción para eliminar todas las ofertas de una 
ciudad concreta. Antes del COMMIT, comprueba que los registros 
ya no están visibles para otras sesiones. Luego confirma o 
revierte la operación.
*/

begin;

delete from ofertas
where ubicacion = 'Barcelona';

SELECT * FROM ofertas
where ubicacion = 'Barcelona';

rollback;