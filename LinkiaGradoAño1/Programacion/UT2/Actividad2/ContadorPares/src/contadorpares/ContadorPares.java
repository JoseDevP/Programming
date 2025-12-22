/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package contadorpares;
import java.util.Scanner;

/**
 *
 * @author josee
 * Crea un programa ContadorPares.java que:
o Pida un número entero positivo.
o Use un bucle for, while o do-while para contar e imprimir los números pares
desde 1 hasta ese número.
o Use continue para omitir los impares.
o Recuerda, para validar si un número es paar puede usar la condición:
* numero % 2 == 0
 */
public class ContadorPares {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        int num = LeerNumero();
        
        ImprimirNumerosPares(num);
        
    }
    
    public static int LeerNumero() 
    {
        Scanner sc = new Scanner(System.in);
        int num;

        while (true) 
        {
            System.out.println("Introduzca un número entero positivo:");

            try 
            {
                num = sc.nextInt();

                if (num >= 1) 
                {
                    return num; 
                } 
                else 
                {
                    System.out.println("El número debe ser un número entero positivo.");
                }
            } 
            catch (Exception e) 
            {
                System.out.println("Error. Introduzca un número entero positivo.");
                sc.nextLine(); 
            }
        }
    }
    
    public static void ImprimirNumerosPares(int num)
    {
        System.out.println("Numeros pares:\n");
        for(int i = 1; i < num; i++)
        {
            if (i % 2 != 0)
                continue;
            System.out.println(i);
        }
    }
    
}
