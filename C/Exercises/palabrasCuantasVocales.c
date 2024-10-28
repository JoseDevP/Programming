#include <stdio.h>

int main(void)
{
	int numPalabras=0;
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	char car;

	printf("Introducir texto:");
	printf("Para finalizar introducir la marca EOF\n\n");
	while ((car = getchar()) != EOF)
	{
		switch (car)
		{
		case 'A': case 'a': case 'Á': case 'á':
			a = 1;
			break;
		case 'E': case 'e': case 'É': case 'é':
			e = 1;
			break;
		case 'I': case 'i': case 'Í': case 'í':
			i = 1;
			break;
		case 'O': case 'o': case 'Ó': case 'ó':
			o = 1;
			break;
		case 'U': case 'u': case 'Ú': case 'ú':
			u = 1;
			break;
		default:
			if (car == ' ' || car == '\t' || car == '\n')
			{
				if ((a + e + i + o + u) >= 4) numPalabras++;
				a = e = i = o = u=0;
			}
			break;
		}
	}
	if ((a + e + i + o + u) >= 4) numPalabras++;
	printf("Numero de palabras con 4 o más vocales distintas %d\n", numPalabras);

}
