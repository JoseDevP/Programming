/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package clase;

/**
 *
 * @author josee
 */
public class Vehiculo {
    public int peso;
    private String matricula;
    public int potencia;
    public int velocidad = 0;
    
    
    //Constructores
    public Vehiculo(int peso, String matricula, int potencia){      
        this.peso = peso;
        this.matricula = matricula;
        this.potencia = potencia;

    }
    
    public Vehiculo(String matricula){
        this.matricula = matricula;
    }
     
    
    public void acelerar(int aceleracion)
    {
        velocidad += aceleracion;
    }    
    
   
}

