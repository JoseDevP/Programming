#include <iostream>

class Cx
{
    private:
        int a[25];
    public:
        Cx() {}
        ~Cx() {}
        // ...
};

int main()
{
    Cx* p = 0;
    int n = 10;

    try
    {
        p = new Cx[n];
    }
    catch( std::bad_alloc& e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
    delete[] p;
}