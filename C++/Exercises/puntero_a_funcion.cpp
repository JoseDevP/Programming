#include <iostream>

using namespace std;

void (*funcA())(const string&);
void funcE(const string&);

int main()
{
    //void (*pf)(const string&) =funcE;
    //pf("Leonor");
    funcA()("Leonor");
}

void funcE(const string& s)
{
    cout << "Hola " << s << '\n';
}

//void (*funcA())(const string&)
//{
//    return funcE;
//}
//o tambien
auto funcA() ->void(*)(const string&)
{
    return funcE;
}