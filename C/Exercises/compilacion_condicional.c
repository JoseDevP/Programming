/*compilacion_condicional.c*/
#include <stdio.h>

#define USA 1
#define ESP 2
#define JPN 3
#define OTRA 4

#define PAIS_ACTIVO ESP

int main(void)
{
    #if PAIS_ACTIVO == USA
        char moneda[]="dolar";
    #elif PAIS_ACTIVO==ESP
        char moneda[]="euro";
    #elif PAIS_ACTIVO==JPN
        char moneda[]="yen";
    #elif defined(OTRA)
        char moneda[]="ninguna";
    #endif

    printf("%s",moneda);
}