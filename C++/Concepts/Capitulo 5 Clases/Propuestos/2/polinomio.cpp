#include <iostream>
#include "polinomio.hpp"
#include <sstream> 
#include <cmath>  
#include <algorithm> 

using namespace pol;

// Termino:
CTermino::CTermino(double coef, int exp) : coeficiente(coef), exponente(exp)
{
    asignarCoeficiente(coef);
    asignarExponente(exp);
}

void CTermino::asignarCoeficiente(double coef)
{
    coeficiente = coef;
}

double CTermino::obtenerCoeficiente() const
{
    return coeficiente;
}

void CTermino::asignarExponente(int exp)
{
    if(exp < 0) 
    {
        std::cerr << "error: El exponente no puede ser negativo\n";
        exponente = 0;
    }
    else
    {
        exponente = exp;
    }
}

int CTermino::obtenerExponente() const
{
    return exponente;
}

std::string CTermino::representacionEnCadena() const // formato {+/-} 7x^4
{
    std::ostringstream termino; 

    if (coeficiente >= 0) {
        termino << '+';
    } else {
        termino << '-';
    }

    if (std::abs(coeficiente) != 1 || exponente == 0) {
        termino << std::abs(coeficiente);
    }

    if (exponente > 0) {
        termino << "x";
        if (exponente > 1) {
            termino << "^" << exponente;
        }
    }

    return termino.str();
}

// Polinomio
CPolinomio::CPolinomio()
{
    polinomio.reserve(100);
}

int CPolinomio::numeroDeTerminos() const
{
    return static_cast<int>(polinomio.size());
}

void CPolinomio::asignarTermino(const CTermino& t)
{
    for (CTermino& termino : polinomio)
    {
        if (termino.obtenerExponente() == t.obtenerExponente())
        {
            termino.asignarCoeficiente(termino.obtenerCoeficiente() + t.obtenerCoeficiente());
            return;
        }
    }

    polinomio.push_back(t);

    std::sort(polinomio.begin(), polinomio.end(), [](const CTermino& a, const CTermino& b) {
        return a.obtenerExponente() < b.obtenerExponente();
    });
}

CPolinomio CPolinomio::operator+(const CPolinomio& pol) const
{
    CPolinomio resultado;

    for (const CTermino& termino : polinomio)
    {
        resultado.asignarTermino(termino);
    }

    for (const CTermino& termino : pol.polinomio)
    {
        resultado.asignarTermino(termino);
    }

    return resultado;
}

std::string CPolinomio::representacionEnCadena() const
{
    std::ostringstream termino; 

    if (numeroDeTerminos() == 0) return "0";
    for (const CTermino& t : polinomio)
    {
        termino << t.representacionEnCadena() << " ";
    }

    std::string result = termino.str();
    if (!result.empty() && result[0] == '+') {
        result.erase(0, 1); 
    }
    return result;
}
