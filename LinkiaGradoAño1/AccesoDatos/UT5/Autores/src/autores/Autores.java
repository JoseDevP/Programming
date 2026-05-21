/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package autores;

import java.io.ByteArrayInputStream;
import net.xqj.basex.BaseXClient;
import java.nio.charset.StandardCharsets;

/**
 *
 * @author josee
 */
public class Autores {

    /**
     * @param args the command line arguments
     */
    static BaseXClient session;
    
    public static void main(String[] args) {
        try 
        {
            session = new BaseXClient("localhost", 1984, "admin", "0831");

            System.out.println("Conectado");
            
            crearBaseDatos();
            insertarXML();
            consulta();
            mostrar();
            añadirPremiosAutor();
            mostrar();
            cerrar();
        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }
    }
    
    static void crearBaseDatos() throws Exception
    {
        
        try 
        {
            session.execute("DROP DB AutoresDB");
        } 
        catch (Exception e) {}
        
        session.execute("CREATE DB AutoresDB");
        
        System.out.println("BD creada");
    }
    
    static void insertarXML() throws Exception
    {
        String xml =
            "<autores>" +
            "<autor id='1'>" +
            "<nombre>Ana Pérez</nombre>" +
            "<nacionalidad>España</nacionalidad>" +
            "</autor>" +
            "<autor id='2'>" +
            "<nombre>John Smith</nombre>" +
            "<nacionalidad>Reino Unido</nacionalidad>" +
            "</autor>" +
            "</autores>";

        ByteArrayInputStream input =
            new ByteArrayInputStream(xml.getBytes(StandardCharsets.UTF_8));

        session.add("autores.xml", input);

        System.out.println("Insertado");
    }
    
    static void consulta() throws Exception
    {
        String query = "xquery //autor[nacionalidad='España']/nombre/text()";

        String resultado = session.execute(query);

        System.out.println("Autores españoles:");
        System.out.println(resultado);
    }
    
    
    static void añadirPremiosAutor() throws Exception
    {
        String query =
            "xquery " +
            "let $doc := doc('AutoresDB/autores.xml') " +
            "return insert node <premios>2</premios> into $doc//autor[@id='1']";

        session.execute(query);

        System.out.println("Añadido");
    }
    
    static void mostrar() throws Exception
    {
        String res = session.execute("xquery //autor");
        System.out.println(res);
    }
    
    static void cerrar() throws Exception
    {
        session.close();
        System.out.println("Cerrado");
    }
}
