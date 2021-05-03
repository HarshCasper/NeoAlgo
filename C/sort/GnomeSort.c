/*
*  Gnome Sort or Stupid Sort is a sorting algorithm that arranges all the elements in their correct positions
*  by means of a series of swaps in a single loop.
*
*  A run thorugh of the numbers is conducted, comparing each of the current numbers (initially
*  the second element) to the number before them.
*		If numbers are not in order,
*			Numbers are swapped
*			Move back to compare previous pair of numbers
*			If no previous number, move to next number
*		Else if numbers are in order,
*			Move to next number
*/

#include <stdio.h>
#include <stdlib.h>
/* Takes integer array and size as input and sorts the array as per afore-mentioned method */
void gnome_sort(int* array, int size)
{
	int index = 0;
	while (index < size) 
	{
		if (index == 0 || array[index] >= array[index - 1])	
			++index;
		else {
			int temp = array[index];
			array[index] = array[index - 1];
			array[index - 1] = temp;
			--index;
		}
	}
}
/* In the main function, inputs from user are read, gnome_sort() is invoked and output is printed */ 
int main()
{
	int size, index;
	printf("How many numbers are to be sorted? ");
	scanf("%d", &size);
	int* array = (int*)malloc(sizeof(int) * size);	
	printf("Enter the numbers to be sorted: \n");
	for (index = 0; index < size; ++index) {
		scanf("%d", &array[index]);
	}
	
	gnome_sort(array, size);
	
	printf("Numbers after sorting: \n");
	for (index = 0; index < size; ++index) {
		printf("%d ", array[index]);
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
