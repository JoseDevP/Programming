#include <stdio.h>
#include <stdlib.h>

void fflushstdin(void);
void VerifyEOF(void);

int main(void)
{
	float precio = 0;
	char car = 0;

	printf("Precio:");
	scanf("%g", &precio);
	VerifyEOF();
	fflushstdin();

	printf("Pulsa enter para continuar");
	scanf("%c", &car);

	printf("Precio=%f\n", precio);

	int putchar(car);

	char c = 'a';
	putchar(c);
}

void fflushstdin(void)
{
	if (!feof(stdin) && !ferror(stdin))
		while (getchar() != '\n');

}

void VerifyEOF()
{
	if (feof(stdin))
	{
		printf("La entrada ha ido bien");
	}
	else if(ferror(stdin))
	{
		printf("La entrada ha ido mal");
		exit(EXIT_FAILURE);

	}
}

