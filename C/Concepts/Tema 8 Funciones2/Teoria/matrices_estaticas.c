/*matrices estaticas*/

#include <stdio.h>
#define FILA 50
#define COL 80

void copiarMatriz(float (*uno)[80],float (*dos)[80])
{
    for (int fil = 0; fil < FILA; fil++)
    {
        for (int col = 0; col < COL; col++)
        {
            uno[fil][col]=dos[fil][col];
        }
    }
    
}   

void copiarMatriz2(float *uno,float *dos)
{
    for (int fil = 0; fil < FILA; fil++)
    {
        for (int col = 0; col < COL; col++)
        {
            *(uno+(fil*COL)+col)=*(dos+(fil*COL)+col);
        }
    }
    
}  

int main(void)
{
    float a[50][80]={1};
    float b[50][80]={0};

}

