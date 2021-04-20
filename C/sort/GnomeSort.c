#include <stdio.h>
#include <stdlib.h>

/*
*  Gnome Sort or Stupid Sort is a sorting algorithm that arranges all the elements in their correct positions
*  by means of a series of swaps in a single loop.
*
*  A run thorugh of the numbers is conducted, comparing each of the current numbers (initially
*  the second element) to the numbers before them.
*		If numbers are not in order,
*			Numbers are swapped
*			Move back to compare previous pair of numbers
*			If no previous number, move to next number
*		Else if numbers are in order,
*			Move to next number
*/

void gnome_sort(int* arr, int size)
{
	int index = 0;
	while (index < size)
	{
		if (index == 0 || arr[index] >= arr[index - 1])		// If no previous position exists or if elements are sorted,
			++index;										//   we move to next position.
		else                                                // Else,
		{
			int temp = arr[index];							//    we swap elements
			arr[index] = arr[index - 1];
			arr[index - 1] = temp;
			--index;										//    and move to previous position
		}
	}
}

int main()
{
	int size, i;
	printf("How many numbers are to be sorted? ");
	scanf("%d", &size);
	int* arr = (int*)malloc(sizeof(int) * size);		//Creating an integer array (arr) of size, size

	printf("Enter the numbers to be sorted: \n");
	for (i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);
	}

	gnome_sort(arr, size);

	printf("Numbers after sorting: \n");
	for (i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	return 0;
}

/*
   [Sample I/O]
	How many numbers are to be sorted? 6
	Enter the numbers to be sorted:
	91 87 75 1 3 108
	Numbers after sorting:
	1 3 75 87 91 108

   [Complexities]
	Time Complexity  : O(n^2)
	Space Complexity : O(1)
*/
