/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad3;

/**
 *
 * @author josee
 */
public class Coche extends Vehiculo
{
    /**
     * 
     * @param marca Marca del Coche
     * @param modelo Modelo del Coche
     * @param año Año del Coche
     */
    public Coche(String marca, String modelo, int año) {
        super(marca, modelo, año);
    }
    
    /**
     * 
     * @return devuelve el impuesto
     */
    @Override
    public double calcularImpuesto() 
    {
        return 80.0;
    }
    
    @Override
    public String toString() {
        return "Marca: " + this.getMarca() +
           ", Modelo: " + this.getModelo() +
           ", Año: " + this.getAño();
    }
    
}
