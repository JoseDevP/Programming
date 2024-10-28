#include <stdio.h>

/*Ajedrez*/


double IntroducirDatosDouble(double* dato);
int IntroducirDatosInt(int* dato);
float IntroducirDatosFloat(float *dato);
void fflushStdin(void);

int main(void)
{
	int falfil, calfil;//posicion incial del alfil
	//Posicion actual fila columma

	printf("Posicion del alfil (fila,columna):");
	scanf(" %d %d", &falfil, &calfil);

	printf("\n");

	//Pintar tablero ajedrez
	for (int fila = 1; fila <= 8; fila++)
	{
		for (int columna = 1; columna <=8; columna++)
		{
			if ((fila + columna == falfil + calfil) || (fila - columna == falfil - calfil))
				printf("* ");
			else if ((fila + columna) % 2 == 0)
				printf("B ");
			else
				printf("N ");

		}

		printf("\n");//cambiar fila

	}
}

double IntroducirDatosDouble(double* dato)
{
	double r=0;
	while (r==0)
	{
		r = scanf("%lf", dato);
		if (r == 0 || ferror(stdin))
		{
			printf("Error. Introduce el dato otra vez\n");
		}
		fflushStdin();
	}
	return r;

}
int IntroducirDatosInt(int* dato)
{
	int r = 0;
	while (r == 0)
	{
		r = scanf("%d", dato);
		if (r == 0 || ferror(stdin))
		{
			printf("Error. Introduce el dato otra vez\n");
		}
		fflushStdin();

	}
	return r;

}
float IntroducirDatosFloat(float* dato)
{
	float r = 0;
	while (r == 0)
	{
		r = scanf("%f", dato);
		if (r == 0 || ferror(stdin))
		{
			printf("Error. Introduce el dato otra vez\n");
		}
		fflushStdin();

	}
	return r;

}

void fflushStdin(void)
{
	if (!feof(stdin) && !ferror(stdin))
	{
		while (getchar() != '\n');
	}
}
