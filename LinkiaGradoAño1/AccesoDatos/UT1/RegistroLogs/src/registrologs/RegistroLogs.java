/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package registrologs;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

import java.io.IOException;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import java.util.Scanner;

/**
 *
 * @author josee
 */
public class RegistroLogs 
{
    /**
     * @param logFile nombre del archivo donde guardaremos los logs
     * @param format formato en que escribiré la fecha en el documento
     */
    private static final String logFile = "logs.txt";
    private static final DateTimeFormatter format = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
    
    public static void main(String[] args) 
    {   
        //importo scanner para poder escribir
        Scanner sc = new Scanner(System.in);
        
        //ruta del archivo
        System.out.println("Introduce la ruta del archivo");
        String route = sc.nextLine();
        
        //accion que queremos realizar
        System.out.println("Acción:   leer / escribir / borrar   ?");
        String action = sc.nextLine().toLowerCase();
        
        //en base que accion decida voy a cada función
        switch(action) 
        {
            case "leer" -> leerArchivo(route);
            case "escribir" -> escribirArchivo(route,sc);
            case "borrar" -> borrarArchivo(route);
        }
        
        sc.close();
    }

    /**
     * 
     * @param route ruta del archivo
     */
    private static void leerArchivo(String route) 
    {
        //Abrimos en modo lectura
        try (BufferedReader br = new BufferedReader(new FileReader(route)))
        {
             //Mostramos cada linea hasta que se acabe el archivo
            String linea;
            while ((linea = br.readLine()) != null) 
            {
                System.out.println(linea);
            }
            //si ha ido bien registramos el log como exito de tipo lectura
            registrarLog("LECTURA", "EXITO", "-");
        }
        catch (IOException e)
        {
            //si ha ido mal registramos el log como fallo de tipo lectura
            registrarLog("LECTURA", "FALLO", e.getMessage());
        }
    }

    private static void escribirArchivo(String route, Scanner sc) 
    {
        //Abrimos en modo escritura
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(route,true)))
        {
            //Escribimos en el archivo
            System.out.println("Escribe lo que quieras añadir:");
            String frase = sc.nextLine();
            bw.write(frase);
            
            //si ha ido bien registramos el log como exito de tipo escritura
            registrarLog("ESCRITURA", "EXITO", "-");
        }
        catch (IOException e)
        {
            //si ha ido mal registramos el log como fallo de tipo escritura
            registrarLog("ESCRITURA", "FALLO", e.getMessage());
        }
    }

    private static void borrarArchivo(String route) 
    {
        //Archivo
        File archivo = new File(route);
        
        if(archivo.delete())
        {
            //si ha ido bien registramos el log como exito de tipo borrado
            registrarLog("BORRADO", "EXITO", "-");
        }
        else 
        {
            //si ha ido mal registramos el log como fallo de tipo borrado
            registrarLog("BORRADO", "FALLIDO", "Error al intentar borrar el archivo");
        }
    }
    
    /**
     * 
     * @param tipo tipo de log
     * @param resultado resultado de log
     * @param mensaje mensaje de log
     */
    private static void registrarLog(String tipo, String resultado, String mensaje) 
    {
        //Abrimos en modo escritura el log.txt
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(logFile, true))) 
        {
            //Ponemos la fecha actual en el formato que queremos
            String fechaHora = LocalDateTime.now().format(format);
            //Escribimos el log
            bw.write(fechaHora + "," + tipo + "," + resultado + "," + mensaje);
            //Cambiamos a la siguiente linea
            bw.newLine();

        } catch (IOException e) {
            System.out.println("Error al escribir en el log.");
        }
    }
    
}
