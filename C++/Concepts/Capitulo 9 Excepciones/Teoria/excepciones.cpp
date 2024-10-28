#include <string>
#include <iostream>

class CDemo
{
    int x;
    public:
        class ElValorNegativo {};

        CDemo()
        {
            x = 0;
            std::cout << "Se construye un objeto CDemo" << std::endl;
        }

        ~CDemo()
        {
            std::cout << "Se destruye un objeto CDemo" << std::endl;
        }

        void AsignarValor(int v)
        {
            if(v < 0)
            {
                std::cout << "Ocurrió una excepción ElValorNegativo\n",
                throw ElValorNegativo();
            }
            else if(v == 0)
            {
                std::cout << "Ocurrió una excepción; valor cero\n";
                throw "valor cero";
            }
            x = v;
        }
};

void MiFuncion(int);

int main()
{
    int a = 0;
    std::cout << "a = "; std::cin >> a;
    std::cout << "Se ejecuta main\n";

    try
    {
        std::cout << "Se llama a MiFuncion desde el bloque try\n";
        MiFuncion(a);
        std::cout << "Finaliza el bloque try\n";
    }
    catch(CDemo::ElValorNegativo& e)
    {
        std::cout << "Se captura la excepción: ";
        std::cout << "ElValorNegativo" << std::endl; 
    }
    catch(const char* s)
    {
        std::cout << s << std::endl;
    }
    std::cout << "Se reanuda la ejecucion de main\n";

    //...
}

void MiFuncion(int x)
{
    std::cout << "Se ejecuta mi Funcion\n";
    CDemo objD;
    objD.AsignarValor(x);
    //...
    std::cout << "Continua la ejecucion de mi Funcion\n";
}


