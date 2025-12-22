/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.claseutorelacionaldb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Logger;
import java.util.logging.Level;

/**
 *
 * @author josee
 */
public class BBDDManager 
{
    private static String datosConexion ="jdbc:mysql://localhost:3306/";
    private static String baseDatos = "javaDAM";
    private static String usuario = "root";
    private static String password = "";
    private Connection con;
    
    public BBDDManager()
    {
       try
        {
            con = DriverManager.getConnection(datosConexion, usuario, password);
            try{
                crearDB();
                crearTablaSerie();
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }

        }
        catch(Exception e)
        {
            e.printStackTrace();

        } 
    }
    
    //crearDb
    private void crearDB() throws Exception
    {
        String query= "create database if not exists " + baseDatos + ";";
        Statement stmt = null;
        
        try{
            stmt = con.createStatement();
            stmt.executeUpdate(query);
            con = DriverManager.getConnection(
            datosConexion + baseDatos,
                    usuario,
                    password);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
        finally {
            stmt.close();
        }
    }
    
    //crear tabla
    private void crearTablaSerie() throws Exception
    {
        String query = "CREATE TABLE IF NOT EXISTS Serie ("
        + "codigo INT PRIMARY KEY AUTO_INCREMENT, "
        + "nombre VARCHAR(100), "
        + "genero VARCHAR(100), "
        + "anyo INT"
        + ");";
        
        Statement stmt =null;
        try{
            stmt = con.createStatement();
            stmt.executeUpdate(query);
        }
        catch(SQLException e)
        {
           e.printStackTrace();
        }
        finally {
            stmt.close();
        }
    }
    
    //insert, update, delete, select...
    private void insertarSerie(String nombre, String genero, String anyo) throws Exception
    {
        String query = "insert into serie(nombre,genero,anyo) "
                + "values('" + nombre + "', '" + genero + "', " + anyo + ")";
        
        // '"  indica que es string
        
        Statement stmt =null;
        try{
            stmt = con.createStatement();
            stmt.executeUpdate(query);
        }
        catch(SQLException e)
        {
           e.printStackTrace();
        }
        finally {
            stmt.close();
        }
    }
    
    //....
    
    //ResultSet -> para insert update y delete(tambien sirve)
    //PreparedStatement -> mas de una cosa a la vez
    
    //Transacciones 
}
    
