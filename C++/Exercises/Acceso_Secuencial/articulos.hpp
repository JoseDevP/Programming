#if !defined (_ARTICULOS_HPP_)
#define _ARTICULOS_HPP_

#include <fstream>
#include <string>
#include "leerdatos.hpp"

//Modo 1 = leer, Modo 2 = añadir
enum modo {NINGUNO = 0, LEER, ANYADIR};

class CArticulos : std::fstream
{
    private:
        int modo;
    public:
        CArticulos();
        ~CArticulos();
        void Nuevo(std::string&);
        void Abrir(std::string&);
        void Agregar();
        float Buscar(std::string&);
        bool Existe(std::string&);
        int Modo() { return modo; }
};

CArticulos::CArticulos()
{
  modo = NINGUNO;
}

CArticulos::~CArticulos()
{
  if (is_open()) close();
}

void CArticulos::Nuevo(std::string& nomf) 
{
    clear(); // desactivar los indicadores que haya activos

    if(nomf.empty())
        throw failure(std::string("Especificar un nombre para el archivo"));

    if(is_open()) close();
    modo = NINGUNO;

    if(Existe(nomf))
    {
        std::cout << "El archivo " << nomf << " existe. " << "¿Desea sobreescribirlo? (s/n): ";
        std::string resp("n");
        leerDato(resp);
        if(resp == "s")
        {
            open(nomf, std::ios::out | std::ios::trunc);
            close();
        } 
    } 

    open(nomf, std::ios::out | std::ios::app | std::ios::binary);
    modo = ANYADIR;
}

void CArticulos::Abrir(std::string& nomf)
{
    clear();

    if(nomf.empty())
        throw failure(std::string("Especificar un nombre para el archivo"));

    if(is_open()) close();
    modo = NINGUNO;

    static const char* opciones[] =
    {
        "leer",
        "escribir"
    };

    int op, nOpciones = sizeof(opciones) / sizeof(char*);

    op = menu(opciones,nOpciones);

    switch (op)
    {
    case 1:
        open(nomf, std::ios::in | std::ios::binary);
        break;

    case 2:
        open(nomf, std::ios::out | std::ios::app | std::ios::binary);
        break;
    }

    modo=op;

}

void CArticulos::Agregar()
{
    clear();
    exceptions(std::ios::failbit | std::ios::badbit);

    if(modo != ANYADIR)
        throw failure(std::string("Abrir el archivo para añadir"));

    CRegistro reg;
    int tm = sizeof(reg);
    char ref[30];
    float pre;

    std::cout << "\nIntroducir datos. Para finalizar, " 
              << "responder \"fin\" a Referencia:.\n\n";
    while (true)
    {
        std::cout << "Referencia: "; leerDato(ref);
        if(!strcmp(ref, "fin")) break;
        std::cout << "Precio:     "; leerDato(pre);

        reg.AsignarRegistro(ref, pre);
        write(reinterpret_cast<char*>(&reg), tm);
    }
    exceptions(std::ios::goodbit);
}

float CArticulos::Buscar(std::string& str)
{
    if(modo != LEER)
    {
        std::cout << "Abrir el archivo para leer\n";
        return -1;
    }

    CRegistro reg;
    seekg(0, std::ios::beg);

    int tm = sizeof(reg);
    char ref[30];
    std::string refe;

    if(str.empty()) return false;

    while (read(reinterpret_cast<char*>(&reg), tm))
    {
        refe = std::string(reg.ObtenerReferencia(ref));
        if(refe.empty()) continue;

        if(str == refe)
            return reg.ObtenerPrecio();
    }

    clear();
    return -1;
}

bool CArticulos::Existe(std::string& nombf)
{
    open(nombf, std::ios::in);
    if(fail())
    {
        clear();
        return false;
    }
    close();
    return true;
}


#endif