/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad4;

/**
 *  : Crea una clase (@code Vehiculo) con un constructor
que reciba marca, modelo y año. Luego crea una clase Coche
que herede de Vehiculo y añada una propiedad
tipoCombustible
 * @author josee
 */
public class Actividad4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Vehiculo ve = new Vehiculo("Yamaha", "MT-07", 2022);
        ve.descripcionVehiculo();
        
        Coche ve2 = new Coche("Tesla", "Model 3", 2023, "Eléctrico");
        ve2.descripcionVehiculo();
    }
    
}
