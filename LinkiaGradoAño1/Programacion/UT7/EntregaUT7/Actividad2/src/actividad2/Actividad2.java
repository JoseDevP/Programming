/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad2;

/**
 *
 * @author josee
 */
public class Actividad2 {

    /**
     * @param args the command line arguments
     * Añadir constructores en Vehiculo, Coche, Moto usandao super() para
     * iniciar propiedades
     * 
     * Sobreescribir el metodo toString() en cada clase con \Override
     */
    public static void main(String[] args) 
    {
        Coche coche = new Coche("Renault","Master",1995);
        Moto moto = new Moto("Yamaha","Reina",2005);
        
        System.out.println(coche.toString());
        System.out.println(moto.toString());
    }
    
}
