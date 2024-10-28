// fourier.cpp - Transformada discreta de Fourier
#include <iostream>
#include <vector>
using namespace std;

struct complejo
{
  double real, imag;
};

complejo sumar( const complejo& a, const complejo& b )
{
  complejo temp;
  temp.real = a.real + b.real;
  temp.imag = a.imag + b.imag;
  return temp;
}

complejo multiplicar( const complejo& a, const complejo& b )
{
  complejo temp;
  temp.real = a.real * b.real - a.imag * b.imag;
  temp.imag = a.real * b.imag + a.imag * b.real;
  return temp;
}

void DFT( vector<complejo>& X, const vector<double>& x )
{
  int n, k, N = x.size();
  double t, pi = 3.141592654;
  complejo a, b;

  for ( k = 0; k < N; k++ )
  {
    X[k].real = 0; X[k].imag = 0;
    for ( n = 0; n < N; n++ )
    {
      a.real = x[n]; a.imag = 0;
      t = k * 2 * pi / N * n;
      b.real = cos( -t ); b.imag = sin( -t );
      b = multiplicar( a, b );
      X[k] = sumar( X[k], b );
    }
  }
}

int main()
{
  // Crear la matriz que almacenar� la secuencia
  // de n�meros reales
  vector<double> x;

  // Introducir la secuencia de n�meros reales
  cout << "Introduzca los valores. Finalizar con eof\n" ;
  double n;
  while (cin >> n) x.push_back(n);

  // Crear la matriz de complejos
  vector<complejo> X(x.size());

  // Calcular la transformada discreta de Fourier
  DFT(X, x);

  cout << "Resultado:\n";
  for (int n = 0; n < X.size(); n++ )
    cout << showpos << X[n].real << X[n].imag << " j\n";
}

