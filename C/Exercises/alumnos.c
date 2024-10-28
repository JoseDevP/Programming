/*
    a)Almacene en una matriz el número de matrícula, apellidos, nombre y direccion de cada
    uno de los alumnos de un determinado curso, La estructura de cada uno de los elementos 
    de la matriz sera del tipo: 

    typedef struct
    {
        char matricula[10];
        char apellidos[30];
        char nombre[20];
        char direccion[30];
    }ficha;

    b) Lea las fichas correspondientes a los alumnos. Para esto escribiremmos una funcion
    con el prototipo:

        void leer(ficha *, int *, const int);

    El primer parametrp representa el puntero que recibirá la dirección de comienzo 
    de la matriz, el segundo parametro es el número actual de alumnos almacenados en la
    matriz y el tercer parámetro es el una constante entera que indicará el número 
    máximo de elementos de la matriz. La funcion leer no devuelve nada.

    c)Busque la ficha correspondiente a un alumno por su numero de matricula o por sus 
    apellidos. Para ello, escribiremos una funcion prototipo:

        void buscar(ficha *, char *, int, int);

    El primer parametro representa a un puntero que recibira la direccion de comienzo 
    de la matriz, el segundo parametro es un puntero a la cadena de caracteres que se
    desea buscar (matricula o nombre), el tercer parametro es el numero de alumnos 
    almacenados en la matris por la función leer y el cuarto parametro es un entero
    que especifica que opcion del menu se ha elegido. (buscar por matricula o apellidos)

    d)La operacion a realizar es decir, leer los datos para los elementos de la matriz,
    buscar por el numero de matricula, buscar or apellido y finalizar, será elegida de un 
    menu visualizado por una funcion con el siguietne prototipo:

        int menu(void);
    
    La funcion menu devuelve como resultado la opcion elegida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXALUM 10



typedef struct
{
    char matricula[10];
    char apellidos[30];
    char nombre[20];
    char direccion[30];
}s_ficha;

void leer(s_ficha *ficha, int nAlumnos);
char *readString(char *str, int l);
void buscar(s_ficha *, char *, int, int);
int menu(void);

int main(void)
{
    s_ficha *ficha=NULL; 
    int correcto=0, nAlumnos=0;
    int opcion=0;

    void (*funcion_a_realizar[3])()={leer,buscar,buscar};    

    do
    {
        opcion=menu();

        if(opcion==1)
        {
            do
            {
                printf("Introduce el numero de alumnos:  ");
                correcto=scanf("%d",&nAlumnos);
                while(getchar() != '\n');
            } while (!correcto || nAlumnos<0 || nAlumnos > MAXALUM);

            if(ficha==NULL)
            {
                if((ficha=(s_ficha *)malloc(nAlumnos*sizeof(s_ficha))) == NULL)
                {
                    printf("Ha habido un error al signar un espacio para la ficha");
                    exit(0);
                }
            }
            else
            {
                if((ficha=realloc(ficha,nAlumnos*sizeof(s_ficha))) == NULL)
                {
                    printf("Ha habido un error al signar un espacio para la ficha");
                    exit(0);
                }
            }
            

            funcion_a_realizar[opcion-1](ficha,nAlumnos);

        }

        else if(opcion==2)
        {
            if(ficha!=NULL)
            {
                char matricula[10];
                do
                {
                    printf("Introduce la matricula:  ");
                } while (readString(matricula,10) == NULL);
              
                funcion_a_realizar[opcion-1](ficha, matricula, nAlumnos, 'm');
            }
            else
            {
                printf("No hay ningun alumno.\n\n");

            }
        }
        else if(opcion==3)
        {
            if(ficha!=NULL)
            {
                char apellidos[30];
                do
                {
                    printf("Introduce los apellidos:  ");
                } while (readString(apellidos,30) == NULL);
              
                funcion_a_realizar[opcion-1](ficha, apellidos, nAlumnos, 'a');
            }
            else
            {
                printf("No hay ningun alumno.\n\n");

            }
        }

    } while (opcion !=4);
    

    
    
    

}

void leer(s_ficha *ficha, int nAlumnos)
{
    

    for (int i = 0; i < nAlumnos; i++)
    {
        char nombre[20];
        do
        {
            printf("Introduce el nombre del alumno %d:  ",i+1);
        } while (readString(nombre,20) == NULL);

        strcpy(ficha[i].nombre, nombre);
        
        char apellidos[30];
        do
        {
            printf("Introduce los apellidos del alumno %d:  ",i+1);
        } while (readString(apellidos,30) == NULL);
        
        strcpy(ficha[i].apellidos, apellidos);

        char direccion[30];
        do
        {
            printf("Introduce la direccion del alumno %d:  ",i+1);
        } while (readString(direccion,30) == NULL);
        
        strcpy(ficha[i].direccion, direccion);

        char matricula[10];
        do
        {
            printf("Introduce la matricula del alumno %d:  ",i+1);
        } while (readString(matricula,10) == NULL);
        
        strcpy(ficha[i].matricula, matricula);

    }
    
}

char *readString(char *str, int l)
{
    char *fin, *c;
    fin=fgets(str, l, stdin);
    if (c=strchr(str,'\n'))
        *c='\0';
    else if(!ferror(stdin))
        while ((getchar() != '\n'))
    return fin;
    
}

void buscar(s_ficha *ficha, char * cad_a_buscar, int nAlumnos, int matricula_o_apellidos)
{
    int encontrado=0;
    for (int i = 0; i < nAlumnos; i++)
    {
        if ((matricula_o_apellidos == 'm') && ((strcmp(ficha[i].matricula, cad_a_buscar)) == 0))
        {
            encontrado=1;
        }
        else if ((matricula_o_apellidos == 'a') && ((strcmp(ficha[i].apellidos, cad_a_buscar)) == 0))
        {
            encontrado=1;
        }

        if(encontrado==1)
        {
            printf("Nombre: %s\n",ficha[i].nombre);
            printf("Apellidos: %s\n",ficha[i].apellidos);
            printf("Dirección: %s\n",ficha[i].direccion);
            printf("Matricula: %s\n",ficha[i].matricula);

            break;
        }
    }
    if(encontrado==0)
    {
        printf("No se ha encontrado");
    }
    
}

int menu(void)
{
    int opcion=0;
    do
    {
        printf("Menu de opciones:\n");
        printf("1-> Leer Alumnos:\n");
        printf("2-> Buscar por Matricula:\n");
        printf("3-> Buscar por Apellidos:\n");
        printf("4-> Salir\n");
        scanf("%d",&opcion);
        while(getchar() != '\n');
    } while (opcion<1 || opcion >4);
    system("cls");
    return opcion;
}