/*
    El calendario gregoriano actual obdece a la reforma del calendario juliano que
    ordeno el papa Gregorio XIII en 1582. Se decidió, despues de algunas modificaciones
    que en lo sucesivo fuesen bisiestos todos los años multiplos de 4, pero que de
    los años seculares (acabados en dos 0), solo fuesen bisiestos aquellos que 
    fuesen multiples de 400. Segun estos dos conceptos, construir un programa para
    que dada una fecha (dias, mes, año) devuelva como resultado el día correspondiente
    de la semana.

    La estructura del programa esta formada ademas de la función main por las funciones:

        void leerFecha(int *dia, int *mes, int *anyo);
        void entradaDatos(int *dia, int *mes, int *anyo);
        int anyoBisiesto(int anyo);
        int datosValidos(int dia, int mes, int anyo);
        void escribirFecha(int dd, int mm, int aa);
        int diaSemana(int dia, int mes, int anyo);

    La funcion leerFecha llama a la funcion entradaDatos para leer los datos dia,
    mes, anyo y a la funcion datosValidos para asegurar que los datos introducidos
    corresponden con una fecha correcta.

    La funcion entradaDatos a la vez llama a la función anyo bisiesto para verificar si
    el año es o no bisiesto.

    La funcion escribirFecha llama a la funcion diaSemana para calcular el dia de 
    la semana al que corresponde la fecha introducida y visualiza el resultado.
*/

#include <stdio.h>

void leerFecha(int *dia, int *mes, int *anyo);
void entradaDatos(int *dia, int *mes, int *anyo);
int anyoBisiesto(int anyo);
int datosValidos(int dia, int mes, int anyo);
void escribirFecha(int dd, int mm, int aa);
int diaSemana(int dia, int mes, int anyo);

int main(void)
{
    int dd=0, mm=0, aa=0;
    leerFecha(&dd, &mm, &aa);
    escribirFecha(dd, mm, aa);

}

void leerFecha(int *dia, int *mes, int *anyo)
{
    do
    {
        entradaDatos(dia,mes,anyo);
        while(getchar() != '\n');
    } while (datosValidos(*dia,*mes,*anyo)!=1);
}

void entradaDatos(int *dia, int *mes, int *anyo)
{
    printf("Introduce una fecha (dd-mm-aa): ");
    scanf("%d-%d-%d",dia, mes, anyo);
}

int datosValidos(int dia, int mes, int anyo)
{
    if (anyo < 1800 || anyo > 3000) return 0;
    if (mes < 1 || mes > 12) return 0;

    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (anyoBisiesto(anyo) && mes == 2) {
        diasPorMes[1] = 29;
    }

    if (dia < 1 || dia > diasPorMes[mes - 1]) return 0;

    return 1; 
}

int anyoBisiesto(int anyo)
{
    return (anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0));
}

void escribirFecha(int dd, int mm, int aa)
{
    printf("La fecha es %d del %d del %d",dd,mm,aa);
}

