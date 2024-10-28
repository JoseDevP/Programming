// test.cpp - Alumnos matriculados en una determinada carrera
#include <iostream>
#include <string>
#include <iomanip>
#include "Alumno/alumno.hpp"
using namespace std;

int menu()
{
  cout << '\n';
  cout << "1. Matricular\n";
  cout << "2. Poner notas\n";
  cout << "3. Mostrar expediente\n";
  cout << "4. Salir\n";
  cout << endl;
  cout << "   Opci�n: ";
  int op;
  do
    cin >> op;
  while (op < 1 || op > 4);
  cin.ignore();
  return op;
}

CAsignatura *leerDatosAsig()
{
  CAsignatura *asig;
  int id;
  string nombre_as;
  char sID[8];
  do
  {
    cout << "ID:          "; cin >> id; cin.ignore();

    sprintf(sID, "%.2d", id);
    nombre_as = string("asignatura") + string(sID);
    if (nombre_as.empty()) cout << "ID no v�lido\n";
  }
  while (nombre_as.empty());
  cout << "Nombre:      " << nombre_as;

  asig = new CAsignatura(id, nombre_as);

  return asig;
}

void matricular(vector<CAlumno>& v)
{
  int dni;
  string nombre, direc;
  cout << "DNI:         "; cin >> dni; cin.ignore();
  cout << "Nombre:      "; getline(cin, nombre);
  cout << "Direcci�n:   "; getline(cin, direc);
  CAlumno al(dni, nombre, direc);

  cout << endl;
  cout << "Asignaturas:\n";
  char respuesta;
  do
  {
    CAsignatura *asig = leerDatosAsig();
    al.anyadirAsignatura(asig);
    delete asig;
    cout << endl;
    do
    {
      cout << "�Otra asignatura? s/n: ";
      cin >> respuesta;
      cin.ignore();
    }
    while(respuesta != 's' && respuesta != 'n');
  }
  while(respuesta == 's');

  v.push_back(al);
}

void poner_notas(vector<CAlumno>& v, int id)
{
  if (v.size() == 0)
  {
    cerr << "No hay alumnos matriculados\n";
    return;
  }

  for (unsigned int al = 0; al < v.size(); al++)
  {
    int pos; 
    if (v[al].estaEnActa(id, pos))
    {
      CConvocatoria conv; 
      cout << v[al].obtenerNombre() << ", nota: ";
      float nota; 
      cin >> nota; cin.ignore();
      conv.asignarConvocatoria(
        v[al].obtenerAsignatura(pos)->convocatoriasConsumidas()+1);
      conv.asignarFecha(); 
      conv.asignarNota(nota);
      v[al].obtenerAsignatura(pos)->anyadirConvocatoria(conv);
    }
  }
}

void mostrar_expediente(vector<CAlumno>& v, int dni)
{
  if (v.size() == 0)
  {
    cerr << "No hay alumnos matriculados\n";
    return;
  }
  CConvocatoria c;
  unsigned int al, i = 0;

  for (al = 0; al < v.size(); al++)
    if (v[al].obtenerDNI() == dni) break;
  if (al == v.size())
  {
    cerr << "error: no existe un alumno con ese DNI\n";
    return;
  }

  cout << "Alumno " << v[al].obtenerNombre() << ": " << endl;
  cout << left << setw(25) << "Asignatura"
        << right << setw(15) << "Convocatoria"
        << setw(15) << "Nota" << endl;
  for (unsigned int as = 0; as < v[al].numeroAsignaturas(); as++)
  {
    CAsignatura *asig = v[al].obtenerAsignatura(as);
    cout << left << setw(25) << asig->obtenerNombre();
    for (i = 1; i <= asig->convocatoriasConsumidas(); i++)
    {
      c = asig->obtenerConvocatoria(i);
      cout << right << setw(15) << c.obtenerConvocatoria()
            << setw(15) << c.obtenerNota() << endl
            << left << setw(25) << "";
    }
    if (asig->convocatoriasConsumidas() == 0)
      cout << right << setw(30) << "NP" << endl;
    cout << endl;
  }
}

int main()
{

  vector<CAlumno> alumno;
  int opcion = 0, id, dni;

  do
  {
    opcion = menu();
    switch (opcion)
    {
      case 1:
        matricular(alumno);
        break;
      case 2:
        cout << "ID asignatura: "; cin >> id;
        poner_notas(alumno, id);
        break;
      case 3:
        cout << "DNI: "; cin >> dni;
        mostrar_expediente(alumno, dni);
        break;
    }
  }
  while(opcion != 4);
}

