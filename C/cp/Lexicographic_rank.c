// To find the rank of a string among all its lexicographically sorted permutations.
#include <stdio.h>
#include <string.h>

int lexicographic_rank(char*);
int fact(int);
int smallerright(char *, int);
int main()
{
	char string[100];
	printf("Enter the string:");
	scanf("%s", string);
	printf("Lexicographic Rank of the string=%d", lexicographic_rank(string));
}

// Function to calculate the rank of the string
int lexicographic_rank(char *string)
{
	int length = strlen(string);
	int total_permutation = fact(length);
	int i = 0;
	int rank = 1;
	int countsmallright;
	while (*(string + i) != '\0')
	{
		total_permutation = total_permutation / (length - i);
		countsmallright = smallerright(string, i);
		rank = rank + (countsmallright *total_permutation);
		i++;
	}

	return rank;
}

// Function to check if the element on the right side is smaller than the index ith element
int smallerright(char *string, int index)
{
	int i = index;
	int count = 0;
	while (*(string + i) != '\0')
	{
		if (*(string + i)<*(string + index))
		{
			count = count + 1;
		}
		i++;
	}

	return count;
}

// To calculate factorial of a number using recursion
int fact(int num)
{
	if (num == 0)
		return 1;
	else
		return (num* fact(num - 1));
}

/*
Sample Output
Enter the string:rohan
Lexicographic Rank of the string=117

Complexities
Time Complexity:O(n^2)
Space Complexity:O(n)
*/

