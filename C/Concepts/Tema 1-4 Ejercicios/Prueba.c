/******************Simulacion de una calculadora******************/
#include <stdio.h>
#include <stdbool.h>

double sumar(double dato1, double dato2);
double restar(double dato1, double dato2);
double multiplicar(double dato1, double dato2);
double dividir(double dato1, double dato2);
int menu(void);

int main(void)
{
	double dato1 = 0, dato2 = 0, resultado = 0;
	int operacion = 0;

	while (true)
	{
		operacion = menu();
		if (operacion != 5)
		{
			//Leer datos
			printf("Dato 1:"); scanf("%lf", &dato1);
			printf("Dato 2:"); scanf("%lf", &dato2);
			//Limpiar buffer
			while (getchar() != '\n');

			//Realizar la operacion
			switch (operacion)
			{
			case 1:
				resultado = sumar(dato1, dato2);
				break;
			case 2:
				resultado = restar(dato1, dato2);
				break;
			case 3:
				resultado = multiplicar(dato1, dato2);
				break;
			case 4:
				resultado = dividir(dato1, dato2);
				break;
			default:
				break;
			}
			printf("Resultado = %g\n", resultado);
			printf("Pulse entrar para continuar");
			getchar();
		}
		else
		{
			break;
		}
	}
}


int menu(void)
{
	int op;
	do //Lo hace la primera vez tambien
	{
		system("cls"); // en linux clear
		printf("\t1. sumar\n");
		printf("\t2. restar\n");
		printf("\t3. multiplicar\n");
		printf("\t4. dividir\n");
		printf("\t5. salir\n");
		printf("\nSeleccione la operacion deseada:");
		scanf("%d", &op);
	} 
	while (op < 1 || op>5);
	return op;

}

double sumar(double a, double b)
{
	double c;
	c = a + b;
	return(c);
}

double restar(double a, double b)
{
	double c;
	c = a - b;
	return(c);
}

double multiplicar(double a, double b)
{
	double c;
	c = a * b;
	return(c);
}

double dividir(double a, double b)
{
	double c;
	c = a / b;
	return(c);
}