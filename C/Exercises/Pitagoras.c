#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Teorema Pitagoras*/


double IntroducirDatosDouble(double* dato);
int IntroducirDatosInt(int* dato);
float IntroducirDatosFloat(float *dato);
void fflushStdin(void);

int main(void)
{
	//system("cls");
	unsigned int x = 1, y = 1, z = 0;
	printf("%10s %10s %10s\n","Z","X","Y");
	printf("------------------------------\n");
	while (x<=50)
	{
		while (y <= 50)
		{
			z = (int)sqrt(x * x + y * y);
			if (z > 50) break;
			if (z * z == x * x + y * y)
				printf("%10d,%10d,%10d\n", z, x, y);
			y = y + 1;
		}
		x = x + 1; y = x;
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
