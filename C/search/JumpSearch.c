/* Jump search is a searching algorithm for sorted arrays. In this algorithm, we jump ahead by a fixed number of steps each time, instead
   of traversing the whole array. Suppose array is of size 10, and jump is 3, then, we check array[0], array[3], array[6], array[9]. We get
   an interval in which we are searching for is present. We then traverse the interval lineally to get the exact index of the element.
   The optimal jump size of sqrt(size of the array). This can be easily proved. */

/* REMEMBER : If the array is not sorted, jump search won't work. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This is the function which implements the jump search algorithm.
   The input to the function is the sorted array, the key which we 
   are looking for and the size of the sorted array. */

int jumpSearch(int array[], int key, int size) {

	//Size to jump
	int jump = sqrt(size);

	int initial = 0;

	/*Ensures that value of jump does not cross the size of the array.
	  And also checks if the value at that jump is less than key or not.*/

	while(jump < size && array[jump] <= key) {

		/*This keeps track of the lower bound of the interval
		  in which key could be present*/

		initial = jump;

		//Everytime we increase jump by sqrt(size of the array)
		jump = jump + sqrt(size);

		/*If jump exceeds the size of the array, then we set jump as 
		  the last index  of array + 1*/

		if(jump >= size) {
			jump = size;
		}
	}

	/*As the while loop ends, we are sure that the key, if present in the array
	  is present between index initial and jump.
	  We linearlly travere that interval to look for the key*/

	for(int i = initial; i <= jump - 1; i++) {

		//If we find the key, we return the index of the key
		if(array[i] == key) {
			return i;
		}

		else {
			continue;
		}
	}

	//We reuturn -1 if we did not find the key in the array
	return -1;
}

int main() {
	
	//Size of the array
	int size;

	printf("Enter the size of array : ");

	scanf("%d", &size);

	//Declaring an array
	int arr[size];

	printf("Enter %d numbers in increasing order followed by spaces : ", size);

	//Take elements of the array as input from the user
	for(int i = 0; i < size; i++) {

		scanf("%d", &arr[i]);
	}

	//This contains the value of the key we are looking for
	int key;

	//Prompt the user for the element to search for
	printf("Enter the element to search : ");

	scanf("%d", &key);

	//We call the jumpSearch function, with appropiate parameters
	int position = jumpSearch(arr, key, size);

	//If the key is not found in the array
	if(position != -1) {
		printf("The element %d is present at index %d of the array.\n", key, position);
	}

	//If we find the key in the array, we print its index in the array
	else {
		printf("\nThe element %d is not present in the array.\n", key);
	}

	return 0;
}

/* Sample I/O 
 
	Enter the size of array : 5
	Enter 5 numbers in increasing order followed by spaces : 1 2 3 4 5
	Enter the element to search : 5
	
	The element 5 is present at index 4 of the array.

 */

