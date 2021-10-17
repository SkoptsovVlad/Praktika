#include <iostream>
using namespace std;
int main()
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
    return 0;
}