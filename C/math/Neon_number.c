// C Program to check whether a number is Neon or not. A neon number is a number where the sum of digits of square of the number is equal to the number.

#include <stdio.h>
#include <math.h>
int neon(int n)
{
    int i, sum = 0, t = 1;
    t = pow(n, 2);
    while (t != 0)
    {
        sum = sum + (t % 10);
        t = t / 10;
    }
    if (sum == n)
    {
        printf("Neon number.\n");
    }
    else
    {
        printf("Not a neon number\n");
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter a number to check wheather it is neon or not- ");
    scanf("%d", &n);
    neon(n);
    return 0;
}
/* Sample Input/output
Example 1-
Enter a number to check wheather it is neon or not- 9
Neon number.
Example 2-
Enter a number to check wheather it is neon or not- 144
Not a neon number
*/
