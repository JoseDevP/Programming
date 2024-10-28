#include <iostream>
#include "persona.hpp"
#include "listatfnos.hpp"


void buscar(CListaTfnos& listaTfnos, bool buscar_siguiente)
{
  static int pos = -1;
  static std::string cadenabuscar;
  
  if (!buscar_siguiente)
  {
    std::cout << "conjunto de caracteres a buscar: ";
    getline(std::cin, cadenabuscar);

    pos = listaTfnos.buscar(cadenabuscar, 0);
  }
  else
    pos = listaTfnos.buscar(cadenabuscar, pos+1);
  if (pos == -1)
    if (listaTfnos.longitud() != 0)
      std::cout << "b�squeda fallida\n";
    else
      std::cout << "lista vac�a\n";
  else
  {
    std::cout << listaTfnos.registro(pos).obtenerNombre() << std::endl;
    std::cout << listaTfnos.registro(pos).obtenerDireccion() << std::endl;
    std::cout << listaTfnos.registro(pos).obtenerTelefono() << std::endl;
  }
}

void anyadir(CListaTfnos& listaTfnos)
{
  std::string nombre, direccion;
  long telefono;

  std::cout << "nombre:    "; getline(std::cin, nombre);
  std::cout << "direcci�n: "; getline(std::cin, direccion);
  std::cout << "tel�fono:  "; std::cin >> telefono;
  listaTfnos.anyadir(CPersona{ nombre, direccion, telefono });
}

void eliminar(CListaTfnos& listaTfnos)
{
  long telefono;
  bool eliminado = false;

  std::cout << "tel�fono: "; std::cin >> telefono;
  eliminado = listaTfnos.eliminar(telefono);
  if (eliminado)
    std::cout << "registro eliminado\n";
  else
    if (listaTfnos.longitud() != 0)
      std::cout << "tel�fono no encontrado\n";
    else
      std::cout << "lista vac�a\n";
}



int menu()
{
    std::cout << "\n\n";
    std::cout << "1. Buscar\n";
    std::cout << "2. Buscar siguiente\n";
    std::cout << "3. Añadir\n";
    std::cout << "4. Eliminar\n";
    std::cout << "5. Salir\n";
    std::cout << std::endl;
    std::cout << "  Opcion: ";

    int op;
    do
    {
        std::cin >> op;
    } while (op < 1 || op > 5);
    std::cin.ignore();
    return op;
}

int main()
{
    CListaTfnos listaTfnos;
    int opcion = 0;

    do
    {
        opcion = menu();
        switch (opcion)
        {
            case 1:
                buscar(listaTfnos, false);
                break;
            case 2:
                buscar(listaTfnos, true);
                break;
            case 3:
                anyadir(listaTfnos);
                break;
            case 4:
                eliminar(listaTfnos);
                break;
        }
    } while (opcion != 5);
    
}