#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Ejercicio 2*/
//ax*2+bx+c=0;
//x1=(-b+-sqrt(b*2-4ac)/(2a)
//solucion real si si b*2-4ac >= 0

double IntroducirDatosDouble(double* dato);
int IntroducirDatosInt(int* dato);
float IntroducirDatosFloat(float *dato);
void fflushStdin(void);

void ec2grado(double, double, double, double*, double*);

int main(void)
{
	double a, b, c, x1, x2;
	system("cls"); //Limpiar pantalla
	printf("Introducir los coeficientes a b y c:");
	IntroducirDatosDouble(&a);
	IntroducirDatosDouble(&b);
	IntroducirDatosDouble(&c);

	ec2grado(a, b, c, &x1, &x2);

	printf("Resultado: x1=%g \n x2=%g\n", x1, x2);
}

void ec2grado(double a, double b, double c, double* x1, double* x2)
{
	double d;
	d = b * b - 4 * a * c;
	(d < 0) ? printf("Las raices son complejas\n"), exit(0) : printf("Las raices reales son\n");

	d = sqrt(d);
	*x1 = (-b + d) / (2 * a);
	*x2 = (-b - d) / (2 * a);
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
