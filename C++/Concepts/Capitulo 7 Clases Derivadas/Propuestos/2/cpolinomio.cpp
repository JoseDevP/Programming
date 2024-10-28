#include <iostream>
#include <map>
#include <iterator>
#include "cpolinomio.hpp"

//destructor
CPolinomio::~CPolinomio()
{
    if(terminos.size()) 
        liberarMemoria();
}

//copia
CPolinomio::CPolinomio(const CPolinomio& p)
{
    *this = p;
}

CPolinomio& CPolinomio::operator=(const CPolinomio& p)
{
    if(this == &p) return *this;

    if(terminos.size()) 
        liberarMemoria();
    terminos.resize(p.terminos.size());

    for (size_t i = 0; i < p.terminos.size(); i++)
        terminos[i] = p.terminos[i]->clonar();
    
    return *this;
}

//movimiento
CPolinomio::CPolinomio(CPolinomio&& p)
{
    terminos = std::move(p.terminos);

    p.terminos.clear();
}

CPolinomio& CPolinomio::operator=(CPolinomio&& p)
{
    if(this == &p) return *this;

    if(terminos.size()) 
        liberarMemoria();

    terminos = std::move(p.terminos);
    p.terminos.clear();

    return *this;
}

//[]
CTermino* CPolinomio::operator[](size_t i) const
{
    if(i < 0 || i >= terminos.size()) return nullptr;
    return terminos[i];
}


//aritmeticos
CPolinomio operator+(const CPolinomio& p1, const CPolinomio& p2)
{
    CPolinomio temp;
    std::map<std::string, CTermino*> terminosSemejantes;
    std::map<std::string, CTermino*>::iterator it;

    for (size_t i = 0; i < p1.terminos.size(); i++)
    { 
        if (CTerminoEnX* t2 = dynamic_cast<CTerminoEnX*>(p1.terminos[i]))
        {
            if( CTerminoEnX* t1 = dynamic_cast<CTerminoEnX*>(terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())]) )
            {
                CTerminoEnX asig = *t1 + *t2;

                delete terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())];

                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())] = new CTerminoEnX(asig);
            }                                                               
            else
            {
                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())] = new CTerminoEnX(*t2);
            }
        }
        else if (CTerminoEnY* t2 = dynamic_cast<CTerminoEnY*>(p1.terminos[i]))
        {
            if( CTerminoEnY* t1 = dynamic_cast<CTerminoEnY*>(terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())]) ) 
            {
                CTerminoEnY asig = *t1 + *t2;

                delete terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())];

                terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnY(asig);
            }  
            else
            {
                terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnY(*t2);
            }
        }
        else if (CTerminoEnXY* t2 = dynamic_cast<CTerminoEnXY*>(p1.terminos[i]))
        {
            if( CTerminoEnXY* t1 = dynamic_cast<CTerminoEnXY*>(terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())]))
            {
                CTerminoEnXY asig = *t1 + *t2;

                delete terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())];

                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnXY(asig);
            }
            else
            {
                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnXY(*t2);
            }
        }       
    }

    for (size_t i = 0; i < p2.terminos.size(); i++)
    { 
        if (CTerminoEnX* t2 = dynamic_cast<CTerminoEnX*>(p2.terminos[i]))
        {
            if( CTerminoEnX* t1 = dynamic_cast<CTerminoEnX*>(terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())]) )
            {
                CTerminoEnX asig = *t1 + *t2;

                delete terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())];

                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())] = new CTerminoEnX(asig);
            }
            else
            {
                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX())] = new CTerminoEnX(*t2);
            }
        }
        else if (CTerminoEnY* t2 = dynamic_cast<CTerminoEnY*>(p2.terminos[i]))
        {
            if( CTerminoEnY* t1 = dynamic_cast<CTerminoEnY*>(terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())]) ) 
            {
                CTerminoEnY asig = *t1 + *t2;

                delete terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())];

                terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnY(asig);
            }  
            else
            {
                terminosSemejantes["y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnY(*t2);
            }
        }
        else if (CTerminoEnXY* t2 = dynamic_cast<CTerminoEnXY*>(p2.terminos[i]))
        {
            if( CTerminoEnXY* t1 = dynamic_cast<CTerminoEnXY*>(terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())]))
            {
                CTerminoEnXY asig = *t1 + *t2;

                delete terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())];

                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnXY(asig);
            }
            else
            {
                terminosSemejantes["x^" + std::to_string(t2->obtenerExponenteEnX()) + "y^" + std::to_string(t2->obtenerExponenteEnY())] = new CTerminoEnXY(*t2);
            }
        }       
    }

    
    for ( it = terminosSemejantes.begin(); it != terminosSemejantes.end(); it++)
    {
        temp.terminos.push_back(it->second);
    }
    
    return temp;
}

CPolinomio operator-(const CPolinomio& p1, const CPolinomio& p2)
{
    
}

CPolinomio operator*(const CPolinomio& p1, const CPolinomio& p2)
{

}

CPolinomio operator/(const CPolinomio& p1, const CPolinomio& p2)
{

}

//buscar
CTermino* CPolinomio::buscarTermino(std::string tipo, int expX, int expY)
{
    for (size_t i = 0; i < terminos.size(); i++)
    {
        if(tipo == "CTerminoEnX")
        {
            if(CTerminoEnX* t = dynamic_cast<CTerminoEnX*>(terminos[i]))
            {
                if(t->obtenerExponenteEnX() == expX)
                    return terminos[i];
            }
        }
        else if(tipo == "CTerminoEnY")
        {
            if(CTerminoEnY* t = dynamic_cast<CTerminoEnY*>(terminos[i]))
            {
                if(t->obtenerExponenteEnY() == expX)
                    return terminos[i];
            }
        }
        else if(tipo == "CTerminoEnXY")
        {
            if(CTerminoEnXY* t = dynamic_cast<CTerminoEnXY*>(terminos[i]))
            {
                if(t->obtenerExponenteEnX() == expX&& t->obtenerExponenteEnY() == expY)
                    return terminos[i];
            }
        }
    }
    return nullptr;
}

//ordenar
void CPolinomio::ordenarPolinomio()
{

}


//entrada y salida
std::istream& operator>>( std::istream& is, CPolinomio& p)
{

}

std::ostream& operator<<( std::ostream& os, const CPolinomio& p)
{

}

//mostrar polinomio
void CPolinomio::mostrarPolinomio() const
{

}

void CPolinomio::liberarMemoria()
{
    for (size_t i = 0; i < terminos.size(); i++)
        delete terminos[i];
    terminos.clear();
}   

//longitud
size_t CPolinomio::longitud() const
{
    return terminos.size();
}
