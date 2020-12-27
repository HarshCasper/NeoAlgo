#include <stdio.h>
#include <math.h>

int main()
{
    int n, r, sum = 0;

    printf("Enter the number to check: ");
    scanf("%d", &n);

    int n1 = n;
    while (n > 0)
    {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }

    if (n1 == sum)
    {
        printf("It's a palindrome number \n");
    }
    else
    {
        printf("It's not a palindrome number \n");
    }
}