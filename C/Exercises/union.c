/*Union hace que todos los miembros compartan un unico espacio de memoria*/
#include <stdio.h>

typedef union 
{
    float a;
    int b;
}tunion;

int main(void)
{
    tunion var1;

    var1.a=10.5;

    printf("%g\n",var1.a);
    printf("%d\n",var1.b);
}