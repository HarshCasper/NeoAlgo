/*The program is to check whether a given number is a special number or not.
 A special number is a number whose all digits are 1
 Example-11
 */

#include <stdio.h>

void special(int);

int main() {
    int num;
    printf("Enter a number\n");
    scanf("%d",&num);
	/*Calling of function*/
    special(num);
	
	return 0;
}

void special(int n)
{
    int b,s=0,c=0;
    while(n!=0)
    {
        b=n%10;
		/*Sum of digits*/
        s=s+b;
		/*Count of digits*/
        c++;
        n=n/10;
    }
	/*if sum and count are equal
	then special number*/
    if(s==c)
    printf("The given number is special");
    else
    printf("The given number is not special");
}

/*
Time Complexity:O(n)
Space Complexity:O(1)
Input/Output:
Enter a number
123
The given number is not special
*/
