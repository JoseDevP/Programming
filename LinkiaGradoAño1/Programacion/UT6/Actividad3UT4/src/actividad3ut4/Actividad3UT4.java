/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad3ut4;

import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author josee
 */
public class Actividad3UT4 {

    /**
     * @param args the command line arguments
     * Actividad 3: Uso de HashMap para almacenar usuarios
     El alumno debe:
     • Implementar una versión con HashMap<String, String> usando el
     email como clave y nombre como valor.
     • Almacenar varios usuarios de prueba.
     • Pedir al usuario que introduzca un correo y que muestre su nombre, si no existe
     mostrar error.

     */
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        HashMap<String, String> emails = new HashMap<String, String>();
        emails.put("jose@gmail.com","Jose");
        emails.put("antonio@gmail.com","Antonio");
        emails.put("juan@gmail.com","Juan");
        
        String emailUsuario = pedirCorreo(sc);
        System.out.println(emails.containsKey(emailUsuario) 
                ? emails.get(emailUsuario) : "Error: no existe");
        
        sc.close();
        
    }
    
    /**
     * 
     * @param sc Scanner
     * @return devuelve lo que escribe el ussuario
     */
    public static String pedirCorreo(Scanner sc)
    {
        return sc.nextLine();
    }
}
