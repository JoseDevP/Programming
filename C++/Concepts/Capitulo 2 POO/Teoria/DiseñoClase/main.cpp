#include <iostream>
#include "CCuenta.h"
#include "CCuentaAhorro.h"

using namespace std;

int main()
{
    CCuentaAhorro cuenta01;
    CCuentaAhorro cuenta02("Un nombre", "Una cuenta", 6000, 3.5,2);
 
    cuenta01.asignarNombre("Jose");
    cuenta01.asignarCuenta("5628435691");
    cuenta01.asignarTipoDeInteres(2.5);

    cuenta01.ingreso(12000);
    cuenta01.reintegro(3000);

    cout << "Cuenta 1:" << endl;
    cout << "Nombre: " << cuenta01.obtenerNombre() << endl;
    cout << "Cuenta: " << cuenta01.obtenerCuenta() << endl;
    cout << "Saldo: " << cuenta01.obtenerSaldo() << endl;
    cout << "Tipo de interes: " << cuenta01.obtenerTipoDeInteres() << endl;
    cout << endl;        

    cout << "Cuenta 2:" << endl;
    cuenta02.reintegro(cuenta02.obtenerCuotaManten());

    cuenta02.ingreso(6000);

    cuenta02.reintegro(10000);
    cout << "Nombre: " << cuenta02.obtenerNombre() << endl;
    cout << "Cuenta: " << cuenta02.obtenerCuenta() << endl;
    cout << "Saldo: " << cuenta02.obtenerSaldo() << endl;
    cout << "Tipo de interes: " << cuenta02.obtenerTipoDeInteres() << endl;
    cout << endl;                                                                                                                                                                                                 
}