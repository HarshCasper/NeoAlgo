// Author: @belikesayantan

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

	start := time.Now() // timer starts and records running time of SelectionSort Algorithm
	fmt.Println("Sorted Array is: ", SelectionSort(intArray))
	end := time.Now() // timer stops and recording running time of SelectionSort Algorithm is completed

	fmt.Println("\nRunning Time of SelectionSort Algorithm is: ", end.Sub(start))
}

// SelectionSort Algorithm Time Complexity : O(n^2)
func SelectionSort(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		min := i
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[min] {
				min = j
			}
		}
		if min != i {
			swap(arr, i, min)
		}

	}

	return arr
}

func swap(arr []int, i, j int) {
	temp := arr[i]
	arr[i] = arr[j]
	arr[j] = temp
}

/*
	I/O Sample:

	Sample 1:
	❯ go run selectionSort.go
	Enter an array with spaces
	5 3 2 4 5 84 6 1 54
	Sorted Array is:  [1 2 3 4 5 5 6 54 84]

	Running Time of SelectionSort Algorithm is:  73.83µs


	Sample 2:
	❯ go run selectionSort.go
	Enter an array with spaces
	5 8 6 9 1 3 2 7 4
	Sorted Array is:  [1 2 3 4 5 6 7 8 9]

	Running Time of SelectionSort Algorithm is:  39.509µs



	Time Complexity:
		1. Ω(n^2) in best case
		2. O(n^2) in average case
		3. O(n^2) in worst case

	Space Complexity: O(1) in worst case

*/
