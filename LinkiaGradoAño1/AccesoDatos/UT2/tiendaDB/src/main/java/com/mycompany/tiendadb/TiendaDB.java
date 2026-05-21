/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.tiendadb;

/**
 *
 * @author josee
 */
public class TiendaDB {

    public static void main(String[] args) 
    {
        //Conectarse a la bbdd
        BBDDManager bbdd = new BBDDManager();
        
        //Insertar producto
        bbdd.insertarProducto("Patatas", 6);
        
        //Venta
        bbdd.registrarVenta(1, 2);
        
        //Venta no posible(rollback)
        bbdd.registrarVenta(1, 10);
        
        //cerrar db
        bbdd.desconectar();
    }
}
