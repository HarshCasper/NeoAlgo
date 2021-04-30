/*
C program to find the N'th Lucas Number.
Lucas Numbers is a sequence similar to Fibonacci numbers and is defined 
as the sum of its two immediately previous terms.
The first and second numbers in Lucas sequence are 2 and 1 respectively.
*/
#include <stdio.h>

int lucas_num(int n)
{
    int l1 = 2, l2 = 1;
    if (n == 0)
        return l1;

    for (int i = 2; i <= n; i++)
    {
        int next = l1 + l2;
        l1 = l2;
        l2 = next;
    }
    return l2;
}

int main()
{
    int n;
    printf("Enter the value of n(where you need the nth lucas number): ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Invalid Value of n !!!");
        return 0;
    }
    int res = lucas_num(n);
    printf("The %d'th Lucas Number is %d.", n, res);
    return 0;
}

/*
Time Complexity - O(n), where `n` is the given number.
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the value of n(where you need the nth lucas number): 25
The 25'th Lucas Number is 167761.
*/
