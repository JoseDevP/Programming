#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    double coef[] = {5198.0, 3.21, 46.32, 506.5, 2002.38};
    std::string prov[] = {"Madrid", "Sevilla", "Valencia", "Cantabria", "Barcelona"};

    std::cout << std::setiosflags(std::ios::fixed);

    for (int i = 0; i < sizeof(coef)/sizeof(double); i++)
        std::cout << std::setiosflags( std::ios::left) //justificado a la izquierda
                  << std::setw( 15 )  //ancho para cadenas
                  << std::setfill('.') //caracter de relleno
                  << prov[i] //provincia
                  << std::resetiosflags(std::ios::left) // suprime justificacion
                  << std::setw(10) //ancho para cantidades
                  << std::setprecision( 2 ) //dos decimales
                  << coef[i] << std::endl;
    
    //o tambien 
    std::cout << std::fixed;

    for (int i = 0; i < sizeof(coef)/sizeof(double); i++)
        std::cout << std::left //justificado a la izquierda
                  << std::setw( 15 )  //ancho para cadenas
                  << std::setfill('.') //caracter de relleno
                  << prov[i] //provincia
                  << std::right // suprime justificacion
                  << std::setw(10) //ancho para cantidades
                  << std::setprecision( 2 ) //dos decimales
                  << coef[i] << std::endl;
}