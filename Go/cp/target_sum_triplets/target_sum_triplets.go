/*
	Take as input N, the size of array. Take N more inputs and store that in an array.
	Take as input “target”, a number.
	Write a function which prints all triplets of numbers which sum to target.

For example
input:
	9
	5 7 9 1 2 4 6 8 3
	10
	output:
	1, 2 and 7
	1, 3 and 6
	1, 4 and 5
	2, 3 and 5
*/
package main

import (
	"fmt"
	"sort"
)

func sumTriplets(arr []int, targetSum int) {
	left, right := 0, 0

	arrayLength := len(arr)

	// it will count the number of triplets
	count := 0

	if arrayLength == 0 {
		// corner case
		fmt.Println("Array is empty")
	} else {
		for i := 0; i < arrayLength-2; i++ {

			// Initial condition
			// index for first element is i
			// index for second element is 0
			// index for third element is index of last element
			left = 0
			right = arrayLength - 1

			for left < right {

				sum := arr[i] + arr[left] + arr[right]

				// if the sum of all three elementsis equal to targetSum
				// we should print it and then move forward
				// to next element by breaking the inner loop
				if sum == targetSum {
					fmt.Printf("Triplet is %d %d %d\n", arr[i], arr[left], arr[right])
					count++
					break
				} else if sum < targetSum {
					// if the sum is less than targetSum we should
					// increase the left index for the next element
					left++
				} else {
					// if the sum is greater than targetSum we should
					// decrease the right index for the next element
					right--
				}
			}
		}
	}
	// if there is no triplet exist
	if count == 0 {
		fmt.Println("Sorry couldn't found any triplets with target sum")
	}
}

func main() {
	var length int
	fmt.Println("please enter the number of element")
	fmt.Scanf("%d", &length)

	// making the slice of size length
	array := make([]int, length)
	fmt.Println("enter the space separated elements")
	for i := 0; i < length; i++ {
		fmt.Scanf("%d", &array[i])
	}

	// sort the array in ascending order
	sort.Ints(array)

	var targetSum int
	fmt.Println("enter the target sum")
	fmt.Scanf("%d", &targetSum)

	sumTriplets(array, targetSum)
}

/*
	Time Complexity : O(n^2) because of two nested loops
	Space Complexity : O(1)

	input/output sample

	please enter the number of element
	9
	enter the space separated elements
	5 7 9 1 2 4 6 8 3
	enter the target sum
	10
	Triplet is 1 1 8
	Triplet is 2 1 7
	Triplet is 3 1 6
	Triplet is 4 1 5
	Triplet is 5 1 4
	Triplet is 6 1 3
	Triplet is 7 1 2
*/
