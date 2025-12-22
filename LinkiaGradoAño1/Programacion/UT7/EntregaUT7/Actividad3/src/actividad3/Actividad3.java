/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad3;

import java.util.ArrayList;

/**
 *
 * @author josee
 */
public class Actividad3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Coche coche = new Coche("Renault","Master",1995);
        CocheElectrico cocheEl = new CocheElectrico("RenaultElectrico","Lock",2000);
        Moto moto = new Moto("Yamaha","Reina",2005);
        
        ArrayList<Vehiculo> vehiculos = new ArrayList<Vehiculo>();
        
        vehiculos.add(coche);
        vehiculos.add(moto);
        vehiculos.add(cocheEl);
        
        for(int i = 0; i < vehiculos.size(); i++) {
        System.out.println(vehiculos.get(i).getModelo());
        }
    }
    
}
