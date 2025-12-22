/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package claseut5;
import java.io.*;
/**
 *
 * @author josee
 */
public class ClaseUT5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        PrimeraPagina pp = new PrimeraPagina();
        pp.setVisible(true);
    }
    
    //Buffered reader 
    public static int pedirEntero() throws IOException
    {
        BufferedReader  br= new BufferedReader(new InputStreamReader(System.in));
        
        int numero = -1;
        boolean valido = false;
        
        while (!valido) {
            try{
                System.out.println("Introduce un número entero positivo: ");
                numero = Integer.parseInt(br.readLine());
                
                if(numero >=0){
                    valido =true;
                }
                else {
                    System.out.println("Debe ser un número positivo.");
                }
            }
            catch(NumberFormatException e)
            {
                System.out.println("Entrada no válida. Intenta de nuevo.");
            }
        }
        
        return numero;
    }
    
    //printf
    public static void Printf()
    {
        double pi=3.14159265;
        System.out.printf("Valor de PI: %.2f%n", pi);
    }
    
}
