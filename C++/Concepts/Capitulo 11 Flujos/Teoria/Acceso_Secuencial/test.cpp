#include <iostream>
#include <fstream>
#include <string>
#include "registro.hpp"
#include "articulos.hpp"
#include "leerdatos.hpp"

int main()
{
  static const char *opciones[] = 
  { 
    "Nuevo fichero",
    "Abrir fichero",
    "Añadir registros",
    "Buscar un registro",
    "Salir"
  };
  int nOpciones = sizeof(opciones)/sizeof(char*);
  
  std::string cadenabuscar, nombreFichero, str;
  
  CArticulos fs; 
  float precio = 0;
  bool salir = false;

  while(true)
  {
    str = "ninguno";
    if (fs.Modo() == LEER)
      str = nombreFichero + " abierto para leer";
    else if (fs.Modo() == ANYADIR)
      str = nombreFichero + " abierto para a�adir";
    std::cout << "\nFichero actual: " << str;

    try
    {
      switch (menu(opciones, nOpciones))
      {
        case 1: 
          std::cout << "\nNombre del fichero: ";
          leerDato(nombreFichero);
          fs.Nuevo(nombreFichero);
          break;
        case 2: 
          std::cout << "\nNombre del fichero: ";
          leerDato(nombreFichero);
          fs.Abrir(nombreFichero);
          break;
        case 3: 
          fs.Agregar();
          break;
        case 4: 
          std::cout << "Referencia: ";
          leerDato(cadenabuscar);
          precio = fs.Buscar(cadenabuscar);
          if (precio == -1)
            std::cout << "busqueda fallida\n";
          else
            std::cout << "precio: " << precio << std::endl;
          break;
        case 5: // salir
          salir = true;
      }
    }
    catch(std::ios_base::failure& e)
    {
      std::cout << e.what() << std::endl;
    }
    if (salir) break;
  }
}