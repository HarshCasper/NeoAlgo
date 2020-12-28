#include <stdio.h>
#include <math.h>

int main()
{
    int n, f = 1, s = 0, i, r;

    printf("Enter decimal number to convert: ");
    scanf("%d", &n);

    while (n != 0)
    {
        r = n % 2;
        n = n / 2;
        s = s + r * f;

        f = f * 10;
    }

    printf("Binary form is: %d \n", s);
}
