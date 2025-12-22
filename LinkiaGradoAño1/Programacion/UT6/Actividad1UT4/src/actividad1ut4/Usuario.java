/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad1ut4;

/**
 *Clase que genera {@code Usuario}. 
 * Tiene sus atributos nombre email y edad
 * Tiene su constructor, getteers y setters.
 * @author josee
 */
public class Usuario 
{   
    private String nombre;
    private String email;
    private int edad;
    
    /**
     *
     * @param nombre nombre del usuario
     * @param email email del usuario
     * @param edad edad del usuario
     */
    public Usuario(String nombre, String email, int edad) {
        this.nombre = nombre;
        this.email = email;
        this.edad = edad;
    }
    
    /**
     * 
     * @return devuelve el nombre del usuario
     */
    public String getNombre() {
        return nombre;
    }
    
    /**
     * 
     * @return devuelve el email del usuario
     */
    public String getEmail() {
        return email;
    }
    
    /**
     * 
     * @return devuelve la edad del usuario
     */
    public int getEdad() {
        return edad;
    }
    
    /**
     * 
     * @param nombre nombre del usuario
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * 
     * @param email email del usuario
     */
    public void setEmail(String email) {
        this.email = email;
    }

    /**
     * 
     * @param edad edad del usuario
     */
    public void setEdad(int edad) {
        this.edad = edad;
    }
    
    
}
