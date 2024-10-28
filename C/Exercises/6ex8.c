/*
    Visualizar representación interna de un valor float
    Ej:10**-5
    real=1100 0001 0010 1000 0000 0000 0000 0000
    valor viene daddo por (-1)**5 * 1.M *2 **E-127

    Sign: 1............................... S = 1
    Exponente:100 0001 0.................. E = 3
    Mantisa:010 1000 0000 0000 0000 0000.. M=0.3125
*/

#include <stdio.h>

struct sf1
{
    unsigned b0: 1;
    unsigned b1: 1;
    unsigned b2: 1;
    unsigned b3: 1;
    unsigned b4: 1;
    unsigned b5: 1;
    unsigned b6: 1;
    unsigned b7: 1;
    unsigned b8: 1;
    unsigned b9: 1;
    unsigned b10: 1;
    unsigned b11: 1;
    unsigned b12: 1;
    unsigned b13: 1;
    unsigned b14: 1;
    unsigned b15: 1;
    unsigned b16: 1;
    unsigned b17: 1;
    unsigned b18: 1;
    unsigned b19: 1;
    unsigned b20: 1;
    unsigned b21: 1;
    unsigned b22: 1;
    unsigned b23: 1;
    unsigned b24: 1;
    unsigned b25: 1;
    unsigned b26: 1;
    unsigned b27: 1;
    unsigned b28: 1;
    unsigned b29: 1;
    unsigned b30: 1;
    unsigned b31: 1;
};

union uf1
{
    float x;
    struct  sf1 s;
    
};

int main(void)
{
    union uf1 real;
    
    real.x=-10.5F;
    printf("real = ");
    printf("%d",real.s.b31);
    printf("%d",real.s.b30);
    printf("%d",real.s.b29);
    printf("%d",real.s.b28);
    printf("%d",real.s.b27);
    printf("%d",real.s.b26);
    printf("%d",real.s.b25);
    printf("%d",real.s.b24);
    printf("%d",real.s.b23);
    printf("%d",real.s.b22);
    printf("%d",real.s.b21);
    printf("%d",real.s.b20);
    printf("%d",real.s.b19);
    printf("%d",real.s.b18);
    printf("%d",real.s.b17);
    printf("%d",real.s.b16);
    printf("%d",real.s.b15);
    printf("%d",real.s.b14);
    printf("%d",real.s.b13);
    printf("%d",real.s.b12);
    printf("%d",real.s.b11);
    printf("%d",real.s.b10);
    printf("%d",real.s.b9);
    printf("%d",real.s.b8);
    printf("%d",real.s.b7);
    printf("%d",real.s.b6);
    printf("%d",real.s.b5);
    printf("%d",real.s.b4);
    printf("%d",real.s.b3);
    printf("%d",real.s.b2);
    printf("%d",real.s.b1);
    printf("%d",real.s.b0);
    
}
