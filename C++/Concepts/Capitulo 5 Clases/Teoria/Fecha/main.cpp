#include <iostream>
#include "fecha.hpp"
using namespace fjc;

void leerFecha(int&, int&, int&);
void visualizarFecha(CFecha& fecha);

int main()
{
    //CFecha fecha;
    //int dd = 0, mm = 0, aaaa = 0;
    //bool fechaValida = true;
    //do
    //{
    //    leerFecha(dd, mm, aaaa);
    //    fechaValida = fecha.asignarFecha(dd, mm ,aaaa);
    //} while (!fechaValida);
    //visualizarFecha(fecha);
    
    CFecha fecha1{1,3,2020};
    CFecha* pfecha2 = new CFecha{ fecha1 };

    visualizarFecha(*pfecha2);
    delete pfecha2;
}

void leerFecha(int& dia, int& mes, int& anyo)
{
    std::cout << "dias: "; std::cin >> dia;
    std::cout << "mes: "; std::cin >> mes;
    std::cout << "anyo: "; std::cin >> anyo;
}

void visualizarFecha(CFecha& fecha)
{
    int dd, mm, aaaa;
    fecha.obtenerFecha(dd, mm, aaaa);
    std::cout << dd << "/" << mm << "/" << aaaa << "\n";
    dd = fecha.obtenerDia();
    std::cout << "Dia: " << dd << std::endl; 
}