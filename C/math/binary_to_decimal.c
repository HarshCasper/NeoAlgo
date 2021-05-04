/*
AIM - To take binary number from the user 
      and convert it into binary number.
*/
#include <stdio.h>
#include <stdlib.h>

/*Function decleration*/
int BtoD (char s[]);

int main()
{
    char z[100];
    printf("Enter the binary number : ");
    gets(z);
    printf("Decimal equivalent = %d",BtoD(z));
    return 0;
}
/*Function to convert binary to decimal*/
int BtoD (char s[])
{
    int i,d=0;
    for(i=0;s[i];i++)
    {
        if(s[i]=='0')
            d=d*2+0;
        else
            d=d*2+1;
    }
    return(d);
}

/*

Sample Input/Output:

Enter the binary number : 1111
Decimal equivalent = 15


Time Complexity : O(n)
Space Complexity : O(n)

*/
