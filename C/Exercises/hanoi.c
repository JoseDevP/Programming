/*hanoi.c*/
#include <stdio.h>
typedef struct hanoi
{
    int n_discos;
    char inicial;
    char auxiliar;
    char objetivo;
}hanoi;

typedef struct s
{
    hanoi estado;
    struct s *siguiente;
}Node;

int mover(int, char, char, char);
int mover_NR(int , char , char ,char );
void meter_en_pila(Node **p, int n_discos ,char inicial, char auxiliar, char objetivo);
void sacar_de_pila(Node **p, int *n_discos, char *inicial, char *auxiliar, char *objetivo);
Node *NuevoElemento();


int main(void)
{
    int n_discos, movimientos;

    printf("Numero de discos: ");
    scanf("%d",&n_discos);
    movimientos=mover(n_discos, 'A','B','C');
    printf("\nHanoi Recursivo: movimientos efectuados: %d\n",movimientos);
    movimientos=mover_NR(n_discos, 'A','B','C');
    printf("\nHanoi No Recursivo: movimientos efectuados: %d\n",movimientos);

}

int mover(int n_discos, char inicial, char auxiliar, char objetivo)
{
    static int movimientos = 0;

    if(n_discos > 0)
    {
        mover(n_discos-1,inicial,objetivo,auxiliar); //mover los n-1 discos a auxiliar 
        printf("mover disco de %c a %c\n",inicial,objetivo);//mover disco final a objetivo
        movimientos++;
        mover(n_discos-1,auxiliar,inicial,objetivo);//mover discos n -1 del auxiliar al objetivo
    }
    return movimientos;
}

int mover_NR(int n_discos, char inicial, char auxiliar, char objetivo) {
    Node *hanoi = NULL;
    int movimientos = 0;
    
    meter_en_pila(&hanoi, n_discos, inicial, auxiliar, objetivo);

    while (hanoi) {
        int discos;
        char ini, aux, obj;
        
        sacar_de_pila(&hanoi, &discos, &ini, &aux, &obj);

        if (discos > 0)
        {
            meter_en_pila(&hanoi, discos - 1, aux, ini, obj); 
            printf("Mover disco de %c a %c\n", ini, obj); 
            movimientos++;
            meter_en_pila(&hanoi, discos - 1, aux, ini, obj); 
        }
    }
    
    return movimientos;
}

Node *NuevoElemento()
{
  Node *q = (Node*)malloc(sizeof(Node));
  if (!q) exit(1);
  return (q);
}

void meter_en_pila(Node **p, int n_discos ,char inicial, char auxiliar, char objetivo)
{
  Node *q;

    q = NuevoElemento();
    q->estado.n_discos=n_discos;
    q->estado.inicial=inicial;
    q->estado.auxiliar=auxiliar;
    q->estado.objetivo=objetivo;
    q->siguiente=*p;
    *p = q;
}

void sacar_de_pila(Node **p, int *n_discos, char *inicial, char *auxiliar, char *objetivo)
{
    Node *q = *p; 

    if (q == NULL)
    {
        printf("\nPila vac�a\n");
        exit(2);
     }
    else
    {
        *n_discos = q->estado.n_discos; 
        *inicial= q->estado.inicial;
        *auxiliar= q->estado.auxiliar;
        *objetivo = q->estado.objetivo;
        *p = q->siguiente;
        free(q);
    }
}