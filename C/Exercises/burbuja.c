/*Ordenación mediante el metodo de la burbuja*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar_n(double m[], int n_elementos)
{
    double aux;
    int s=1;
    while (s && (--n_elementos > 0))
    {
        s=0; 
        for (int i = 1; i <=n_elementos; i++)
        {
            if(m[i-1] > m[i])
            {
                aux=m[i-1];
                m[i-1]=m[i];
                m[i]=aux;
                s=1;
            }
        }
    }
    
}

void ordenar_a(char *m[], int n_elementos)
{
    char *aux;
    int s=1;

    while (s && (--n_elementos >0))
    {
        s=0;
        for (int i = 1; i <= n_elementos; i++)
        {
            if(strcmp(m[i-1],m[i])>0)
            {
                aux=m[i-1];
                m[i-1]=m[i];
                m[i]=aux;
                s=1;
            }
        }
        
    }
    
}

int main(void)
{
    int n_elementos=5;

    double m[]={3,2,1,5,4};

    char *s[]={"ccc","bbb","aaa","eee","ddd"};
    ordenar_n(m,n_elementos);
    for (int i = 0; i < n_elementos; i++)
        printf("%g",m[i]);
    printf("\n");
    ordenar_a(s,n_elementos);
    for (int i = 0; i < n_elementos; i++)
        printf("%s",s[i]);
    printf("\n");

    //peor caso-> (n-1)+n(n-2)...+2+1  (en la penultima pasada solo dos compraciones y 
    //ultima solo 1 comparacion)
    /*

        S= (k/2) * (a+l) (s es la suma, a primer termino,l el ultimo y k numero total terminos)

        formula matematica-> ((n-1)*n)/2

        (n−1) es el número de comparaciones en la primera pasada.
        (n−2) es el número de comparaciones en la segunda pasada.
        La suma total de estas comparaciones puede ser simplificada a ((n-1)*n)/2

        tambien otra forma es (n^2-n)/2
    */

   //caso mediano -> 3(n^2-n)/4
   //caso más favorable intercambios = 0
}