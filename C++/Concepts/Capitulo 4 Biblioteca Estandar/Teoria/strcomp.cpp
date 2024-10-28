#include <iostream>
#include <string>

std::string minusculas(std::string& str);

int main()
{
    std::string str1 = "La provincia de Santander es muy bonita";
    std::string str2 = "La provincia de SANTANDER es muy bonita";
    std::string strtemp;

    if(minusculas(str1) > minusculas(str2))
        strtemp = "mayor que ";
    else if(minusculas(str1) < minusculas(str2))
        strtemp = "menor que ";
    else
        strtemp ="igual que ";

    std::cout << str1 << " es " << strtemp << str2 << std::endl;
}

std::string minusculas(std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
    
}