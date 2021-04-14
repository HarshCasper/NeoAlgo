/* This program is the implementation of maximum subarray problem
using Dynamic Programming in Go. In this problem we need to find a
sub array such that its sum is maximum among the other possible
sub arrays.*/

package main

import (
	"fmt"
	"math"
)

// This function returns maximum of two integers
func get_max(A, B int) int {
	if(A > B) {
		return A
	} else {
		return B
	}
}

// This function returns the sum of max sub-array
func max_subarray_sum(size int, array []int) int {

	// Variable contains minimum 64 bit int
	var max_sum int = math.MinInt64
	dp := 0

	for i := 0; i < size; i++ {
		/* The maximum possible sum at each step is
		given by the recursive relation: 
		dp[i] = maximum sub array sum in A[0.....i].
		dp[i] = max(A[i], A[i] + Sigma(j = 0 to i-1) A[j])*/
		dp = get_max(array[i], array[i] + dp)
		if(max_sum < dp) {
			max_sum = dp
		} else {
			continue
		}
	}
	// Return the max sum
	return max_sum
}

func main() {

	// Take length of array as input from the user
	fmt.Print("Enter the length of the array: ")
	var size int
	fmt.Scan(&size)

	// Take array elements as input from the user
	array := make([]int, size)
	fmt.Print("Enter elements of array followed by spaces: ")
	for i := 0; i < size; i++ {
		fmt.Scan(&array[i])
	}

	// Call the function and print the max sub array sum
	var maximum int = max_subarray_sum(size, array)
	fmt.Print("\nMax sub-array sum possible for the input array is: ", maximum)
	fmt.Print("\n")
}

/*
Sample I/O:

Enter the length of the array: 6
Enter elements of array followed by spaces: 10 -2 1 4 4 -2

Max sub-array sum possible for the input array is: 17
*/
