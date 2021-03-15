/*An integer x is said to be Noble given an array 
if the number of integers greater than x are equal to x.
If noble integer is not found output is -1.
*/
#include <stdio.h>

int nobleint(int *, int);
int main()
{
	int num, i, k, arr[1000], arr2[1000], m;
	printf("Enter the number of elements:");
	scanf("%d", &num);
	printf("Enter the elements:");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	m = nobleint(arr, num);
	printf("%d", m);

	return 0;
}

// To find the noble integer from the given array
int nobleint(int *arr, int num)
{
	int count, i, j, x = 0;
	for (i = 0; i < num; i++)
	{
		count = 0;
		for (j = 0; j < num; j++)
		{
			if (*(arr + i)<*(arr + j))
				count = count + 1;
		}

		if (count == *(arr + i))
		{
			x = 1;
			return (count);
		}
	}

	if (x == 0)
		return (-1);
}

/*
Sample Output

Enter the number of elements:4
Enter the elements:7 3 9 81
3
Enter the number of elements:3
Enter the elements:2 2 2
-1

Complexities
Time Complexity:O(n^2)
Space Complexity:O(1)
*/

