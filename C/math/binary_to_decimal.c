/*
AIM - To take binary number from the user 
      and convert it into binary number.
*/
#include <stdio.h>
#include <stdlib.h>

/*Function decleration*/
int BinarytoDecimal (char s[]);

int main()
{
    char temp[100];
    printf("Enter the binary number : ");
    gets(temp);
    printf("Decimal equivalent = %d",BinarytoDecimal(temp));
    return 0;
}
/*Function to convert binary to decimal*/
int BinarytoDecimal (char temp[])
{
    int i,decimal=0;
    for(i=0;temp[i];i++)
    {
        if(temp[i]=='0')
            decimal=decimal*2+0;
        else
            decimal=decimal*2+1;
    }
    return(decimal);
}

/*

Sample Input/Output:

Enter the binary number : 1111
Decimal equivalent = 15


Time Complexity : O(n)
Space Complexity : O(n)

*/
