/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.ColegioDb;

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
    private static String baseDatos = "Colegio";
    private static String usuario = "root";
    private static String password = "Jose0831";
    private Connection con;
    
    
    public BBDDManager()
    {
        try
        {
            con = DriverManager.getConnection(datosConexion, usuario, password);
            System.out.println("Conectado al servidor MySQL");
            
            try
            {
                crearDb();
                
                con.close();
                con = DriverManager.getConnection(
                    datosConexion + baseDatos, usuario, password
                );
                System.out.println("Conectado a la base de datos " + baseDatos + " correctamente");
                
                crearTablaCurso();
                crearTablaAlumno();
                         
            }
            catch(Exception e)
            {
                System.out.println("Ha habido un error al conectarse a "
                + baseDatos + "\n" + e.getMessage());
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    
    /**
     * Crea la base de datos si no existe
     * @throws Exception 
     */
    private void crearDb() throws Exception
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
            e.printStackTrace();
        }
        finally
        {
            if (stmt != null) 
            {
                stmt.close();
            }
        }
    }

    /**
     * Crea la tabla alumno si no existe
     * @throws Exception 
     */
    private void crearTablaAlumno() throws Exception
    {
        String query = "CREATE TABLE IF NOT EXISTS Alumno ("
                + "idAlumno INT AUTO_INCREMENT PRIMARY KEY, "
                + "idCurso INT, "
                + "nombre VARCHAR(100) NOT NULL, "
                + "genero VARCHAR(100) NOT NULL, "
                + "edad INT NOT NULL, "
                + "CONSTRAINT fk_alumno_curso FOREIGN KEY (idCurso) REFERENCES "
                + "Curso(idCurso)"
                + ");";
        
        Statement stmt = null;
        
        try
        {
            stmt = con.createStatement();
            stmt.executeUpdate(query);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
        finally
        {
            if(stmt != null)
            {
                stmt.close();
            }
        }
    }
    
    /**
     * Crea la tabla curso si no existe
     * @throws Exception 
     */
    private void crearTablaCurso() throws Exception
    {
        String query = "CREATE TABLE IF NOT EXISTS Curso ("
                + "idCurso INT AUTO_INCREMENT PRIMARY KEY, "
                + "nombre VARCHAR(100) NOT NULL"
                + ");";
        Statement stmt = null;
        
        try
        {
            stmt = con.createStatement();
            stmt.executeUpdate(query);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
        finally
        {
            if(stmt != null)
            {
                stmt.close();
            }
        }
    }
    
    /**
     * 
     * @param nombre nombre del curso a insertar
     */
    public void insertarCurso(String nombre) 
    {
        String query = "INSERT INTO Curso (nombre) VALUES (?)";
                
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setString(1, nombre);
            pstmt.executeUpdate();
            
            System.out.println("Curso insertado");
            
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    /**
     * 
     * @param idCurso id del curso a modificar
     * @param nombre nuevo nombre
     */
    public void modificarCurso(int idCurso, String nombre)
    {
        String query = "UPDATE Curso SET nombre = ? WHERE idCurso = ?";
                
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setString(1, nombre);
            pstmt.setInt(2, idCurso);
            pstmt.executeUpdate();
            
            System.out.println("Curso modificado");
            
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    /**
     * 
     * @param idCurso id del curso a eliminar
     */
    public void eliminarCurso(int idCurso)
    {
        String query = "DELETE FROM Curso WHERE idCurso = ?";
                
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setInt(1, idCurso);
            pstmt.executeUpdate();
            
            System.out.println("Curso eliminado");
            
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    /**
     * Muestra todos los cursos
     */
    public void mostrarCursos()
    {
        String query = "SELECT * FROM Curso";
                
        try(PreparedStatement pstmt = con.prepareStatement(query);
                ResultSet rs = pstmt.executeQuery())
        {
            System.out.println("Cursos:");
            while(rs.next())
            {
                int idCurso = rs.getInt("idCurso");
                String nombre = rs.getString("nombre");
                
                System.out.println("ID: " + idCurso + ", Nombre: " + nombre);
            }
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    
    /**
     * 
     * @param idCurso id del curso a insertar 
     * @param nombre nombre del curso a insertar 
     * @param genero genero del curso a insertar 
     * @param edad edad del curso a insertar 
     */
    public void insertarAlumno(int idCurso,String nombre, String genero, int edad) 
    {
        String query = "INSERT INTO Alumno (idCurso, nombre, genero, edad) VALUES "
                + "(?, ?, ?, ?)";
                
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setInt(1, idCurso);
            pstmt.setString(2, nombre);
            pstmt.setString(3, genero);
            pstmt.setInt(4, edad);
            pstmt.executeUpdate();
            
            System.out.println("Alumno insertado");
            
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    /**
     * 
     * @param idAlumno id del curso a modificar
     * @param idCurso idCurso nuevo
     * @param nombre nombre nuevo
     * @param genero genero nuevo
     * @param edad  edad nuevo
     */
    public void modificarAlumno(int idAlumno,int idCurso,String nombre, String genero, int edad)
    {
        String query = "UPDATE Alumno SET idCurso= ?, nombre = ?, genero = ?,"
                + "edad = ?  WHERE idAlumno = ?";
                
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setInt(1, idCurso);
            pstmt.setString(2, nombre);
            pstmt.setString(3, genero);
            pstmt.setInt(4, edad);
            pstmt.setInt(5, idAlumno);
            pstmt.executeUpdate();
            
            System.out.println("Alumno modificado");
            
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    /**
     * 
     * @param idAlumno id del alumno a eliminar
     */
    public void eliminarAlumno(int idAlumno)
    {
        String query = "DELETE FROM Alumno WHERE idAlumno = ?";
                
        try(PreparedStatement pstmt = con.prepareStatement(query))
        {
            pstmt.setInt(1, idAlumno);
            pstmt.executeUpdate();
            
            System.out.println("Alumno eliminado");
            
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    /**
     * Muestra todos los alumnos
     */
    public void mostrarAlumnos()
    {
        String query = "SELECT * FROM Alumno";
                
        try(PreparedStatement pstmt = con.prepareStatement(query);
                ResultSet rs = pstmt.executeQuery())
        {
            System.out.println("Alumnos:");
            while(rs.next())
            {
                int idAlumno = rs.getInt("idAlumno");
                int idCurso = rs.getInt("idCurso");
                String nombre = rs.getString("nombre");
                String genero = rs.getString("genero");
                int edad = rs.getInt("edad");
                
                System.out.println("ID: " + idAlumno
                        + ", idCurso: " + idCurso
                        + ", Nombre: " + nombre
                        + ", Genero: " + genero
                        + ", Edad: " + edad);
            }
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }
    
    
}
