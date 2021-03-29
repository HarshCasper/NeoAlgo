// Linear Search in Go
// Return index of found element else return -1
package main

import (
	"fmt"
)

func main() {
	arr := []int{1, 5, 2, -5, 8, 4, 9, -12}
	fmt.Printf("Array: %v\n", arr)
	var find int
	fmt.Printf("Please enter element to be found: ")
	fmt.Scan(&find)
	result := search(arr, find)
	fmt.Printf("Result: %d", result)
}

func search(list []int, item int) int {
	for i := range list {
		if list[i] == item {
			return i
		}
	}
	return -1
}
