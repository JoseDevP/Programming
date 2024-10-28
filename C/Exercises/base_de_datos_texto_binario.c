#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

typedef struct
{
    char reference[20];
    double price;
}registro;

typedef struct
{
    char fileName[20];
    FILE *fddbb;
    int nRegs;
    int lenReg;
    int regsDeleted;
}dataBase;

bool exist(char *nameDataBase);
void fflushStdin(void);
char *readString(char *str, int n);
void initializeBD(dataBase *db);
int openFile(dataBase *db);
void closeDataBase(dataBase *db);
void addRecord(dataBase *db);
void modifyRecord(dataBase db);
void deleteRecord(dataBase *db);
void visualiceRecord(dataBase db);
int writeRecord(int pos, registro reg, dataBase db);
registro readRecord(int pos, dataBase db);
void updateDataBase(dataBase *db);

int main(void)
{
    setlocale(0, "es_ES.UTF-8");
    int opcion=0;
    dataBase db;
    initializeBD(&db);
    
    do
    {
        opcion=menu(db);
        switch (opcion)
        {
        case 1:
            openFile(&db);
            break;
        case 2:
            addRecord(&db);
            break;
        case 3:
            modifyRecord(db);
            break;
        case 4:
            deleteRecord(&db);
            break;
        case 5:
            visualiceRecord(db);
            break;
        
        default:
            break;
        }
    } while (opcion!=6);
    
    if(db.fddbb!=NULL)
    {
        closeDataBase(&db);
        db.fddbb=NULL;
    }
}

int menu(dataBase db)
{
    int op;

    printf("\n\n");
    printf("1->Open File\n");
    printf("2->Add record\n");
    printf("3->Modify record\n");
    printf("4->Delete record\n");
    printf("5->Visualice record\n");
    printf("6->Exit\n\n");
    printf("    Option: ");

    do
    {
        scanf("%d",&op);
        fflushStdin();
        if(op<1 || op >6)
        {
            printf("Invalid Option. Option: ");
        }

    } while (op<1 || op >6);
    system("cls");
    
    if(db.fddbb==NULL)
        printf("There's no open file.");
    return op;
}


bool exist(char *nameDataBase)
{
    FILE *pf;
    if((pf=fopen(nameDataBase,"rb"))!=NULL)
    {
        fclose(pf);
        return true;
    }
    return false;
}

void fflushStdin(void)
{
    while(getchar()!='\n');
}

char *readString(char *str, int n)
{
    char *f, *c;
    f=fgets(str,n,stdin);
    if(c=strchr(str,'\n'))  *c='\0';
    else if(!ferror(stdin)) fflushStdin();
    return f;
}



void initializeBD(dataBase *db)
{
    *(db->fileName)=0;
    db->fddbb=NULL;
    db->nRegs=0;
    db->lenReg=sizeof(registro);
    db->regsDeleted=0;
}

int openFile(dataBase *db)
{
    char answer;
    char *mode="w+b";
    if(db->fddbb!=NULL)
    {
    do
    {
        printf("There's another open file. Do you want to close it? (y/n)\n");
        scanf("%c",&answer);    fflushStdin();
    } while (answer != 'y' && answer != 'n');
    if(answer == 'n')
        return 0;
    else
        closeDataBase(db);
    }

    printf("Enter the name of the database:  ");
    readString(db->fileName,sizeof(db->fileName));

    if(exist(db->fileName))
    {
        do
        {
            printf("This file already exists. Do you want to overwite it? (y/n)\n");
            scanf("%c",&answer);    fflushStdin();
        } while (answer != 'y' && answer != 'n');
        if(answer == 'n')
            mode="r+b";
    }

    if((db->fddbb=fopen(db->fileName,mode))==NULL)
    {
        perror("Error opening file.\n");
        return 0;
    }

    db->lenReg=sizeof(registro);

    fseek(db->fddbb,0,SEEK_END);
    db->nRegs=ftell(db->fddbb)/db->lenReg;
    rewind(db->fddbb);
    
    printf("File %s opened\n",db->fileName);
    return 1;
}

void closeDataBase(dataBase *db)
{
    if(db->regsDeleted)
    {
        db->regsDeleted=0;
        updateDataBase(db);
    }
    if(db->fddbb) fclose(db->fddbb);
    db->fddbb=NULL;
    db->nRegs=0;
}

void updateDataBase(dataBase *db)
{
    registro reg;
    dataBase dbTemp;
    initializeBD(&dbTemp);

    dbTemp.fddbb=tmpfile();
    if(ferror(dbTemp.fddbb))
    {
        printf("Error while creating temporal file\n");
        return;
    }

    for (int i = 0; i < db->nRegs; i++)
    {
        reg=readRecord(i,*db);
        if(strcmp(reg.reference,"delete")) continue;
        writeRecord(i,reg,dbTemp);
        dbTemp.nRegs+=1;
    }
    rewind(dbTemp.fddbb);

    closeDataBase(db);

    if((db->fddbb=fopen(db->fileName,"w+b"))==NULL)
    {
        perror("Error while opening database\n");
        return;
    }
    
    for (int i = 0; i < dbTemp.nRegs; i++)
    {
        reg=readRecord(i,dbTemp);
        writeRecord(i,reg,*db);
        db->nRegs+=1;
    }
}


void addRecord(dataBase *db)
{
    if(db->fddbb==NULL)
    {
        printf("Database not conected\n");
        return;
    }
    registro reg;
    printf("Introduce the reference of the record:\n");
    readString(reg.reference,sizeof(reg.reference));
    printf("Introduce the price of the record:\n");
    if((scanf("%lf",&reg.price))!=1)
    {
        printf("Invalid input for the price");
        fflushStdin();
        return;
    }
    fflushStdin();

    fseek(db->fddbb,0,SEEK_END);
    if(writeRecord(db->nRegs, reg, *db)) db->nRegs++;
    rewind(db->fddbb);

}

void modifyRecord(dataBase db)
{
    registro reg;
    int op=-1, recordNumb=0;
    
    if(db.fddbb == NULL)
    {
        printf("Database not conected\n");
        return;
    }
    printf("Choose record from 0 to %d\n",db.nRegs-1);
    scanf("%d",&recordNumb); fflushStdin();

    reg=readRecord(recordNumb,db);
    if(strcmp(reg.reference,"")==0 && reg.price==0.0) return;
    printf("%s\n",reg.reference);
    printf("%g\n",reg.price);

    do
    {
        printf("\n\n");
        printf("Modificar el dato\n");
        printf("1-> Referencia\n");
        printf("2-> Precio\n");
        printf("3-> Salir y salvar los cambios\n");
        printf("4-> Salir sin salvar los cambios\n");
        printf("    Opcion:");
        scanf("%d",&op); fflushStdin();
        if(op<1 || op>4)
            printf("Option not posible. Choose one between 1 to 4\n");

        switch (op)
        {
        case 1:
            printf("Reference:     ");
            readString(reg.reference, sizeof(reg.reference));
            break;
        case 2:
            printf("Price:     ");
            scanf("%lf",&reg.price); while(getchar() != '\n');
            break;
        }
    } while (op != 3 && op != 4);
    
    if (op==3)
        writeRecord(recordNumb,reg,db);
}

void deleteRecord(dataBase *db)
{
    registro reg;
    char reference[20];
    if(db->fddbb == NULL)
    {
        printf("Database not conected\n");
        return;
    }

    printf("Input the reference:\n");
    readString(reference,sizeof(reference));
    
    bool found=false;

    for (int i = 0; i < db->nRegs; i++)
    {
        reg=readRecord(i,*db);
        if(strcmp(reg.reference,reference)==0)
        {
            strcpy(reg.reference,"delete");
            writeRecord(i,reg,*db);
            db->regsDeleted++;
            found=true;
            break;
        }
    }
    if(found)
        printf("Deleted\n");
    else
        printf("Not Found\n");


}

void visualiceRecord(dataBase db)
{
    registro reg;

    for (int i = 0; i < db.nRegs; i++)
    {
        reg=readRecord(i,db);
        printf("\n\n");
        printf("Record %d\n",i);
        printf("Reference %s\n",reg.reference);
        printf("Price %.2f\n",reg.price);
    }
    
}




int writeRecord(int pos, registro reg, dataBase db)
{
    fseek(db.fddbb, pos*db.lenReg, SEEK_SET);
    fwrite(&reg,db.lenReg,1,db.fddbb);
    if(ferror(db.fddbb))
    {
        perror("Error writing the record");
        return 0;
    }
    clearerr(db.fddbb);
    return 1;
        
}

registro readRecord(int pos, dataBase db)
{
    registro reg;

    fseek(db.fddbb, pos*db.lenReg, SEEK_SET);
    fread(&reg,db.lenReg,1,db.fddbb);
    if(ferror(db.fddbb))
    {
        perror("Error reading the record");
    }
    clearerr(db.fddbb);
    return reg;
        
}
