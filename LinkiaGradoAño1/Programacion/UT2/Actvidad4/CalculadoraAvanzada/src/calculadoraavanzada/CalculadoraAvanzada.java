/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package calculadoraavanzada;

import java.util.Scanner;

/**
 *
 * @author josee
 * Crea un programa CalculadoraAvanzada.java que:
o Permita al usuario elegir una operación (suma, resta, multiplicación, división)
mediante switch.
o Solicite dos números y muestre el resultado.
o Use estructuras combinadas (if, switch, bucles).
o Incluya comentarios y simule una depuración con mensajes de
seguimiento (System.out.println()). Es decir, tras cada línea que modifique
alguna variable o sea relevante para el código, pon un System.out.println para
que muestre por cosola la acción realizada.
 */

public class CalculadoraAvanzada {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in); //creo instancia del scanner
        
        double n1 = LeerNumero(sc, "Primer número: "); //Llamo a la funcion Leernumero y le paso en que numero estamos
        double n2 = LeerNumero(sc, "Segundo número: ");
             
        int opcion = 0; //Aqui guardare que opcion quiere escoger de la calculadora
        
        while(opcion < 1 || opcion > 4) //bucle while para que si no ha elegido una operacion valida no pueda avanzar
        {
            System.out.print("Operación a realizar:\n 1-Sumar \n 2-Restar \n 3-Multiplicar \n 4-Dividir \n");
            opcion = sc.nextInt();
        }
        
        switch (opcion){ //segun la opcion llamara a una funcion u otra
            case 1 -> Sumar(n1, n2);
            case 2 -> Restar(n1, n2);
            case 3 -> Multiplicar(n1, n2);
            case 4 -> Dividir(n1, n2);
            
        }
    }
    
     public static double LeerNumero(Scanner sc, String frase)
    {
        double num = 0;
        boolean esValido = false; //booleano para que mientras sea falso no pueda avanzar

        while (!esValido) 
        {
            System.out.print(frase);
            
            String texto = sc.nextLine();
            
            try //con el try catch si el parse no funciona capturare el error y no le permitire avanzar
            {
                num = Double.parseDouble(texto); //parse para convertir a double
                esValido = true; // si no ha habido ningun error avanzara y saldra del bucle
            } 
            catch (NumberFormatException e)  //en caso de error capturamos la excepcion y no dejamos avanzar
            {
                System.out.println("Error: El número no es válido.\n");
            }
        }

        return num; //devolvemos el numero ya convertido a double
    }
    
    /**
    * Suma los numeros
    *
    * @param n1 Primer Numero
    * @param n2 Segundo Numero
    * 
    */    
    public static void Sumar(double n1, double n2)
    {
        double n3 = n1 + n2; //calculo
        ImprimirResultado(n3); //llamos a imprimirresultado pasandole lo que nos ha dadod
    }
    
    /**
    * Restar los numeros
    *
    * @param n1 Primer Numero
    * @param n2 Segundo Numero
    * 
    */  
    public static void Restar(double n1, double n2) 
    {
        double n3 = n1 - n2; 
        ImprimirResultado(n3);       
    }
    
    /**
    * Multiplicar los numeros
    *
    * @param n1 Primer Numero
    * @param n2 Segundo Numero
    * 
    */  
    public static void Multiplicar(double n1, double n2)
    {
        double n3 = n1 * n2;
        ImprimirResultado(n3);
    }
    
    /**
    * Dividir los numeros
    *
    * @param n1 Primer Numero
    * @param n2 Segundo Numero
    * 
    */  
    public static void Dividir(double n1, double n2)
    {        
        double n3 = n1 / n2; 
        ImprimirResultado(n3);
    }
    
    /**
    * Imprime el resultado y realiza operaciones logicas y relacionales
    *
    * @param n3 Resultado de la operación
    * 
    */ 
    public static void ImprimirResultado(double n3)
    {
        String text3 = String.valueOf(n3); //con valueOf convertimos el double a texto
        
        System.out.println("El resultado de la operación es: "+ text3 + "\n" + //imprimimos resultado
                "Por tanto es: " + ((n3 > 0) ? "positivo, " : "negativo, ") + //Operacion logica
                ((n3 > 100) ? "mayor que 100, " : "menor o igual que 100, ") + //Operacion logica
                ((n3 > 0 && n3 <= 200) ? "y está entre 0 y 200, " : "y no está entre 0 y 200")); //Operacion relacional

    }
    
}
