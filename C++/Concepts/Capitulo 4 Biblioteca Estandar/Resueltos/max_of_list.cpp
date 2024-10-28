/*
    Programa que lea y almacene una lista de valores introducida por el teclado.
    Una vez leida, buscará los valores máximo y minimo, y los imprimirá;
*/
#include <iostream>
#include <vector>
#include <limits>

bool leerDouble(double& num);

int main(void)
{
    std::vector<double> v1;
    double num;
    bool resultado;

    std::cout << "Introduce el numero a leer.\n Devuelve EOF para finalizar." << std::endl;

    do
    {
        std::cout << "Numero :";
        resultado = leerDouble(num);
        if(resultado)
            v1.push_back(num);
    } while (!std::cin.bad() && !std::cin.eof());

    if(!v1.empty())
    {
        std::cout << "\n\n";
        std::cout << "Lista:" << std::endl;

        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "Numero " << i << " ->" << v1.at(i) << std::endl;
        
    }
}

bool leerDouble(double& num)
{
    bool eof = false, fail = false;
    std::cin >> num;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // por si ha sido correcta pero la entrada tenia mas datos de la cuetnar hayq ue eliminarlo

    eof=std::cin.eof();
    fail=std::cin.fail();
    if(eof || fail)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    if(fail)
    {
        std::cout << "Error al introducir el dato. Vuelvelo a introducir";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}