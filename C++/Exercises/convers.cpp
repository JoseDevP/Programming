#include <iostream>
#include <string>

int main()
{
    try
    {
        std::string str1 = "54";
        std::string str2 = "3.1416";
        std::string str3 = "31080 personas";
        std::string str4 = "uno, dos y 3";

        int int1 = std::stoi(str1);
        int int2 = std::stoi(str2);
        int int3 = std::stoi(str3);
        //int int4 = std::stoi(str4); //error std::invalid_argument
        double double1 = std::stod(str2);

        std::cout << "std::stoi(\"" << str1 << "\") es " << int1 << '\n';
        std::cout << "std::stoi(\"" << str2 << "\") es " << int2 << '\n';
        std::cout << "std::stoi(\"" << str3 << "\") es " << int3 << '\n';
        std::cout << "std::stod(\"" << str2 << "\") es " << double1 << '\n';

        double f = 3.1416;
        std::string str5 = std::to_string(f);
        std::cout << f << '\n' << "to_string: " << str5 << '\n';
    }
    catch(const std::exception e)
    {
        std::cerr << e.what() << '\n';
    }
    
}