// C Program to find Binary Exponent Recursively.

#include <stdio.h>

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

    scanf("%d%d", &a, &b);

    if (a == 0 && b == 0)
    {
        printf("Math Error");
    }
    else if (b < 0)
    {
        printf("Exponent must be Positive");
    }
    else
    {
        int resRecurse = binExpo(a, b);

        printf("%d", resRecurse);
    }
}