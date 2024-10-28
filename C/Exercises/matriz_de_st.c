/* Matriz de structs*/
#include <stdio.h>
#include <string.h>

#define NA 100  

char* readString(char*,int);

typedef struct 
{
    char nombre[60];
    float nota;
}tficha;


int main (void)
{
    static tficha alumno[NA];
    int n=0;
    
    char *fin=NULL;
    int aprobados=0, suspendidos=0;

    printf("Introducir datos. ");
    printf("Para finalizar teclear la marca de EOF\n\n");

    printf("Nombre: ");
    fin=readString(alumno[n].nombre,sizeof(alumno[n].nombre));
    while (fin != NULL)
    {
        printf("Nota: ");
        scanf("%f",&alumno[n++].nota);
        while(getchar() != '\n');
        if(n==NA) break;

        printf("Nombre: ");
        fin=readString(alumno[n].nombre,sizeof(alumno[n].nota));
    }
    
    for (int i = 0; i < n; i++)
    {
        if(alumno[i].nota >= 5)       
            aprobados++;
        else 
            suspendidos++;
        
    }

    printf("Alumnos aprobados %.4g%%\n Alumnos suspendidos %.4g%%",(float)aprobados/n*100,(float)suspendidos/n*100);
    

}

char* readString(char* str,int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c=0;
    else if(!feof(stdin))
        while(getchar() != '\n');
    return fin;
}
