#include <iostream>
using namespace std;
int main()
{
    int value, n1, n2, c1, c2;
    unsigned int order = 32;
    unsigned int mask = 1 << order - 1;
    cout << "Enter the integer number ";
    cin >> value;
    value = ~value;
    for (int i=1; i<=order; i++)
    {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i % order-1 == 0 || i % 8 == 0) putchar(' ');
    }
    cout << endl;
    return 0;
}