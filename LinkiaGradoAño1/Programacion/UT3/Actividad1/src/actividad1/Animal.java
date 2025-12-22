/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad1;

/**
 * Esta clase {@code Animal} crea un Animal con su altura y su peso.
 * Proporciona metodos para acceder y poder modificarlos y tambien 
 * mostrar su sonido.
 * 
 * De esta clase extienden las clases {@code Gato} y {@code Perro] 
 * en las que se redefine el metodo hacerSonido()
 * 
 * hacerSonido()
 */
public class Animal 
{
    
    private int altura;    
    private int peso;
    
    /**
     * *Crea objeto {@code Animal} con su altura y su peso
     * 
     * @param altura es la altura del animal
     * @param peso es el peso del animal
     */
    public Animal(int altura, int peso) 
    {
        this.altura = altura;
        this.peso = peso;
    }
    
    /**
     * @return altura en cm
     */
    public int getAltura() {
        return altura;
    }

    /**
     * @return peso en kilos
     */
    public int getPeso() {
        return peso;
    }
    
    /*
    * @param altura es la altura del animal
    */
    public void setAltura(int altura) {
        this.altura = altura;
    }
    
    /**
    * @param peso es el peso del animal
    */
    public void setPeso(int peso) {
        this.peso = peso;
    }
    
    
    /**
    * En este método se emite el sonido del aanimal usando println(),
    * Este metodo se sobreescribe en las clases hija
    */
    public void hacerSonido()
    {
        System.out.println("Sonido de Animal");
    }
}
