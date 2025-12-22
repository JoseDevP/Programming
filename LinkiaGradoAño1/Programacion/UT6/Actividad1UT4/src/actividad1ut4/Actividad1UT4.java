/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad1ut4;

import java.util.ArrayList;

/**
 *
 * @author josee
 * Actividad 1: Crear una clase Usuario y almacenar objetos en
un ArrayList
El alumno debe:
• Crear una clase Usuario con nombre, email y edad.
• Crear un ArrayList<Usuario> y añadir varios objetos.
• Mostrar los datos por consola usando un bucle.
 */
public class Actividad1UT4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        ArrayList<Usuario> usuarios = new ArrayList<Usuario>();
        usuarios.add(new Usuario("Jose","jose@gmail.com",26));
        usuarios.add(new Usuario("Antonio","antonio@gmail.com",98));
        usuarios.add(new Usuario("Luna","luna@gmail.com",34));
        
        for (Usuario user : usuarios)
            System.out.println("Nombre: " + user.getNombre() +
            "  Email: " + user.getEmail() +
            "  Edad: " + user.getEdad() + "\n");
    }
    
}
