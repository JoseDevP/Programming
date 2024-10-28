#include <stdio.h>
#include <math.h>

/*Equacion ax'2+bx+c=0*/
//si a=0 y b=0 mensaje ecaucion es degenerada
//si a=0 y b!=0 reiz unica con valor -c/b
//otros casos x1=(-b+-sqrt(b'2-4*a*c)/(2a)

//d =b2-4ac es el discriminante 
//Si d >= 0 dos raices
//menor dos raices complejas forma x+yj, x-yj

int main(void)
{
	double a, b, c;
	double d;
	double re, im;//parte real o imaginaria

	printf("Coeficientes a,b,c de la ecuacion");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("\n");


	if (a == 0 && b == 0)
	{
		printf("La raiz es degenerada\n");

	}
	else if (a == 0)
	{
		printf("La unica raiz es:%.21f\n",-c/b);

	}
	else
	{
		re = -b / (2 * a);
		d = b * b - 4 * a * c;
		im = sqrt(fabs(d)/(2*a));
		if (d >= 0)
		{
			printf("Raices Reales:\n");
			printf("%.2lf %.2lf\n",re+im,re-im);

		}
		else
		{
			printf("Raices Complejas:\n");
			printf("%.2lf + %.2lf j\n", re, fabs(im));
			printf("%.2lf - %.2lf j\n", re, fabs(im));

		}
	}
}