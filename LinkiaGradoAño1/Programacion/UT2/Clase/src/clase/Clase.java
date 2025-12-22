/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package clase;
import java.util.Scanner;

/**
 *
 * @author josee
 */
public class Clase {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        //Array 1
        int[] edadAlumnos = {65,21,23,25,30};

        for(int i = 0; i < 5; i++)
        {
            System.out.println(edadAlumnos[i]);        
        }
        
        System.out.println("\n\n");
        
        
        
        //Array 2
        
        Scanner sc = new Scanner(System.in);
        
        int[] valores = new int[4];
        
        for(int i=0; i < valores.length; i++)
        {
            System.out.println("Intorduce el valor de la posicion " + i);       
            valores[i] = sc.nextInt(); 
        }
 
        
        for(int i = 0; i < valores.length; i++)
        {
            System.out.println(valores[i]);        
        }
        
        
        
        //if
        int edad=20;
        if (edad >= 15)
        {
            System.out.println("No necesita autorización");
        }
        else if (edad >= 16)
        {
            System.out.println("No necesita autorización, pero hablar con padres");
        }
        else 
        {
            System.out.println("Necesita autorización");
        }
        
        //switch
        
        int diasemana =2;
        
        switch(diasemana)
        {
            case 1:
                System.out.println("El dia " + diasemana + " es lunes");
                break;
            case 2:
                System.out.println("El dia " + diasemana + " es martes");
                break;
            case 3:
                System.out.println("El dia " + diasemana + " es miercoles");
                break;
            case 4:
                System.out.println("El dia " + diasemana + " es jueves");
                break;
            case 5:
                System.out.println("El dia " + diasemana + " es viernes");
                break;
        }
        
        //while
        int numero = 5;
        
        while(numero <= 10 )
        {
            System.out.println(numero);
            numero++;
        }
        
        //for
        
        numero = 0;
        
       for(int i = 0; i <= 10; i++)
       {
           System.out.println(numero);
           numero++;
       }
       
       
       //trycatch
       
      try
      {
          int tnumero = 1/0;
      }
      catch(Exception e)
      {
         System.out.println("Excepción " + e);       
      }
       
    }
    
}
