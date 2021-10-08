#include <iostream>
#include <cmath>

int main()
{
    int order = 0, mantissa, Order[12] = {}, Mantissa[52] = {};
    float number;
    bool sign_Order, sign_Mantissa;
    std::cin >> number;
    sign_Mantissa = number < 0;
    if (sign_Mantissa)
        number = -number;
    while (number >= 1)
    {
        number /= 10;
        order += 1;
    }
    while (number < 0.1)
    {
        number *= 10;
        order -= 1;
    }
    sign_Order = order < 0;
    float fraction = 1;
    while (fraction != 0)
    {
        int integer = (int)number;
        fraction = number - integer;
        number *= 10;
    }
    mantissa = number / 10;
    for (int i = 11; i >= 0; i--)
    {
        if (order >= pow(2, i))
        {
            Order[11-i] = 1;
            order -= pow(2, i);
        }
    }
    if (sign_Order)
    {
        for (int k = 0; k < 12; k++)
        {
            if (Order[k] == 0)
                Order[k] = 1;
            else
                Order[k] = 0;
        }
        if (Order[11] == 1)
        {
            for (int c = 11; c >= 0; c--)
            {
                if (Order[c])
                    Order[c] = 0;
                else
                {
                    Order[c] = 1;
                    break;
                }
            }
        }
        else
            Order[11] = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        if ((i % 8 == 0) || (i == 1)) 
            std::cout << " " << Order[i];
        else 
            std::cout << Order[i];
    }
    for (int i = 51; i >= 0; i--)
    {
        if (mantissa >= pow(2, i))
        {
            Mantissa[51-i] = 1;
            mantissa -= pow(2, i);
        }
    }
    if (sign_Mantissa)
    {
        for (int k = 0; k < 52; k++)
        {
            if (Mantissa[k] == 0)
                Mantissa[k] = 1;
            else
                Mantissa[k] = 0;
        }
        if (Mantissa[51] == 1)
        {
            for (int c = 51; c >= 0; c--)
            {
                if (Mantissa[c])
                    Mantissa[c] = 0;
                else
                {
                    Mantissa[c] = 1;
                    break;
                }
            }
        }
        else
            Mantissa[51] = 1;
    }
    for (int i = 0; i < 52; i++)
    {
        if ((i % 8 == 0) || (i == 1)) 
            std::cout << " " << Mantissa[i];
        else 
            std::cout << Mantissa[i];
    }
    return 0;
}