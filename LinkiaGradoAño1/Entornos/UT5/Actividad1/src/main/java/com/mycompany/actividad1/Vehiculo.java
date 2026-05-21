/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.actividad1;

/**
 *
 * @author josee
 */
public abstract class Vehiculo 
{
    private int matricula;
    private String modelo;
    private String color;
    private int ruedas;

    public Vehiculo(int matricula, String modelo, String color, int ruedas) 
    {
        this.matricula = matricula;
        this.modelo = modelo;
        this.color = color;
        this.ruedas = ruedas;
    }

    public int getMatricula() 
    {
        return matricula;
    }

    public void setMatricula(int matricula) 
    {
        this.matricula = matricula;
    }

    public String getModelo() 
    {
        return modelo;
    }

    public void setModelo(String modelo) 
    {
        this.modelo = modelo;
    }

    public String getColor() 
    {
        return color;
    }

    public void setColor(String color) 
    {
        this.color = color;
    }

    public int getRuedas() 
    {
        return ruedas;
    }

    public void setRuedas(int ruedas) 
    {
        this.ruedas = ruedas;
    }
    
    public void acelerar()
    {
        System.out.println("El vechiculo está acelerando.");
    }
    
    public abstract void descripcion();
    
}
