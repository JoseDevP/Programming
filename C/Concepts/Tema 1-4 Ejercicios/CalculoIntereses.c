#include <stdio.h>

/*Ejercicio 1*/
//calcula intereses producidos, capital total de una cantidad c invertida a interes r
//durante t dias

//formula I=(c*r*t)/(360*100)

double IntroducirDatosDouble(double* dato);
int IntroducirDatosInt(int* dato);
float IntroducirDatosFloat(float *dato);
void fflushStdin(void);


int main(void)
{
	double interesesProducidos = 0, capitalTotal = 0, capitalInvertido = 0;
	float interes=0;
	int tiempo = 0;

	printf("Capital Invertido:");
	IntroducirDatosDouble(&capitalInvertido);
	printf("\nA un interes:");
	IntroducirDatosFloat(&interes);
	printf("\nEn un tiempo:");
	IntroducirDatosInt(&tiempo);

	interesesProducidos = (capitalInvertido * interes * tiempo) / (360 * 100);
	capitalTotal = capitalInvertido + interesesProducidos;

	printf("El capital total es de: %lf y los intereses producidos son %lf",capitalTotal,interesesProducidos );
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
