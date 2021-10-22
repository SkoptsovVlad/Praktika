#include <iostream>
using namespace std;
int main()
{
    int value, n1, n2, c1, c2;
    unsigned int order = 32;
    unsigned int mask = 1 << order - 1;
    cout << "Enter the integer number ";
    cin >> value;
    cin >> c1 >> c2;
    n1 = value & 1 << c1-1;
    n2 = value & 1 << c2-1;

    for (int i=1; i<=order; i++)
    {
        if (i==(33-c1)) putchar(n2 ? '1' : '0');
        if (i==(33-c2)) putchar(n1 ? '1' : '0');
        if (i!=(33-c1) && i!=(33-c2)) putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i % order-1 == 0 || i % 8 == 0) putchar(' ');
    }
    cout << endl;
    return 0;
}