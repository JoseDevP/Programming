/*Ejercicio 3: Transferencia de cuentas bancarias
Implementa un sistema de transferencia de dinero entre cuentas bancarias. Cada cuenta 
tiene un saldo, y múltiples hilos intentan transferir dinero de una cuenta a otra.
 Usa std::unique_lock con std::defer_lock y la función std::lock() para evitar 
 interbloqueo mientras bloqueas ambas cuentas durante la transferencia.

Requerimientos:
Crea una clase Cuenta con un saldo y un std::mutex para proteger el acceso al saldo.
Implementa una función transferir que realice la transferencia entre cuentas usando 
std::unique_lock y std::lock() para bloquear las cuentas.
Usa varios hilos para realizar transferencias simultáneas.
*/
#include <iostream>
#include <thread>
#include <mutex>

class CuentaBancaria
{
    private:
        double saldo;
        std::mutex mutex_asignar;
    
    public:
        CuentaBancaria(double sal) : saldo(sal)
        {
            asignarSaldo(sal);
        }

        void asignarSaldo(double sal)
        {
            std::lock_guard<std::mutex> lg(mutex_asignar);
            if(sal < 0)
            {
                saldo = 0;
                return;
            }
            saldo = sal;
        }

        double obtenerSaldo() const
        {
            return saldo;
        }


        friend void Transferir(CuentaBancaria& origen, CuentaBancaria& destino);
};

void Transferir(CuentaBancaria& origen, CuentaBancaria& destino)
{
    std::scoped_lock(origen.mutex_asignar, destino.mutex_asignar);

    if(origen.saldo < 10) return;

    origen.saldo -= 10;
    destino.saldo += 10;
}

int main()
{
    CuentaBancaria cuenta1(100);
    CuentaBancaria cuenta2(0);

    std::thread t1(Transferir, std::ref(cuenta1), std::ref(cuenta2));
    std::thread t2(Transferir, std::ref(cuenta1), std::ref(cuenta2));
    std::thread t3(Transferir, std::ref(cuenta1), std::ref(cuenta2));
    std::thread t4(Transferir, std::ref(cuenta1), std::ref(cuenta2));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "Saldo cuenta 1: " << cuenta1.obtenerSaldo() << std::endl;
    std::cout << "Saldo cuenta 2: " << cuenta2.obtenerSaldo() << std::endl;

    return 0;
}



