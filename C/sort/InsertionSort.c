/*INSERTION SORT
The array is virtually split into a sorted and an unsorted part. 
Values from the unsorted part are picked and placed at the correct position in the sorted part.
*/
#include <stdio.h>

void insertion_sort(int[], int);
int main()
{
	int arraySize, index, temp, key;
	printf("Enter the size of the array:");
	scanf("%d", &arraySize);
	int arr[arraySize];	// declaring array by - 'arr'
	printf("Enter the elements to sort:");
	for (index = 0; index < arraySize; index++)
	{
		scanf("%d", &arr[index]);
	}

	insertion_sort(arr, arraySize);
	printf("Sorted Array:");
	for (index = 0; index < arraySize; index++)
	{
		printf("%d ", arr[index]);
	}

	return 0;
}

// Function to sort the array using insertion sort method
void insertion_sort(int arr[], int arraySize)
{
	int index, key, temp;
	for (index = 1; index < arraySize; index++)
	{
		key = arr[index];	// the key stores the value at the index position
		temp = index - 1;
		while (temp >= 0 && arr[temp] > key)
		{
			arr[temp + 1] = arr[temp];
			temp--;
		}

		arr[temp + 1] = key;
	}
}

/*
Sample Output
Enter the size of the array:6
Enter the elements to sort:17 8 9 0 2
Sorted Arrray:0 2 8 9 17

Complexities
Time Complexity:O(n^2)
Space Complexity:O(1)
*/

