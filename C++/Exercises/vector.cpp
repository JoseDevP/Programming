#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

bool leerInt(int& n);
void visualizarMatriz1D(std::vector<int>& v);
void visualizarMatriz2D(std::vector< std::vector<int>>& v);

int main()
{
    //Primer Vector
    bool correcto=false;
    #pragma region primerVector
    int n_elementos_v1;
    std::cout << "Indique el numero de elementos del vector" << std::endl;
    do
    {          
        correcto = leerInt(n_elementos_v1);
        if (!correcto) 
        {
            std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
        }

    } while (!std::cin.bad() && !std::cin.eof() && !correcto);

    std::cout << std::endl;
    std::cout << std::endl;


    std::vector<int> v1(n_elementos_v1,0);
    visualizarMatriz1D(v1);
    #pragma endregion

    //Segundo vector
    #pragma region segundoVector
    int filas;
    int columnas;

    std::cout << "Ahora vamos a crear una Matriz bidimensional" << std::endl;
    std::cout << "Indique el numero de filas" << std::endl;
    do
    {          
        correcto = leerInt(filas);
        if (!correcto) 
        {
            std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
        }

    } while (!std::cin.bad() && !std::cin.eof() && !correcto);

    std::cout << "Indique el numero de columnas" << std::endl;
    do
    {          
        correcto = leerInt(columnas);
        if (!correcto) 
        {
            std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
        }

    } while (!std::cin.bad() && !std::cin.eof() && !correcto);

    std::cout << std::endl;
    std::cout << std::endl;



    std::vector< std::vector<int> > v2( filas, std::vector<int>(columnas));
    visualizarMatriz2D(v2);
    
    #pragma endregion

    //acceso a los elementos

    std::cout << "Primer Elemento vector 1" << std::endl;
    std::cout << v1.front() << std::endl;

    std::cout << "Ultimo Elemento vector 1" << std::endl;
    std::cout << v1.back() << std::endl;

    try {
        std::cout << "Elemento 15 vector 1" << std::endl;
        std::cout << v1.at(15)  << std::endl;
    } catch (const std::out_of_range& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    //Buscar
    std::vector<int>::iterator r;
    r = find(v1.begin(), v1.end(), 4);
    if(*r == 4)
        std::cout << "Encontrado el 4" << std::endl;
    else
        std::cout << "No encontrado el 4" << std::endl;


    //Tamaño
    int tamañoEl = v1.size();
    v1.reserve(4);
    v1.resize(tamañoEl - 2);
    std::cout << "Capacidad" << v1.capacity() << std::endl;
    std::cout << "Matriz 1 menos dos elemto" << std::endl;
    visualizarMatriz1D(v1);

    

    //Insertar y Eliminar
    v1.pop_back();
    std::cout << "Borrado el del final" << std::endl;
    visualizarMatriz1D(v1);
    std::cout << "Añadido 6 al final" << std::endl;
    v1.push_back(3);
    visualizarMatriz1D(v1);
    std::cout << "Insertado -100 en posicion 2 " << std::endl;
    v1.insert(v1.begin()+2, 1, -100);
    visualizarMatriz1D(v1);
    //r=v1.begin();
    //v1.erase(r+1,r+3);
    //v1.clear();
}

bool leerInt(int& n)
{
    std::cin >> n;
    if(std::cin.eof() || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        return false;
    }
    return true;
}

void visualizarMatriz1D(std::vector<int>& v)
{
    int c=0;
    std::vector<int>::iterator e;

    for (e = v.begin(); e != v.end(); e++)
    {
        *e = ++c;
        std::cout << *e << " " ;

    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void visualizarMatriz2D(std::vector< std::vector<int>>& v)
{
    int c=0;
    std::vector< std::vector<int> >::iterator i;
    std::vector<int>::iterator i2;


    for ( i = v.begin(); i != v.end(); i++)
    {
        for ( i2 = i->begin(); i2 != i->end(); i2++)
        {
            *i2= ++c;
            std::cout << *i2 << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}





