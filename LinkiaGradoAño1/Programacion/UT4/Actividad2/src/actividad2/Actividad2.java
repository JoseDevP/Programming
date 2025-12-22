/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad2;

/**
 * Actividad 2: Diseña una clase CuentaBancaria con
propiedades privadas para el saldo y el titular. Implementa
métodos para depositar, retirar y consultar el saldo.
 * @author josee
 */
public class Actividad2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        CuentaBancaria cb = new CuentaBancaria(0,"Jose");
        System.out.println(cb.consultarSaldo());
        
        cb.depositarSaldo(100.53);
        System.out.println(cb.consultarSaldo());
        
        cb.retirarSaldo(50);
        System.out.println(cb.consultarSaldo());
    }
    
}
