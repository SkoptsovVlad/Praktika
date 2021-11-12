#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include <utility>
#include <ctime>

using namespace std;

void paragraph2 (int A[], int size);
void paragraph3a (int A[], int size);
void paragraph3b (int A[], int size);
void paragraph4 (int A[], int size);
void paragraph5 (int A[], int size);
void paragraph6 (int A[], int size);
void paragraph7a (int A[], int size, int x);
void paragraph7b (int A[], int size, int x);
void paragraph8 (int A[], int size);

int main()
{
    // пункт 1
    int N = 100, unsorted_array[N];
    bool answer;
    do 
    {
        cout << "Paragraph №1" << endl;
        srand(time(0));
        for (int& x: unsorted_array) 
            x = rand() % 199 - 99;
        for (int x: unsorted_array)
            cout << x << ' ';
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer; 
        cout << endl;
    } while (answer);

    // создаётся копия массива, которая потом будет отсортирована
    int sorted_array[N];
    for (int i=0; i<N; i++)
        sorted_array[i] = unsorted_array[i];
    
    // пункт 2
    do
    {
        cout << "Paragraph №2" << endl;
        paragraph2(sorted_array, N);
        for (int x: sorted_array)
            cout << x << ' ';
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer;
        cout << endl;
    } while (answer);
    
    // пункт 3
    do
    {
        cout << "Paragraph №3" << endl;
        paragraph3a (unsorted_array, N);
        paragraph3b (sorted_array, N);
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // пункт 4 
    do
    {
        cout << "Paragraph №4" << endl;
        paragraph4 (sorted_array, N);
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // пункт 5
    do
    {
        cout << "Paragraph №5" << endl;
        paragraph5 (sorted_array, N);
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer;
        cout << endl;
    } while (answer);
    
    // пункт 6
    do
    {
        cout << "Paragraph №6" << endl;
        paragraph6 (sorted_array, N);
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // пункт 7
    do
    {
        cout << "Paragraph №7" << endl;
        int X;
        cout << "Enter the number ";
        cin >> X;
        paragraph7a (sorted_array, N, X);
        paragraph7b (sorted_array, N, X);
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // пункт 8
    do
    {
        cout << "Paragraph №8" << endl;
        paragraph8 (sorted_array, N);
        cout << endl;
        cout << "Again? 1 - yes, 0 - no ";
        cin >> answer;
        cout << endl;
    } while (answer);
    return 0;
}

void paragraph2 (int A[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        bool flag = true;
        for (int j=0; j<size-1-i; j++)
            if (A[j] > A[j+1])
            {
                std::swap (A[j], A[j+1]);
                flag = false;
            }
        if (flag) break;
    }
}

void paragraph3a (int A[], int size)
{
    auto start = chrono::high_resolution_clock::now();
    int min = A[0], max = A[0];
    for (int i=0; i<size-1; i++)
    {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Max " << max << ", Min " << min << endl;
    cout << "Duration of the Search in unsorted array " << duration.count()*1000 << "ms." << endl;
}
void paragraph3b (int A[], int size)
{
    auto start = chrono::high_resolution_clock::now();
    int min = A[0], max = A[size-1];
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Duration of the Search in sorted array " << duration.count()*1000 <<  "ms." << endl;
}

void paragraph4 (int A[], int size)
{
    int average = (A[0]+A[size-1])/2, count = 0;
    cout << "Average value " << average << endl;
    for (int i=0; i<size; i++)
    {
        if (A[i] == average) 
        {
            count++;
            cout << average << '[' << i << "] ";
        }
        if (A[i] > average) break;
    }
    cout << endl;
    cout << "The number of elements equal to the average " << count << endl;
}

void paragraph5 (int A[], int size)
{
    int number, value;
    cout << "Enter the number ";
    cin >> number;
    for (int i=0; i<size; i++)
        if (A[i] >= number)
        {
            value = i;
            break;
        }
    cout << "The number of elements less than specified value " << value << endl;
    
}

void paragraph6 (int A[], int size)
{
    int number, value;
    cout << "Enter the number ";
    cin >> number;
    for (int i=0; i<size; i++)
        if (A[size-1-i] <= number)
        {
            value = i;
            break;
        }
    cout << "The number of elements larger than specified value " << value << endl;
}

void paragraph7a (int A[], int size, int x)
{
    int L = 0, R = size, mid;
    auto start = chrono::high_resolution_clock::now();
    while (L < R-1)
    {
        mid = (L+R)/2;
        if (x < A[mid]) R = mid;
        else L = mid;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    if (A[L] == x)
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    cout << "Duration of the Binary search " << duration.count()*1000 << "ms." << endl;
}
void paragraph7b (int A[], int size, int x)
{
    bool found = false;
    auto start = chrono::high_resolution_clock::now();
    for (int i=0; i<size; i++)
        if (A[i] == x)
        {
            found = true;
            break;
        }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Duration of the Brute-force search " << duration.count()*1000 << "ms." << endl;
}

void paragraph8 (int A[], int size)
{
    int index1, index2;
    cout << "Enter the indexes ";
    cin >> index1 >> index2;
    auto start = chrono::high_resolution_clock::now();
    std::swap (A[index1], A[index2]);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    for (int i=0; i<size; i++)
        cout << A[i] << ' ';
    cout << endl;
    cout << "Duration of the Exchange " << duration.count()*1000 << "ms." << endl;
}