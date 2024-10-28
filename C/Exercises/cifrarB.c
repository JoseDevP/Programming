#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ReflejarByte(c)\
        ( ( ((c)&0x01) << 7) | ( ((c)&0x02) << 5) |\
          ( ((c)&0x04) << 3) | ( ((c)&0x08) << 1) |\
          ( ((c)&0x10) >> 1) | ( ((c)&0x20) >> 3) |\
          ( ((c)&0x40) >> 5) | ( ((c)&0x80) >> 7) )

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
    unsigned char resultado=byte ^ clave;
    resultado=ReflejarByte(resultado);
    return ~resultado;

}


unsigned char descifrar(unsigned char byte, unsigned char clave) 
{
    unsigned char resultado=~byte;
    resultado=ReflejarByte(resultado);
    return resultado^clave;
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