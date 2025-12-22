/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package actividad1;

/**
 * Clase que instancia {@code Libro}
 * Tiene atributos como titulo, autor y año de Publicacion.
 * Tiene un constructors y metodos getters y setters.
 * @author josee
 */
public class Libro 
{
    private String titulo;
    private String autor;
    private int añoPublicacion;
    
    /**
     * @param titulo Titulo del libro
     * @param autor Autor del libro
     * @param añoPublicacion Año en que se publico el libro
     */
    public Libro(String titulo, String autor, int añoPublicacion) 
    {
        this.titulo = titulo;
        this.autor = autor;
        this.añoPublicacion = añoPublicacion;
    }
    
    /**
     * @return devuelve el titulo del libro
     */
    public String getTitulo() 
    {
        return titulo;
    }
    
    /** 
     * @return devuelve el autor del libro
     */
    public String getAutor() 
    {
        return autor;
    }
    
    /**
     * @return devuelve el año en que se publicó el libro
     */
    public int getAñoPublicacion() 
    {
        return añoPublicacion;
    }
    
    /**
     * @param titulo Titulo del libro
     */
    public void setTitulo(String titulo) 
    {
        this.titulo = titulo;
    }
    
    /**
     * 
     * @param autor Autor del libro
     */
    public void setAutor(String autor) 
    {
        this.autor = autor;
    }
    
    /**
     * 
     * @param añoPublicacion Año en que se publico el libro
     */
    public void setAñoPublicacion(int añoPublicacion) 
    {
        this.añoPublicacion = añoPublicacion;
    }

    public void mostrarInformacion()
    {
        System.out.println(this.getTitulo() + ", " + 
                this.getAutor() + ", " +
                this.getAñoPublicacion() + ".");
    }
    
}
