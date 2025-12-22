/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad2;
import java.util.List;
import java.util.ArrayList;

/**
 *Clase (@code Almacen) que genera una instancia de un Almacen.
 * Esta clase permite tener una lista de (@code Producto), 
 * que se puede manipular aañaadiendo, eliminando o buscando un producto
 * @author josee
 */
public class Almacen 
{
    List<Producto> productos;
    
    /**
     * Creaa lista de objetos {@code Producto}
     */
    public Almacen() 
    {
        this.productos =  new ArrayList<>();
    }
    
    /**
     * @return productos devuelve la lista de (@code Producto)
     */
    public List<Producto> getProductos() 
    {
        return productos;
    }
    
    /**
     * @param productos lista de (@code Producto)
     */
    public void setProductos(List<Producto> productos) 
    {
        this.productos = productos;
    }
    
    /**
     * @param producto producto que vaamos a añadir a la lista
     */
    public void addProducto(Producto producto)
    {
        this.productos.add(producto);
    }
    
    /**
     * @param nombreProducto nombre del producto que vamos a eliminar de la lista
     */
    public void deleteProducto(String nombreProducto)
    {
        this.productos.remove(searchProducto(nombreProducto));
    }

    /**
     * @param nombreProducto nombre del producto que buscamos
     * @return producto que devolvemos
     */
    public Producto searchProducto(String nombreProducto)
    {
        for (Producto p : productos)
        {
            if(p.getNombre().equalsIgnoreCase(nombreProducto))
                return p;
        }
        return null;
    }
    
    public void mostrarProductos()
    {
        for(int i = 0; i < this.productos.size(); i++)
            System.out.println(productos.get(i).getNombre() + " " + 
                    productos.get(i).getCantidad() + " " +
                    productos.get(i).getPrecio() + "\n");
    }
}
