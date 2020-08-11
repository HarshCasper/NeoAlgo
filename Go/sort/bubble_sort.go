package main

import "fmt"

// Bubble sort, sometimes referred to as sinking sort, 
// is a simple sorting algorithm that repeatedly steps through the list, 
// compares adjacent elements and swaps them if they are in the wrong order.
func bubble_sort(arr []int,num int) []int {
	for i:= 0; i <= num - 1; i++ {
		for j := 0; j < num - i - 1; j++ {
			// Checking if the adjacent elements are not in order.
			if (arr[j] > arr[j + 1]) {
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
			}
		} 
	}

	return arr
}

func main() {
	var size int
	fmt.Printf("Please enter the size of the array: ")
	fmt.Scan(&size)

	var arr = make([]int, size)
	for itr := 0; itr < size; itr++ {
		fmt.Printf("Enter the element %d: ", itr + 1)
		fmt.Scan(&arr[itr])
	}

	fmt.Println("The entered array is:", arr)

	sorted := bubble_sort(arr, size)
	fmt.Println("The sorted array is:", sorted)
}
