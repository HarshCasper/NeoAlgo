/*
C Program to check whether a number is Palindrome or not
An integer is a palindrome if the reverse of that number is equal to the original number.
Example of Palindromes are 11,44,101,121,
*/
#include <stdio.h>

int reverse_num(int);
int main()
{
	int n, rev;
	printf("\n Enter a number:");
	scanf("%d", &n);
	rev = reverse_num(n);
	if (rev == n)
	{
		printf("\n %d is a palindrome", n);
	}
	else
	{
		printf("\n %d is not a palindrome", n);
	}
	return 0;
}
int reverse_num(int num)
{
	int rev = 0;
	int rem;
	while (num > 0)
	{
		rem = num % 10;
		rev = rev *10 + rem;
		num = num / 10;
	}
	return rev;
}

/*
Sample Output
Enter a number: 121
121 is a palindrome

Complexities
Time Complexity: O(n)
Space Complexity: O(1)
*/

