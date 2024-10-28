/*calculadora.c*/

#include <stdio.h>
#include <stdlib.h>

double sumar(double dato1, double dato2);
double restar(double dato1, double dato2);
double multiplicar(double dato1, double dato2);
double dividir(double dato1, double dato2);
int menu(void);
double ejecutar(double (*pfn)(), double a, double b);

int main(void)
{
    double dato1=0, dato2=0, resultado=0;
    int op=0, nFunciones=4;

    double (**operacion)(double,double)= (double (**)(double,double))malloc(nFunciones*sizeof(double(*)(double,double)));
    operacion[0]=sumar;
    operacion[1]=restar;
    operacion[2]=multiplicar;
    operacion[3]=dividir;

    while (1)
    {
        op=menu();

        if (op != 5)
        {
            printf("Dato 1: "); scanf("%lf",&dato1);
            printf("Dato 2: "); scanf("%lf",&dato2);

            while (getchar() != '\n');
            
            resultado = operacion[op-1](dato1,dato2);

            printf("Resultado: %lf\n",resultado);

            printf("Pulse <Entrar> para continuar:");
            getchar();
            
        }
        else
            break;
    }

    for (int i = 0; i < 4; i++)
    {
        free(operacion[i]);
    }
    free(operacion);
    
}

int menu(void)
{
    int op;
    do
    {
        system("cls");
        printf("\t1.Sumar\n");
        printf("\t2.Restar\n");
        printf("\t3.Multiplicar\n");
        printf("\t4.Dividir\n");
        printf("\t5.Salir\n");
        printf("\tSeleccione la operacion deseada:\n");
        scanf("%d",&op);
    } while (op <1 || op >5);
    return op;
}

double sumar(double dato1, double dato2)
{
    return dato1+dato2;
}

double restar(double dato1, double dato2)
{
    return dato1-dato2;
}

double multiplicar(double dato1, double dato2)
{
    return dato1*dato2;
}

double dividir(double dato1, double dato2)
{
    return dato1/dato2;
}