/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad4;

/**
 *Clase que genera la instancia de {@code Coche} que deriva de Vehiculo
 * Tiene un atributo nuevo.
 * Tiene su constructor, getters y setters, y metodo para describirlo
 * @author josee
 */
public class Coche extends Vehiculo
{
    private String tipoCombustible;
    
    public Coche(String marca, String modelo, int año, String tipoCombustible) 
    {
        super(marca, modelo, año);
        this.tipoCombustible = tipoCombustible;
    }

    public String getTipoCombustible() 
    {
        return tipoCombustible;
    }

    public void setTipoCombustible(String tipoCombustible) 
    {
        this.tipoCombustible = tipoCombustible;
    }
    
    /**
     * Describe el Coche
     */
    @Override
    public void descripcionVehiculo()
    {
        System.out.println(this.getMarca() + ", " +
                this.getModelo() + ", " +
                this.getAño() + ", " +
                this.tipoCombustible);
    }
    
}
