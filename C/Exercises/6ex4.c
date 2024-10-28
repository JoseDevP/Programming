/*
    La mediana de una lista de n numeros se define como el valor que es menor o 
    igual que los valores correspondientes a la mitad de los numeros, y mayor o igual
    que los valores correspondientes a la otra mitad

    Ej:
        16 12 99 95 18 87 10
        es 18, porque este valor es menor de 99,85,87(mitad de los numero),y mayor que 
        16,12,10(otra mitad)

    Realiza un programa que lea un numero impar de valores y dé como resultado la mediana.
    Entrada de valroes finaliza cuando EOF
*/
#include <stdio.h>
#define MAX 100

void verValores(int *,int);
int mediana(int *,int);

int main(void)
{
    int cantidad=0;

    int i=0;
    int f=0;
    printf("Introduce una cantidad de numeros impar:");
    while (cantidad<=0 || (cantidad%2)==0)
    {
        scanf("%d",&cantidad);
        if((cantidad%2)==0)
        {
           puts("Tiene que ser impar"); 
        }
    }
    while(getchar()!='\n');

    f=0;
    int valores[cantidad];
    
    do
    {
        printf("Introduce el valor %d: \n",i+1);
        while ((f=scanf("%d",&valores[i]))==0);
        while(getchar()!='\n');
        i++;
        
    } while (!feof || i<cantidad);

    verValores(valores,cantidad);
    printf("\n\n");
    int m=mediana(valores,cantidad);
    printf("\n\n");
    printf("La mediana es %d",m);
}


void verValores(int *val,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",val[i]);
    }
    
}

int mediana(int *val,int n)
{
    int temp=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (val[j] > val[j + 1])
            {
                temp = val[j];
                val[j] = val[j + 1];
                val[j + 1] = temp;
            }
        }
    }
    verValores(val,n);
    return (val[n/2]);
}