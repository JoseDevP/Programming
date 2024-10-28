#if !defined (_LEERDATOS_HPP_)
#define _LEERDATOS_HPP_

#include <iostream>
#include <string>
#include <limits>

template<class T> bool leerDato(T& dato)
{
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
 
    try
    {
      std::cin >> dato;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cin.exceptions(std::ios::goodbit);
      return true;
    }
    catch(std::ios_base::failure& e)
    {
      if(std::cin.eof())
      {
        std::cin.clear();
        std::cin.exceptions(std::ios::goodbit);
        return false;
      }
      else
      {
        std::cerr << e.what() << ": entrada no valida" << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return leerDato(dato);
      }
    }
    
}

bool leerDato(std::string& dato)
{
  std::cin.exceptions(std::ios::failbit | std::ios::badbit);

  try
  {
    std::getline(std::cin, dato);

    std::cin.exceptions(std::ios::goodbit);
    return true;
  }
  catch(std::ios_base::failure& e)
  {
    if(std::cin.eof())
    {
      std::cin.clear();
      std::cin.exceptions(std::ios::goodbit);
      return false;
    }
    else
    {
      std::cerr << e.what() << ": entrada no valida" << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return leerDato(dato);
    }
  }
  
}

int menu(const char* opciones[], int nOpciones)
{
    int i = 0;
    int op = -1;

    for (int i = 0; i < nOpciones; i++)
        std::cout << (i+1) << ". " << opciones[i] << std::endl;
    
    do
    {
        std::cout << "Opcion-> "; leerDato(op);
    } while (op < 1 || op > nOpciones);

    return op;
}

#endif