#include <stdio.h>

/*Continue*/


double IntroducirDatosDouble(double* dato);
int IntroducirDatosInt(int* dato);
float IntroducirDatosFloat(float *dato);
void fflushStdin(void);

int main(void)
{
	int n;
	for (n = 0; n <= 100; n++)
	{
		if (n % 5 != 0) continue;
		{
			printf("%d\n", n);
		}
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
