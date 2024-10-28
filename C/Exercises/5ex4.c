/*
    Hacer
                    1 
                  2 3 2
                3 4 5 4 3
              4 5 6 7 6 5 4
            5 6 7 8 9 8 7 6 5
          6 7 8 9 0 1 2 3 4 5 6
        7 8 9 0 1 2 3 2 1 0 9 8 7
      8 9 0 1 2 3 4 5 4 3 2 1 0 9 8 
    9 0 1 2 3 4 5 6 7 6 5 4 3 2 1 0 9

    nfilas 11-20
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Para srand y rand
#include <time.h>   // Para time

int getFirstNum(int i)
{
    int count=9;
    int number;
    while (true)
    {
        if(i<=count)
        {
            number=i-(count-9);
            break;
        }
        count+=9;
    }
    return number;
}

int main(void)
{
    srand((unsigned)time(NULL));

    int numero_filas=11+rand()%50;
    int numero_espacios=numero_filas-1;
    int numeros_por_filas=1;

    for (int i = 1; i < numero_filas+1; i++)
    {
        for (int j = 0; j < numero_espacios; j++)
        {
            printf(" ");
        }

        int fila_number=getFirstNum(i);
        int medio=(numeros_por_filas/2);
        for (int k = 1; k < numeros_por_filas+1; k++)
        {
            
            if(fila_number<0)
            {
                fila_number=9;
            }
            if(fila_number>9)
            {
                fila_number=0;
            }
            printf("%d",fila_number);
            if(k>medio)
            {
                fila_number--;
            }
            else
            {                
                fila_number++;
            }
            
        }
        numeros_por_filas+=2;
        
        for (int l = 0; l < numero_espacios; l++)
        {
            printf(" ");
        }
        printf("\n");
        
        numero_espacios--;
    }
    
}
