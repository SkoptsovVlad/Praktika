#include <iostream>
#include <utility>

int main()
{
    int N = 100, unsorted_array[N];
    for (int& x: unsorted_array) 
        x = rand() % 199 - 99;

    int sorted_array[N];
    for (int i=0; i<N; i++)
        sorted_array[i] = unsorted_array[i];

    
    bool flag = true;
    int start = 0, end = N-1;
    while (flag) 
    {
        flag = false;
        for (int i=start; i<end; i++)
            if (sorted_array[i] > sorted_array[i+1])
            {
                std::swap (sorted_array[i], sorted_array[i+1]);
                flag = true;
            }
        end--;
        for (int j=end; j>start; j--)
            if (sorted_array[j] < sorted_array[j-1])
            {
                std::swap (sorted_array[j], sorted_array[j-1]);
                flag = true;
            }
        start++;
    }


    for (int x: sorted_array)
        std::cout << x << ' ';
    return 0;
}