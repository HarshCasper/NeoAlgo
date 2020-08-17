//Implementation of Euler's Totient Function in C

#include<stdio.h>

int gcd(int a, int b)
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int f(unsigned int n)
{
    unsigned int result = 1;

    for(int i = 2; i < n; i++)
    {
        if(gcd(i,n) == 1)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    int result = f(n);

    printf("F(%d) = %d", n, result);

    return 0;
}

/*
SAMPLE INPUT:
5

SAMPLE OUTPUT:
F(5) = 4
*/