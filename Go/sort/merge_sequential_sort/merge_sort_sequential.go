package main

import (
	"fmt"
	"time"
)

// merge(): a simple function which merge the two slices into one slice

func merge(left []int, right []int) []int {
	result := make([]int, len(left)+len(right))

	leftArrayIndex, rightArrayIndex := 0, 0

	for resultArrayIndex := 0; resultArrayIndex < len(result); resultArrayIndex++ {
		if leftArrayIndex >= len(left) {
			result[resultArrayIndex] = right[rightArrayIndex]
			rightArrayIndex++
			continue

		} else if rightArrayIndex >= len(right) {
			result[resultArrayIndex] = left[leftArrayIndex]
			leftArrayIndex++
			continue

		}

		if left[leftArrayIndex] < right[rightArrayIndex] {
			result[resultArrayIndex] = left[leftArrayIndex]
			leftArrayIndex++

		} else {
			result[resultArrayIndex] = right[rightArrayIndex]
			rightArrayIndex++

		}

	}

	return result
}

func mergeSort(arr []int) []int {
	length := len(arr)
	if length < 2 {
		return arr
	}
	left := arr[0 : length/2]
	right := arr[length/2:]

	// making recursive call with mergeSort() function on both halves of slice
	left = mergeSort(left)
	right = mergeSort(right)

	return merge(left, right)
}

func main() {
	arr := []int{3, 5, 1, 6, 1, 7, 2, 4, 5, 1}

	start := time.Now() // adding timestamp when excecution of mergesort start

	arr = mergeSort(arr)

	end := time.Now() // adding timestamp when excecution of mergesort finish

	fmt.Println("sorted array is")
	fmt.Println(arr)
	fmt.Println("time taken by algorithm is")
	fmt.Println(end.Sub(start))
}

/*
	input/output sample

	sorted array is
	[1 1 1 2 3 4 5 5 6 7]
	time taken by algorithm is
	2.535µs



	Time Complexity: O(nLog(n)) in worst case
	Space Complexity: O(n) in worst case

*/
