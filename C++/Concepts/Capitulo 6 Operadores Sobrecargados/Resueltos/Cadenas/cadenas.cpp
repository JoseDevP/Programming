#include <iostream>
#include "cadenas.hpp"

////////////////////////////////////////////////////////////////////////////
//Mensajes de error
static const char* MensajeError[] = {"Insuficiente memoria"};

//Manipulacion del error
void CCadena::error(const char* mensaje)
{
    std::cerr << "\aerror" << mensaje << std::endl;
    exit(1);
}

//Constructor
CCadena::CCadena(const char* pcad)
{
    if(pcad == 0)
        nLong = 0;
    else
        nLong = strlen(pcad);
    pmCad = new (std::nothrow) char[nLong +1];
    if(!pmCad)  CCadena::error(MensajeError[0]);
    if(pcad == 0)
        *pmCad = 0;
    else
        strcpy(pmCad, pcad);
}

CCadena::CCadena(const CCadena& x)
{
    nLong = x.nLong;
    pmCad = new (std::nothrow) char[nLong + 1];
    if(!pmCad)  CCadena::error(MensajeError[0]);
    strcpy(pmCad, x.pmCad);
}

CCadena::CCadena(char car, int n)
{
    nLong = n;
    pmCad = new (std::nothrow) char[n + 1];
    if(!pmCad) CCadena::error(MensajeError[0]);
    std::fill(pmCad, pmCad+nLong, car);
    pmCad[nLong] = '\0';
}

CCadena::~CCadena()
{
    delete[] pmCad;
}

//Operaciones de asignacion
CCadena& CCadena::operator=(const CCadena& x)
{
    if(this == &x) return *this;
    nLong = x.nLong;
    delete[] pmCad;
    pmCad = new (std::nothrow) char[nLong +1];
    if(!pmCad) CCadena::error(MensajeError[0]);
    strcpy(pmCad,x.pmCad);
    return *this;
}

CCadena& CCadena::operator=(const char* c)
{
    nLong = strlen(c);
    delete[] pmCad;
    pmCad = new (std::nothrow) char[nLong + 1];
    if(!pmCad)  CCadena::error(MensajeError[0]);
    strcpy(pmCad, c);
    return *this; 
}

//Operador de indexacion
char& CCadena::operator[](unsigned int ind)
{
    if(ind < 0 || ind > nLong) std::cerr <<"error: indice fuera de limites\n";
    return pmCad[ind];
}

//Concatenar cadenas de caracteres
CCadena operator+(const CCadena& x, const CCadena& y)
{
    CCadena temp;
    temp.nLong = x.nLong + y.nLong;
    delete[] temp.pmCad;
    temp.pmCad = new (std::nothrow) char[temp.nLong + 1];
    if(!temp.pmCad) CCadena::error(MensajeError[0]);
    strcpy(temp.pmCad, x.pmCad);
    strcat(temp.pmCad, y.pmCad);
    return temp; 
}

CCadena& CCadena::operator+=(const CCadena& x)
{
    return *this = *this + x;
}

//Comparacion de cadenas
bool operator==(const CCadena& x, const CCadena& y)
{
    return strcmp(x.pmCad, y.pmCad) == 0;
}

bool operator!=(const CCadena& x, const CCadena& y)
{
    return !(x==y);
}

bool operator<(const CCadena& x, const CCadena& y)
{
    return strcmp(x.pmCad, y.pmCad) < 0;
}

bool operator>(const CCadena& x, const CCadena& y)
{
    return strcmp(x.pmCad, y.pmCad) > 0;
}


//Operaciones de entrad/salida

std::ostream& operator<<(std::ostream& os, const CCadena& x)
{
    return os << x.pmCad;
}

std::istream& operator>>(std::istream& is, CCadena& x)
{
    char cadena[256], c;
    is.get(cadena, 256, '\n');

    if(is.get(c) && c != '\n') std::cerr << "Cadena demasiado larga; se ha truncado\n";
    x = cadena;
    return is;
}