/*memset memcpy memcmp*/
#include <stdio.h>
#include <string.h>
#define FILAS 3
#define COLS 3

int main(void)
{
    float a[FILAS][COLS],c[FILAS][COLS];
    int fila=0,col=0;
    

    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));

    for (fila = 0; fila < FILAS; fila++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("a[%d][%d]=",fila,col);
            scanf("%f",&a[fila][col]);
        }
        
    }

    memcpy(c,a,sizeof(a));

    if (memcmp(a,c,sizeof(a))==0)
        puts("Las matrices a y c contienen los mismos datos\n");
    else
        puts("Las matrices a y c no contienen los mismos datos\n");

    for (fila = 0; fila < FILAS; fila++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("%10g",c[fila][col]);
        }
        
    }
    


}