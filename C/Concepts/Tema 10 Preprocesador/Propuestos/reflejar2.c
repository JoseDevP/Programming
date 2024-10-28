#include <stdio.h>

 void Visualizar(unsigned char c);
 
#define ReflejarByte(c) \
        ( (((c)&0x01) << 7) | (((c)&0x02) << 5) |\
          (((c)&0x04) << 3) | (((c)&0x08) << 1) |\
          (((c)&0x10) >> 1) | (((c)&0x20) >> 3) |\
          (((c)&0x40) >> 5) | (((c)&0x80) >> 7) )
          

 int main(void)
 {
    unsigned char c;
    printf("Indique el caracter a reflejar:  ");
    c=getchar();
    Visualizar(c);

    c=ReflejarByte(c);
    printf("Caracter reflejado: %c\n",c);
    Visualizar(c);

 }

 void Visualizar(unsigned char c)
 {
    for (int i = 7; i >=0; i--)
    {
        printf("%d",((c & 1<<i)) ? 1 : 0);
    }
    printf("\n");
 }