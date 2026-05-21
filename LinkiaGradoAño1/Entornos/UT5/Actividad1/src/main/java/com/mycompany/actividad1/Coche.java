/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.actividad1;

/**
 *
 * @author josee
 */
public class Coche extends Vehiculo
{    
    
    public Coche(int matricula, String modelo, String color, int ruedas) 
    {
        super(matricula, modelo, color, ruedas);
    }
    
    @Override
    public void descripcion()
    {
        System.out.println("Es un Coche.");
    }
}
