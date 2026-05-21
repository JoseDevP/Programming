/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package creaciónxml;

import java.io.File;
import java.util.Scanner;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.*;
/**
 *
 * @author josee
 */
public class CreaciónXML {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        try
        {
            Scanner sc = new Scanner(System.in);
            
            //Nombre direccion y email del usuario
            System.out.println("Nombre:");
            String nombre = sc.nextLine();
            
            System.out.println("Apellido:");
            String apellido = sc.nextLine();
                     
            System.out.println("Email:");
            String email = sc.nextLine();
     
            
                                
            File archivo = new File("usuarios.xml");
            
            //creo fabrica de objetos parser xml con factory
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            
            DocumentBuilder builder = factory.newDocumentBuilder();
            
            //archivo en memoria
            Document document;
                   
            //nodo xml raiz
            Element raiz;
            
            
            
            
            if(archivo.exists())
            {
                //parseo
                document = builder.parse(archivo);
                //obtener "usuarios"
                raiz = document.getDocumentElement();
            }
            else
            {
                //si no existe creo un nuevo documento
                document = builder.newDocument();
                //creo usuarios
                raiz = document.createElement("usuarios");
                //y añado el nodo como raiz 
                document.appendChild(raiz);
            }
            
            
            
            //creo elemento usuario
            Element usuario = document.createElement("usuario");
            
            //creo elemento nombre
            Element eNombre = document.createElement("nombre");
            eNombre.appendChild(document.createTextNode(nombre));
            
            //creo elemento direccion
            Element eApellido = document.createElement("apellido");
            eApellido.appendChild(document.createTextNode(apellido));           
            
            //creo elemento email
            Element eEmail = document.createElement("email");
            eEmail.appendChild(document.createTextNode(email));
            
            //Los añado como hijos a usuario
            usuario.appendChild(eNombre);
            usuario.appendChild(eApellido);
            usuario.appendChild(eEmail);
            
            //añado usuario a la raiz
            raiz.appendChild(usuario);
            
            
            //creo fabrica de transformadores
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            //Para convertir el DOM en XML creo transformador
            Transformer transformer = transformerFactory.newTransformer();
            //formato
            transformer.setOutputProperty(OutputKeys.INDENT, "yes");
            
            //DOM en memoria
            DOMSource source = new DOMSource(document);
            //Destino, es decir el archivo usuarios.xml
            StreamResult result = new StreamResult(archivo);
            
            transformer.transform(source, result);
            
            System.out.println("Usuario guardado.");
                    
            
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
    
}
