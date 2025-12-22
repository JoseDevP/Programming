/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.ColegioDb;

/**
 *
 * @author josee
 */
public class ColegioDb {

    public static void main(String[] args) 
    {
        BBDDManager bbddManager = new BBDDManager();
        
        bbddManager.insertarCurso("Matemáticas");
        bbddManager.mostrarCursos();
        
        bbddManager.insertarAlumno(1, "Juan", "M", 18);
        bbddManager.insertarAlumno(1, "Maite", "F", 23);
        
        bbddManager.modificarAlumno(1, 1, "Jose", "M", 26);
        
        bbddManager.eliminarAlumno(2);
        bbddManager.mostrarAlumnos();
    }
}
