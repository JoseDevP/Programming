#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main(void)
{
    int nFilas;
    int nCols;

    std::vector<std::vector<int>> v( 4, std::vector<int>(4) );


    for (int i = 0; i < v.size(); ++i) 
    {
        std::fill(v[i].begin(), v[i].end(), 5);
    }

    std::vector<std::vector<int>>::iterator i;
    std::vector<int>::iterator i2;

    for (i = v.begin(); i != v.end(); i++)
    {
        for (i2 = (*i).begin(); i2 != (*i).end(); i2++)
        {
            std::cout << *i2 << " ";
        }
        std::cout << std::endl;
        
    }
    
    v.clear();

    std::string cadena;
    long numero;

    std::map<std::string, long> m;
    std::map<std::string, long>::iterator im;

    std::cout << "Introduce una clave y luego un valor\n";
    while (std::cin >> cadena >> numero)    m[cadena] = numero;

    if(!m.empty())
    {
        im = m.find("eo");
        if(im != m.end())
        {
            std::cout << "Encontrado eo\n";
            m.erase(im);
        }
    }
    for (im = m.begin(); im != m.end(); im++)
        std::cout << "Clave: " << im->first << " Valor: " << im->second << std::endl;
    
    
}