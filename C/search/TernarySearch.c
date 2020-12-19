#include <stdio.h>

int ternarySearchIterative(int left, int right, int key, int array[])
{
	while (right >= left)
	{
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		if (array[mid1] == key)
		{
			return mid1;
		}

		if (array[mid2] == key)
		{
			return mid2;
		}

		if (key < array[mid1])
		{
			right = mid1 - 1;
		}
		else if (key > array[mid2])
		{
			left = mid2 + 1;
		}
		else
		{
			left = mid1 + 1;
			right = mid2 - 1;
		}
	}

	return -1;
}

int ternarySearchRecursive(int left, int right, int key, int array[])
{
	// Find the mid1 and mid2 
	if (right >= left)
	{
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		// Check if key is present at any mid 
		if (array[mid1] == key)
		{
			return mid1;
		}

		if (array[mid2] == key)
		{
			return mid2;
		}

		// Since key is not present at mid, 
		// check in which region it is present 
		// then repeat the Search operation 
		// in that region 
		if (key < array[mid1])
		{
			// The key lies in between l and mid1 
			return ternarySearchRecursive(left, mid1 - 1, key, array);
		}
		else if (key > array[mid2])
		{
			// The key lies in between mid2 and r 
			return ternarySearchRecursive(mid2 + 1, right, key, array);
		}
		else
		{
			// The key lies in between mid1 and mid2 
			return ternarySearchRecursive(mid1 + 1, mid2 - 1, key, array);
		}
	}

	// Key not found 
	return -1;
}

int main()
{
	int num;
	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("\nEnter %d sorted elements: ", num);
	int array[num];
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}

	int key, index;
	printf("\nEnter Key to be searched: ");
	scanf("%d", &key);
	printf("\nRecursive Search:");
	index = ternarySearchRecursive(0, num, key, array);
	printf("\nIndex of %d is %d.", key, index);
	printf("\nIterative Search:");
	index = ternarySearchIterative(0, num, key, array);
	printf("\nIndex of %d is %d.", key, index);
}

/*
Time Complexity: O(log3 n)
Space Complexity: O(1)

Input :
Enter number of elements: 8
Enter 8 elements: 12 25 48 52 67 78 89 91
Enter Key to be searched: 52

Output : 
Recursive Search: 
Index of 52 is 3.
Iterative Search:
Index of 52 is 3.
*/
