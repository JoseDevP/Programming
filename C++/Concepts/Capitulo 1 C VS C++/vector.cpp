#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> ConstruirMatriz(int nFilas, int nColumnas)
{
    vector<vector<double>> v (nFilas, vector<double>(nColumnas,0));
    return v;
}

void LeerMatriz(vector<vector<double>>& m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[i].size(); j++)
        {
            cout << "m[" << i << "] [" << j << "]: ";
            cin >> m[i][j];
        }
        
    }
}

void MostrarMatriz(vector<vector<double>>& m)
{
    for (auto i : m)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main(void)
{
    int filas, cols;
    cout << "Introduce el numero de filas para la matriz:  ";
    cin >> filas;
    cout << "Introduce el numero de columnas para la matriz:  ";
    cin >> cols;
    vector<vector<double>> m = ConstruirMatriz(filas, cols);
    LeerMatriz(m);
    MostrarMatriz(m);
    return 0;
}