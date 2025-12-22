-- n 1
-- indices para campos que solemos usar mas para ir mas rapido


create database facturacion;
use facturacion;

create table clientes(
cif varchar(10) primary key,
nombre varchar(40) not null,
direccion varchar(40)
);

create table facturas( 
id_factura integer auto_increment primary key,
fecha_factura date,
total decimal(8,2),
cif varchar(10),
constraint fk_facturas_clientes foreign key (cif) references clientes(cif)
);

-- indice
create index idx_nombre on clientes(nombre);
show index from clientes;
show index from facturas;