/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package claseut5;
import java.io.*;

/**
 *
 * @author josee
 */
public class LectorArchivo 
{
    
    public static void LeerArchivo()
    {
        try 
        {
            BufferedReader  br = new BufferedReader(new FileReader("datos.txt"));
            
            String linea;
            while ((linea = br.readLine()) != null) {
                System.out.println("Linea: " + linea);
            }
            //cerrar el archivo
            br.close();
        }
        catch(IOException e)
        {
            System.out.println("Error al leer el archivo." + e.getMessage());
            
        }
    }
    
    public static void EscribirArchivo()
    {
        try
        {
           BufferedWriter bw = new BufferedWriter( new FileWriter("datos.txt"));
           bw.write("Primera linea.");
           bw.newLine();
           bw.write("Segunda linea.");
           bw.close();
        }
        catch(IOException e)
        {
            System.out.println("Error al escribir en el archivo.");
        }
    }
    
    public static void CrearArchivo()
    {
        File archivo =new File("datos.txt");
        
         if (archivo.exists()) {
            System.out.println("El archivo existe");
        } else {
            System.out.println("¡El archivo no existe!");
            try 
            {
                if (archivo.createNewFile()) 
                {
                    System.out.println("Archivo creado correctamente.");
                } 
                else 
                {
                    System.out.println("No se pudo crear el archivo.");
                }
            } 
            catch (IOException e) 
            {
                System.out.println("Ocurrió un error al crear el archivo: " + e.getMessage());
            }
        }
    }
}
