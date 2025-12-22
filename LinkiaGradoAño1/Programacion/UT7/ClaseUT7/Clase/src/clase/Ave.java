/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package clase;

/**
 *
 * @author josee
 */
public class Ave extends Animal implements Accion
{
    
    public Ave(String nombre, int edad) {
        super(nombre, edad);
    }

    @Override
    public void accion() {
        System.out.println("Mi animal de nombre " + getNombre() + " está volando");
    }
    
}
