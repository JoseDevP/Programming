#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "IntDatosEspecificos.h"

void leerInt(int* pdato)
{
	char sdato[20];
	bool error = false;

	while (true)
	{
		error = false;
		scanf(" %s", sdato);
		if (cadenaValida(sdato, "+-0123456789"))
		{
			if (conCar(sdato, '+') > 1 || posCar(sdato, '+') > 0)
				error = true;
			else if (conCar(sdato, '-') > 1 || posCar(sdato, ' - ') > 0)
				error = true;
		}
		else
			error = true;
		if (error)
		{
			printf("DatoIncorrecto-Introduzca otro:");
		}
		else
			break;
	}
	*pdato = atoi(sdato);
}

void leerDouble(double* pdato)
{
	char sdato[20];
	bool error = false;

	while (true)
	{
		error = false;
		scanf(" %s", sdato);
		if (cadenaValida(sdato, "+-.0123456789"))
		{
			if (conCar(sdato, '+') > 1 || posCar(sdato, '+') > 0)
				error = true;
			else if (conCar(sdato, '-') > 1 || posCar(sdato, ' - ') > 0)
				error = true;
			else if (conCar(sdato, '.') > 1)
				error = true;
		}
		else
			error = true;
		if (error)
		{
			printf("DatoIncorrecto-Introduzca otro:");
		}
		else
			break;
	}
	*pdato = atof(sdato);
}

int cadenaValida(char cadena[], char cars[])
{
	int lon1 = strlen(cadena), lon2 = strlen(cars), i, j;
	bool continuar;
	for (i = 0; i < lon1; i++)
	{
		continuar = false;
		for (j = 0; j < lon2; j++)
		{
			if (cadena[i] == cars[j])
			{
				continuar = true;
				break;
			}
		}
		if (!continuar) break;
	}
	return continuar;
}

int posCar(char cadena[], int c)
{
	int lon = strlen(cadena),i,pos=-1;
	for (i = 0; i < lon; i++)
	{
		if (cadena[i] == c)
		{
			pos = i;
			break;
		}
	}
	return pos;

}

int conCar(char cadena[], int c)
{
	int lon = strlen(cadena), i, cont = 0;
	for (i = 0; i < lon; i++)
	{
		if (cadena[i] == c)
		{
			cont++;
		}
	}
	return cont;
}
int main (void)
{
	int i;
	double d;

	printf("Introducir un valor int:"); leerInt(&i);
	printf("Correcto:%d\n", i);
	printf("Introducir un valor float:") ; leerDouble(&d);
	printf("Correcto:%lf\n", d);
}