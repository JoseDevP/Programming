/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package clase;

import java.util.ArrayList;

/**
 *
 * @author josee
 */
public class Clase {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Perro per = new Perro("perro", 2);
        per.accion();
        
        Ave av = new Ave("ave", 2);
        av.accion();
        
        var inventario = new ArrayList<Animal>();
        inventario.add(per);
        inventario.add(av);
        
        System.out.println(inventario.get(0).getNombre());
    }
    
}
