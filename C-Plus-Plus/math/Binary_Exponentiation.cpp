// C++ Program to find Binary Exponent Iteratively and Recursively.

#include <iostream>

// Iterative function to calculate exponent.

int binExpo_iterate(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2)
        {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

// Recursive function to calculate exponent.

int binExpo_recurse(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int res = binExpo_recurse(a, b / 2);
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
        int resIterate = binExpo_iterate(a, b);
        int resRecurse = binExpo_recurse(a, b);

        std::cout << resIterate << std::endl;
        std::cout << resRecurse << std::endl;
    }
}