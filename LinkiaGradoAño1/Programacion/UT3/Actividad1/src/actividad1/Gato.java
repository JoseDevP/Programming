/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad1;

/**
 * Esta clase deriva de la clase {@code Animal}, de la cual hereda sus atributos 
 * y metodos.
 * Sobreescribe el metodo hacerSonido().
 * 
 * @author josee
 */
public class Gato extends Animal
{
    /**
     * *Crea objeto {@code Gato} con su altura y su peso
     * 
     * @param altura es la altura del Gato
     * @param peso es el peso del Gato
     */
    public Gato(int altura, int peso) 
    {
        super(altura, peso);
    }
    
    /*
    *Se sobreescribe el metodo heredaado de la clase base
    */
    @Override
    public void hacerSonido()
    {
        System.out.println("Miau");
    }
}
