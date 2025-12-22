/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad4;

/**
 *Clase que genera la instancia de {@code Vehiculo}
 * Tiene atributos marca, modelo, año.
 * Tiene su constructor, getters y setters, y metodo para describirlo
 * @author josee
 */
public class Vehiculo 
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
    public Vehiculo(String marca, String modelo, int año) 
    {
        this.marca = marca;
        this.modelo = modelo;
        this.año = año;
    }

    /**
     * 
     * @return devuelve la marca del vehiculo
     */
    public String getMarca() {
        return marca;
    }
    
    /**
     * 
     * @return devuelve el modelo del vehiculo
     */
    public String getModelo() {
        return modelo;
    }
    
    /**
     * 
     * @return devuelve el año del vehiculo
     */
    public int getAño() {
        return año;
    }

    /**
     * 
     * @param marca Marca del vehiculo
     */
    public void setMarca(String marca) {
        this.marca = marca;
    }

    /**
     * 
     * @param modelo Modelo del vehiculo
     */
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    /**
     * 
     * @param año Año del vehiculo
     */
    public void setAño(int año) {
        this.año = año;
    }
    
    /**
     * Describe el Vehiculo
     */
    public void descripcionVehiculo()
    {
        System.out.println(this.marca + ", " +
                this.modelo + ", " +
                this.año);
    }
    
}
