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
    
    for (int i=1; i<N; i++)
    {
        int temp = sorted_array[i];
        int j = i;
        while (j>0 and sorted_array[j-1]>temp)
        {
            sorted_array[j] = sorted_array[j-1];
            j--;
        }
        sorted_array[j] = temp;
    }

    for (int& x: sorted_array)
        std::cout << x << ' ';
    return 0;
}