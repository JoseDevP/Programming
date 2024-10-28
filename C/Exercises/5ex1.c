/*Calcule e imprima la suma de los multiples de 5 comprendido entre los 
valores a y b. 
El programa no permitira introducir valores negativos para a y b
y verificara que a < b. Si es mayor que b intercambiara los valores*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verifyNumber(int *a, int *b)
{
	if(*a < 0 || *b < 0)
	{
		return false;
	}
	else
	{
		if(*a>*b)
		{
			int temp=*a;
			*a=*b;
			*b=temp;
		}
		return true;
	}
	
}

int sumaMultiples(int a, int b)
{	
	int resultado=0;
	for (int i = a; i < b; i++)
	{
		if(i%5==0)
		{
			resultado+=i;
		}
	}
	return resultado;
}


int main(void)
{
	int a;
	int b;
	int resultado;
	while (true)
	{
		printf("Introduce el número 1: ");
        if (scanf("%d", &a) != 1)
        {
            while (getchar() != '\n');
            printf("Entrada no válida. Por favor, introduce un número entero.\n");
            continue;
        }

        printf("Introduce el número 2: ");
        if (scanf("%d", &b) != 1)
        {
            while (getchar() != '\n');
            printf("Entrada no válida. Por favor, introduce un número entero.\n");
            continue;
        }

		
		if(verifyNumber(&a,&b))
		{
			break;
		}
	}
	printf("a es %d\n",a);
	printf("b es %d\n",b);

	resultado=sumaMultiples(a,b);
	printf("La suma de los multiples entre %d y %d es %d",a,b,resultado);
}

