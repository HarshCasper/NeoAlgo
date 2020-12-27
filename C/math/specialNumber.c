#include <stdio.h>
#include <math.h>

int main()
{
    int n, n1, i, r, sum = 0;

    printf("Enter the number to check: ");
    scanf("%d", &n);

    n1 = n;
    while (n > 0)
    {
        r = n % 10;
        int fact = 1;
        for (i = 1; i <= r; i++)
        {
            fact = fact * i;
        }
        sum = sum + fact;
        n = n / 10;
    }
    if (n1 == sum)
    {
        printf("It's a Special Number!\n");
    }
    else
    {
        printf("It's NOT a Special Number\n");
    }
}
