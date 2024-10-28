#include <iostream>
#include <new>

void LiberarMemoria(char *p[], int n);

int main()
{
    const unsigned long TBloqueMem = 32768;

    const unsigned long TotalBloques = 128000;
    char* pBloqueMem[TotalBloques];

    int i = -1;
    do
    {
        i++;
        try
        {
            pBloqueMem[i] = new char[TBloqueMem];
        }
        catch(std::bad_alloc)
        {
            LiberarMemoria(pBloqueMem, i);
            return -1;
        }
        
    } while (pBloqueMem[i] && i < TotalBloques -1);
    LiberarMemoria(pBloqueMem, TotalBloques);
}

void LiberarMemoria(char *p[], int n)
{
    for (int i = 0; i < n; i++)
        delete[] p[i];
    std::cout << " Se liberaron " << n << "bloques\n";
    
}