#include <stdio.h>
#include <math.h>

int main()
{
    int n, f = 1, s = 0, i, r;

    printf("Enter binary number to convert: ");
    scanf("%d", &n);

    while (n != 0)
    {
        r = n % 10;
        n = n / 10;
        s = s + r * f;

        f = f * 2;
    }

    printf("Decimal form is: %d \n", s);
}
