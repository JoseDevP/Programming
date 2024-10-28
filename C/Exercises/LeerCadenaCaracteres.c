#include <stdio.h>
#include <stdlib.h>
#define LF 10

void fflushstdin(void);
void VerifyEOF(void);


int main(void)
{
	//FORMA 1
	//char nombre[80] = { 0 };
	//int i = 0;
	//printf("Nombre:");
	//nombre[i] = getchar();
	//while (nombre[i] != LF)
	//{
	//	i++;
	//	nombre[i] = getchar();
	//
	//}
	//nombre[i] = '\0';
	//printf("%s", nombre);
	//
	//FORMA 2
	//char nombre2[80] = { 0 };
	//printf("Nombre:");
	//scanf("%s", nombre2);
	//printf("%s", nombre2);
	//esto por ejemplo si hay dos palabras solo lee una

	//FORMA3	
	char nombre3[80] = { 0 };
	printf("Nombre:");
	scanf("%[^\n]", nombre3);
	printf("%s", nombre3);
}


