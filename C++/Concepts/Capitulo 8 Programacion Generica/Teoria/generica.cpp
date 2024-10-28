#include <iostream>

class T
{
    private:
        int a;
    public:
        T(int p = 0) :a(p) {}
        int get() const { return a; }
};

int i;

template<typename T = int, T i = 0>
T f(T x)
{
    T v1 = i + x;
    ::T v2 = ::i = v1;
    return v2.get();
}

template<typename T2 = int>
T2 menor(T2 x, T2 y)
{
    return (x < y) ? x : y;
} 

int main()
{
    constexpr int k = 0;
    std::cout << f<int, k>(12) << std::endl;
    std::cout << menor<double>(3.45, 5.66);
}
