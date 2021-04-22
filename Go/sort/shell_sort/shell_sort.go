/* This function written in Go sorts the array using shell sort algorithm.
This algorithm is a generalized version of insertion sort. Shell sort first
sorts the elements far apart from each other and successively reduces the
interval between the elements to be sorted.*/

package main

import (
	"fmt"
)

// This function prints the sorted array
func printArray(array []int, number int) {
	fmt.Print("\nSorted array: ")
	for i := 0; i < number; i++ {
		fmt.Print(array[i], " ")
	}
	fmt.Print("\n")
}

// This function sorts array using shell sort algorithm
func ShellSort(array []int, number int) {

	// Start with interval n / 2
	var interval int = number / 2

	// After each iteration, divide the interval by 2
	for interval > 0 {
		for i := interval; i < number; i++ {
			// Value to be inserted
			insert := array[i]
			j := i
			/* Shift heavier elements towards right making it easy
			for further iterations*/
			for j >= interval && array[j - interval] > insert {
				array[j] = array[j - interval]
				j = j - interval
			}
			// Insret the element
			array[j] = insert
		}
		interval = interval / 2
	}
	// Print the final sorted array
	printArray(array, number)
}

func main() {

	// Take length of array as input from the user
	var number int
	fmt.Print("Enter the length of the array: ")
	fmt.Scan(&number)

	// Take elements of array as input from the user
	fmt.Print("Enter the elements of the array followed by spaces: ")
	array := make([]int, number)
	for i := 0; i < number; i++ {
		fmt.Scan(&array[i])
	}

	// Call the sorting function
	ShellSort(array, number)
}

/*

Sample I/O:

Enter the length of the array: 7
Enter the elements of the array followed by spaces: 7 2 4 9 3 5 1

Sorted array: 1 2 3 4 5 7 9

Time Complexity - O(n^2)

Space Complexity - O(n)

*/

