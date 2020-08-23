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

	for i := 0; i < arrayLength-2; i++ {

		left = 0
		right = arrayLength - 1

		for left < right {

			sum := arr[i] + arr[left] + arr[right]

			if sum == targetSum {
				fmt.Printf("Triplet is %d %d %d\n", arr[i], arr[left], arr[right])
				break
			} else if sum < targetSum {
				left++
			} else {
				right--
			}
		}

	}

}

func main() {
	var length int
	fmt.Println("please enter the number of element")
	fmt.Scanf("%d", &length)

	array := make([]int, length) //making the array of size length
	fmt.Println("enter the space separated elements")
	for i := 0; i < length; i++ {
		fmt.Scanf("%d", &array[i])
	}

	sort.Ints(array) // sorting the array of integers

	var targetSum int
	fmt.Println("enter the target sum")
	fmt.Scanf("%d", &targetSum)

	sumTriplets(array, targetSum)

}
