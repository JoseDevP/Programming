/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package gestortemperaturas;
import java.util.Scanner;

/**
 *
 * @author josee
 * Crea un programa GestorTemperaturas.java que:
o Declare un array de 7 posiciones para temperaturas semanales.
o Solicite al usuario que introduzca los valores mediante Scanner.
o Calcule la media.
o Use try-catch para controlar errores de entrada (por ejemplo, si se introduce
texto en lugar de números).
 */
public class GestorTemperaturas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int[] temperaturasSemanales = new int[7];
        for(int i = 0; i < temperaturasSemanales.length; i++)
        {
            temperaturasSemanales[i] = LeerNumero(sc);
        }
        
        double media = Media(temperaturasSemanales);
        System.out.println("La media es :" + media);
    }
    
    public static int LeerNumero(Scanner sc) 
    {
        int num;

        while (true) 
        {
            System.out.println("Introduzca un número:");

            try 
            {
                num = sc.nextInt();
                return num; 
            } 
            catch (Exception e) 
            {
                System.out.println("Error. Introduzca un número.");
                sc.nextLine(); 
            }
        }
    }
    
    public static double Media(int[] temperaturasSemanales)
    {
        int suma = 0;
    
        for (int i = 0; i < temperaturasSemanales.length; i++) 
        {
            suma += temperaturasSemanales[i];
        }
    
        return (double) suma / temperaturasSemanales.length;
    }
}
