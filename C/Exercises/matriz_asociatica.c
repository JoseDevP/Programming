/* matriz-asociatica.c */

#include <stdio.h>

int diasMes(int);
unsigned char* nombresMes(int mes);

int main(void)
{
    int mes, r;
    do{
        printf("Introduce el mes (1 = enero , 0 = salir):");
        r=scanf("%d",&mes);
        if(r==1 && mes >=1 && mes <= 12)
            printf("El mes de  %s tiene %d dias\n",
            nombresMes(mes),diasMes(mes));
    }while(mes != 0);
}

int diasMes(int mes)
{
    int dias_mes[13]=
    {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(mes >= 1 && mes <=12)
    {
        return dias_mes[mes];
    }
    else
        return dias_mes[0];
}
unsigned char* nombresMes(int mes)
{
    static unsigned char nombre_mes[13][12]= //static hace que se mantenga
    {
        "error",
        "enero","febrero","marzo","abril",
        "mayo","junio","julio","agosto",
        "septiembre","octube","noviembre","diciembre"};

    if (mes >= 1 && mes <=12)
    {
        return nombre_mes[mes];
    }
    else
        return nombre_mes[0];
    
}
