#include <iostream>
#include <utility>
#include <cmath>
#include <random>

int main()
{
    int N = 10, sorted_array[10];
    for (int& x : sorted_array)
        x = rand()%10;
    for (int& x: sorted_array)
        std::cout << x << ' ';
    std::cout << std::endl;
    float k = 1.247, S = N-1;
    while (S >= 1)
    {
        for (int i=0; i+S<N; i++)
        {
            if (sorted_array[i] > sorted_array[int(i+S)])
                std::swap (sorted_array[i], sorted_array[int(i+S)]);
        }
        S /= k;
    }

    for (int& x: sorted_array)
        std::cout << x << ' ';
    return 0;
}