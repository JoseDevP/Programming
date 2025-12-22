/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad1;

/**
 * Actividad 1: Crea una clase (@code Libro} que represente un libro
    con propiedades como título, autor y año de publicación.
    Incluye métodos para mostrar la información del libro y
    actualizar el año.
 * @author josee
 */
public class Actividad1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Libro libr = new Libro("Las Aventuras de Jose", "Jose Cazorla", 2005);
        libr.mostrarInformacion();
    }
    
}
