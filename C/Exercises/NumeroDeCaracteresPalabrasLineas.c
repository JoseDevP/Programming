/*Contar caracteresPalbras y lineas de un texto*/
#include <stdio.h>

int main(void)
{
	const int SI = 1;
	const int NO = 0;

	char car;
	int palabra = NO;
	int nCaracteres = 0, nPalabras = 0, nLineas = 0;

	printf("Introducir texto:");
	printf("Pulsa Entrar después de cada linea.\n");
	printf("Para finalizar introducir EOF\n\n");

	while ((car=getchar())!=EOF)
	{
		++nCaracteres;
		//Eliminar blancos, tabuladores y finales de linea entre palabras
		if (car == ' ' || car == '\n' || car == '\t')
		{
			palabra = NO;
		}
		else if (palabra == NO) //Comienza una palabra
		{
			nPalabras++;
			palabra = SI;
		}

		if (car == '\n')
		{
			nLineas++;
		}
	}
	printf("Numero de caracteres: %d\nNumero de palabras:  %d\n Numero de Lineas: %d\n",nCaracteres,nPalabras,nLineas);
}
