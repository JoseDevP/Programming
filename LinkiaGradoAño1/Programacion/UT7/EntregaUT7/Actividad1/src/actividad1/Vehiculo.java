/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad1;

/**
 *
 * @author josee
 * Clase que genera instancia (@code Vehiculo)
 * Tiene propiedades marca, modelo, año
 * Tiene metodo abstracto calcularImpuesto()
 */
public abstract class Vehiculo 
{
    private String marca;
    private String modelo;
    private int año;

    /**
     * 
     * @param marca Marca del vehiculo
     * @param modelo Modelo del vehiculo
     * @param año Año del vehiculo
     */
    public Vehiculo(String marca, String modelo, int año) {
        this.marca = marca;
        this.modelo = modelo;
        this.año = año;
    }

    /**
     * 
     * @return devuelve Marca del vehiculo
     */
    public String getMarca() 
    {
        return marca;
    }
    
    /**
     * 
     * @return devuelve Modelo del vehiculo
     */
    public String getModelo() 
    {
        return modelo;
    }

    /**
     * 
     * @return devuelve Año del vehiculo
     */
    public int getAño() 
    {
        return año;
    }
    
    /**
     * 
     * @param marca Marca del vehiculo
     */
    public void setMarca(String marca) 
    {
        this.marca = marca;
    }
    
    /**
     * 
     * @param modelo Modelo del vehiculo
     */
    public void setModelo(String modelo) 
    {
        this.modelo = modelo;
    }

    /**
     * 
     * @param año Año del vehiculo
     */
    public void setAño(int año) 
    {
        this.año = año;
    }   
    
    /**
     * 
     * @return devuelve el impuesto
     */
    public abstract double calcularImpuesto();
}
