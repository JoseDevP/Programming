/*
    Una empresa dedicada a la venta de electrodomésticos y a su posterior mantenimineto desea
    tener una aplicación que automatice todos sus procesos de gestión.

    Esto supone tener la informacion de todos los clientes que compran electrodomestcos, 
    junto con los contratos de mantenimiento  (esta ultima informacion logicamente,
    solo estar disponible en los casos en que el cliente contrate un seguro de mantenimiento
    para los electrodomesticos adquiridos),almacenada en una matriz dinamica de estructuras.

    Cada cliente podrta asegurrar o no el electrodomestico comprado y cada electrodomestico
    aasegurado dará lugar a un contrato de mantenimiento.

    La estructura tcon almacena la información de cada electrodomestico comprado y asegurado.

    typedef struct
    {
        char descripcion[80];   //descripcion electrodomestico
        int valorCompra;        //valor electrodomestico
        int impContrato;        //importe del contrato de mantenimiento
        char numSerie[15];      //numero de serie del aparato
        char numContrato[10]    //numero del contrato
    }tcon;  

    Para almacenar los contratos de mantenimiento suscritos por cada cliente, se define
    una estructura tcontrato as:

    typedef struct
    {
        tcon *Contrato
        int nContratosAct; //numero total de contratos pro cliente
    }tcontrato;

    Para almacenar los datos de los clientes que han comprado electrodomesticos aunque
    no hayan asegurado ninguno, se defeine una estructura tcliente asi:

    typedef struct
    {
        char Nombre[35];
        char Apellidos[55];
        char Direccion[35];
        char Codigo[15];
        tcontrato ContratoCli
    }tcliente;

    La matriz dinamica de estructuras con la informacion de los clientes estara referenciada 
    por la variable pcliente:

    tcliente *pcliente

    a)Funcion autorizaReparacion.
        Indica si se autoriza o no una reparación de un electrodmestico depnediendo de:
            Existe contrato para el electrodomestico con el numero serie especificado
            El coste de reparación no excede del 25% del valor de compra.

        int autorizaReparacion(tclient *pcliente, char numSerie[15],int numClientes,int
                                                                            importeReparacion)
        Valor retornado:
            0 si el importe de la reparacion excede el 25% de la compra
            1 si se autoriza
            2 si el numero de serie no existe
    
    b)Funcion darDeAltaUnContrato.
        Dara de alta un contrato para un cliente existente en pcliente, solicitando lso datos
        del teclado.

            void darDeAltaUnContrato(tcliente *plcliente, int i);

            Valor retornado ninguno
        El nuevo contrato introducido se insertará en la posicion primera si este clietne no tuviera
        coontratos vigentes.
        En caso contrario, se insertará después del ultimo contrato existente.(realloc)

    c)Funcion buscarPosicion. 
        Permite encontrar la posicion de un determinado cliente en la
        matriz dinámica de estructuras. El prototipo:
        
        int buscarPosicion(tcliente *pcliente, char *codigo, int numClientes);

        Valor retornado:
            Entero que indica la posicion que ocupa el cliente en la matriz
            -1 si el cliente no se encuentra

    d)Funcion listar. 
        Mostrara en pantalla un listado de todos los datos de los clietnes.
        En el caso de que un cliente no tenga ningun contratos mostrara un mensaje indicandolo.

        void listar(tcliente *pcliente, int numClientes);

        Valor retornado ninguno

    e)Funcion LiberarMemoria. 
    Liberará toda la memoria que se haya asignado durante la ejecucion del programa.

    void liberarMemoria(tcliente *pcliente, int numClientes);

    Valor retornado ninguno.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char descripcion[80];  
    int valorCompra;       
    int impContrato;       
    char numSerie[15];     
    char numContrato[10];
}tcon;  //informacion del contrato

typedef struct
{
    tcon *Contrato;
    int nContratosAct; 
}tcontrato; //contratos de un cliente

typedef struct
{
    char Nombre[35];
    char Apellidos[55];
    char Direccion[35];
    char Codigo[15];
    tcontrato ContratoCli;
}tcliente; //informacion cliente


int autorizaReparacion(tcliente *pcliente, char numSerie[15],int numClientes,int importeReparacion);
void darDeAltaUnContrato(tcliente *plcliente, int i);
int buscarPosicion(tcliente *pcliente, char *codigo, int numClientes);
void listar(tcliente *pcliente, int numClientes);
void liberarMemoria(tcliente *pcliente, int numClientes);

int registrarClientes(tcliente **ppcliente,int nClientes);
char *readString(char *str, int n);

int main(void)
{
    int nClientes=0, correcto=0;
    do
    {
        printf("Introduce el numero de clientes:  ");
        correcto=scanf("%d",&nClientes);
        while(getchar() != '\n');
    } while (!correcto || nClientes<=0);
    
    tcliente *pcliente=(tcliente *)malloc(nClientes*sizeof(tcliente));

    registrarClientes(&pcliente, nClientes);

    system("cls");

    while (1)
    {
        int correcto=-1, respuesta;
        do
        {
            printf("Empresa de Electrodomesticos----->\n\n");
            printf("         Menu de opciones         \n");
            printf("----------------------------------\n");
            printf("Selecciona una opcion:\n");
            printf("1->Mostrar Clientes\n");
            printf("2->Dar de alta un Contrato\n");
            printf("3->Reparacion Producto\n");
            printf("4->Salir\n");

            correcto=scanf("%d",&respuesta);
            while(getchar() != '\n');
        } while (correcto<0 || correcto>4);
        
        system("cls");

        if(respuesta==1)
            listar(pcliente, nClientes);
        
        if (respuesta==2)
        {
            char Codigo[15];
            
            do
            {
                printf("Introduce el codigo del cliente: ");
            } while ((readString(Codigo, 80)) == NULL);

            int pos=buscarPosicion(pcliente, Codigo, nClientes);

            darDeAltaUnContrato(pcliente, pos);
        }

        if (respuesta==3)
        {
            char numSerie[15];
            int importeReparacion=0,correcto=0;
            
            do
            {
                printf("Introduce el numero de serie del producto: ");
            } while ((readString(numSerie, 15)) == NULL);

            do
            {
                printf("Inserta el importe de reparación del electrodomestico: ");
                correcto=scanf("%d",&importeReparacion);
                while(getchar() != '\n');
            } while (!correcto);

            int reparacion=autorizaReparacion(pcliente, numSerie, nClientes, importeReparacion);
            if(reparacion==1)
                puts("Aceptado");
            else
                puts("Denegado");

        }

        if (respuesta==4)
        {
            printf("Finalizando programa\n");
            break;
        }

    }

    liberarMemoria(pcliente, nClientes);
    
    exit(0);
    
}

int registrarClientes(tcliente **ppcliente,int nClientes)
{
    tcliente *cliente=*ppcliente;
    for (int i = 0; i < nClientes; i++)
    {
        printf("Cliente %d: \n",i);
        char Nombre[35];
        do
        {
            printf("Inserta nombre cliente: ");
        } while ((readString(Nombre, 35)) == NULL);

        strcpy(cliente[i].Nombre, Nombre);

        char Apellidos[55];
        do
        {
            printf("Inserta apellidos cliente: ");
        } while ((readString(Apellidos, 55)) == NULL);

        strcpy(cliente[i].Apellidos, Apellidos);

        char Direccion[35];
        do
        {
            printf("Inserta direccion cliente: ");
        } while ((readString(Direccion, 35)) == NULL);

        strcpy(cliente[i].Direccion, Direccion);

        char Codigo[15];
        do
        {
            printf("Inserta codigo cliente: ");
        } while ((readString(Codigo, 15)) == NULL);

        strcpy(cliente[i].Codigo, Codigo);

        printf("\n\n");

        cliente[i].ContratoCli.Contrato=NULL;
        cliente[i].ContratoCli.nContratosAct=0;
    }
    
}

int autorizaReparacion(tcliente *pcliente, char numSerie[15],int numClientes,int importeReparacion)
{
    for(int i = 0; i < numClientes; i++) 
    {
        for (int j = 0; j < pcliente[i].ContratoCli.nContratosAct; j++)
        {       
            if(strcmp(pcliente[i].ContratoCli.Contrato[j].numSerie,numSerie)==0)
            {
                int porcentaje=(pcliente[i].ContratoCli.Contrato[j].valorCompra*25)/100;
                if (importeReparacion <= porcentaje)
                    return 1;
                else
                    return 0;

            }
        }
    }
    return 2;
}

void darDeAltaUnContrato(tcliente *plcliente, int i)
{

    if((plcliente[i].ContratoCli.Contrato)==NULL)
    {
        if((plcliente[i].ContratoCli.Contrato=(tcon *)malloc(sizeof(tcon)))==NULL)
        {
            fprintf(stderr, "Error al asignar memoria \n");
            exit(1);
        }
    }    
    else 
    {
        if((plcliente[i].ContratoCli.Contrato=realloc(plcliente[i].ContratoCli.Contrato,  (plcliente[i].ContratoCli.nContratosAct+1)*sizeof(tcon)))==NULL)
        {
            fprintf(stderr, "Error al asignar memoria\n");
            exit(1);
        }
    }
        
    
    plcliente[i].ContratoCli.nContratosAct+=1;

    int indice_contrato=plcliente[i].ContratoCli.nContratosAct-1;
    int correcto=0;

    // descripcion
    char descripcion[80];
    do
    {
        printf("Inserta descripción del contrato: ");
    } while ((readString(descripcion, 80)) == NULL);

    strcpy(plcliente[i].ContratoCli.Contrato[indice_contrato].descripcion, descripcion);

    //valorCompra
    int valorCompra=0;
    do
    {
        printf("Inserta el valor de compra del electrodomestico: ");
        correcto=scanf("%d",&valorCompra);
        while(getchar() != '\n');
    } while (!correcto);

    plcliente[i].ContratoCli.Contrato[indice_contrato].valorCompra=valorCompra;

    //impContrato
    int impContrato=0;
    do
    {
        printf("Inserta el importe del electrodomestico: ");
        correcto=scanf("%d",&impContrato);
        while(getchar() != '\n');
    } while (!correcto);

    plcliente[i].ContratoCli.Contrato[indice_contrato].impContrato=impContrato;
    
    // numSerie
    char numSerie[15];
    do
    {
        printf("Introduce el numero de serie: ");
    } while ((readString(numSerie, 15)) == NULL);

    strcpy(plcliente[i].ContratoCli.Contrato[indice_contrato].numSerie, numSerie);

    // numContrato
    char numContrato[10];
    do
    {
        printf("Introduce el numero de contrato: ");
    } while ((readString(numContrato, 10)) == NULL);

    strcpy(plcliente[i].ContratoCli.Contrato[indice_contrato].numContrato, numContrato);
    
}

char *readString(char *str, int n)
{
    char *fin, *c;
    fin=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))
        *c='\0';
    else if(!ferror(stdin)) 
        while(getchar() != '\n');
    return fin;
}

int buscarPosicion(tcliente *pcliente, char *codigo, int numClientes)
{
    for (int i = 0; i < numClientes; i++)
    {
        if((strcmp(pcliente[i].Codigo,codigo))==0)
            return i;
    }
    return -1;
}

void listar(tcliente *pcliente, int numClientes)
{
    for (int i = 0; i < numClientes; i++)
    {
        printf("Cliente %d: \n",i);

        printf("Nombre cliente: %s\n",pcliente[i].Nombre);
        printf("Apellidos cliente: %s\n",pcliente[i].Apellidos);
        printf("Direccion cliente: %s\n",pcliente[i].Direccion);
        printf("Codigo cliente: %s\n",pcliente[i].Codigo);

        if(pcliente[i].ContratoCli.Contrato!=NULL && pcliente[i].ContratoCli.nContratosAct>0)
        {
            for (int j = 0; j < pcliente[i].ContratoCli.nContratosAct; j++)
            {
                printf("Descripcion Electrodoméstico: %s\n",pcliente[i].ContratoCli.Contrato[j].descripcion);
                printf("Valor Compra Electrodoméstico: %d\n",pcliente[i].ContratoCli.Contrato[j].valorCompra);
                printf("Importe Contrato Electrodoméstico: %d\n",pcliente[i].ContratoCli.Contrato[j].impContrato);
                printf("Numero de Serie Electrodoméstico: %s\n",pcliente[i].ContratoCli.Contrato[j].numSerie);
                printf("Numero de Contrato Electrodoméstico: %s\n",pcliente[i].ContratoCli.Contrato[j].numContrato);
            }
            
        }
        else
        {
            printf("No dispone de ningun contrato.\n");
        }
        
        printf("\n\n");
    }
    
}

void liberarMemoria(tcliente *pcliente, int numClientes)
{
    for (int i = 0; i < numClientes; i++)
    {
        if(pcliente[i].ContratoCli.Contrato!=NULL)
        {
            free(pcliente[i].ContratoCli.Contrato);

        }
    }
    free(pcliente);
    
}