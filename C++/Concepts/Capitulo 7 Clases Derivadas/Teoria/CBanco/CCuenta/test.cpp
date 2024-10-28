#include <stdio.h>
#include "ccuentaAhorro.hpp"

int main()
{
    CCuentaAhorro cuenta01;
    cuenta01.asignarNombre("Un nombre");
    cuenta01.asignarCuenta("Una cuenta");
    cuenta01.asignarTipoDeInteres(2.5);
    cuenta01.asignarCuotaMantenimiento(20);
    cuenta01.ingreso(100000);
    cuenta01.comisiones();
}