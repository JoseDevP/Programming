/*
    Calcula el importe a pagar por un vehiculo al circular por una autopista.
    Vehiculo:
        Bici
        Moto
        Coche
        Camión
    enum vehiculos

    importe:
        Fijo 100 unidades para bicicletas
        Motos y coches 30 unidades por km
        caiones 30 unidades por km mas 25 unidades por tn.

    Presentación:
        1 - Bici
        2 - Moto
        3 - Coche
        4 - Camión
        5 - Salir

        Seleccione la opción deseada:4
        ¿Km y toneladas? 100 50
        importe=4250
*/

#include <stdio.h>

enum Vehiculos
{
    Bici=1,Moto,Coche,Camión
};

int main(void)
{
    int opcion;
    int importe;
    int km;
    int tn;

    printf("Elije una opción para ver el importe a pagar\n");
    printf("1 - Bici\n");
    printf("2 - Moto\n");
    printf("3 - Coche\n");
    printf("4 - Camión\n");
    printf("5 - Salir\n");

    while (1)
    {
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Entrada no válida. Por favor, introduce un número.\n");
        } 
        else 
        {
            break;
        }
    }

    switch (opcion)
    {
    case Bici:
            importe=100;
            printf("El importe es de: %d\n",importe);
        break;
    case Moto:
    case Coche:
            printf("¿Cuantos km tiene?");
            while (1)
            {
                if (scanf("%d", &km) != 1) {
                    while (getchar() != '\n');
                    printf("Entrada no válida. Por favor, introduce un número.\n");
                } 
                else 
                {
                    break;
                }
            }
            importe=30*km;
            printf("El importe es de: %d\n",importe);
        break;
    case Camión:
            printf("¿Cuantos km y toneladas tiene?");
            while (1)
            {
                if (scanf("%d %d",&km,&tn) != 2) {
                    while (getchar() != '\n');
                    printf("Entrada no válida. Por favor, introduce un número.\n");
                } 
                else 
                {
                    break;
                }
            }
            importe=30*km+25*tn;
            printf("El importe es de: %d\n",importe);
        break;
    case 5:
        break;
    default:
        break;
    }
}