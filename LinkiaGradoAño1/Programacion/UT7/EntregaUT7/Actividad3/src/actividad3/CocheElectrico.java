/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad3;

/**
 *
 * @author josee
 */
public class CocheElectrico extends Coche implements Electrico
{
    
    public CocheElectrico(String marca, String modelo, int año) {
        super(marca, modelo, año);
    }

    @Override
    public void cargarBateria() {
        System.out.println("Cargando la bateria");
    }
    
}
