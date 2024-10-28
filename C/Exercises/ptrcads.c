/*
    Funcion que devuelve el nombre del mes 1 a 12 dado
*/

#include <stdio.h>

//Funcion que devuelve una cadena de caracteres
char *nombre_mes(unsigned int mm);

int main(void)
{
    unsigned int dia,mes,anyo,r;
    char *m;

    printf("Introducir una fecha (dd-mm-aaaa): ");
    //Los datos en la entrada irán separados por '-'
    do
    {
        r=scanf("%u-%u-%u",&dia,&mes,&anyo);
        if(r!=3) printf("formato: dd-mm-aaaa\n");
        while(getchar() != '\n');
    } while (r != 3);

    m=nombre_mes(mes);
    printf("\nMes: %s\n",m);
    
}

char *nombre_mes(unsigned int mm)
{
    //mes es ua matriz de punteros a cadenas de caracteres
    static char *mes[]={"Mes no correcto",
    "Enero","Febrero","Marzo",
    "Abril","Mayo","Junio","Julio",
    "Agosto","Septiembre","Octubre",
    "Noviembre","Diciembre"};
    
    return ((mm>0 && mm<=12) ? mes[mm] : mes[0]);
    
}