/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad3;

/**
 *
 * @author josee
 */
public class Moto extends Vehiculo
{
    /**
     * 
     * @param marca Marca del Moto
     * @param modelo Modelo del Moto
     * @param año Año del Moto
     */
    public Moto(String marca, String modelo, int año) {
        super(marca, modelo, año);
    }
    
    /**
     * 
     * @return devuelve el impuesto
     */
    @Override
    public double calcularImpuesto() 
    {
        return 50.0;
    }

    @Override
    public String toString() {
        return "Marca: " + this.getMarca() +
           ", Modelo: " + this.getModelo() +
           ", Año: " + this.getAño();
    }
}
