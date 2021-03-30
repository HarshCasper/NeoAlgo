//C Program to check a number is Happy Number or not.
#include <stdio.h>

int happy_number(int);
int main()
{
	int n, ans;
	printf("Enter a number: ");
	scanf("%d", &n);
	ans = happy_number(n);
	if (ans == 1)
		printf("%d is a happy number", n);
	else
		printf("%d is not a happy number", n);
	return 0;
}

// Function to check if the number is a happy number or not
int happy_number(int n)
{
	int temp = n;
	int sum = 0, digit;
	while (sum != 1 && sum != 4)
	{
		sum = 0;
		while (temp != 0)
		{
			digit = temp % 10;
			sum += digit * digit;
			temp = temp / 10;
		}

		temp = sum;

	}

	return sum;
}

/*
Sample Output:
Enter a number: 32
32 is a happy number.

Complexities
Time Complexity:O(logn)
Space Complexity:O(1)
*/

