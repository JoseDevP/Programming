#if !defined (_HILO_HPP_)
#define _HILO_HPP_

#include <iostream>
#include <string>
#include <thread>

class CHilo
{
    private:
        std::string m_nombreHilo;
        std::thread m_hilo;
        static void ejec_hilo(CHilo*);

    protected:
        virtual void fnHilo() = 0;

    public:
        CHilo(std::string nom = "");
        void iniciar();
        void esperar_finalizacion();

        std::string obtener_nombre() const;
        void asignar_nombre(std::string);
        std::thread::id obtener_id() const;
};

CHilo::CHilo(std::string nom = "") : m_nombreHilo(nom) {}

void CHilo::iniciar()
{
    m_hilo = std::thread(ejec_hilo, this);
}

void CHilo::ejec_hilo(CHilo* pHilo)
{
    pHilo->fnHilo();
}

void CHilo::esperar_finalizacion()
{
    if (m_hilo.joinable()) m_hilo.join();
}

std::string CHilo::obtener_nombre() const
{
    return m_nombreHilo;
}

void CHilo::asignar_nombre(std::string nom) 
{
    m_nombreHilo = nom;
}

std::thread::id CHilo::obtener_id() const
{
    return m_hilo.get_id();
}

#endif