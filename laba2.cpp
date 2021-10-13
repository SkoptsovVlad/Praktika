#include <iostream>
#include <cmath>

int main()
{
    long int A[32] = {}, number;
    std::cin >> number;
    if (number < 0) number = pow(2, 32) - abs(number);
    for (int i=0; i<32; i++)
    {
        A[31-i] = number % 2;
        number = number / 2;
    }
    for (int i=0; i<32; i++)
    {   
        if (i%8==7 || i==0)
            std::cout << A[i] << " ";
        else 
            std::cout << A[i];
    }
    return 0;
}