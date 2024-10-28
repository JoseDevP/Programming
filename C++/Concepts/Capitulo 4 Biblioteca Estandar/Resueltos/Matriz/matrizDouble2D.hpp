#include <vector>

typedef std::vector<std::vector<double>> MatrizDouble2D;
typedef std::vector<double> MatrizDouble1D;

void ConstruirMatriz(MatrizDouble2D& m, int filas, int cols);
void LeerMatriz(MatrizDouble2D& m);
void MostrarMatriz(MatrizDouble2D& m);
void LeerMatrizIt(MatrizDouble2D& m);
void MostrarMatrizIt(MatrizDouble2D& m);
void MostrarMatrizC(MatrizDouble2D& m);
void LeerMatrizC(MatrizDouble2D& m);
char si_no();