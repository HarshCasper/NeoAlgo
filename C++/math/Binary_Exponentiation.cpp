// C++ Program to find Binary Exponent Iteratively and Recursively.

#include <iostream>

// Recursive function to calculate exponent.

int binExpo(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int res = binExpo(a, b / 2);
    if (b % 2)
    {
        return res * res * a;
    }
    else
    {
        return res * res;
    }
}

// Main function

int main()
{
    int a, b;

    std::cin >> a >> b;

    if (a == 0 && b == 0)
    {
        std::cout << "Math Error" << std::endl;
    }
    else if (b < 0)
    {
        std::cout << "Exponent must be Positive" << std::endl;
    }
    else
    {
        int resRecurse = binExpo(a, b);

        std::cout << resRecurse << std::endl;
    }
}