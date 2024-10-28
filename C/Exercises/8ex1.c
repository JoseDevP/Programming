/*
    Realizar un programa que:
    a)Lea dos cadenas de caracteres denominadas cadena1 y cadena2 y un numero 
    entero n;
    b)Llame a una funcion:
        int compcads(cadena1, cadena2, n);
    que compare los n primeros caracteres de cadena1 y cadena2 y devuelva como resultado
    un valor entero (no usan strcmp):

    0 si cadena1 y cadena2 son iguales
    1 si cadena1 es mayor que cadena2
    -1 si cadena1 es menor que cadena2

    si n es menor que 1 o mayor que la longitud de la menor de las cadena, la
    comparacion se hará sin tener en cuenta este parametro

    c)Escriba la cadena que sea menor según los n primeros caracteres (esto es,
    la que este antes por orden alfabetico);
*/

#include <stdio.h>
#include <string.h>

int compcads(char *cadena1, char *cadena2,int n);

char *readString(char *str, int n)
{
    char *fin,*c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if(!ferror(stdin))
        while(getchar() != '\n');
    return fin;
}

int main(void)
{
    char cadena1[50], cadena2[50];
    int n=0;

    do
    {
        printf("Escribe la cadena 1:\n");
    } while ((readString(cadena1,50))==NULL);
    
    do
    {
        printf("Escribe la cadena 2:\n");
    } while ((readString(cadena2,50))==NULL);
    
    int correcto=0;

    do
    {
        printf("Escribe el numero hasta donde llegará la comparación:\n");
        correcto=scanf("%d",&n);
    } while (!correcto);

    int comparacion=compcads(cadena1,cadena2,n);
    
    if(comparacion==0)
    {
        printf("Son iguales\n");
    }
    else if(comparacion>0)
    {
        printf("La primera cadena es mayor que la cadena 2\n");
    }
    else if(comparacion<0)
    {
        printf("La primera cadena es menor que la cadena 2\n");
    }
}

int compcads(char *cadena1, char *cadena2,int n)
{
    int MAXLONG;

    MAXLONG=(strlen(cadena1) > strlen(cadena2)) ? strlen(cadena1):strlen(cadena2);

    int pc1=0, pc2=0;
    int fila;

    if(n < 1 || n > MAXLONG)
        fila=MAXLONG;
    else
        fila=n;

    for (int i = 0; i < fila; i++)
    {
        if(cadena1[i] == cadena2[i])
        {
            pc1++;
            pc2++;
        }
        else if(cadena1[i] > cadena2[i])
        {
            pc2++;
        }
        else if(cadena1[i] < cadena2[i])
        {
            pc1++;
        }
    }

    if(pc1 == pc2)
        return 0;
    else if(pc1 > pc2)
        return -1;
    else if(pc1 < pc2)
        return 1;
    
}