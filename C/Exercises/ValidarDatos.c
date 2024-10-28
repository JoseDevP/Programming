#include <stdio.h>
#pragma once //Solo 1 vez

double sumar(double, double);
double restar(double, double);
int leerDouble(double*);
void fflushstdin(void);

int main(void)
{
	double op1 = 0, op2 = 0,resultado = 0;

	//Introducir Datos
	printf("Operando 1\n"); leerDouble(&op1);
	printf("Operando 2\n"); leerDouble(&op2);
	printf("Operandos %g y %g \n", op1, op2);
}

int leerDouble(double* dato)
{
	int r = 0;
	while (r==0)
	{
		r = scanf("%lf", dato);
		if (r == 0 || ferror(stdin))
		{
			printf("Dato Incorrecto, Introduzca otro");
		}
		fflushstdin();
	}
	return r;
}

void fflushstdin(void)
{
	if (!feof(stdin) && !ferror(stdin))
	{
		while (getchar() != '\n');
	}
}

