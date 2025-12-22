package com.mycompany.claseut9;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.TypedQuery;

//Object Db

public class ClaseUT9 {

    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence
            .createEntityManagerFactory("objectdb:db/ejemploDB.odb;user=admin;password=admin");

        EntityManager em = emf.createEntityManager();
        
        final Libro libro1 = new Libro();
        
        //insert
        em.getTransaction().begin();
        em.persist(libro1);
        em.getTransaction().commit();
        
        
        //Consultas
        TypedQuery<Libro> query = em.createQuery("SELECT l FROM Libro l", Libro.class);    
        List<Libro> libros = query.getResultList();
        
        //Modificar
        em.getTransaction().begin();
        for(Libro l : libros){
            l.titulo="SHADK";
        }
        em.getTransaction().commit();
        
        //Eliminar
        em.getTransaction().begin();
        for(Libro l : libros){
            if("SHADK".equals(l.titulo))
            {
                em.remove(l);
            }
        }
        em.getTransaction().commit();
        
        
        //Where
        TypedQuery<Libro> query2 = em.createQuery("SELECT l FROM Libro l WHERE titulo=:tit", Libro.class);    
        query.setParameter("tit","SHADK");
        List<Libro> libros2 = query.getResultList();
        
        try {
            // Operaciones
        } catch(Exception e) {
            
        } finally {
            em.close();   // cerrar conexion con base datos
            emf.close();  // cerrar el vinculo con base datos
        }
    }
}
