/* Program to convert decimal number system to octal number system.
Decimal number: The number with base 10 is called Decimal number.
Octal Number: The number with base 8 is called Octal number. */

#include<stdio.h>
//Function which convert decimal to octal and print it
void conversion(int n)
{
     if(n==0)                                                         /*base case when the recursion will stop */
      return;                                                        /* returns nothing */
      dec_to_oct(n/8);                                              /* the function will call itself by passing n/8 */
      printf("%d",n%8);                                            /* print the n%8 value ex. n=2 so the n%8=2 */
        return;                                                   /* returns nothing */
}
//driver code
int main()
{
    int Num;
    printf("Enter a Number: ");
    scanf("%d",&Num);     /* taking input */
    if(Num<0)
    {
    printf("The octal conversion of %d is: -",Num);          /* providing better UI to user */
    Num=Num*-1;                                             /* converting no into a positive one */
    }
else
    printf("The octal conversion of %d is: ",Num);        /* providing better UI to user */
    conversion(Num);                                     /* function to convert decimal to octal */
    return 0;

}
/*
Example:
case 1:
Input: Enter a Number: 16
Output: The octal conversion of 16 is: 20
case 2:
Input: Enter a Number: -10
Output: The octal conversion of -10 is -12

Time complexity:O(n)
Space Complexity:O(1)

*/
