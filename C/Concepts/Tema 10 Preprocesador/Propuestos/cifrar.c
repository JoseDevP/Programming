/*
    Escribit un programa que permita cifrar un archivo de texto, de acuerdo con las siguientes 
    especificaciones:

    El programa se invocara desde la linea de comandos asi:

        cifrar -c clave
    donde -c clave indica al programa cual es la clave que se va a emplear para realizar el
    cifrado. La clave será un valor entero entre 0 y 255;

    El texto a cifrar se leera del archivo estandar de entrada y el texto cifrado se visualiozar
    en el archivo estandar de salida.

    El cifrado del texto se relizara byte a byte utilizando el siguietne algortimo:

    Se calculara la OR exclusiva entre los bytes de entrada y la clave.
    Los bytes resultantes de la operacion anterior se reflejaran; esto es el bit 0 pasara a
    ser el bit 7, el bit 1 pasara a ser el bit 6... 
    Los bytes resultantes de la operación anterior seran complementados a 1 y estos seran los bytes
    cifrados.

    Por ejemplo, si el byte de entrada es b=0x9a(10011010) y la clave es 0x49(01001001) el proceso:
    b XOR c:            (10011010) XOR (01001001) = (11010011)
    Reflejar            (11001011)
    Complemento a 1     (00110100)

    El byte cifrado resultante es 0x34.

    Se pide realizar un programa denominado cifrar con las macros y funciones  que se indican 
    a continuacion:

    a)Escribir una macro ReflejarByte:
        #define ReflejarByte(b)
    Esta macro recibira como parametro un byte y dara como resultado el byte reflejado.

    b)Escribir una funcion cifrar de acuerdo con el siguiente prototipo
        unsigned char cifrar(unsigned char byte, unsigned char clave);
    Esta funcion recibe como parametros el byte a cifrar y la clave y devuelve como resultado 
    el byte cifrado

    c)Escribir una funcion descifrar de acuerdo con el siguiente prototipo
        unsigned char descifrar(unsigned char byte, unsigned char clave);
    Esta funcion recibe como parametros el byte cifrado y la clave y devuelve como resultado 
    el byte sin cifrar.

    d)Escribir una funcion main que utilizando las funciones anterirores permita cifrar
    o decifrar un texto

    ¿Como invocaria desde la linea de ordenes del sistema operativo al programa cifrar para 
    redirigir la E/s y trabajar con archivos distintos a los estandar?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ReflejarByte(c)\
         ((((c)&0x01) << 7) | (((c)&0x02) << 5) |\
            (((c)&0x04) << 3) | (((c)&0x08) << 1) |\
            (((c)&0x10) >> 1) | (((c)&0x20) >> 3) |\
            (((c)&0x40) >> 5) | (((c)&0x80) >> 7))

int esNumeroValido(const char *str, unsigned char *valor) {
    char *endptr;
    long num = strtol(str, &endptr, 10);

    if (*endptr != '\0' || endptr == str || num < 0 || num > 255) {
        return 0;
    }

    *valor = (unsigned char)num;
    return 1;
}

unsigned char cifrar(unsigned char byte, unsigned char clave);
unsigned char descifrar(unsigned char byte, unsigned char clave);


int main(int argc, char *argv[])
{
    unsigned char clave;

    if(argc != 3)
    {
        printf("Sintaxis cifrar -c clave\n");
        exit(0);
    }
    else if( (strcmp(argv[1],"-c")) ==0  && esNumeroValido(argv[2],&clave))
    {

        char op;

        do
        {
            printf("Quieres cifrar o descifrar ( c / d ):  ");
            op=getchar();
            while (getchar() != '\n');
        } while (op != 'c' && op != 'd');

        int c;
        while ((c = getchar()) != EOF)
        {
            if (op == 'c') {
                putchar(cifrar((unsigned char)c, clave));
            } else {
                putchar(descifrar((unsigned char)c, clave));
            }
        }
    }
}

unsigned char cifrar(unsigned char byte, unsigned char clave) 
{
    unsigned char resultado = byte ^ clave; // XOR 1 si bits diferente y 0 si son iguales

    resultado = ReflejarByte(resultado); // Reflejar los bits

    return ~resultado; // Invierte los bits(0->1, 1->0)
}

unsigned char descifrar(unsigned char byte, unsigned char clave) 
{
    unsigned char resultado = ~byte; // Deshacer complemento a 1

    resultado = ReflejarByte(resultado); // Reflejar los bits

    return resultado ^ clave; // XOR con la clave para recuperar byte original
}