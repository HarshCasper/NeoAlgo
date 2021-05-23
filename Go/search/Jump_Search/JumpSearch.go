/* Jump search is a searching algorithm for sorted arrays. In this algorithm,
we jump ahead by a fixed number of steps each time, instead of traversing the
whole array. Suppose array is of size 10, and jump is 3, then, we check array[0],
array[3], array[6], array[9]. We get an interval in which we are searching for
is present. We then traverse the interval lineally to get the exact index of the
element. The optimal jump size of sqrt(size of the array). This can be easily proved.

REMEMBER : If the array is not sorted, jump search won't work.*/

package main

import (
	"fmt"
	"math"
)

/* This is the function which implements the jump search algorithm.
The input to the function is the sorted array, the element which we
are looking for and the size of the sorted array.*/
func search(array []int, element, n int) int {

	//Size to jump
	var jump int = int(math.Sqrt(float64(n)))

	initial := 0

	/*Ensures that value of jump does not cross the 
	size of the array. And also checks if the value
	at that jump is less than element or not.*/
	for jump < n && array[jump] <= element {

		/*This keeps track of the lower bound of the
		interval in which element could be present*/
		initial = jump

		//Everytime we increase jump by sqrt(size of array)
		jump = jump + int(math.Sqrt(float64(n)))

		/*If jump exceeds the size of the array, then we
		set jump as the last index  of array + 1*/
		if(jump >= n) {
			jump = n
		}
	}

	/*As the while loop ends, we are sure that the element, if
	present in the array is present between index initial and jump.
	We linearlly travere that interval to look for the element*/
	for i := initial; i <= jump - 1; i++ {

		//If we find the element, we return the index in the array
		if(array[i] == element) {
			return i
		} else {
			continue
		}
	}
	//We reuturn -1 if element is not found in the array
	return -1
}

func main() {

	// Take length of array as input from the user
	fmt.Print("Enter the size of the array: ")
	var n int
	fmt.Scan(&n)

	// Take elements of array as input from the user
	fmt.Print("Enter ", n, " numbers in increasing order followed by spaces : ")
	array := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	// Take element to search as input from the user
	fmt.Print("Enter the element to search: ")
	var element int
	fmt.Scan(&element)

	// Call search function to find the index
	var index int = search(array, element, n)

	/* If index is -1, the element is not present
	Else print index of element in the array*/
	if(index == -1) {
		fmt.Print("\nThe element ", element, " is not present in the array.\n")
	} else {
		fmt.Print("\nThe element ", element, " is present at ", index, " index in the array.\n");
	}
}

/* Sample I/O:

a)

Enter the size of the array: 6
Enter 6 numbers in increasing order followed by spaces : -3 -1 3 5 6 7
Enter the element to search: 5

The element 5 is present at 3 index in the array.

b)

Enter the size of the array: 6
Enter 6 numbers in increasing order followed by spaces : -2 -1 4 6 8 10
Enter the element to search: 5

The element 5 is not present in the array.

*/
