/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package calculadorabasica;
import java.util.Scanner; //importo el scanner

/**
 *
 * @author josee
 */
public class CalculadoraBasica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in); //creo instancia del scanner
        
        double num1 = 0;        
        double num2 = 0;
        
        System.out.println("Primer número: ");
        String texto1 = sc.nextLine();
        num1 = Double.parseDouble(texto1); //con parse convierto el texto a numero
        
        System.out.println("Segundo número: ");
        String texto2 = sc.nextLine();
        num2 = Double.parseDouble(texto2);
        
        double num3 = 0;
        num3 = num1 + num2; //calculo
        ImprimirResultado(num3 , "Suma");  //realizo las operaaciones y las paso a la funcion ImprimirResutltado
        
        num3 = num1 - num2; //calculo
        ImprimirResultado(num3 , "Resta");
        
        num3 = num1 * num2; //calculo
        ImprimirResultado(num3 , "Multiplicacion");
        
        num3 = num1 / num2; //calculo
        ImprimirResultado(num3 , "División");
        
    }
    
    public static void ImprimirResultado(double n3 , String operacion)
    {
        String text3 = String.valueOf(n3); //con valueOf convertimos el double a texto
        
        System.out.println("El resultado de la "+ operacion + " es: "+ text3 + "\n" + //imprimimos resultado
                "Por tanto es: " + ((n3 > 0) ? "positivo, " : "negativo, ") + //Operacion logica
                ((n3 > 100) ? "mayor que 100, " : "menor o igual que 100, ") + //Operacion logica
                ((n3 > 0 && n3 <= 200) ? "y está entre 0 y 200, " : "y no está entre 0 y 200")); //Operacion relacional

    }
    
}
