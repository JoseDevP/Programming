/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package miprimerprograma;
import java.util.Scanner; //imporatmos el scanner para usarlo después

/**
 *
 * @author josee
 */

/*
    Crea un programa llamado MiPrimerPrograma.java que:
    o Declare una clase pública.
    o Contenga el método main.
    o Declare al menos una variable y una constante.
    o Imprime un mensaje en consola.
    o Incluye comentarios explicativos
*/

public class MiPrimerPrograma 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) //Metodo principal
    {
        int numero; // Puede cambiaar el valor, y aun no se ha iniciado
        final int numeroConstante = 3; // No puede cambiar el valor
        
        Scanner sc = new Scanner(System.in); //Creamos una nueva instancia del scanner con new
        System.out.println("Escribe un numero"); //Preguntamos un numero
        numero = sc.nextInt(); //Obtenemos el numero que ha introducido el usuario
        
        System.out.println("Tu numero es: " + numero); //Y aqui lo mostramos

    }
       
    
}
