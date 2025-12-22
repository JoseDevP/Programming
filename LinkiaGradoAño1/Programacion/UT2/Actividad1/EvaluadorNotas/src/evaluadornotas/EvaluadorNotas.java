/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package evaluadornotas;
import java.util.Scanner;

/**
 *
 * @author josee
 * Crea un programa EvaluadorNotas.java que:
o Solicite una nota numérica del 0 al 10.
o Use estructuras if, if-else o switch para mostrar el resultado textual:
“Suspenso”, “Aprobado”, “Notable”, “Sobresaliente”.
o Incluya validación de entrada.

 */
public class EvaluadorNotas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        int num = LeerNumero();
        
        if(num < 5)
            System.out.println("Suspenso");
        else if(num == 5)
            System.out.println("Aprovado");
        else if(num > 5)
            if(num <= 8)
                System.out.println("Notable");
            else
                System.out.println("Sobresaliente");       
    }
    
    public static int LeerNumero() 
    {
        Scanner sc = new Scanner(System.in);
        int num;

        while (true) 
        {
            System.out.println("Introduzca una nota numérica del 0 al 10:");

            try 
            {
                num = sc.nextInt();

                if (num >= 0 && num <= 10) 
                {
                    return num; 
                } 
                else 
                {
                    System.out.println("El número debe estar entre 0 y 10.");
                }
            } 
            catch (Exception e) {
                System.out.println("Error. Introduzca un número válido del 0 al 10.");
                sc.nextLine(); 
            }
    }
}

    
}
