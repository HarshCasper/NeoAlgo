/*Bubble Sort Algorithm is the sorting algorithm in which each element is compared to its adjacent element 
and if first elememt is greater than second element ,then the swapping occurs.
The swapping occurs till the array is sorted.
*/

#include <stdio.h>
#include <stdbool.h>

void swap(int *, int *);
bool optimised_bubble(int[], int);
int main()
{
	int size, arr[size], temp;
	//Reading Input
	printf("Input :\n");
	printf("Enter the size of an array : \n");
	scanf("%d", &size);
	printf("Enter the elements of an array :\n");
	for (int index = 0; index < size; index++)
	{
		scanf("%d", &arr[index]);
	}

	optimised_bubble(arr, size);
	//Displaying Output
	printf("Output :\n");
	printf("The sorted array is :\n");
	for (int index = 0; index < size; index++)
	{
		printf("%d ", arr[index]);
	}

	return 0;
}

// Function to sort the array in an optimised way
bool optimised_bubble(int arr[], int size)
{
	int index;
	bool sort = true;
	for (int index = 0; index < size; index++)
	{
		for (int j = 0; j < size - 1 - index; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				sort = false;
			}
		}

		if (sort)
		{
			break;
		}
	}
}

// Function to swap two numbers
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
 Input:
 Enter the size of an array: 5
 Enter the elements of an array :
 7 9 8 2 4
 Output :
 2 4 7 8 9
 Time Complexity :  O(n)
 Space Complexity : O(1)
*/

