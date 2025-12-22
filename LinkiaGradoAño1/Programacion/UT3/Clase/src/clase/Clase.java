/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package clase;

/**
 *
 * @author josee
 * Programacion orientada a objetos
 */
public class Clase {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Coche coche = new Coche(12000,"sgddfg",1800,4);
        Moto moto = new Moto(12000,"sgddfg",1800, 28);
        Hibrido hibrido = new Hibrido(12000,"sgddfg",1800,4,5000);

        System.out.println("El coche tiene " + coche.getNumPuertas());
        System.out.println("La moto tiene " + moto.getRigidezCaballete());

        
        coche.acelerar(20);

    }
    
}
