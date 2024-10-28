#if !defined (_ARTICULOS_HPP_)
#define _ARTICULOS_HPP_

#include <fstream>
#include <string>
#include "leerdatos.hpp"

//Modo 1 = leer, Modo 2 = añadir
enum modo {NINGUNO = 0, LEER_ESCRIBIR, ANYADIR};

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
        void Modificar();
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
        "leer y escribir",
        "añadir"
    };

    int op, nOpciones = sizeof(opciones) / sizeof(char*);

    op = menu(opciones,nOpciones);

    switch (op)
    {
    case 1:
        open(nomf, std::ios::in | std::ios::out | std::ios::binary);
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

void CArticulos::Modificar()
{
    clear();
    exceptions(std::ios::failbit | std::ios::badbit);
    if(modo != LEER_ESCRIBIR)
        throw failure(std::string("Abrir el archivo para leer y escribir"));

    CRegistro reg;
    int tm = sizeof(reg);

    seekp(0L, std::ios::end);

    long totalReg = tellp() / tm;

    long nreg, desp; 
    do
    {
        std::cout << "\nNumero  de registro entre 1 y " << totalReg << " (0 para salir): ";
        leerDato(nreg);
        if(nreg > 0 && nreg <= totalReg)
        {
            desp = (nreg - 1) * tm;
            seekg(desp, std::ios::beg);
            read(reinterpret_cast<char*>(&reg), tm);
            std::cout << std::endl << reg;

            static const char* opciones[] = 
            {
                "referencia",
                "precio",
                "salir y salvar los cambios",
                "salir sin salvar los cambios"
            };

            int op, nOpciones = sizeof(opciones) / sizeof(char*);
            char ref[30];
            float pre;
            do
            {
                std::cout << "\nModificar el dato:";
                switch (op = menu(opciones, nOpciones))
                {
                case 1: //modificar referencia
                    std::cout << "Referencia: "; leerDato(ref);
                    reg.AsignarRegistro(ref, reg.ObtenerPrecio());
                    break;
                case 2:// modificar precio
                    std::cout << "Precio: "; leerDato(pre);
                    reg.AsignarRegistro(reg.ObtenerReferencia(ref), pre);
                    break;
                case 3: //salir y guardar los cambios
                    break;
                case 4://salir sin guardar los cambios
                    break;
                }

            } while (op != 3 && op != 4);
            
            if(op == 3)
            {
                seekp(-tm, std::ios::cur);
                write(reinterpret_cast<char*>(&reg), tm);
            }
        }
        else if (nreg < 0)
            std::cout << "error: numero de registro negativo\n";
    } while (nreg != 0);
    exceptions(std::ios::goodbit);
}

float CArticulos::Buscar(std::string& str)
{
    if(modo != LEER_ESCRIBIR)
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