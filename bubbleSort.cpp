#include <iostream>
#include <utility>
using std::swap;

int main()
{
    int N = 100, unsorted_array[N];
    for (int& x: unsorted_array) 
        x = rand() % 199 - 99;

    int sorted_array[N];
    for (int i=0; i<N; i++)
        sorted_array[i] = unsorted_array[i];
    
    for (int i=0; i<N-1; i++)
    {
        bool flag = true;
        for (int j=0; j<N-1-i; j++)
            if (sorted_array[j] > sorted_array[j+1])
            {
                swap (sorted_array[j], sorted_array[j+1]);
                flag = false;
            }
        if (flag) break;
    }
    for (int& x: sorted_array)
        std::cout << x << ' ';
    return 0;
}