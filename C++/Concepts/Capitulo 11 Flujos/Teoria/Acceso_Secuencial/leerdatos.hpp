// leerdatos.h - Funciones para leer datos de forma segura
#if !defined( _LEERDATOS_H_ )
#define _LEERDATOS_H_

#include <iostream>
#include <limits>
#include <string>


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
      return leerDato(dato);
    }
  }
  
}

int menu(const char *opciones[], int numOpciones)
{
  int i = 0; 
  int opcion = 0;

  for (int i = 1; i <= numOpciones; i++)
    std::cout << i << ": " << opciones[i] << std::endl;

  do
  {
    std::cout << "Opcion -> "; leerDato(opcion);
  } while (opcion < 0 || opcion > numOpciones);
  
  return opcion;
}

#endif 
