/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad1;

/**
 *
 * @author josee
 * 1.Crear una classe abstracta vehiculo con propiedades comunes
 * (marca, modelo, año) y unmetodo abstracto calcularImpuesto();
 * 2.Crear dos subsclases: Coche y Moto, que exstiendan Vehículo e implementen
 * el metodo calcularImpuesto() con logica distinta.
 */
public class Actividad1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Coche coche = new Coche("Renault","Master",1995);
        Moto moto = new Moto("Yamaha","Reina",2005);
        
        System.out.println(coche.calcularImpuesto());
        System.out.println(moto.calcularImpuesto());
    }
    
}
