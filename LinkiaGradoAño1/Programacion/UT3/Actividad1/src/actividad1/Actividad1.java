/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad1;

/**
 * En esta clase se provará el correcto funcionanmiento de las clases
 * {@code Animal}, {@code Perro} y {@code Gato}
 * @author josee
 */
public class Actividad1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        /*
        * Creamos un animal y mostramos su sonido.
        *Si todo ha ido bien deberia mostrar "Sonido de Animal"
        */
        Animal anim = new Animal(36,15);
        anim.hacerSonido();
        
        /*
        * Creamos un Perro y mostramos su sonido.
        *Si todo ha ido bien deberia mostrar "Guau Guau"
        */
        Perro perr = new Perro(36,15);
        perr.hacerSonido();
        
        /*
        * Creamos un Gato y mostramos su sonido.
        *Si todo ha ido bien deberia mostrar "Miau"
        */
        Gato gatt = new Gato(36,15);
        gatt.hacerSonido();
    }
    
}
