// A number is said to be Magic Number, when the recursive sum of the digits is 1.
#include <stdio.h>

int calsum(int);
int magic_num(int);
int main()
{
	int num;
	printf("Enter the number to be checked:");
	scanf("%d", &num);
	if (magic_num(num) == 1)
		printf("%d is a magic number", num);
	else
		printf("%d is not a magic number", num);
	return 0;
}

// Function to check if the number is a magic number or not
int magic_num(int num)
{
	int sum;
	while (num > 9)
	{
		sum = calsum(num);
		num = sum;
	}

	return num;
}

// Function to calculate the sum of digits
int calsum(int num)
{
	int sum = 0, rem;
	while (num > 0)
	{
		rem = num % 10;
		sum = sum + rem;
		num = num / 10;
	}

	return sum;
}

/*
Sample Output
Enter the number to be checked:1729
1729 is a magic number

Complexities
Time Complexity:O(n)
Space Complexity:O(n)
*/

