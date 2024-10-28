/*Ejercicio Tarot*/
/*Pedir fecha int dd mm aa*/
/*Numero Tarot*/
/*Ejemplo 22+09+1998=2029=>2+0+2+9=13=>1+3=4*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkNum(int dd,int mm,int aa)
{
	if(aa>0 && aa <= 3000)
	{
		if(mm>0 && mm <= 12)
		{
			switch (mm)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 9:
			case 11:
				if(dd>0 && dd<=31)
				{
					return true;
				}
				else
					return false;
				break;
			case 4:
			case 6:
			case 8:
			case 10:
			case 12:
				if(dd>0 && dd<=30)
				{
					return true;
				}
				else
					return false;
				break;
			case 2:
				int ndias=28;
				if((aa % 4 == 0 && (aa % 100 != 0 || aa % 400 == 0)))
					ndias=29;
				if(dd>0 && dd<=ndias)
				{
					return true;
				}
				else
					return false;
				break;
			default:
				return false;
			}
		}
		else
			return false;
	}
	else
		return false;
	
}

int GetTarotNumber(int dd, int mm, int aa)
{
    int tarotNumber = dd + mm + aa;

    while (tarotNumber > 9) //9 porque solo 1 digito
    {
        int temp = tarotNumber;
        tarotNumber = 0;
        
        while (temp != 0)
        {
            int digit = temp % 10;  //obtieene el ultimo digito
            tarotNumber += digit;   
            temp = temp / 10;       
        }
    }
    
    return tarotNumber; 
}

int main(void)
{
	int dd,mm,aa;
	printf("Introduce el dia en que naciste: ");
	while (true)
	{
		while (scanf("%d",&dd)!=1)
		{
			while(getchar()!='\n');
			printf("No es correcto.Vuelve a Introducirlo: ");
		}
		printf("Introduce el mes en que naciste: ");
		while (scanf("%d",&mm)!=1)
		{
			while(getchar()!='\n');
			printf("No es correcto.Vuelve a Introducirlo: ");
		}
		printf("Introduce el año en que naciste: ");
		while (scanf("%d",&aa)!=1)
		{
			while(getchar()!='\n');
			printf("No es correcto.Vuelve a Introducirlo: ");
		}
		if(checkNum(dd,mm,aa))
		{
			break;
		}
		else
			printf("La fecha no es valida. Introducela otra vez\n ");
	}
	
	int tarotNumber=GetTarotNumber(dd, mm, aa);
	
	printf("Tu numero del tarot es: %d",tarotNumber);
	

	
}