/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.claseut9;

import java.util.ArrayList;
import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.OneToMany;

/**
 *
 * @author josee
 */

@Entity
public class Libreria 
{
    @Id @GeneratedValue long id;
    String direccion;
    
    @OneToMany (cascade = CascadeType.ALL,
            mappedBy= "libreria", orphanRemoval = true)
    
    private List<libro> libros = new ArrayList<>();

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }
}
