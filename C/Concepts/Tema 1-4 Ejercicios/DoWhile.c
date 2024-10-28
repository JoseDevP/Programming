#include <stdio.h>

/*Do While*/


double IntroducirDatosDouble(double* dato);
int IntroducirDatosInt(int* dato);
float IntroducirDatosFloat(float *dato);
void fflushStdin(void);

int main(void)
{
	double n;    //numero
	double aprox;//aprox raiz cuadrada
	double antaprox;//anterior aprox a la raiz cuadrada
	double epsilon;//coeficiente de error

	printf("Número:");
	IntroducirDatosDouble(&n);
	printf("Raiz Cuadrada aproximada:");
	IntroducirDatosDouble(&aprox);
	printf("Coeficiente de error");
	IntroducirDatosDouble(&epsilon);

	do
	{
		antaprox = aprox;
		aprox = (n / antaprox + antaprox) / 2;
	}
	while (fabs(aprox - antaprox) > epsilon);

	printf("La raiz cuadrada de %.2lf es %.2lf\n", n, aprox);
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
