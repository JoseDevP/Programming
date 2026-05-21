/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.empresadb;

/**
 *
 * @author josee
 */
public class EmpresaDB {

    public static void main(String[] args) 
    {
        //Conectarse a la bbdd
        BBDDManager bbdd = new BBDDManager();
        
        //Insertar cliente
        bbdd.insertarCliente("Jose", "Barcelona");
        
        //Mostrar clientes
        bbdd.mostrarClientes();
        
        //Actualizar ciudad
        bbdd.actualizarCliente(1, "Jose", "Madrid");
        
        //Comprovar que ha cambiado 
        bbdd.mostrarClientes();
        
        //Eliminar cliente por id
        bbdd.eliminarCliente(1);
        
        //Comprovar que ha cambiado 
        bbdd.mostrarClientes();
        
        //cerrar db
        bbdd.desconectar();
    }
}
