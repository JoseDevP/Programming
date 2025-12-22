/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad2;

/**
 * Esta clase genera un {@code Producto).
 * Contiene los atributos nombre, caantidad y precio
 * Tiene un constructor y getters y setters para cada atributo
 * 
 * @author josee
 */
public class Producto 
{
    private String nombre;
    private int cantidad;
    private double precio;

    /**
    * Crea objeto {@code Producto}
    *@param nombre nombre del producto
    *@param cantidad cuanto contenido hay del producto
    *@param precio cuanto vale el producto
    */
    public Producto(String nombre, int cantidad, double precio) 
    {
        this.nombre = nombre;
        this.cantidad = cantidad;
        this.precio = precio;
    }
    
    /**
     * @return nombre devuelve el nombre
    */
    public String getNombre() 
    {
        return nombre;
    }
    
    /**
     * @return cantidad devuelve la cantidad
    */
    public int getCantidad() 
    {
        return cantidad;
    }
    
    /**
     * @return precio devuelve el precio
    */
    public double getPrecio() 
    {
        return precio;
    }
    
    /**
     * @param nombre devuelve el nombre
    */
    public void setNombre(String nombre) 
    {
        this.nombre = nombre;
    }
    
    /**
     * @param cantidad devuelve la cantidad
    */
    public void setCantidad(int cantidad) 
    {
        this.cantidad = cantidad;
    }
    
    /**
     * @param precio devuelve el precio
    */
    public void setPrecio(double precio) 
    {
        this.precio = precio;
    }
    
    
}
