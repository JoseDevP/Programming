/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad2;

/**
 *Esta clase genera una instanciaa de {@code CuentaBancaria}.
 * Tiene atributos como saldo y titular.
 * Tiene constructos, getters y setters, y metodos para depositar, retirar 
 * y consultar el saldo.
 * @author josee
 */
public class CuentaBancaria 
{
    private double saldo;
    private String titular;
    
    /**
     * 
     * @param saldo Saldo de la cuenta bancaria 
     * @param titular Titular de la cuenta bancaria
     */
    public CuentaBancaria(double saldo, String titular) 
    {
        this.saldo = saldo;
        this.titular = titular;
    }

    /**
     * 
     * @return devuelve el saldo de la cuenta bancaria 
     */
    public double getSaldo() 
    {
        return saldo;
    }

    /**
     * 
     * @return devuelve el titular de la cuenta bancaria
     */
    public String getTitular() 
    {
        return titular;
    }

    /**
     * 
     * @param saldo Saldo de la cuenta bancaria 
     */
    public void setSaldo(double saldo) 
    {
        this.saldo = saldo;
    }
    
    /**
     * 
     * @param titular Titular de la cuenta bancaria
     */
    public void setTitular(String titular) 
    {
        this.titular = titular;
    }
    
    /**
     * 
     * @param saldo Saldo a depositar en la cuenta bancaria.
     */
    public void depositarSaldo(double saldo)
    {
        this.saldo += saldo;
    }
    
    /**
     * 
     * @param saldo Saldo a retirar en la cuenta bancaria.
     */
    public void retirarSaldo(double saldo)
    {
        this.saldo -= saldo;
        if(this.saldo < 0)
            this.saldo = 0;
    }
    
    /**
     * 
     * @return devuelve el saldo de la cuenta bancaria
     */
    public double consultarSaldo()
    {
        return saldo;
    }
}
