#include <fstream>
#include <string>
#include <iostream>

int main()
{
    try
    {
        const char* provincia[] = {"Madrid", "Santander", "Sevilla",
                             "A Coruña", "Valencia"};
                             
        std::fstream fs;
        std::string nombreArchivo = "datos";
        fs.open(nombreArchivo, std::ios::out|std::ios::trunc|std::ios::in);

        if(!fs) throw "No se puede abrir el archivo";

        for (int i = 0; i < sizeof(provincia)/sizeof(const char*); i++)
            fs << provincia[i] << "\n";

        std::string str;
        fs.seekg(std::ios::beg);
        for (int i = 0; i < sizeof(provincia)/sizeof(const char*); i++)
        {
            std::getline(fs, str);
            //fs >> str; interpretaria el espacio como separador
            std::cout << str << std::endl;
        } 
    }
    catch(const char* str)
    {
        std::cerr << str << '\n';
    }
    
}