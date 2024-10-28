#if !defined (_INVENTARIO_HPP_)
#define _INVENTARIO_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "leerdatos.hpp"
#include "producto.hpp"

enum modo {NINGUNO = 0, LEER_Y_ESCRIBIR, ANYADIR};

class Inventario : public std::fstream
{
    private:
        int modo;
    public:
        Inventario();
        ~Inventario();
        void Nuevofichero(std::string nomFich);
        void Abrirfichero(std::string nomFich);
        void AñadirRegistros();
        double BuscarRegistro(char* ref);
        void Modificar();
        bool Existe(std::string nomFich);
};

Inventario::Inventario()
{
    modo = NINGUNO;
}

Inventario::~Inventario()
{
    if(is_open()) close();
}

void Inventario::Nuevofichero(std::string nomFich)
{
    char respuesta = 'n';
    clear();
    if(is_open()) close();

    if(nomFich.empty()) 
        throw failure(std::string(": El nombre de fichero esta vacio"));

    if(Existe(nomFich))
    {
        std::cout << "El archivo existe. Quiere truncarlo? (s/n)" << std::endl;
        do
        {
            leerDato(respuesta);
            if(respuesta != 's' && respuesta != 'n')
            {
                std::cout << "Responda con 's' o con 'n' " << std::endl;
            }
        } while (respuesta != 's' && respuesta != 'n');
        
        if(respuesta == 's')
        {
            open(nomFich, std::ios::out | std::ios::trunc | std::ios::binary);
            close();
            std::cout << "entra";
        }
    }
    open(nomFich, std::ios::out | std::ios::app | std::ios::binary);
    modo = ANYADIR;
}

void Inventario::Abrirfichero(std::string nomFich)
{
    clear();
    if(is_open()) close();

    if(nomFich.empty()) 
        throw failure(std::string(": El nombre de fichero esta vacio"));

    if(!Existe(nomFich)) 
        throw failure(std::string(": El fichero no existe"));


    std::cout << "En que modo quiere abrir el archivo\n";

    const char* opciones[] = 
    {
        "Leer y Escribir",
        "Añadir"
    };

    int op, nOpciones = sizeof(opciones) / sizeof(char*);

    switch (op = menu(opciones,nOpciones))
    {
    case 1:
        open(nomFich, std::ios::in | std::ios::out | std::ios::binary);
        modo = LEER_Y_ESCRIBIR;
        break;
    case 2:
        open(nomFich, std::ios::out | std::ios::app | std::ios::binary);
        modo = ANYADIR;
        break;
    }

}

void Inventario::AñadirRegistros()
{
    clear();
    exceptions(std::ios::failbit | std::ios::badbit);

    if(!is_open())
        throw failure(std::string(": No hay ningun archivo abierto"));

    if(modo != ANYADIR)
        throw failure(std::string(": Abre el archivo en modo Añadir"));

    Producto producto;

    int tmProducto = sizeof(producto);

    char referencia[30]; 
    char nombre[30];
    long cantidad;
    double precio;

    std::cout << "Introduce una referencia vacia para finalizar (salir)" << std::endl;

    do
    {
        std::cout << "Referencia:  "; leerDato(referencia);
        if(strcmp(referencia, "salir") == 0)
            break;
        producto.SetReferencia(referencia);

        std::cout << "Nombre:      "; leerDato(nombre);
        producto.SetNombre(nombre);

        std::cout << "Cantidad:    "; leerDato(cantidad);
        producto.SetCantidad(cantidad);

        std::cout << "Precio:      "; leerDato(precio);
        producto.SetPrecio(precio);

        if (!write(reinterpret_cast<char*>(&producto), tmProducto)) 
        {
            std::cerr << "Error al escribir el producto" << std::endl;
        }

    } while (true);

    exceptions(std::ios::goodbit);
}

double Inventario::BuscarRegistro(char* ref)
{
    clear();

    if(!is_open())
        throw failure(std::string(": No hay ningun archivo abierto"));

    if(modo != LEER_Y_ESCRIBIR)
        throw failure(std::string(": Abre el archivo en modo Leer y Escribir"));

    seekg(0, std::ios::beg);

    Producto producto;

    int tmProducto = sizeof(producto);
    
    while (read(reinterpret_cast<char*>(&producto), tmProducto))
    {
        std::cout << producto.GetReferencia() << std::endl;
        if(strcmp(producto.GetReferencia(), ref) == 0)
        {
            return producto.GetPrecio();
        }
    }
    return -1;
}

void Inventario::Modificar()
{
    clear();
    exceptions(std::ios::failbit | std::ios::badbit);

    if(!is_open())
        throw failure(std::string(": No hay ningun archivo abierto"));

    if(modo != LEER_Y_ESCRIBIR)
        throw failure(std::string(": Abre el archivo en modo Leer y escribir"));

    Producto producto;

    int tmProducto = sizeof(producto);

    char referencia[30]; 
    char nombre[30];
    long cantidad;
    double precio;

    seekp(0, std::ios::end);

    int numProductos = tellp() / tmProducto;

    int op = -1;
    
    do
    {
        std::cout << "Productos de 1 a " << numProductos << std::endl;
        std::cout << "Elije el numero de producto" << std::endl;
        leerDato(op);
    } while (op < 1 || op > numProductos);

    int desp = ((op -1) * tmProducto);

    seekg(desp, std::ios::beg);

    read(reinterpret_cast<char*>(&producto), tmProducto);
    
    std::cout << "Producto:" << std::endl; 
    std::cout << "Referencia:" << producto.GetReferencia() << std::endl; 
    std::cout << "Nombre:" << producto.GetNombre() << std::endl; 
    std::cout << "Cantidad:" << producto.GetCantidad() << std::endl; 
    std::cout << "Precio:" << producto.GetPrecio() << std::endl; 

    std::cout << "\n\n" << "Elije que desea cambiar:" << std::endl;

    const char* opciones[] =
    {
        "Referencia",
        "Nombre",
        "Cantidad",
        "Precio",
        "Salir"
    };

    int nOpciones = sizeof(opciones) / sizeof(char*);

    bool salir = false;

    do
    {
        switch (op = menu(opciones,nOpciones))
        {
        case 1://ref
            std::cout << "Referencia:  "; leerDato(referencia);
            producto.SetReferencia(referencia);
            break;
        case 2://nom
            std::cout << "Nombre:      "; leerDato(nombre);
            producto.SetNombre(nombre);
            break;
        case 3://can
            std::cout << "Cantidad:    "; leerDato(cantidad);
            producto.SetCantidad(cantidad);
            break;
        case 4://prec
            std::cout << "Precio:      "; leerDato(precio);
            producto.SetPrecio(precio);
            break;
        case 5: 
            salir = true;
            break;
        }
    } while (!salir);

    seekp( desp, std::ios::beg);

    write(reinterpret_cast<char*>(&producto), tmProducto);
    exceptions(std::ios::goodbit);
}

bool Inventario::Existe(std::string nomFich)
{
    open(nomFich, std::ios::in | std::ios::binary);
    if(fail())
    {
        clear();
        return false;
    }
    close();
    return true;
}


#endif