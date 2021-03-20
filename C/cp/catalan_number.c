/*
The Catalan numbers form a sequence of natural numbers that occur in various 
counting problems, often involving recursively-defined objects.

Application in some combinatorial problems:
1.Number of correct bracket sequence consisting of n opening and n closing brackets.
2.The number of rooted full binary trees with n+1 leaves (vertices are not numbered). A rooted binary tree is full if every vertex has either two children or no children.
3.The number of ways to completely parenthesize n+1 factors. 
*/

#include <stdio.h>

int catalan(int num)
{
	if (num <= 1)
	{
		return 1;
	}

	int res = 0;
	for (int i = 0; i < num; i++)
		res += catalan(i) *catalan(num - i - 1);
	return res;
}

int main()
{
	int num;
	printf("Enter Number: ");
	scanf("%d", &num);
	printf("\n");
	for (int i = 1; i <= num; i++)
	{
		printf("%d ", catalan(i));
	}

	return 0;
}

/*
Sample input and output
Enter number: 7
1 2 5 14 42 132 429

time complexity: O(n^2)
space complexity: O(n)
*/ 
