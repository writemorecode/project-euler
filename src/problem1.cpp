/**
 * Project Euler
 * Problem 1 - Multiples of 3 and 5
 * */

#include <iostream>

int main(void)
{
    int sum = 0;
    int i = 0;

    while(true)
    {
        if(i >= 1000)
        {
            break;
        }
        if(i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
        i++;
    }

    std::cout << sum << std::endl;

    return 0;
            
}
