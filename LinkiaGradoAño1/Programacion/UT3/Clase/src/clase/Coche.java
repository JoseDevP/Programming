/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package clase;

/**
 *
 * @author josee
 */
public class Coche extends Vehiculo {
    public int numPuertas;

    public Coche(int peso, String matricula, int potencia, int numPuertas) {
        super(peso, matricula, potencia);
        this.numPuertas =numPuertas;
    }

    public int getNumPuertas() {
        return numPuertas;
    }

    public void setNumPuertas(int numPuertas) {
        this.numPuertas = numPuertas;
    }
    
}
