/*
C Program to check whether a number is Palindrome or not
An integer is a palindrome if the reverse of that number is equal to the original number.
Example of Palindromes are 11,44,101,121,
*/

#include <stdio.h>
#include <unistd.h>

void main()
{
	int rev = 0, rem = 0, n, num ;
	printf("\n Enter a number:\t");
	scanf("%d", &n);
	num = n;
	printf("\n Reverse of %d is ", n);
	while (n > 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n = n / 10;
	}

	printf("%d", rev);
	if (rev == num)
	{
		printf("\n %d is a palindrome", num);
	}
	else
	{
		printf("\n %d is not a palindrome", num);
	}

	getchar();
}

/*
Sample Case:
Example 1:
Enter a number: 121
Reverse of 121 is 121
121 is a palindrome

Example 2:
Enter a number: 123
Reverse of 123 is 321
321 is not a palindrome

Time Complexity: O(n)
Space Complexity: O(1)
*/
