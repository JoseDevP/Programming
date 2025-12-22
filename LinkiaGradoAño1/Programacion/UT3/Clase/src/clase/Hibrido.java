/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package clase;

/**
 *
 * @author josee
 */
public class Hibrido extends Coche {
    
    private int potenciaCarga = 0;
    
    public Hibrido(int peso, String matricula, int potencia, int numPuertas, int potenciaCarga) {
        super(peso, matricula, potencia, numPuertas);
        this.potenciaCarga = potenciaCarga;
    }
    
}
