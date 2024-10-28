#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>

#include "cbanco.hpp"
#include "CCuenta/ccuentaAhorro.hpp"
#include "CCuenta/ccuentaCorriente.hpp"
#include "CCuenta/ccuentaCorrientePlus.hpp"

double leerDato()
{
    double dato = 0.0;
    std::cin >> dato;
    while (std::cin.fail())
    {
        std::cout << '\a';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');
        std::cin >> dato;
    }
    std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');
    return dato;
}

CCuenta* leerDatos(int op)
{
    CCuenta* obj;
    std::string nombre, cuenta;
    double saldo, tipoi, mant;
    std::cout << "Nombre............: ";
    std::getline(std::cin, nombre);
    std::cout << "Cuenta............: ";
    std::getline(std::cin, cuenta);
    std::cout << "Saldo.............: ";
    saldo = leerDato();
    std::cout << "Tipo de interes...: ";
    tipoi = leerDato();

    if(op == 1)
    {
        std::cout << "Mantenimiento...........:";
        mant = leerDato();
        obj = new CCuentaAhorro(nombre, cuenta, saldo, tipoi, mant);
    }
    else
    {
        int transex;
        double imptrans;
        std::cout << "Importe por transacción...:";
        imptrans = leerDato();
        std::cout << "Transacciones exentas.....:";
        transex = (int)leerDato();
        if(op == 2)
            obj = new CCuentaCorriente(nombre, cuenta, saldo, tipoi, imptrans, transex);
        else
            obj = new CCuentaCorrientePlus(nombre, cuenta, saldo, tipoi, imptrans, transex);
    }

    return obj;
}

int CrearMenu(const char* opMenu[], int num_opciones)
{
    int opcion;
    system("cls");
    std::cout << "\nElija una opcion:\n" << std::endl;
    for (int i = 0; i < num_opciones; i++)
        std::cout << "\t" << std::setw(2) << i + 1 << ". " << opMenu[i] << std::endl;

    do
    {
        std::cout <<  ">> "; std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');
        if(opcion < 1 || opcion > num_opciones)
            std::cout << "Opcion Incorrecta\n" << std::endl;
    } while (opcion < 1 || opcion > num_opciones);
    
    return opcion;
}

void VisualizarCuentas(const CBanco& banco, std::string tipoCuenta = "")
{
    std::cout << ((tipoCuenta == " ") ? "Todas" : tipoCuenta) << ":\n";
    
    for (size_t i = 0; i < banco.longitud(); i++)
    {
        if(tipoCuenta == "" || CBanco::tipoCuenta(banco[i]) == tipoCuenta)
            std::cout << banco[i]->obtenerNombre() << ", " << banco[i]->obtenerCuenta() << ", " 
            << banco[i]->obtenerSaldo() << std::endl;
    }
    
}

int main()
{
    CBanco banco;
    CCuenta* cuen = 0;
    CBanco* copiaBanco = nullptr;


    int opcion = 0, pos  = -1;
    std::string cadenabuscar;
    std::string cuenta;
    double cantidad;
    bool eliminado = false;

    static const char* opciones[] = 
    {
        "Saldo", "Buscar siguiente", "Ingreso", "Reintegro", "Añadir", "Eliminar", "Mantenimiento", 
        "Copia de seguridad", "Restaurar copia de seguridad", "Mostrar cuentas", "Salir"
    };

    const int num_opciones = sizeof(opciones) / sizeof(char*);

    static const char* opciones2[] = 
    {
        "Todas", "Cuentas de ahorro", "Cuentas corrientes", "Cuentas corrientes plus", "Salir" 
    };

    const int num_opciones2 = sizeof(opciones) / sizeof(char*);

    do
    {
        opcion = CrearMenu(opciones, num_opciones);
        switch (opcion)
        {
        case 1: //saldo
            std::cout << "Nombre total o parcial, o cuenta: ";
            std::getline(std::cin, cadenabuscar);
            pos = banco.buscar(cadenabuscar);
            if(pos == -1)
            {
                if(banco.longitud() != 0)
                    std::cout << "búsqueda fallida\n";
                else
                    std::cout << "no hay cuentas\n";
            }
            else
            {
                std::cout << banco[pos]->obtenerNombre() << std::endl;
                std::cout << banco[pos]->obtenerCuenta() << std::endl;
                std::cout << banco[pos]->obtenerSaldo() << std::endl;
            }
            break;

        case 2: //buscar siguiente
            pos = banco.buscar(cadenabuscar, pos + 1);
            if(pos == -1)
                if(banco.longitud() != 0)
                    std::cout << "búsqueda fallida\n";
                else
                    std::cout << "no hay cuentas\n";
            else
            {
                std::cout << banco[pos]->obtenerNombre() << std::endl;
                std::cout << banco[pos]->obtenerCuenta() << std::endl;
                std::cout << banco[pos]->obtenerSaldo() << std::endl;
            }
            break;

        case 3://ingreso
        case 4://reintegro
            std::cout << "Cuenta: "; std::getline(std::cin, cuenta);
            pos = banco.buscar(cuenta);
            if(pos == -1)
                if(banco.longitud() != 0)
                    std::cout << "búsqueda fallida\n";
                else
                    std::cout << "no hay cuentas\n";
            else
            {
                std::cout << "Cantidad: "; cantidad = leerDato();
                if(opcion == 3)
                    banco[pos]->ingreso(cantidad);
                else
                    banco[pos]->reintegro(cantidad);
            }
            break;

        case 5://añadir
            std::cout << "Tipo de cuenta < 1-(CA), 2-(CC), 3-(CCI) >: ";
            do
            {
                opcion = (int)leerDato();
            } while (opcion < 1 || opcion > 3);
            cuen = leerDatos(opcion);
            banco.anyadir(cuen);
            delete cuen;
            break;

        case 6://eliminar
            std::cout << "Cuenta: "; std::getline(std::cin, cuenta);
            eliminado = banco.eliminar(cuenta);
            if(eliminado)
                std::cout << "registro eliminado\n";
            else
                if(banco.longitud() != 0)
                    std::cout << "cuenta no encontrada\n";
                else
                    std::cout << "no hay cuentas\n";   
            break;

        case 7://mantenimiento
            for (pos = 0; pos < banco.longitud(); pos++)
            {
                banco[pos]->comisiones();
                banco[pos]->intereses();
            }
            
            break;

        case 8://copia de seguridad
            if(banco.longitud() == 0) break;
            if(!copiaBanco)
            {
                copiaBanco = new CBanco(banco);
                if(copiaBanco) std::cout << "copia realizada con exiteo\n";
            }
            else
            {
                std::cout << "existe una copia, restaurarla\n";
            }
            break;

        case 9://restaurar copia de seguridad
            if(!copiaBanco)
            {
                banco = *copiaBanco;
                std::cout << "copia de seguridad restaurada\n";
                delete copiaBanco;
                copiaBanco = nullptr;
            }
            else
                std::cout << "no existe una copia de seguridad\n";
            break;

        case 10://Mostrar cuentas
            

            do
            {
                opcion = CrearMenu(opciones2, num_opciones2);

                switch (opcion)
                {
                case 1:
                    VisualizarCuentas(banco);
                    system("pause");
                    break;
                
                case 2:
                    VisualizarCuentas(banco, "CCuentaAhorro");
                    system("pause");
                    break;
                
                case 3:
                    VisualizarCuentas(banco, "CCuentaCorriente");
                    system("pause");
                    break;
                
                case 4:
                    VisualizarCuentas(banco, "CCuentaCorrientePlus");
                    system("pause");
                    break;

                case num_opciones2:
                    break;
                }
            } while (opcion != num_opciones2);
            break;

        case 11://salir
            if(copiaBanco) delete copiaBanco;
            break;
        }
        system("pause");
    } while (opcion != num_opciones);
    
}


