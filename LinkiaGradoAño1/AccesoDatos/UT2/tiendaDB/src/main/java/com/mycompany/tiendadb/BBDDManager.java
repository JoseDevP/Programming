/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tiendadb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author josee
 */
public class BBDDManager 
{
    private static String datosConexion="jdbc:mysql://localhost:3306/";
    private static String baseDatos  = "tiendaDB";
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
                
                crearTablaProductos();
                crearTablaVentas();
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
    
    private void crearTablaProductos() 
    {
        String query = "CREATE TABLE IF NOT EXISTS Productos ("
                + "id_producto INT AUTO_INCREMENT PRIMARY KEY, "
                + "nombre VARCHAR(100), "
                + "stock INT"
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
    
    private void crearTablaVentas() 
    {
        String query = "CREATE TABLE IF NOT EXISTS Ventas ("
                + "id_venta INT AUTO_INCREMENT PRIMARY KEY, "
                + "id_producto INT, "
                + "unidades INT, "
                + "fecha DATE, "
                + "FOREIGN KEY(id_producto) REFERENCES Productos(id_producto)"
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
    
    public void insertarProducto(String nombre, int stock)
    {
        String query = "INSERT INTO Productos (nombre,stock) VALUES (?, ?)";
        
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setString(1, nombre);
            pstmt.setInt(2, stock);
            pstmt.executeUpdate();
            
            System.out.println("Producto insertado");
        }
        catch(SQLException e)
        {
            System.out.println(e.getMessage());
        }
    }
    
    public void registrarVenta(int idProducto, int unidades)
    {
        try
        {
            //Desactivo auto commit
            con.setAutoCommit(false);
            
            //Insertar venta
            String sqlVenta = "INSERT INTO Ventas (id_producto, unidades, fecha) "
                    + "VALUES (?, ?, CURDATE())";
            
            try(PreparedStatement psVenta = con.prepareStatement(sqlVenta))
            {
                psVenta.setInt(1, idProducto);
                psVenta.setInt(2, unidades);
                psVenta.executeUpdate();
            }
            
            
            //Actualizar Productos
            String sqlStock = "UPDATE Productos SET stock = stock - ? "
                    + "WHERE id_producto = ? AND stock >= ?";
            
            try(PreparedStatement psStock = con.prepareStatement(sqlStock))
            {
                psStock.setInt(1, unidades);
                psStock.setInt(2, idProducto);
                psStock.setInt(3, unidades);
                int actualizados = psStock.executeUpdate();
                
                if(actualizados == 0)
                {
                    throw new SQLException("Insuficiente Stock o producto no existente");
                }
            }
            
            //Si no ha habido errores -> hago el commit
            con.commit();
            System.out.println("Transacción realizada: "
                    + "Producto: " + idProducto
                    + " Unidades: "  + unidades);
            
            
        }
        catch (SQLException e)
        {
            try 
            {
                con.rollback();
                System.out.println("Rollback: " + e.getMessage());
                
            } 
            catch (SQLException ex) 
            {
                System.out.println("Error en el rollback: " + ex.getMessage());
            }
            
        }
        finally 
        {
            try 
            {
                con.setAutoCommit(true); // Restaurar auto-commit
            } 
            catch (SQLException exc) 
            {
                System.out.println(exc.getMessage());
            }
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
