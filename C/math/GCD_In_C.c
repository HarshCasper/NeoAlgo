/*Euclidean Algorithm for GCD
GCD of two numbers is the largest number that divides both of them
*/
#include <stdio.h>

int Euclid_GCD(int, int);
int main()
{
	int num1, num2, gcd;
	printf("Enter the two numbers:");
	scanf("%d %d", &num1, &num2);
	gcd = Euclid_GCD(num1, num2);
	printf("GCD=%d", gcd);
	return 0;
}

// Recursive function to show Euclidean Algorithm
int Euclid_GCD(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	else
		return (Euclid_GCD(num2, num1 % num2));
}

/*
Sample Output
Enter the two numbers:77 121
GCD=11

Complexities
Time Complexity:O(logN)
Space Complexity:O(1)
*/

