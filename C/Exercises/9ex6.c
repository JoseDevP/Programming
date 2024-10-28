/*
    Programa que permita crear un archivo nuevo, abrir uno existente, añadir, mmodificar o eliminar
    registros y visualizar el contenido del archivo. El nombre del archivo será introducido a traves
    del teclado. Cada registro del archivo estara formado por los datos referencia y precio segun la estructutraa:

        typedef struct
        {
            char referencia[20];
            double precio;
        }registro;
    
    Asi mismo para que el usuario pueda elegir cualquiera de las operaciones enunciadas el programa
    visualizara en la pantalla un menú similar al siguiente:

        Nombre del archivo: articulos
        1.Abrir registro
        2.Añadir registro
        3.Modificar registro
        4.Eliminar registro
        5.Visualizar registros
        6.Salir

            Opcion:
    Cuando se habra un archivo y exista se le permitira al usuario sobreescribirlos si asi lo desea.
    El resto de las opciones realizaran la tarea especificada por su titulo, excepto la opcion
    Visualizar regiustros que visualizara aquellos cuya referencia sea una especificada, o bien contenga 
    una subcadena especificada cuando la subcadena sea "*" se visualizaran todos.

    Se debera realizar al menos una fucnion para cad una de las opciones; la opcion Salir invocara a 
    una funcion que cerrará la base de datos con las operaciones que este proceso conlleve.

    Por otra parte, un archivo abiierto quedará definido por los atributos siguientes:
        Una cadena que almacene el nombre del archivo
        Un flujo vinculado con el archivo
        Numero de registros del archivo
        Longitud de cada registro
        Miembro que indique si se eliminó un registro

        typedef struct
        {
            char nombreArchivo[20];
            FILE *fes;
            int nregs;
            int tamreg;
            int regsEliminados;
        }baseDeDatos;

    Siguiendo el ejemplo, el trabajo con un archivo debera permitir, iniciar, verificar si existe, 
    insertar, obtener, buscar y eliminar un registro, asi como actualizar el archivo cuando sea preciso.
    Este trabajo será realizado por las funciones siguientes.

        inicarRegistro: iniciara a 0 los miembros de una estructura de tipo registro
        iniciarBaseDeDatos: iniciara a 0 los miembros de estructura base de datos
        existe: devuelve true si el archivo cuyo nombre se pasa como argumento existe
        escribirRegistro: sobreescribir un registro en una posicion cualquiera dentro de un archivo
        anyadirRegistro: permitirá añadir un registro al final
        leerRegistro: devuele el registro solicitado del archivo
        buscarRegistro: permite localizar un determinado registro en el archivo 
                        Devuelve la posicion del registro (primer registro es 0) o -1 si no se ha encontrado
        eliminarRegistro:permite marcar un registro como borrado.
        actualizarBaseDeDatos: eliminar fisicamente del archivo los registros marcados por la funcion eliminarRegistro
        cerrarBaseDeDatos: invoca a la funcion actualizar base de datos si se elimno algun registro
                            (miembro regsEliminados distinto de 0) y cierra el archivo)
    Funciones para el menu principal:
        menu
        menuAbrirBaseDeDatos
        menuAbrirAnyadirReg
        menuModificarReg
        menuEliminarReg
        menuVisualizarRegs
    

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char referencia[20];
    double precio;
}registro;

typedef struct
{
    char nombreArchivo[20];
    FILE *fes;
    int nregs;
    int tamreg;
    int regsEliminados;
}baseDeDatos;

char *readString(char *str, int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))  *c='\0';
    else if (!feof(stdin))
        while(getchar() != '\n');
    return fin;
}

void iniciarRegistro(registro *reg)
{
    *(reg->referencia)=0;
    reg->precio=0;
}

bool existe(char *nombreArch)
{
    bool existe=false;
    FILE *pf=NULL;
    if((pf=fopen(nombreArch,"rb"))!=NULL)
    {
        existe=true;
    }
    return existe;
}

int escribirRegistro(int i, registro reg, baseDeDatos bd)
{
    if(i>=0 && i<=bd.nregs)
    {
        fseek(bd.fes,i*bd.tamreg,SEEK_SET);
        fwrite(&reg,bd.tamreg,1,bd.fes);
        if(!ferror(bd.fes)) return 1;
        printf("Error al escribir en el archivo\n");
    }
    else
        printf("Numero de registro fuera de limites.");
    return 0;
}

void anyadirRegistro(registro reg, baseDeDatos *bd)
{
    if(escribirRegistro(bd->nregs, reg, *bd)) bd->nregs++;
}

registro leerRegistro(int i, baseDeDatos bd)
{
    registro reg;
    iniciarRegistro(&reg);

    if(i>=0 && i < bd.nregs)
    {
        fseek(bd.fes,i*bd.tamreg,SEEK_SET);
        fread(&reg,bd.tamreg,1,bd.fes);
    }
    else
        printf("Numero de registro fuera de limites.");
    return reg;
}

int buscarRegistro(char *str, int nreg, baseDeDatos bd)
{
    registro reg;

    if(str==NULL)   return -1;
    if(nreg < 0)    nreg=0;
    for (int reg_i = nreg; reg_i < bd.nregs; reg_i++)
    {
        reg=leerRegistro(reg_i,bd);
        if(strstr(reg.referencia,str))
            return reg_i;
    }
    return -1;
}

int eliminarRegistro(char *ref, baseDeDatos *bd)
{
    registro reg;

    for (int reg_i = 0; reg_i < bd->nregs; reg_i++)
    {
        reg=leerRegistro(reg_i,*bd);
        if(strstr(ref,reg.referencia) == 0)
        {
            strcpy(reg.referencia,"borrar");

            escribirRegistro(reg_i,reg,*bd);
            bd->regsEliminados=1;
            return 1;
        }
    }
    return 0;
}

void iniciarBaseDeDatos(baseDeDatos *bd)
{
    *(bd->nombreArchivo)=0;
    bd->fes=NULL;
    bd->nregs=0;
    bd->tamreg=sizeof(registro);
    bd->regsEliminados=0;
}

void cerrarBaseDeDatos(baseDeDatos *bd)
{
    if(bd->regsEliminados)
    {
        bd->regsEliminados=0;
        actualizarBaseDeDatos(bd);
    }
    if(bd->fes) fclose(bd->fes);
    bd->fes=NULL;
    bd->nregs=0;
}


int actualizarBaseDeDatos(baseDeDatos *bd)
{
    registro reg;
    baseDeDatos bdtemp;
    iniciarBaseDeDatos(&bdtemp);

    bdtemp.fes=tmpfile();
    if(bdtemp.fes==NULL)
    {
        printf("Error. No se puede crear un archivo temporal\n");
        return 0;
    }

    for (int reg_i = 0; reg_i < bd->nregs; reg_i++)
    {
        reg=leerRegistro(reg_i,*bd);
        if(strcmp(reg.referencia,"borrar")==0) continue;
        anyadirRegistro(reg,&bdtemp);
    }

    cerrarBaseDeDatos(bd);
    if((bd->fes=fopen(bd->nombreArchivo,"wb"))==NULL)
    {
        perror("Error. No se puede crear el archivo");
        return 0;
    }
    rewind(bdtemp.fes);
    for (int i = 0; i < bdtemp.nregs; i++)
    {
        reg=leerRegistro(i,bdtemp);
        anyadirRegistro(reg,bd);
    }
    return 1;
}


int menuAbrirBaseDeDatos(baseDeDatos *bd)
{
    char resp='n';
    char *modo;
    if(bd->fes)
    {
        printf("Ya hay un archivo abierto");
        return 0;
    }

    printf("Nombre del archivo: ");
    readString(bd->nombreArchivo,sizeof(bd->nombreArchivo));
    modo="w+b";

    if(existe(bd->nombreArchivo))
    {
        do
        {
            printf("Este archivo existe ¿Desea sobrescribirlo? (s/n) ");
            resp=tolower(getchar());
            while(getchar() != '\n');
        } while (resp != 's' && resp != 'n');
        if(resp != 'n')
            modo="r+b";
    }

    if((bd->fes=fopen(bd->nombreArchivo,modo))==NULL)
    {
        printf("Error: No se puede crear el archivo\n");
        bd->fes=0;
        return 0;
    }

    bd->tamreg=sizeof(registro);
    fseek(bd->fes,0,SEEK_END);
    bd->nregs = ftell(bd->fes)/sizeof(registro);
    rewind(bd->fes);
    printf("Archivo %s abierto\n",bd->nombreArchivo);
    return 1;
}   

int menuAnyadirReg(baseDeDatos *bd)
{
    registro reg;

    printf("Referencia:    ");
    readString(reg.referencia,sizeof(reg.referencia));
    printf("Precio:        ");
    scanf("%lf",&reg.precio); while(getchar() != '\n');
    anyadirRegistro(reg,bd);

    return 1;
}

int menuModificarReg(baseDeDatos bd)
{
    registro reg;
    int op=3, nreg=0;
    if(bd.nregs == 0)
    {
        printf("archivo vacio\n");
        return 0;
    }

    printf("Numero de registro entre o y %d: ",bd.nregs-1);
    scanf("%d",&nreg); while(getchar() != '\n');

    reg=leerRegistro(nreg,bd);
    if(strcmp(reg.referencia,"")==0 && reg.precio==0.0) return 0;
    printf("%s\n",reg.referencia);
    printf("%g\n",reg.precio);

    do
    {
        printf("\n\n");
        printf("Modificar el dato\n");
        printf("1-> Referencia\n");
        printf("2-> Precio\n");
        printf("3-> Salir y salvar los cambios\n");
        printf("4-> Salir sin salvar los cambios\n");
        printf("    Opcion:");
        scanf("%d",&op); while(getchar() != '\n');

        switch (op)
        {
        case 1:
            printf("Referencia:     ");
            readString(reg.referencia, sizeof(reg.referencia));
            break;
        case 2:
            printf("Precio:     ");
            scanf("%lf",&reg.precio); while(getchar() != '\n');
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }

    } while (op !=3 && op !=4);

    if(op == 3) escribirRegistro(nreg,reg,bd);
    
    return 1;
}

int menuEliminarReg(baseDeDatos *bd)
{
    char referencia[20];
    int eliminado=0;

    if(bd->nregs ==0)
    {
        printf("Archivo vacio\n");
        return 0;
    }
    printf("Referencias:    ");
    readString(referencia,sizeof(referencia));
    eliminado=eliminarRegistro(referencia,bd);
    if(eliminado)
        printf("Registro Eliminado\n");
    else
        if(bd->nregs != 0)
            printf("Referencia no encontrada\n");
        else
            printf("Lista vacia\n");
    return eliminado;
}

int menuVisualizarRegs(baseDeDatos bd)
{
    registro reg;
    char str[20];
    int nreg=-1;

    iniciarRegistro(&reg);
    if(bd.nregs ==0)
    {
        printf("archivo vacio\n");
        return 0;
    }
    
    printf("conjunto de caracteres a buscar: ");
    readString(str,sizeof(str));

    do
    {
        if(*str != '*')
            nreg=buscarRegistro(str,nreg+1,bd);
        else
            if(++nreg==bd.nregs)    break;
        if(nreg > -1)
        {
            reg=leerRegistro(nreg,bd);
            printf("Registro: %d\n",nreg);
            printf("%s\n",reg.referencia);
            printf("%g\n\n",reg.precio);
        }
        
    } while (nreg != -1);
    
    if(strcmp(reg.referencia,"")==0 && reg.precio==0.0f)
        printf("No se encontró ningun registro\n");

    return 1;
}

int menu(baseDeDatos bd)
{
    int op;

    printf("\n\n");
    printf("1->Abrir archivo\n");
    printf("2->Añadir registro\n");
    printf("3->Modificar registro\n");
    printf("4->Eliminar registro\n");
    printf("5->Visualizar registro\n");
    printf("6->Salir\n\n");
    printf("    Opcion: ");

    do
    {
        scanf("%d",&op); while(getchar() != '\n');
        if(op <1 || op >6)
            printf("Opcion no valida. Elija otra: ");
    } while (op<1 || op>6);

    if(op>1 && op<6 && !bd.fes)
    {
        printf("No hay un archivo abierto");
        return 0;
    }
    return op;
}

int main(void)
{
    int opcion=0;
    baseDeDatos articulos;
    iniciarBaseDeDatos(&articulos);

    int (*opciones_del_menu[])()={menuAbrirBaseDeDatos,menuAnyadirReg,menuModificarReg,menuEliminarReg,menuVisualizarRegs};

    do
    {
        opcion=menu(articulos);
        if(opcion==2 || opcion==4 )
            (*opciones_del_menu[opcion-1])(articulos);
        else
            (*opciones_del_menu[opcion-1])(&articulos);

    } while (opcion != 6);
    
}
