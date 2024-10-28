#include <iostream>
#include <random>
#include <functional>
#include <chrono>
#include <vector>
#include <cmath>

class CRandInt
{
    private:
        std::default_random_engine re; //admite seed
        std::uniform_int_distribution<> dist; // inf- sup
        int semilla;
    public:
        CRandInt(int inf, int sup, int semilla = 0) : dist(inf, sup), re(static_cast<unsigned>(semilla)) {}
        int operator() () {return dist(re);} //retornar int
        
};

int main()
{
    const int N = 6, INF = 1, SUP = 49;
    int n, semilla  = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    CRandInt rnd{INF, SUP, semilla};

    std::vector<int> v;

    for (int i = 0; i < N; i++)
    {
        do
        {
            n = rnd();
        } while (std::find(std::begin(v), std::end(v), n) != std::end(v));
        v.push_back(n);
        
    }

    for (int i = 0; i < v.size(); i++)  std::cout << v[i] << '\t';
    
    std::cout << std::endl;
    
    
}