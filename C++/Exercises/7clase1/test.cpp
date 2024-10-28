#include <iostream>
#include <limits>

#include "cbiblioteca.hpp"
#include "cficha.hpp"
#include "cficha_libro.hpp"
#include "cficha_libro_volumen.hpp"
#include "cficha_revista.hpp"

const char* opcionesMenu[] = 
{
    "Añadir ficha",
    "Buscar ficha",
    "Buscar siguiente",
    "Eliminar ficha",
    "Listado de la biblioteca",
    "Copia de seguridad",
    "Restaurar copia de seguridad",
    "Salir"
};
int tamañoMenu = sizeof(opcionesMenu) / sizeof(char*);

const char* opcionesFichas[] = 
{
    "Todas",
    "Libro",
    "Libro Volumen",
    "Revistas"
};
int tamañoFichas = sizeof(opcionesFichas) / sizeof(char*);

int menu(const char* opciones[], int tamaño)
{
    int i = 0;
    int res = -1;

    std::cout << "-----------------------------" << std::endl;
    for (size_t i = 0; i < tamaño; i++)
    {
        std::cout << i+1 << ". " << opciones[i] << std::endl;
    }
    do
    {
        std::cout << "Respuesta ->  "; std::cin >> res;
        if(res < 0 || res > tamaño)
        {
            std::cout << "Indice fuera de limites\n";
        }
    } while (res < 0 || res > tamaño);

    return res;
}

double leerNumero()
{
    double num;
    std::cin >> num;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> num;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return num;
}

CFicha* crearFicha()
{
    std::string tipo; 
    std::string referencia; 
    std::string titulo; 
    
    std::cout << "Tipo de ficha:\n" 
    << "(Libro / Libro Volumen / Revista)"<< std::endl;
    std::getline(std::cin, tipo);
    
    std::cout << "Referencia: "<< std::endl;
    std::getline(std::cin, referencia);

    std::cout << "Titulo: "<< std::endl;
    std::getline(std::cin, titulo);

    if(tipo == "Libro")
    {
        std::string autor;
        std::string editorial;

        std::cout << "Autor: "<< std::endl;
        std::getline(std::cin, autor);

        std::cout << "Editorial: "<< std::endl;
        std::getline(std::cin, editorial);

        CFicha* ficha = new CFichaLibro(referencia, titulo, autor, editorial);
        return ficha;
    }
    else if(tipo == "Libro Volumen")
    {
        std::string autor;
        std::string editorial;
        
        std::cout << "Autor: "<< std::endl;
        std::getline(std::cin, autor);

        std::cout << "Editorial: "<< std::endl;
        std::getline(std::cin, editorial);

        int numeroVolumen = leerNumero();

        CFicha* ficha = new CFichaLibroVolumen(referencia, titulo, autor, editorial, numeroVolumen);
        return ficha;
    }
    else if(tipo == "Revista")
    {
        int numeroRevista = leerNumero();
        long añoPublicacion = leerNumero();

        CFicha* ficha = new CFichaRevista(referencia, titulo, numeroRevista, añoPublicacion);
        return ficha;
    }
    else
    {
        return nullptr;
    }
}

void leerFicha(CFicha *ficha)
{
    std::cout << "Referencia-> " << ficha->obtenerReferencia() << std::endl;
    std::cout << "Titulo-> " << ficha->obtenerTitulo() << std::endl;
    
    if(CFichaLibro* f = dynamic_cast<CFichaLibro*>(ficha))
    {
        std::cout << "Autor-> " << f->obtenerAutor() << std::endl;
        std::cout << "Editorial-> " << f->obtenerEditorial() << std::endl;
    }
    else if(CFichaLibroVolumen* f = dynamic_cast<CFichaLibroVolumen*>(ficha))
    {
        std::cout << "Autor-> " << f->obtenerAutor() << std::endl;
        std::cout << "Editorial-> " << f->obtenerEditorial() << std::endl;
        std::cout << "Volumen-> " << f->obtenerVolumen() << std::endl;
    }
    else if(CFichaRevista* f = dynamic_cast<CFichaRevista*>(ficha))
    {
        std::cout << "Numero revista-> " << f->obtenerNumero() << std::endl;
        std::cout << "Año publicacion-> " << f->obtenerAño() << std::endl;
    }
    std::cout << "\n\n";
}

int main()
{
    CBiblioteca biblioteca;
    CBiblioteca* bibliotecaCopiaSeguridad = nullptr;

    CFicha* ficha =nullptr;
    std::string referencia = ""; 

    int opcion = -1;
    int i = 0;

    opcion = menu(opcionesMenu, tamañoMenu);

    switch (opcion)
    {
    case 1: //Añadir ficha
        if((ficha = crearFicha()) != nullptr)
        {
            biblioteca.anyadirFicha(ficha);
            delete ficha;
            std::cout << "Añadido correctamente" << std::endl;
        }
        else
        {
            std::cout << "Tipo de ficha no existente" << std::endl;
        }
        break;
    case 2: //Buscar ficha
        std::cout << "Referencia: "; std::getline(std::cin, referencia); 
        i = biblioteca.buscarFicha(referencia, 0);
        if(i == -1)
            std::cout << "No encontrada" << std::endl;
        else
        {
            leerFicha(biblioteca[i]);
        }
        break;
    case 3: //Buscar siguiente
        i = biblioteca.buscarFicha(referencia, i+1);
        if(i == -1)
            std::cout << "No encontrada" << std::endl;
        else
        {
            leerFicha(biblioteca[i]);
        }
        break;
    case 4: //Eliminar ficha
        std::cout << "Referencia: "; std::getline(std::cin, referencia); 
        i = biblioteca.buscarFicha(referencia, 0);
        if(i == -1)
            std::cout << "No encontrada" << std::endl;
        else
        {
            biblioteca.eliminarFicha(referencia);
            std::cout << "Eliminada" << std::endl;
        }
        break;
    case 5: //Listado de la biblioteca
        if(biblioteca.longitud() == 0)
        {
            std::cout << "Biblioteca vacia" << std::endl;
        }
        else
        {
            opcion = menu(opcionesFichas, tamañoFichas);

            switch (opcion)
            {
            case 1: //"Todas"
                for (size_t i = 0; biblioteca.longitud(); i++)
                {
                    leerFicha(biblioteca[i]);
                }
                break;
            case 2: //"Libro"
                for (size_t i = 0; biblioteca.longitud(); i++)
                {
                    if(CFichaLibro* f = dynamic_cast<CFichaLibro*>(biblioteca[i]))
                    {
                        leerFicha(biblioteca[i]);
                    }
                }
                break;
            case 3: //"Libro Volumen"
                for (size_t i = 0; biblioteca.longitud(); i++)
                {
                    if(CFichaLibroVolumen* f = dynamic_cast<CFichaLibroVolumen*>(biblioteca[i]))
                    {
                        leerFicha(biblioteca[i]);
                    }
                }
                break;
            case 4: //"Revistas"
                for (size_t i = 0; biblioteca.longitud(); i++)
                {
                    if(CFichaRevista* f = dynamic_cast<CFichaRevista*>(biblioteca[i]))
                    {
                        leerFicha(biblioteca[i]);
                    }
                }
                break;
            }         
        } 
        break;
    case 6: //Copia de seguridad
        bibliotecaCopiaSeguridad = new CBiblioteca(biblioteca);
        if(bibliotecaCopiaSeguridad != nullptr)
            std::cout << "Copia de seguridad realizada";
        break;
    case 7: //Restaurar copia de seguridad
        if(bibliotecaCopiaSeguridad == nullptr)
            std::cout << "No hay una copia de seguridad" << std::endl;
        else
        {
            biblioteca = *bibliotecaCopiaSeguridad;
            std::cout << "Restaurado" << std::endl;
        }
        break;
    case 8: //Salir
        if(bibliotecaCopiaSeguridad != nullptr)
            delete bibliotecaCopiaSeguridad;
        break;
    }
}
