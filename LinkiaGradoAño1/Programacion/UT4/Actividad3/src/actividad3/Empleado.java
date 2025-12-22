/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad3;

/**
 * Clase que genera instancia de {@code Empleado).
 * Tiene atributos como nombre, salario, y cargo
 * Tiene un constructor, geters y setters y metodos para calculaar el salario
 * anual y cambiar el cargo
 * @author josee
 */
public class Empleado 
{
    private String nombre;
    private double salario;
    private String cargo;

    /**
     * 
     * @param nombre Nombre de el empleado
     * @param salario Salario de el empleado
     * @param cargo Cargo de el empleado
     */
    public Empleado(String nombre, double salario, String cargo) 
    {
        this.nombre = nombre;
        this.salario = salario;
        this.cargo = cargo;
    }  

    /**
     * 
     * @return devuelve el nombre de el empleado
     */
    public String getNombre() 
    {
        return nombre;
    }

    /**
     * 
     * @return devuelve el salario de el empleado
     */
    public double getSalario() 
    {
        return salario;
    }

    /**
     * 
     * @return devuelve el cargo de el empleado
     */
    public String getCargo() 
    {
        return cargo;
    }
    
    /**
     * 
     * @param nombre Nombre de el empleado
     */
    public void setNombre(String nombre) 
    {
        this.nombre = nombre;
    }

    /**
     * 
     * @param salario Salario de el empleado
     */
    public void setSalario(double salario) 
    {
        this.salario = salario;
    }

    /**
     * 
     * @param cargo Cargo de el empleado
     */
    public void setCargo(String cargo) 
    {
        this.cargo = cargo;
    }
    
    /**
     * 
     * @return devuelve el salario anual de el empleado
     */
    public double salarioAnual()
    {
        return salario * 12;
    }
    
    /**
     * 
     * @param cargo nuevo cargo del empleado
     */
    public void cambiarCargo(String cargo)
    {
        this.cargo = cargo;
    }
    
    public void descripcionEmpleado()
    {
        System.out.println(this.nombre + ", " +
                this.salario + ", " +
                this.cargo + ", ");
    }
}
