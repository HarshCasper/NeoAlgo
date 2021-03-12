/*
By Sidharth Sethi
github - TechSpiritSS
*/
#include <stdio.h>
int main()
{
    int a, b, a1, b1;
    printf("Enter number a and b\n");
    scanf("%d %d", &a, &b);
    // Cloning value of a and b into spare variables
    a1=a;
    b1=b;
    //Loop till both aren't the same
    while(a!=b)
    {
        if(a<b)
            a+=a1;
        else
            b+=b1;
    }
    printf("LCM of %d and %d is %d", a1,b1,a);
}