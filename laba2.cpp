#include <iostream>
#include <cmath>

int main()
{
    int number, A[32] = {};
    bool sign;
    std::cin >> number;
    sign = number < 0;
    number = abs(number);
    for (int i = 31; i >= 0; i--)
    {
        if (number >= pow(2, i))
        {
            A[31-i] = 1;
            number -= pow(2, i);
        }
    }
    if (sign)
    {
        for (int k = 0; k < 32; k++)
        {
            if (A[k] == 0)
                A[k] = 1;
            else
                A[k] = 0;
        }
        if (A[31] == 1)
        {
            for (int c = 31; c >= 0; c--)
            {
                if (A[c])
                    A[c] = 0;
                else
                {
                    A[c] = 1;
                    break;
                }
            }
        }
        else
            A[31] = 1;
    }
    for (int i = 0; i < 32; i++)
    {
        if ((i % 8 == 0) || (i == 1)) 
            std::cout << " " << A[i];
        else 
            std::cout << A[i];
    }
    return 0;
}