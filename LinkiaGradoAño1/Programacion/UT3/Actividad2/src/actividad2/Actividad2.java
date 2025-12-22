/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad2;
import java.util.Scanner;
import java.util.List;


/**
 *
 * @author josee
 */
public class Actividad2 
{

    /**
     * Esta aplicacion permite añadir, eliminar y buscar (@code Producto) que 
     * pertenecen a un objeto de la clase (@code Almacen)
     * @param args
     */
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        Almacen almacen = new Almacen();
        
        /*Lista de las opciones por si en algun momento añadimos más*/
        List<String> opciones = List.of(
        "Añadir Producto",
        "Eliminar Producto",
        "Buscar Producto",
        "Ver todos los productos",
        "Salir"
        );
        
        int opcion = 0;
        
        while (opcion != 5) 
        {
            System.out.println("------------- Almacén ------------------");
            /*Llamomos a la funcion que mostrará las funciones*/
            opcion = mostrarOpciones(opciones, sc);

            switch (opcion) {
                case 1 -> añadirProducto(almacen, sc);
                case 2 -> {
                    System.out.println("Nombre del producto:\n");
                    String nombre = sc.nextLine();
                    eliminarProducto(almacen, nombre);
                }
                case 3 -> {
                    System.out.println("Nombre del producto:\n");
                    String nombre = sc.nextLine();
                    buscarProductos(almacen, nombre);}
                case 4 -> almacen.mostrarProductos();
                case 5 -> System.out.println("Saliendo del programa...");
            }
        }

        sc.close();
        
    }
    
    /**
     * Este metodo muestra todas las opciones disponibles
     * 
     * @param opciones lista de las opciones disponibles
     * @param sc Scanner
     * @return devuelve la opcion escogida
     */
    public static int mostrarOpciones(List<String> opciones, Scanner sc)
    {   
        for(int i = 0; i < opciones.size(); i++)
            System.out.println((i + 1) + "." + opciones.get(i) + "\n");
       
        
        int opcion = 0;
        
        while (opcion < 1 || opcion > opciones.size())
        {
            System.out.println("Escoje la opcion: ");
            opcion = sc.nextInt();
            sc.nextLine();
        }
        
        return opcion;
    }
    
    /**
     * Añade un producto al almacen
     * 
     * @param almacen objeto almacen
     * @param sc Scanner
     */
    private static void añadirProducto(Almacen almacen, Scanner sc) 
    {
        String nombre;
        int cantidad;
        double precio;
        
        System.out.println("Nombre del producto:\n");
        nombre = sc.nextLine();
        
        System.out.println("Cantidad del producto:\n");
        cantidad = sc.nextInt();
        
        System.out.println("Precio del producto:\n");
        precio = sc.nextDouble();
        sc.nextLine();
                
        Producto producto = new Producto(nombre,cantidad,precio);
        almacen.addProducto(producto);
        
        System.out.println("Producto añadido\n");
        
    }
    
    /**
     * Elimina un producto al almacen
     * 
     * @param almacen objeto almacen
     * @param nombre Nombre del producto
     */
    private static void eliminarProducto(Almacen almacen,String nombre) 
    {
        if(!buscarProductos(almacen,nombre))
        {
            System.out.println("Producto no encontrado\n");
            return;
        }       
        
        almacen.deleteProducto(nombre);
        
        System.out.println("Producto eliminado\n");
    }
    
    /**
     * Busca un producto al almacen
     * 
     * @param almacen objeto almacen
     * @param nombre Nombre del producto
     */
    private static boolean buscarProductos(Almacen almacen,String nombre) 
    {
        
        Producto p = almacen.searchProducto(nombre);
        if(p == null)
        {
            System.out.println("Producto no encontrado\n");
            return false;
        }
        
        System.out.println("Nombre: " + p.getNombre() + " " + 
                    "Cantidad: " +p.getCantidad() + " " +
                    "Precio: " +p.getPrecio() + "\n");
        
        return true;
    }
    
}
