#if !defined (_TELEFONO_HPP_)
#define _TELEFONO_HPP_

#include <iostream>
#include <fstream>
#include "persona.hpp"
#include "leerdatos.hpp"

class CTelefonos : private std::fstream
{
    private:
        int modo;
    public:
        CTelefonos();
        ~CTelefonos();
        int Modo() {return modo;}
        bool Existe(std::string&);
        CPersona LeerReg(long nreg);
        void Nuevo(std::string&);
        void Abrir(std::string&);
        void Agregar();
        long Buscar(const char*, long pos);
        void Modificar();
};

CTelefonos::CTelefonos()
{
    modo = 0;
}

CTelefonos::~CTelefonos()
{
    if(is_open()) close();
}

bool CTelefonos::Existe(std::string& nomf)
{
    open(nomf, std::ios::in);
    if(fail())
        return false;
    close();
    return true;
}

CPersona CTelefonos::LeerReg(long nreg)
{
    clear();
    exceptions(std::ios::failbit | std::ios::badbit);

    if(modo != 1)
        throw failure(std::string("Abrir el archivo para leer y escribir"));
    
    CPersona reg;
    seekp(0L, std::ios::end);
    long totalRegs = tellp() / reg.tamanyo();
    if(nreg < 1 || nreg > totalRegs)
        throw failure(std::string("Número de registro no válido"));

    seekg( (nreg - 1)*reg.tamanyo(), std::ios::beg );
    read(reinterpret_cast<char*>(&reg), reg.tamanyo());

    exceptions(std::ios::goodbit);
    return reg;
}

void CTelefonos::Nuevo(std::string& nomf)
{
    clear();

    if(nomf.empty())
        throw failure(std::string("Especificar un nombre para el archivo"));
    
    if(is_open()) close();
    modo = 0;

    if(Existe(nomf))
    {
        std::cout << "El archivo" << nomf << " existe. " << "¿Desea sobreescribirlo? (s/n) ";

        std::string resp("n");
        leerDato(resp);
        if(resp == "s")
        {
            open(nomf, std::ios::out | std::ios::trunc |std::ios::binary);
            close();
        }
        
    }
    
    open(nomf, std::ios::out | std::ios::app | std::ios::binary);
    modo = 2;
}

void CTelefonos::Abrir(std::string& nomf)
{
    clear();
    
    if(nomf.empty())    
        throw failure(std::string("Especificar un nombre para el archivo"));

    if(is_open()) close();

    modo = 0;

    static const char* opciones[] = 
    {
        "leer y escribir",
        "añadir"
    };

    int op, nOpciones = sizeof(opciones) / sizeof(char*);

    switch (op = menu(opciones,nOpciones))
    {
    case 1:
        open(nomf, std::ios::in | std::ios::out | std::ios::binary);
        modo = 1;
        break;

    case 2:
        open(nomf, std::ios::out | std::ios::app | std::ios::binary);
        modo = 2;
        break;
    }
}

void CTelefonos::Agregar()
{
    clear();

    exceptions(std::ios::failbit | std::ios::badbit);

    if(modo != 2)
        throw failure(std::string("Abrir el archivo para añadir"));

    CPersona reg;
    char nom[30];
    char dir[40];
    long tfno;

    std::cout << "\nIntroducir datos. Para finalizar, "
              << "responder \"fin\" a Nombre:.\n\n";
    
    while (true)
    {
        std::cout << "Nombre:    "; leerDato(nom);
        if(!strcmp(nom, "fin")) break;
        std::cout << "Direccion:    "; leerDato(dir);
        std::cout << "Telefono:    "; leerDato(tfno);
        reg =CPersona(nom, dir, tfno);
        write(reinterpret_cast<char*>(&reg), reg.tamanyo());
    }
    

    exceptions(std::ios::goodbit);
}

long CTelefonos::Buscar(const char* str, long nreg)
{
    if(modo != 1)
    {
        std::cout << "Abrir el archivo para leer y escribir\n";
        return -1;
    }

    CPersona reg;
    char nom[30];

    if(str == 0) return -1;
    if(nreg <= 0) nreg = 1;

    seekg((nreg - 1 ) * reg.tamanyo(), std::ios::beg);
    while ( read(reinterpret_cast<char*>(&reg), reg.tamanyo()) )
    {
        reg.ObtenerNombre(nom);
        if(nom == 0) continue;

        if(strstr(nom, str) != 0)
            return tellg() / reg.tamanyo();
    }
    clear();
    return -1;
}

void CTelefonos::Modificar()
{
    clear();
    exceptions(std::ios::failbit | std::ios::badbit);

    if(modo != 1)
        throw failure(std::string("Abrir el archivo para leer y escribir"));

    CPersona reg;

    seekp(0, std::ios::end);
    long totalreg= tellp() / reg.tamanyo();

    long nreg, desp;
    do
    {
        std::cout << "\nNumero de registro entre 1 y " << totalreg << " (0 para salir): ";
        leerDato(nreg);
        if(nreg > 0 && nreg <= totalreg)
        {
            desp = (nreg -1) * reg.tamanyo();
            seekg(desp, std::ios::beg);

            read(reinterpret_cast<char*>(&reg), reg.tamanyo());
            std::cout << std::endl << reg;

            static const char* opciones[] = 
            {
                "nombre",
                "direccion",
                "telefono",
                "salir y salvar los cambios",
                "salir sin salvar los cambios"
            };

            int op, nOpciones = sizeof(opciones) / sizeof(char*);

            char nom[30]; reg.ObtenerNombre(nom);
            char dir[40]; reg.ObtenerNombre(dir);
            long tfno; tfno = reg.ObtenerTelefono();

            do
            {
                std::cout << "\n Modificar el dato:";
                switch (op = menu(opciones, nOpciones))
                {
                case 1: //nombre
                    std::cout << "Nombre:    "; leerDato(nom);
                    break;
                case 2: //direccion
                    std::cout << "Direccion: "; leerDato(dir);
                    break;
                case 3: //telefono
                    std::cout << "Telefono:  "; leerDato(nom);
                    break;
                case 4: //guardar y salir
                    break;
                case 5: //salir
                    break;
                }

                reg = CPersona(nom, dir, tfno);

            } while (op != 4 && op != 5);
            
            if(op == 4)
            {
                seekp(desp, std::ios::beg);
                write(reinterpret_cast<char*>(&reg), reg.tamanyo());
            }
        }
        else if(nreg < 0)
            std::cout << "error: numero de registro negativo\n";
    } while (nreg < 0);
    exceptions(std::ios::goodbit);
}

#endif