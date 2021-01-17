package main

import (
	"fmt"
	"strconv"
)

// Finds the largest number in an array
func findLargestNum(array []int) int {
	largestNum := 0

	for i := 0; i < len(array); i++ {
		if array[i] > largestNum {
			largestNum = array[i]
		}
	}
	return largestNum
}

func radixSort(array []int) []int {

	largestNum := findLargestNum(array)
	size := len(array)
	significantDigit := 1
	unSorted := make([]int, size, size)

	// Loop until the largest significant digit is reached
	for largestNum/significantDigit > 0 {
		strconv.Itoa(significantDigit)

		bucket := [10]int{0}

		for i := 0; i < size; i++ {
			bucket[(array[i]/significantDigit)%10]++
		}

		for i := 1; i < 10; i++ {
			bucket[i] += bucket[i-1]
		}

		for i := size - 1; i >= 0; i-- {
			bucket[(array[i]/significantDigit)%10]--
			unSorted[bucket[(array[i]/significantDigit)%10]] = array[i]
		}

		for i := 0; i < size; i++ {
			array[i] = unSorted[i]
		}

		significantDigit *= 10
	}

	return array
}

func main() {

	unsortedList := []int{14, 10, 9, 18, 20, 5, 2, 7}

	sortedList := radixSort(unsortedList)

	fmt.Println("\nSorted List:", sortedList, "\n")
}

/*
Output -
Sorted List: [2 5 7 9 10 14 18 20]
*/
