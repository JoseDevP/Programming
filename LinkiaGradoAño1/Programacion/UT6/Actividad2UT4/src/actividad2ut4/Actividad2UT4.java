/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad2ut4;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author josee
 */
public class Actividad2UT4 {

    /**
     * @param args the command line arguments
     * Actividad 2: Validar mediante expresiones regulares.
     * El alumno debe:
     • Solicitar varios correos electrónicos al usuario.
     • Almacenarlos en un ArrayList.
     • Recorrer y validar cada email con una expresión regular.
     • Mostrar por consola o por una interfaz gráfica el resultado de cada
     validación
     */
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        ArrayList<String> correos = new ArrayList<String>();
        correos.add(pedirCorreo(sc));
        correos.add(pedirCorreo(sc));
        correos.add(pedirCorreo(sc));
        
        for (String correo : correos) 
        {
            System.out.println("El email " + correo + " es " +
            (validarEmail(correo) ? "válido" : "inválido"));
        }
        
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
    
    /**
     * 
     * @param email email del usuario a validar
     * @return devuelve true si es valido y false si es invalido
     */
    public static boolean validarEmail(String email)
    {
        String patronEmail = "^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$";
        Pattern pattern = Pattern.compile(patronEmail);
        Matcher matcher = pattern.matcher(email);
        return matcher.matches();
    }
    
}
