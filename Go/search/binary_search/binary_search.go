// Binary Search in Go
// Requires array to be sorted
// Return index of found element else return -1
package main

import (
	"fmt"
)

func main() {
	arr := []int{2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
	fmt.Printf("Array: %v\n", arr)
	var find int
	fmt.Printf("Please enter element to be found: ")
	fmt.Scan(&find)
	result := search(arr, find)
	fmt.Printf("Result: %d", result)
}

func search(list []int, item int) int {
	low := 0
	high := len(list) - 1
	for low <= high {
		middle := (low + high) / 2
		if list[middle] == item {
			return middle
		} else if list[middle] < item {
			low = middle + 1
		} else {
			high = middle - 1
		}
	}
	return -1
}
