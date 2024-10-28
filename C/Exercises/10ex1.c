/*
    Elegir un programa cualquiera de los realizados hasta ahora y añadir el codigo que supuestamente
    se necesitaria para visualizar resultados intermedios en un proceso de depuracion de dicho
    programa.

    El programa se invocara desde la linea de ordenes asi:

    nombre_programa /DDEBUG

    Por ejemplo la siguietne funcion incluye codigo de depuracion que solo se incluira en el caso
    de que al compilar el programa se especifique la constante simbolica DEBUG.

    void Visualizar(unsigned char c)
    {
        int=0;
        for(int i=7; i>=0; i++)
        {  
            #if defined(DEBUG)
                printf("\ni = %d ",i);
            #endif

            printf("%d", (c & (1 << i)) ? i : 0);
        }
        printf("\n");
    }
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

#define ReflejarByte(c)\
        ( ( ((c)&0x01) << 7) | ( ((c)&0x02) << 5) |\
          ( ((c)&0x04) << 3) | ( ((c)&0x08) << 1) |\
          ( ((c)&0x10) >> 1) | ( ((c)&0x20) >> 3) |\
          ( ((c)&0x40) >> 5) | ( ((c)&0x80) >> 7) )

void Visualizar(unsigned char c)
{
    for(int i=7; i>=0; i--)
    {  
        #if defined(DEBUG)
            printf("\ni = %d ",i);
        #endif
        printf("%d", (c & (1 << i)) ? i : 0);
    }
    printf("\n");
}

int numeroEsValido(char *str,unsigned char *valor)
{
    if (str == NULL || valor == NULL) {
        return 0; 
    }

    char *endptr;
    long num=strtol(str,&endptr,10);//base 10 decimal
    if(*endptr!='\0' || endptr==str || num<0 || num > 255)
        return 0;

    *valor=(unsigned char) num;
    return 1;
}

unsigned char cifrar(unsigned char byte, unsigned char clave) 
{
    unsigned char resultado = byte ^ clave;
    
    #if defined(DEBUG)
        printf("Valor original: ");
        Visualizar(byte);
        printf("Clave: ");
        Visualizar(clave);
        printf("Resultado XOR: ");
        Visualizar(resultado);
    #endif

    resultado = ReflejarByte(resultado);
    
    #if defined(DEBUG)
        printf("Resultado después de reflejar: ");
        Visualizar(resultado);
    #endif

    return ~resultado;
}


unsigned char descifrar(unsigned char byte, unsigned char clave) 
{
    unsigned char resultado = ~byte;
    
    #if defined(DEBUG)
        printf("Valor cifrado: ");
        Visualizar(byte);
        printf("Clave: ");
        Visualizar(clave);
        printf("Resultado después de invertir: ");
        Visualizar(resultado);
    #endif

    resultado = ReflejarByte(resultado);
    
    #if defined(DEBUG)
        printf("Resultado después de reflejar: ");
        Visualizar(resultado);
    #endif

    return resultado ^ clave;
}

    
int main(int argc, char *argv[])
{
    unsigned char clave;


    if(argc != 3)
    {
        printf("Sintaxis cifrar -c clave\n");
        exit(0);
    }
    if( ((strcmp(argv[1],"-c"))==0) && numeroEsValido(argv[2],&clave) )
    {
        char op;

        do
        {
            printf("Quieres cifrar o descifrar ( c / d ):  ");
            op=getchar();
            while (getchar() != '\n');
        } while (op != 'c' && op != 'd');

        int c;
        while ((c=getchar()) != EOF)
        {
            if(op=='c')
                putchar(cifrar((unsigned char)c, clave));
            else
                putchar(descifrar((unsigned char)c, clave));
        }
        
    }
    else
    {
        printf("La clave deber ser un numero valido entre 0 y 255\n");
        exit(0);
    }
}