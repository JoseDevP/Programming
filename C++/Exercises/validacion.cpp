#include <iostream>
#include <limits>

bool leerDouble(double& dato);

int main()
{
    double notas[7] = {0};
    int i = 0;
    bool datoDouble = true;
    std::cout << "Introducir notas. Finalizar con eof.\n\n";
    do
    {
        std::cout << "nota[" << i << "] = "; 
        datoDouble = leerDouble(notas[i++]);
    } while (datoDouble && i < 7);
    
}

bool leerDouble(double& dato)
{
    bool fail = false, eof = false;
    do
    {
        std::cin >> dato;
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');//si entrada no es valida ignore no limpia ya que hay errores en cin
        fail = std::cin.fail(); eof = std::cin.eof();
        if(eof) //pulsa control+z
        {
            std::cin.clear(); 
            return false;
        }
        if(fail)
        {
            std::cout << "error: dato no valido\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (fail);
    return true;
}


