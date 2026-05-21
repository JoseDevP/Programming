/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package biblioteca;
import org.xmldb.api.DatabaseManager;
import org.xmldb.api.base.Collection;
import org.xmldb.api.base.Database;
import org.xmldb.api.modules.CollectionManagementService;
import org.xmldb.api.modules.XMLResource;
import org.xmldb.api.modules.XQueryService;
/**
 *
 * @author josee
 */
public class Biblioteca 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        // TODO code application logic here
        try 
        {
            Collection coleccion = conectar();

            crearColeccion(coleccion);

            coleccion = DatabaseManager.getCollection(
                    "xmldb:exist://localhost:8080/exist/xmlrpc/db/Biblioteca",
                    "admin",
                    "0831"
            );

            insertarDocumento(coleccion);

            añadirEditorial(coleccion);
            
            consultarTitulos(coleccion);

        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
    
    
    public static Collection conectar() {
        try 
        {

            Class<?> clase = Class.forName("org.exist.xmldb.DatabaseImpl");

            Database baseDatos = (Database) clase.getDeclaredConstructor().newInstance();

            DatabaseManager.registerDatabase(baseDatos);

            String uri = "xmldb:exist://localhost:8080/exist/xmlrpc";
            String user = "admin";
            String pass = "0831";

            Collection coleccion = DatabaseManager.getCollection(uri + "/db", user, pass);

            return coleccion;

        } 
        catch (Exception e) 
        {
            e.printStackTrace();
            return null;
        }
    }
    
    public static void crearColeccion(Collection coleccion) throws Exception
    {

        CollectionManagementService service =
                (CollectionManagementService) coleccion.getService("CollectionManagementService", "1.0");

        try 
        {
            service.createCollection("Biblioteca");
            System.out.println("Creado Biblioteca");

        } 
        catch (Exception e) 
        {
            System.out.println("No se puede crear");
        }
    }
    
    public static void insertarDocumento(Collection coleccion) 
    {
        try {

            XMLResource recurso =
                    (XMLResource) coleccion.createResource("libros.xml", "XMLResource");

            recurso.setContent(
                    "<biblioteca>" +
                    "<libro>" +
                    "<titulo>Acceso a Datos</titulo>" +
                    "<autor>María López</autor>" +
                    "<precio>29.95</precio>" +
                    "</libro>" +
                    "</biblioteca>"
            );

            coleccion.storeResource(recurso);

            System.out.println("Insertado");

        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }
    }
    
    public static void añadirEditorial(Collection coleccion) 
    {

        try {

            XQueryService xqueryService =
                    (XQueryService) coleccion.getService("XQueryService", "1.0");

            String xquery =
                    "update insert <editorial>Cruïlla</editorial> " +
                    "into doc('/db/Biblioteca/libros.xml')/biblioteca/libro";

            xqueryService.query(xquery);

            System.out.println("Añadido nodo editorial");

        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }
    }
    
    public static void consultarTitulos(Collection coleccion) 
    {

        try 
        {

            XQueryService xqueryService =
                    (XQueryService) coleccion.getService("XQueryService", "1.0");

            String xquery =
                    "for $l in doc('/db/Biblioteca/libros.xml')//libro " +
                    "return $l/titulo/text()";

            org.xmldb.api.base.ResourceSet result = xqueryService.query(xquery);

            org.xmldb.api.base.ResourceIterator iter = result.getIterator();

            while (iter.hasMoreResources()) 
            {
                System.out.println(iter.nextResource().getContent());
            }

        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }
    }
    
    public static void eliminarDocumento(Collection coleccion)
    {
        try
        {
            org.xmldb.api.base.Resource recurso =
                    coleccion.getResource("libros.xml");

            if (recurso != null)
            {
                coleccion.removeResource(recurso);
                System.out.println("Eliminado");
            }
            else
            {
                System.out.println("Error");
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}



