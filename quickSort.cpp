#include <iostream>
#include <utility>
#include <random>

void quickSort(int A[], int start, int end);

int main()
{
    int N = 100, unsorted_array[N];
    for (int& x: unsorted_array) 
        x = rand() % 199 - 99;

    int sorted_array[N];
    for (int i=0; i<N; i++)
        sorted_array[i] = unsorted_array[i];
    
    quickSort(sorted_array, 0, N-1);

    for (int& x: sorted_array)
        std::cout << x << ' ';
    return 0;
}

void quickSort(int A[], int start, int end)
    {
        if (start >= end) return;
        int L = start, R = end;
        int X = A[rand() % (end-start+1) + start];
        while (L <= R)
        {
            while (A[L] < X) L++;
            while (A[R] > X) R--;
            if (L <= R)
            {
                std::swap(A[L], A[R]);
                L++;
                R--;
            }
        }
        quickSort(A, start, R);
        quickSort(A, L, end);
    }