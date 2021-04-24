// Author : @belikesayantan

package main

import (
	"bufio"
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {
	var strArray []string
	var intArray []int

	fmt.Println("Enter an array with spaces")
	reader := bufio.NewReader(os.Stdin)
	arr, err := reader.ReadString('\n')
	if err != nil {
		inputErr := errors.New("something is wrong with your array input")
		log.Fatal(inputErr)
	}
	arr = strings.TrimSpace(arr)
	strArray = strings.Split(arr, " ")

	for _, val := range strArray {
		ele, err := strconv.Atoi(val)
		if err != nil {
			panic(err)
		}
		intArray = append(intArray, ele)
	}

	start := time.Now() // timer starts and records running time of QuickSort Algorithm
	fmt.Println("Sorted Array is: ", QuickSort(intArray, 0, len(intArray)-1))
	end := time.Now() // timer stops and recording running time of QuickSort Algorithm is completed

	fmt.Println("\nRunning Time of QuickSort Algorithm is: ", end.Sub(start))
}

// QuickSort Algorithm Time Complexity : O(n^2)
func QuickSort(arr []int, start, end int) []int {
	if len(arr) == 0 {
		return nil
	}

	if len(arr) == 1 {
		return arr
	}

	if start < end {
		pivotIndex := partition(arr, start, end)
		QuickSort(arr, start, pivotIndex-1)
		QuickSort(arr, pivotIndex+1, end)
	}

	return arr
}

func partition(arr []int, start, end int) int {
	pivot := arr[end]
	pivotIndex := start - 1

	for i := start; i < end; i++ {
		if arr[i] < pivot {
			pivotIndex++
			swap(arr, i, pivotIndex)
		}
	}
	swap(arr, pivotIndex+1, end)
	return pivotIndex + 1
}

func swap(arr []int, i, j int) {
	temp := arr[i]
	arr[i] = arr[j]
	arr[j] = temp
}

/*
	I/O Sample:

	Sample 1:
	❯ go run quickSort.go
	Enter an array with spaces
	5 3 2 4 5 84 6 1 54
	Sorted Array is:  [1 2 3 4 5 5 6 54 84]

	Running Time of QuickSort Algorithm is:  46.35µs


	Sample 2:
	❯ go run quickSort.go
	Enter an array with spaces
	5 8 6 9 1 3 2 7 4
	Sorted Array is:  [1 2 3 4 5 6 7 8 9]

	Running Time of QuickSort Algorithm is:  113.059µs



	Time Complexity:
		1. Ω(n log(n)) in best case
		2. O(n log(n)) in average case
		3. O(n^2) in worst case

	Space Complexity: O(log(n)) in worst case

*/
