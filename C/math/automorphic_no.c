/*
C program to check whether the number is automorphic or not.
Automorphic number is a number whose square ends with the original number itself
*/
#include <stdio.h>

int automorphic_num(int);
int main()
{
	int n, l;
	printf("Enter the number to check:\n");
	scanf("%d", &n);
	l = automorphic_num(n);
	if (l == n)
		printf("\nAUTOMORPHIC NUMBER !");
	else
		printf("\nNOT AUTOMORPHIC NUMBER !");
	return 0;
}

// Function to check if the number is automorphic or not
int automorphic_num(int n)
{
	int s, temp, l;
	temp = n;
	s = n * n;
	int flag = 1;
	while (n != 0)
	{
		flag = flag * 10;
		n = n / 10;
	}

	l = s % flag;
	return l;
}

/*
Sample Input-Output:1
Enter the number to check:
7
NOT AUTOMORPHIC NUMBER !

Sample Input-Output:2
Enter the number to check:
5
AUTOMORPHIC NUMBER !

Time Complexity: O(n)
*/

