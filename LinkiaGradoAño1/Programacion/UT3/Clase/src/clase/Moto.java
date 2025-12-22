/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package clase;

/**
 *
 * @author josee
 */
public class Moto extends Vehiculo
{
    private double rigidezCaballete;

    public Moto(int peso, String matricula, int potencia, double rigidezCaballete) 
    {
        super(peso, matricula, potencia);
        this.rigidezCaballete = rigidezCaballete;
    }


    public double getRigidezCaballete() 
    {
        return rigidezCaballete;
    }

    public void setRigidezCaballete(double rigidezCaballete) 
    {
        this.rigidezCaballete = rigidezCaballete;
    }
    
}
