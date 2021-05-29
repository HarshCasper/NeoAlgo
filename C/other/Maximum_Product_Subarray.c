/* Find the maximum product subarray of a given array */

#include<stdio.h>
/* Function for finding minimum of two numbers */
int min(int p, int q)
{
    if (p < q)
        return p;
    else
        return q;
}

/* Function for finding maximum of two numbers */
int max(int p, int q)
{
    if (p > q)
        return p;
    else
        return q;
}

/* Function for finding maximum product subarray */
int solve()
{
    /* Input size of an array */
    int n;
    scanf("%d", &n);

    /* Declear an array*/
    int a[n];

    /* Input values in an array */
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &a[i]);
    }

    int maxend = 0, minend = 0;
    int maxupto = 0;

    /* traverse the given array */
    for (int i = 0; i < n; i++)
    {
        int temp = maxend;
        /* Update the maximum product */
        maxend = max(a[i], max(a[i] * maxend, a[i] * minend));

        /* Update the minimum product */
        minend = min(a[i], min(a[i] * temp, a[i] * minend));
        maxupto = max(maxupto, maxend);
    }

    /* Return the maximum product */
    return maxupto;
}

int main()
{
    int k = solve();

    printf("The maximum product of a subarray is %d", k);
    return 0;
}

/*
Test cases :

    Input 1 :

        8
        -4 9 -7 0 -15 6 2 -3

    Output 1 :

        The maximum product of a subarray is 540

    Input 2 :

        5
        6 -3 -10 0 2

    Output 2 :

        The maximum product of a subarray is 180

    Time complexity: O(n)
    Space Complexity: O(1)
*/
