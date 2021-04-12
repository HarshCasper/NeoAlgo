
/* Below code is an implementation of binary search in Golang using
recursive method. An array is taken as input from the user, followed
by the element the user wants to search in the array. The search function
is called. If the element is present in the array, then print the index
of the element in the array.
NOTE : For binary search to work, the input array must be SORTED*/

package main

import (
	"fmt"
)

// This function recursively searches for element in array
func search(array []int, left, right, element int) int {

	// If left pointer exceeds the right pointer
	if(left > right) {
		return -1
	} else {
		// Find the middle index
		var middle int = left + (right - left) / 2;
		// If element is found return index
		if(array[middle] == element) {
			return middle
		} else if(array[middle] > element) {
			/* If middle element is greater than the given
			element to search, then, recursively search in
			the left half of the array.*/
			return search(array, left, middle - 1, element)
		} else if(array[middle] < element) {
			/* If middle element is less than the given
			element to search, then, recursively search
			in the right half of the array.*/
			return search(array, middle + 1, right, element);
		}
	}
	// If not found, return -1
	return -1
}

func main() {

	// Take length of array as input from the user
	fmt.Print("Enter the length of the array: ")
	var n int
	fmt.Scan(&n)

	// Take elements of array as input from the user
	fmt.Print("Enter ", n, " elements followed by spaces: ")
	array := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	// Take element to search as input from the user
	fmt.Print("Enter the element you want to search: ")
	var element int
	fmt.Scan(&element)

	// Call search function to find the index
	var index int = search(array, 0, n - 1, element)

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

Enter the length of the array: 5
Enter 5 elements followed by spaces: -1 3 5 9 21
Enter the element you want to search: 3

The element 3 is present at 1 index in the array.

b)

Enter the length of the array: 5
Enter 5 elements followed by spaces: -2 -1 3 4 6
Enter the element you want to search: 2

The element 2 is not present in the array.
*/
