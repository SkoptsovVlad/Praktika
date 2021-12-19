#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void PrintArray(int& A, int n);
void Paragraph1a(int& A, int n);
void Paragraph1b(int& A, int n);
void HorizontalTransposition(int& A, int n);
void VerticalTransposition(int& A, int n);
void Transposition(int& A, int n);
void ShakerSort(int& A, int n);

int main(){
    // пункт 1a
    int N, go;
    cout << "Paragraph 1a" << endl;
    cout << "Enter the size of matrix ";
    cin >> N; 
    int Arr1[N][N] = {};
    Paragraph1a(Arr1[0][0], N);
    cout << "Continue? ";
    cin >> go;
    cout << endl;
    // пункт 1b
    cout << "Paragraph 1b" << endl;
    cout << "Enter the size of matrix ";
    cin >> N; 
    int Arr[N][N] = {};
    Paragraph1b(Arr[0][0], N);
    cout << "Continue? ";
    cin >> go;
    cout << endl;
    // пункт 2a
    cout << "Paragraph 2a" << endl;
    Transposition(Arr[0][0], N);
    HorizontalTransposition(Arr[0][0], N);
    PrintArray(Arr[0][0], N);
    cout << "Continue? ";
    cin >> go;
    cout << endl;
    // пункт 2b
    cout << "Paragraph 2b" << endl;
    HorizontalTransposition(Arr[0][0], N);
    VerticalTransposition(Arr[0][0], N);
    PrintArray(Arr[0][0], N);
    cout << "Continue? ";
    cin >> go;
    cout << endl;
    // пункт 2c
    cout << "Paragraph 2c" << endl;
    VerticalTransposition(Arr[0][0], N);
    PrintArray(Arr[0][0], N);
    cout << "Continue? ";
    cin >> go;
    cout << endl;
    // пункт 2d
    cout << "Paragraph 2d" << endl;
    HorizontalTransposition(Arr[0][0], N);
    PrintArray(Arr[0][0], N);
    cout << "Continue? ";
    cin >> go;
    cout << endl;
    // пункт 3
    cout << "Paragraph 3" << endl;
    ShakerSort(Arr[0][0], N);
    PrintArray(Arr[0][0], N);
    cout << "Continue? ";
    cin >> go;
    cout << endl;
    // пункт 4
    cout << "Paragraph 4" << endl;
    int number;
    char operation;
    cout << "Enter the number and operation ";
    cin >> number >> operation;
    switch (operation)
    {
    case '+':
        for (int i=0, *Next=&Arr[0][0], *End=Next+N*N; Next<End; i++, Next++)
            *Next += number;
        PrintArray(Arr[0][0], N);
        break;
    case '-':
        for (int i=0, *Next=&Arr[0][0], *End=Next+N*N; Next<End; i++, Next++)
            *Next -= number;
        PrintArray(Arr[0][0], N);
        break;
    case '*':
        for (int i=0, *Next=&Arr[0][0], *End=Next+N*N; Next<End; i++, Next++)
            *Next *= number;
        PrintArray(Arr[0][0], N);
        break;
    case '/':
        for (int i=0, *Next=&Arr[0][0], *End=Next+N*N; Next<End; i++, Next++)
            *Next /= number;
        PrintArray(Arr[0][0], N);
        break;
    default:
        cout << "Error" << endl;
        break;
    }
    return 0;
}

void PrintArray(int& A, int n)
{
    int *a = &A;
    for (int i=0, *Next=a, *End=Next+n*n; Next<End; i++, Next++){
        cout << setw(4) << *Next;
        if (i % n == n-1) cout << endl;
    }
    cout << endl;
}
void Paragraph1a(int& A, int n)
{
    int *Begin = &A, *End=Begin+n*n-1;
    for (int i=0; i<n-1; Begin++, i++){
        *Begin = 1 + rand()%(n*n-1);
        PrintArray(A, n);
    }
    int temp = n-1, sign = 1;
    while (temp > 0){
        for (int i=0; i<temp; Begin+=n*sign, i++){
            *Begin = 1 + rand()%(n*n-1);
            PrintArray(A, n);
        }
        for (int i=0; i<temp; Begin-=sign, i++){
            *Begin = 1 + rand()%(n*n-1);
            PrintArray(A, n);
        }
        temp--;
        sign = -sign;
    }
    *Begin = 1 + rand()%(n*n-1);
    PrintArray(A, n);
}
void Paragraph1b(int& A, int n)
{
    int *Begin = &A, *End=Begin+n*n-1;
    int sign = 1;
    for (int c=0; c<n; c++){
        for (int i=0; i<n-1; Begin+=n*sign, i++){
            *Begin = 1 + rand()%(n*n-1);
            PrintArray(A, n);
        }
        *Begin = 1 + rand()%(n*n-1);
        PrintArray(A, n);
        Begin++;
        sign = -sign;
    }
}
void HorizontalTransposition(int& A, int n)
{
    int *a = &A, mid = n / 2;
    for (int i=0, *Begin=a; i<n; i++, Begin+=n)
        for (int j=0; j<mid; j++)
            std::swap(*(Begin+j), *(Begin+mid+j));
}
void VerticalTransposition(int& A, int n)
{
    int *a = &A, mid = n / 2;
    for (int i=0, *Begin=a; i<mid*n; i++, Begin++)
        std::swap(*(Begin), *(Begin+mid*n));
}
void Transposition(int& A, int n)
{
    int *a = &A, mid = n / 2, difference = (n*n - n) / 2;
    for (int c=0; c<=(mid-1)*n; c+=n)
        for (int i=0, *Begin=a+mid+c; i<mid; i++, Begin++)
            std::swap(*(Begin), *(Begin+difference));
}
void ShakerSort(int& A, int n)
{
    bool flag = true;
    int *Begin=&A, *End=Begin+n*n;
    while (flag) 
    {
        flag = false;
        for (int *Next=Begin; Next<End; Next++)
            if (*Next > *(Next+1))
            {
                std::swap (*Next, *(Next+1));
                flag = true;
            }
        End--;
        for (int *Next=End; Next>Begin; Next--)
            if (*Next < *(Next-1))
            {
                std::swap (*Next, *(Next-1));
                flag = true;
            }
        Begin++;
    }
}