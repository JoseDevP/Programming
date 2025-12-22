/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package claseut6;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

/**
 *
 * @author josee
 */
public class ClaseUT6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        /*Arrays -> estaticos*/
        int[]numerosEstatico = new int[5];
        int[] numerosEstatico2 = {10,9,4,3,8};
        
        //System.out.println(numerosEstatico2[3]);
        
        
        /*ArrayList */
        //->listas dinamicas pero solo trabaja con objetos
        //Wraper-> representacion de valor primtivo en modo objeto
        //int ->Integer
        //double -> Double
        //char -> Character
        ArrayList<Integer> numerosDinamico = new ArrayList<Integer>();
        
        numerosDinamico.add(10);
        numerosDinamico.add(9);
        numerosDinamico.add(4);
        numerosDinamico.add(3);
        numerosDinamico.add(8);
        
        //System.out.println(numerosDinamico.get(3));
        
        
        
        
        //Metodos -> get, clear, contains, foreach, remove,removeIf
        
        
        
        //Leer
        //numerosDinamico.forEach( (numero) -> System.out.println(numero) );
        
        //for(int i =0; i<numerosDinamico.size();i++)
        //    System.out.println(numerosDinamico.get(i));
        
        //for(int numero : numerosDinamico)
        //    System.out.println(numero);
        
        
        
        
        /*//Diccionario*/
        //-> HashMap -> indice con valor
        //metodos, get, put, clone, contains, foeach,get
        HashMap<String,Integer> edades = new HashMap<String,Integer>();
        edades.put("2342345",10);
        edades.put("234432534",5);
        edades.put("23423322345",3);
        edades.put("122334",2);
        
        /*System.out.println(edades.get("2342345"));
        
        for(String clave : edades.keySet())
        {
            System.out.println(clave + " " + edades.get(clave));
        }*/
        
        
        
        /*Iteradores*/
        //Recorrer los elemtnos, muy util al eliminar (ya que se modifica el tamaño)
        //metodos -> next, hasNext, remove 
        ArrayList<String> nombres = new ArrayList<String>();
        nombres.add("Jose");
        nombres.add("Juana");
        nombres.add("Lucía");
        Iterator<String> it = nombres.iterator();
        /*while(it.hasNext())
        {
           String nombre = it.next();
           System.out.println(nombre);
        }*/
        
        /*for(String nombre : nombres)
            System.out.println(nombre);*/
        
        
        
        
        /*Metodos Genericos -> T /*  
        */
        
        
        /*Expresiones regulares Regex -> patrones para realizar busquedas /*
        //Mirar tabla 

    }
    
}
