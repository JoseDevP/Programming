/*
    Suponga que disponemos en el disco de dos archivos denominados notas y modify.
    La estructura de cada uno de los regisros para ambos archivos se corresponde a:

        typedef struct
        {
            unsigned char nombre[LONG];
            float nota;
        }alumno;

    Suponga tambien que ambos archivos estan ordenados ascendentemente por el campo nombre;

    En el archivo modify se han grabado las modificaciones que posteriormente realizaremos sobre 
    el archivo notas.En modify hay como máximo un registro por alumno y se corresponde con:

    -Registros que tambien estan en el archivo notas pero que han variado en su campo nota.
    -Registros nuevos; esto es, registros que no estan en el archivo notas.
    -Registros que tambien estan en el archivo notas y que deseamos eliminar. 
    Estos registros se distinguen porque nota vale -1;

    Se pide realizar un program que permitya obtener a partir de los archivos notas y modify 
    un tercer archivo actualizado. El archivo resultante terminara llamandose notas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG 100

typedef struct
{
    unsigned char nombre[LONG];
    float nota;
}alumno;

typedef struct 
{
    FILE *stre;
    int nStudents;
    size_t sizeStruct;
}file;

void initialize(file *mod);
void updateNotas(file mod);
void close(file *f);
alumno readAlumno(int i, file f);
void writeAlumno(int i, alumno a ,file f);
int searchAlumno(char nombre[LONG], file f);
char *leerCadena(char *str, int n);
void fflushStdin();
void modifyScore(file f);
void addRecord(file *f);
void deleteRecord(file f);
void visualiceRecords(file f);
int menu();

int main(void)
{
    file mod;
    initialize(&mod);

    int opcion;
    do
    {
        opcion=menu();
        switch (opcion)
        {
        case 1:
            modifyScore(mod);
            break;
        case 2:
            addRecord(&mod);
            break;
        case 3:
            deleteRecord(mod);
            break;
        case 4:
            visualiceRecords(mod);
            break;
        case 5:
            updateNotas(mod);
            break;
        case 6:
            break;
        }
    } while (opcion != 5 && opcion !=6);
    
    

    close(&mod);
}

void initialize(file *mod)
{
    alumno a;

    file notas;
    mod->stre=fopen("modify.bi","w+b");
    notas.stre=fopen("notas.bi","rb");
    if(mod->stre == NULL || notas.stre ==NULL)
    {
        perror("Error while iniciating File");
        exit(1);
    }
    
    fseek(notas.stre,0,SEEK_END);
    notas.sizeStruct = sizeof(alumno);
    notas.nStudents=ftell(notas.stre) / notas.sizeStruct;
    rewind(notas.stre);

    mod->nStudents=notas.nStudents;
    mod->sizeStruct=notas.sizeStruct;

    for (int i = 0; i < notas.nStudents; i++)
    {
        a=readAlumno(i,notas);
        writeAlumno(i,a,*mod);
    }
    

    fclose(notas.stre);
    
}

void updateNotas(file mod)
{
    alumno a;
    file notas;

    notas.stre = fopen("notas.bi", "wb");
    if (notas.stre == NULL)
    {
        perror("Error while opening notas.bi for writing");
        return;
    }

    fclose(mod.stre);
    mod.stre = fopen("modify.bi", "rb");
    if (mod.stre == NULL)
    {
        perror("Error while opening modify.bi for reading");
        fclose(notas.stre);
        return;
    }
    notas.nStudents=mod.nStudents;
    notas.sizeStruct=mod.sizeStruct;

    for (int i = 0; i < mod.nStudents; i++)
    {
        a = readAlumno(i, mod);
        if (a.nota == -1)
            continue;
        writeAlumno(i, a, notas);
    }

    fclose(notas.stre);
}


void close(file *f)
{
    f->nStudents=0;
    fclose(f->stre);
    f->sizeStruct=0;
}


alumno readAlumno(int i, file f)
{
    alumno a;
    fseek(f.stre,i*f.sizeStruct,SEEK_SET);
    fread(&a,f.sizeStruct,1,f.stre);
    if(ferror(f.stre))
    {
        perror("Error while reading.");
    }
    clearerr(f.stre);
    return a;
}

void writeAlumno(int i, alumno a ,file f)
{
    if (f.stre == NULL)
    {
        perror("File pointer is NULL");
        return;
    }
    fseek(f.stre, i * f.sizeStruct, SEEK_SET);
    size_t result = fwrite(&a, f.sizeStruct, 1, f.stre);
    if (result != 1)
    {
        perror("Error while writing.");
    }
    clearerr(f.stre);
}

int searchAlumno(char nombre[LONG], file f)
{
    alumno a;

    for (int i = 0; i < f.nStudents; i++)
    {
        a=readAlumno(i,f);
        if(strcmp(nombre,a.nombre)==0)
        {
            return i;
        }
    }
    return -1;
}


char *leerCadena(char *str, int n)
{
    char *fin,*c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))  *c='\0';
    else if(!ferror(stdin)) fflushStdin();
    return fin;
}

void fflushStdin()
{
    while(getchar() != '\n');
}

void modifyScore(file f)
{
    alumno a;
    int posStudent;

    printf("Input the name of the student:\n");
    leerCadena(a.nombre,sizeof(a.nombre));

    if((posStudent=searchAlumno(a.nombre,f))==-1)
    {
        printf("Alumno no encontrado\n");
        return;
    }

    printf("Input the new score:\n");
    scanf("%f",&a.nota); fflushStdin();

    writeAlumno(posStudent,a,f);

}

void addRecord(file *f)
{
    alumno a;

    printf("Input the name of the student:\n");
    leerCadena(a.nombre,sizeof(a.nombre));

    printf("Input the new score:\n");
    scanf("%f",&a.nota); fflushStdin();

    writeAlumno(f->nStudents,a,*f);

    f->nStudents++;
}

void deleteRecord(file f)
{
    alumno a;
    int posStudent;

    printf("Input the name of the student:\n");
    leerCadena(a.nombre,sizeof(a.nombre));

    if((posStudent=searchAlumno(a.nombre,f))==-1)
    {
        printf("Alumno no encontrado\n");
        return;
    }
    
    a.nota=-1;

    writeAlumno(posStudent,a,f);
}

void visualiceRecords(file f)
{
    alumno a;

    for (int i = 0; i < f.nStudents; i++)
    {
        a=readAlumno(i,f);
        printf("\n");
        printf("Nombre Alumno: %s\n",a.nombre);
        printf("Nota: %.2f\n",a.nota);
    }
    
}


int menu()
{
    int op=-1;
    do
    {
        printf("\n\n");
        printf("1->Modify score\n");
        printf("2->New Record\n");
        printf("3->Delete Record\n");
        printf("4->View Records\n");
        printf("5->Exit saving\n");
        printf("6->Exit without saving\n");
        printf("        option:  ");
        scanf("%d",&op);
        fflushStdin();
    } while (op<1 || op>6);

    return op;
    
}
