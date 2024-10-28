#define MAX 10

typedef struct
{
    float r; //parte real de numero complejo
    float i;//parte imaginaria
}tcomplejo;

typedef struct
{   
    int filas;   //Filas matriz
    int columnas;//Columnas matriz
    tcomplejo c[MAX][MAX];
}tmatriz;

tmatriz LeerMatriz();
void VisualizarMatriz(tmatriz m);
tmatriz sumarMatrices(tmatriz a, tmatriz b);