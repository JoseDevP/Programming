import java.util.Scanner;

public class MiPrimerPrograma {
    public static void main(String[] args) 
    {
        //Numericos
        int numero = 1;
        double altura = 1.65;

        //Texto

        char caracter ='a';
        String frase = "alguna cosa";

        //Logicas > Boolean
        boolean estaMatriculado = true;



        //Scanner
        Scanner sc = new Scanner(System.in);

        System.out.println("¿Cómo te llamas?");

        String nombre = sc.nextLine();

        System.out.println("¿Que edad tienes?");

        int edad = sc.nextInt(); 

        System.out.println("Hola,  yo me llamo " + nombre + " y tengo " +
        edad + " años");
        
        sc.close();
    }
}
