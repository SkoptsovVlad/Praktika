#include <iostream>
#include <cmath>

int main()
{
    int Mantissa[23] = {}, Exp[8] = {};
    float number;
    bool sign;
    std::cin >> number;
    sign = number < 0;
    if (sign) number = -number;
    long int integer_part = (int)number, exp = 0;
    float fractional_part = number - integer_part;
    integer_part /= 2;
    for (int i = 0; i < 24; i++)
    {
        if (integer_part < pow(2, i))
        {
            exp = i;
            break;
        }
    }
    if (integer_part == 0)
    {
        exp = 0;
        while (fractional_part < 1)
        {
            fractional_part = fractional_part*2;
            exp -= 1;
        }
        fractional_part -= 1;
    for (int c=0; c<23; c++)
        {
        Mantissa[c] = (int)(fractional_part*2);
        fractional_part = fractional_part*2-Mantissa[c];
        }
    }
    else
    {
    for (int k = 0; k < 23; k++)
    {
        if (integer_part >= pow(2, (exp-1-k)))
        {
        Mantissa[k] = 1;
        integer_part -= pow(2, (exp-1-k));
        }
    }
    for (int c=exp; c<23; c++)
        {
        Mantissa[c] = (int)(fractional_part*2);
        fractional_part = fractional_part*2-Mantissa[c];
        }
    }
    exp += 127;
    for (int i=0; i<8; i++)
    {
        Exp[7-i] = exp % 2;
        exp = exp / 2;
    }
    std::cout << sign << " ";
    for (int i=0; i<8; i++)
        std::cout << Exp[i];
    std::cout << " ";
    for (int i=0; i<23; i++)
        std::cout << Mantissa[i];
    return 0;
}