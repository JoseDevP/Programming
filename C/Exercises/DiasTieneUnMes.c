#include <stdio.h>

/*Switch*/


double IntroducirDatosDouble(double* dato);
int IntroducirDatosInt(int* dato);
float IntroducirDatosFloat(float *dato);
void fflushStdin(void);

enum meses
{
	ninguno,enero,febrero,marzo,abril,mayo,junio,julio,agosto,septiembre,octubre,noviembre,diciembre
};

int main(void)
{
	int dd = 0, mm = 0, aa = 0;

	printf("Introduce el mes (##) y el año (##):\n");
	int r = 0;
	while (r == 0)
	{
		r = scanf("%d %d", &mm, &aa);
		if (r == 0 || ferror(stdin))
		{
			printf("Error. Introduce el dato otra vez\n");
		}
		fflushStdin();
	}
	switch (mm)
	{
	case enero:
	case marzo:
	case mayo:
	case julio:
	case agosto:
	case octubre:
	case diciembre:
		dd = 31;
		break;
	case abril:
	case junio:
	case septiembre:
	case noviembre:
		dd = 30;
		break;
	case febrero:
		if ((aa % 4 == 0) && (aa % 100 != 0) || (aa % 400 == 0))
			dd = 29;
		else
			dd = 28;
		break;
	default:
		printf("El mes no es valido\n");
	break;
	}
	if (mm >= enero && mm <= diciembre)
		printf("\n El mes %d del año %d tiene %d dias\n", mm, aa, dd);
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
