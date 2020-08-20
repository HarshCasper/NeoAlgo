/*
	creating a goroutine for a small slice or array, and having to wait for
	the Go runtime to schedule it is way more expensive
	than calling the sequential implementation in the same goroutine.

*/
package main

import (
	"fmt"
	"sync"
	"time"
)

// merge(): a simple function which merge the two slices into one slice

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

// parallel implementation of merge sort with goroutines
func mergeSortParaller(arr []int) []int {
	/*
		 max := 2048
		 we cand add condition like this
		 if len(arr) < max{
			mergeSortSequential(arr)
		 }
		 it will use normal mergesort  after array became small
		 because for that small size, creating gorouting and waiting for scheduler
		 is became more expansive in parallel mergesort

	*/

	length := len(arr)
	if length < 2 {
		return arr
	}

	// WaitGroup waits for goroutines to finish
	var waitGroup sync.WaitGroup

	// adding total counts of goroutines to do wait
	waitGroup.Add(1)
	left := arr[0 : length/2]
	right := arr[length/2:]

	// left part of array will be handle by another goroutine
	go func() {
		defer waitGroup.Done()
		left = mergeSortParaller(left)
	}()

	// right part of array will handle by this main goroutine
	right = mergeSortParaller(right)

	// waiting for goroutin to finish it's work
	waitGroup.Wait()

	return merge(left, right)
}

func main() {
	arr := []int{3, 5, 1, 6, 1, 7, 2, 4, 5, 1}

	start := time.Now() // adding timestamp when excecution of mergesort start

	arr = mergeSortParaller(arr)

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
	51.359µs



	Time Complexity: O(Log(n)) in worst case
	Space Complexity: O(n) in worst case

*/
