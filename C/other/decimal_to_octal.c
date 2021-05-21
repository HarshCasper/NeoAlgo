/*
AIM - To take decimal number from the user
      and convert it into octal number.
*/
#include <stdio.h>
#include <stdlib.h>

/*Function declaration*/
int DecimaltoOctal (int);

int main()
{
    int decimal;
    printf("Enter the decimal-number : ");
    scanf("%d",&decimal);
    printf("Octal equivalent = %d",DecimaltoOctal(decimal));
    return 0;
}
/*Function to convert decimal to octal*/
int DecimaltoOctal(int decimal)
{
    int octal=0,remainder=0,position=1;
    while(decimal!=0)
    {
        remainder=decimal%8;
        octal=remainder*position+octal;
        position=position*10;
        decimal=decimal/8;
    }
    return(octal);
}

/*

Sample Input/Output:

Enter the decimal-number : 125
Octal equivalent = 175


Time Complexity : O(n)
Space Complexity : O(1)

*/


