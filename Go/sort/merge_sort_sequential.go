package main

import (
	"fmt"
	"time"
)

func merge(left []int, right []int) []int {

	result := make([]int, len(left)+len(right))

	i, j := 0, 0

	for k := 0; k < len(result); k++ {
		if i >= len(left) {
			result[k] = right[j]
			j++
			continue

		} else if j >= len(right) {
			result[k] = left[i]
			i++
			continue

		}

		if left[i] < right[j] {
			result[k] = left[i]
			i++

		} else {
			result[k] = right[j]
			j++

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
