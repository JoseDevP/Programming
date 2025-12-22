/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad3;

/**
 * Actividad 3: Implementa una clase Empleado con
propiedades como nombre, salario y cargo. Añade un
constructor personalizado y métodos para calcular el salario
anual y cambiar el cargo.

 * @author josee
 */
public class Actividad3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Empleado em = new Empleado("Jose",1120,"Director");
        em.descripcionEmpleado();
        
        em.cambiarCargo("Jefe Administracion");
        em.descripcionEmpleado();
        
        System.out.println("Salario Anual: " + em.salarioAnual());
    }
    
}
