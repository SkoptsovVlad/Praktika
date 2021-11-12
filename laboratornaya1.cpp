#include <iostream>
#include <cmath>
using namespace std;

void lab1();
void lab2();
void lab3();
void lab4();

int main()
{
    lab1();
    lab2();
    lab3();
    lab4();
    return 0;
}

void lab1()
{
    cout << "int = " << sizeof(int) << endl;
    cout << "short int = " << sizeof(short int) << endl;
    cout << "long int = " << sizeof(long int) << endl;
    cout << "float = " << sizeof(float) << endl;
    cout << "double = " << sizeof(double) << endl;
    cout << "long double = " << sizeof(long double) << endl;
    cout << "char = " << sizeof(char) << endl;
    cout << "bool = " << sizeof(bool) << endl;
}

void lab2()
{
    int number;
    unsigned int order = 32;
    unsigned int mask = 1 << order - 1;
    cout << "Enter the integer number ";
    cin >> number;
    for (int i=1; i<=order; i++)
    {
        putchar(number & mask ? '1' : '0');
        number <<= 1;
        if (i % order-1 == 0 || i % 8 == 0) putchar(' ');
    }
    cout << endl;
}

void lab3()
{
    union
    {
        int tool;
        float number = 3.14;
    };
    unsigned int order = 32;
    unsigned int mask = 1 << order - 1;
    cout << "Enter the fractonal number ";
    cin >> number;
    for (int i=1; i<=order; i++)
    {
        putchar(tool & mask ? '1' : '0');
        tool <<= 1;
        if (i % 8 == 1 && i < 10) putchar(' ');
    }
    cout << endl;
}

void lab4()
{
    union
    {
        int A[2];
        double number = 3.14;
    };
    unsigned int order = 32;
    unsigned int mask = 1 << order - 1;
    cout << "Enter the fractonal number ";
    cin >> number;
    for (int c=1; c>=0; c--)
    {
        for (int i=1; i<=order; i++)
        {
            putchar(A[c] & mask ? '1' : '0');
            A[c] <<= 1;
            if ((i == 1 || i == 12) && c==1) putchar(' ');
        }
    }
    cout << endl;
}