/*args*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int nA, char *args[]) //nombre, arg1,arg2...
{
    if(nA==1)
    {
        printf("Bienvenido al Programa de Prueba\n");
    }
    else
    {
        bool arg_a=false, arg_b=false, arg_c=false;

        for (int i = 1; i < nA; i++)
        {
            if(strcmp(args[i],"-a")==0) arg_a=true;
            if(strcmp(args[i],"-b")==0) arg_b=true;
            if(strcmp(args[i],"-c")==0) arg_c=true;
        }

        if(arg_a)
        {
            printf("Argumento a seleccionado\n");
        }
        if(arg_b)
        {
            printf("Argumento b seleccionado\n");
        }
        if(arg_c)
        {
            printf("Argumento c seleccionado\n");
        }
    }
}