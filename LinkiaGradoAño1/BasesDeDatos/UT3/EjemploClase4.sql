-- Usuarios

create user Jose@localhost identified by '1234';
drop user Jose@localhost;

-- Permisos Grant, 
-- *.* todas las bases y tablas
-- Basedatos.* todas las tablas de esa base
-- Basedatos.tabla solo a esa tabla en esa base
-- flush privileges -> recargar permisos
-- grant all on *.* to Jose@localhost;
-- grant select on *.* to Jose@localhost;
-- grant select, insert on *.* to Jose@localhost;

grant select on facturacion.* to Jose@localhost;
flush privileges;

-- permisos del usuario
show grants;

-- quitar permisos revoke
revoke select on facturacion.* from Jose@localhost;