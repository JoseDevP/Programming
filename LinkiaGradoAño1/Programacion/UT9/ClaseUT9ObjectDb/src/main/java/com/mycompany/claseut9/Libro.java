/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.claseut9;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.ManyToOne;

/**
 *
 * @author josee
 */

/*
    @ManyToMany
    @ManyToOne
    @OneToMany
    @OneToOne
*/

@Entity
public class Libro
{

    @Id @GeneratedValue Long id; //autoincrementa
    public String titulo;
    
    @ManyToOne
    private Libreria libreria;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }
    
    
    
}
