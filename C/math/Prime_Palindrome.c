/*
Sidharth Sethi
GitHub - TechSpiritSS
*/

#include<stdio.h>

int isPrime (int a)
{
    if( a <= 1)
        return 0;
    for(int i=2; i*i <= a; i++)
        if(a % i == 0)
            return 0;
    return 1;
}

int isPalindrome(int a)
{
    int A = a;
    int b = 0;
    while( a > 0)
    {
        b *= 10;
        int last = a % 10;
        a /= 10;
        b += last;
    }

    if(A == b)
        return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        if(isPrime(i))
            if(isPalindrome(i))
                printf("%d \n", i);

    return 0;
}

/*

Time Complexity is O(n*n) I don't know about Palindrome so I am taking it as 1

Space Complexity is O(1) it remains constant

Example
Input
500

Output
2
3
5
7
11
101
131
151
181
191
313
353
373
383

*/