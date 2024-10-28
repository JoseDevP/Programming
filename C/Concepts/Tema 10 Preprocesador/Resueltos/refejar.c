/*
    Realizar un programa que solicite introducir un caracter por el teclado y dé como rewsultado
    el caracter reflejado en binario.

    Introducir un carácter A:
    01000001

    Caracter reflejado: é
    10000010

    La estructura del programa constará de las funciones siguientes:

    a)Una funcion principal main que llamará a un macro RefeljarByte que invierta el orden de 
    los bits (el bit 0 pasará a ser el bit 7, el bit 1 el 6...) y una funcion Visualizar para mostra
    el caracter introducido y el refeljado de la forma expuesta anteriormente(simbolo hexadecimal
    y en binario).

    b)Una macro ReflejarByte:
    #define ReflejarByte(b)
    Esta macro recibirá como paramtreo un byte b y dara como resultado el byte reflejado

    c)Una funcion Visualizar con el prototipo siguiente:
    void Visualizar(unsigned char c);
    Esta funcion recibira como parametro el caracter que se quiere visualizar y los presentara
    simbolicamente en hexadecimal y en binario
*/

#include <stdio.h>

#define ReflejarByte( c )\
           ((((c)&0x01) << 7) | (((c)&0x02) << 5) |\
            (((c)&0x04) << 3) | (((c)&0x08) << 1) |\
            (((c)&0x10) >> 1) | (((c)&0x20) >> 3) |\
            (((c)&0x40) >> 5) | (((c)&0x80) >> 7))

            /*
              01111101    | or bit a bit mientras haya un 1 pone 1

            | 10000000 -7
            | 00000000 -5
            | 00100000 -3
            | 00010000 -1 
            | 00001000 +1 
            | 00000100 +3
            | 00000010 +5 
            | 00000000 +7
            | --------
            | 10111110
            */

void Visualizar(unsigned char c);

int main(void)
{
    unsigned char c;
    
    printf("Introducir un caracter: ");
    c=getchar();
    Visualizar(c);
    c=ReflejarByte(c);
    printf("\nCaracter reflejado: %c\n",c);
    Visualizar(c);
}

void Visualizar(unsigned char c)
{
    for (int i = 7; i >=0; i--)
    {
        printf("%d",(c & (1 << i)) ? 1 :0);
                    /*
                        & and bit a bit mientras haya un 0 pone 0
                        ej 7-> (10101010 & 10000000) -> 10000000 ->True ->printf(1)
                        ej 6-> (10101010 & 01000000) -> 00000000 ->False ->print(0)
                        ...
                        ej 0-> (10101010 & 00000001) -> 00000000 ->False ->print(0)
                    */
    }
    printf("\n");
}
