/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.empresadb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


/**
 *
 * @author josee
 */
public class BBDDManager 
{
    private static String datosConexion="jdbc:mysql://localhost:3306/";
    private static String baseDatos  = "empresaDB";
    private static String usuario = "root";
    private static String password = "Jose0831";
    private Connection con;
    
    public BBDDManager()
    {
        try
        {
            con = DriverManager.getConnection(datosConexion,usuario,password);
            System.out.println("Conectado al servidor MySql");
            
            try
            {
                crearDb();
                
                con.close();
                
                con = DriverManager.getConnection(
                    datosConexion + baseDatos, usuario, password
                );
                
                System.out.println("Conectado a la base de datos " + baseDatos + " correctamente");
                
                crearTablaClientes();
            }
            catch(SQLException e)
            {
                System.out.println("Error al conectarse a " + baseDatos + ": " + e.getMessage());
            }
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
    }
    
    private void crearDb() 
    {
        String query = "create database if not exists " + baseDatos + ";";
        Statement stmt = null;
        
        try
        {
            stmt = con.createStatement();
            stmt.executeUpdate(query);
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            if (stmt != null) 
            {
                try
                {
                    stmt.close();
                }
                catch(SQLException e)
                {
                    System.out.println(e.getMessage());
                }
                
            }
        }
    }
    
    private void crearTablaClientes() 
    {
        String query = "CREATE TABLE IF NOT EXISTS Clientes ("
                + "id_cliente INT AUTO_INCREMENT PRIMARY KEY, "
                + "nombre VARCHAR(100), "
                + "ciudad VARCHAR(50)"
                + ");";
        
        Statement stmt = null;
        
        try
        {
            stmt = con.createStatement();
            stmt.executeUpdate(query);
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            if (stmt != null) 
            {
                try
                {
                    stmt.close();
                }
                catch(SQLException e)
                {
                    System.out.println(e.getMessage());
                }
                
            }
        }
    }

    public void insertarCliente(String nombre, String ciudad)
    {
        String query = "INSERT INTO Clientes (nombre,ciudad) VALUES (?, ?)";
        
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setString(1, nombre);
            pstmt.setString(2, ciudad);
            pstmt.executeUpdate();
            
            System.out.println("Cliente insertado");
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
    }
    
    public void mostrarClientes()
    {
        String query = "SELECT * FROM Clientes";
        
        try(PreparedStatement pstmt = con.prepareStatement(query);
                ResultSet rs = pstmt.executeQuery())
        {
            System.out.println("Clientes:");
            while(rs.next())
            {
                int idCliente = rs.getInt("id_cliente");
                String nombre = rs.getString("nombre");
                String ciudad = rs.getString("ciudad");
                
                System.out.println("ID: " + idCliente + ", Nombre: " + nombre
                + ", Ciudad: " + ciudad);
            }
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
    }
    
    public void actualizarCliente(int idCliente, String nombre, String ciudad)
    {
        String query = "UPDATE Clientes SET nombre = ? "
                + ",ciudad = ?"
                + " WHERE id_cliente = ?";
        
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setString(1, nombre);
            pstmt.setString(2, ciudad);
            pstmt.setInt(3, idCliente);
            pstmt.executeUpdate();
            
            System.out.println("Cliente modificado");
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
    }
    
    public void eliminarCliente(int idCliente)
    {
        String query = "DELETE FROM Clientes WHERE id_cliente = ?";
        
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setInt(1, idCliente);
            pstmt.executeUpdate();
            
            System.out.println("Cliente eliminado");
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
    }
    
    public void desconectar() 
    {
    if (con != null) 
    {
        try 
        {
            con.close();
            System.out.println("Desconectado correctamente");
            
        } catch (SQLException e) 
        {
            System.out.println(e.getMessage());
        }
    }
}
}
