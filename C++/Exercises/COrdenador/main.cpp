#include <iostream>
#include "COrdenador.hpp"

using namespace std;

int main()
{
    COrdenador ordenador01;
    COrdenador ordenador02("Mac", "I7", 3, true, true);
    COrdenador ordenador03;

    ordenador02.desactivarPresentacionPantalla();
    ordenador03.activarPresentacionPantalla();

    ordenador01.Estado();
    ordenador02.Estado();
    ordenador03.Estado();
}