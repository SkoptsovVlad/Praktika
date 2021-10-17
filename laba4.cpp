#include <iostream>
using namespace std;
int main()
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
    return 0;
}