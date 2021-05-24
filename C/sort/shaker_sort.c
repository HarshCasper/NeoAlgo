/* Shaker Sort In C
The algorithm extends the bubble sort by operating in two directions
*/
#include <stdio.h>

void shakersort(int[], int);
void swap(int *, int *);
int main()
{
	int num, i, arr[10000];
	printf("Enter the number of elements:");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Enter the elements to be sorted:");
	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}

	shakersort(&arr[0], num);
	printf("\n");
	printf("Sorted Array:");
	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
// Sorts the given array bidirectionally
void shakersort(int arr[], int num)
{
	int end, start, i;
	end = num - 1;
	start = 1;
	// Bidirectional comparison
	while (start <= num / 2)
	{
		for (i = start - 1; i < end; i++)
		{
			if (arr[i] > arr[i + 1])
				swap(&arr[i], &arr[i + 1]);
		}

		end = end - 1;
		for (i = end; i >= start; i--)
		{
			if (arr[i] < arr[i - 1])
				swap(&arr[i], &arr[i - 1]);
		}

		start = start + 1;
	}
}
// Swaps two elements
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/*
Sample Output
Enter the number of elements: 13
Enter the elements to be sorted:86 74 -2 -9 67 25 33 86 17 -8 42 10 0
Sorted Array:-9 -8 -2 0 10 17 25 33 42 67 74 86 86  

Complexities
Worst case performance:O(n^2)
Best case performance:O(n)
Average performance: O(n^2)
Worst Case Space complexity: O(1) 
*/

