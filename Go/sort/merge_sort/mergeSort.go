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

	start := time.Now() // timer starts and records running time of MergeSort Algorithm
	fmt.Println("Sorted Array is: ", MergeSort(intArray))
	end := time.Now() // timer stops and recording running time of MergeSort Algorithm is completed

	fmt.Println("\nRunning Time of MergeSort Algorithm is: ", end.Sub(start))
}

func merge(arr1 []int, arr2 []int) []int {
	i, j := 0, 0

	arr := make([]int, len(arr1)+len(arr2))

	for i < len(arr1) && j < len(arr2) {
		if arr1[i] < arr2[j] {
			arr[i+j] = arr1[i]
			i++
		} else {
			arr[i+j] = arr2[j]
			j++
		}
	}

	for i < len(arr1) {
		arr[i+j] = arr1[i]
		i++
	}
	for j < len(arr2) {
		arr[i+j] = arr2[j]
		j++
	}

	return arr
}

// MergeSort Algorithm Time Complexity : O(nlogn) in worst-case
func MergeSort(arr []int) []int {
	if len(arr) == 0 {
		return nil
	}

	if len(arr) < 2 {
		return arr
	}
	mid := len(arr) / 2
	left := MergeSort(arr[:mid])
	right := MergeSort(arr[mid:])

	return merge(left, right)
}

/*
	I/O Sample:

	Sample 1:
	❯ go run mergeSort.go
	Enter an array with spaces
	5 3 2 4 5 84 6 1 54
	Sorted Array is:  [1 2 3 4 5 5 6 54 84]

	Running Time of MergeSort Algorithm is:  280.029µs


	Sample 2:
	❯ go run mergeSort.go
	Enter an array with spaces
	5 8 6 9 1 3 2 7 4
	Sorted Array is:  [1 2 3 4 5 6 7 8 9]

	Running Time of MergeSort Algorithm is:  83.639µs



	Time Complexity:
		1. Ω(n log(n)) in best case
		2. O(n log(n)) in average case
		3. O(n log(n)) in worst case

	Space Complexity: O(n) in worst case

*/
