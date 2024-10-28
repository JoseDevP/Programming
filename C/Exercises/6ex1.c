/*
    Bistograma con los pesos de los alumnos de determinado curso

    Peso      Número de alumnos
    ---------------------------
    21        **   
    22        ****
    23        ***********
    24        ***** 
    ...       ...

    numero de asteriscos se corresponde con el número de alumnos del peso especificado

    Realiza un programa que lea los pesos e imprima el histograma correspondiente.
    Suponer que los pesos están comprendidos entre los valores 10 y 100kg. En el
    histograma solo aparecerán los pesos que se corresponde con uno o más alumnso.
*/

#include <stdio.h>
#define MAX_ALUMNOS 100

int main(void)
{
    int nAlumnos=0;
    printf("Pesos de alumnos:\n\n");

    printf("¿Cuantos alumnos hay?\n");
    scanf("%d",&nAlumnos);

    int pesos[nAlumnos];
    char numero_repeticiones[nAlumnos][100];
    int i=0;
    do
    {
        do
        {
            printf("Introduce el peso de el alumno %d: ",i+1);
            scanf("%d",&pesos[i]);
            while(getchar() != '\n');
        } while (pesos[i]<10 || pesos[i]>100);
        i++;

    } while ( i<nAlumnos);

    
    for (int i = 0; i < nAlumnos; i++)
    {
        int nRep=0;
        numero_repeticiones[i][0]='*';
        nRep++;
        for (int j = i+1; j < nAlumnos; j++)
        {
            if((pesos[i]==pesos[j]) && (pesos[i]!=0))
            {
                numero_repeticiones[i][nRep++]='*';
                printf("%d %d",pesos[i],pesos[j]);
                pesos[j]=0;
            }
        }
    }
    printf("\n\n");
    
    printf("Peso      Número de alumnos\n");
    printf("---------------------------\n");
    for (int i = 0; i < nAlumnos; i++)
    {
        if(pesos[i]!=0)
        {
            printf("%d       %s\n",pesos[i],numero_repeticiones[i]);

        }
    }
    

}