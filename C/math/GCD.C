/*
Sidharth Sethi
GitHub - TechSpiritSS
*/

#include <stdio.h>

int GCD(int a, int b)
{
    if( a == 0)
        return b;
    else if( b == 0)
        return a;
    else if( a >= b)
        GCD(a-b, b);
    else
        GCD(a, b-a);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", GCD(a,b));

    return 0;
}

/*

time complexity O(N)
space complexity O(1)

Example 1

Input
45 10

Output
5

Example 2

Input
999 465

Output
3

*/