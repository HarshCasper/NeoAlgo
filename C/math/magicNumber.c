
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int s = 0, r;
    printf("Enter number to check: ");
    scanf("%d", &n);

    while (n > 9)
    {
        s = 0;

        while (n != 0)
        {
            r = n % 10;
            n = n / 10;
            s = s + r;
        }
        n = s;
    }

    if (n == 1)
        printf("It's a Magic Number \n");

    else
    {
        printf("It's NOT a Magic Number \n");
    }

    return 0;
}