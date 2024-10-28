/*refelejar.c*/

#include <stdio.h>

union byte
{
    unsigned char byte;
    struct 
    {
        unsigned char b0 :1;
        unsigned char b1 :1;
        unsigned char b2 :1;
        unsigned char b3 :1;
        unsigned char b4 :1;
        unsigned char b5 :1;
        unsigned char b6 :1;
        unsigned char b7 :1;
    }bits;
    
};

void presentar(unsigned char c);
unsigned char ReflejarByte(union byte b);

int main(void)
{
    union byte b;
    printf("Introducir un carácter: ");
    b.byte =getchar();
    presentar(b.byte);
    b.byte=ReflejarByte(b);
    printf("Carácter reflejado: %c\n",b.byte);
    presentar(b.byte);
}

void presentar(unsigned char c)
{
    printf("El valor ASCII de %c es %Xh; en binario: ",c,c);
    for (int i = 7; i >=0; i--) // ver en binario
        printf("%d",(c & (1<<i) ? 1 :0));
    printf("\n");    
}

unsigned char ReflejarByte(union byte b)
{
    union byte c;
    
    c.bits.b0= b.bits.b7;
    c.bits.b1= b.bits.b6;
    c.bits.b2= b.bits.b5;
    c.bits.b3= b.bits.b4;
    c.bits.b4= b.bits.b3;
    c.bits.b5= b.bits.b2;
    c.bits.b6= b.bits.b1;
    c.bits.b7= b.bits.b0;

    return (c.byte);
}