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

	fmt.Println(("Enter the maximum element value you have in the array:"))
	m, err := reader.ReadString('\n')
	m = strings.TrimSpace(m)
	max, _ := strconv.Atoi(m)

	start := time.Now() // timer starts and records running time of CountingSort Algorithm
	fmt.Println("Sorted Array is: ", CountingSort(intArray, max))
	end := time.Now() // timer stops and recording running time of CountingSort Algorithm is completed

	fmt.Println("\nRunning Time of CountingSort Algorithm is: ", end.Sub(start))
}

// CountingSort Algorithm Time Complexity : O(n + k) where k is the max element in the array
func CountingSort(arr []int, max int) []int {
	if len(arr) == 0 {
		return nil
	}

	if len(arr) == 1 {
		return arr
	}

	counter := make([]int, max+1)
	sorted := make([]int, 0)

	for i := 0; i < len(arr); i++ {
		counter[arr[i]] = counter[arr[i]] + 1
	}

	for i := 0; i < len(counter); i++ {
		count := counter[i]

		for j := 0; j < count; j++ {
			sorted = append(sorted, i)
		}

	}

	return sorted
}

/*
	I/O Sample:

	Sample 1:
	❯ go run countingSort.go
	Enter an array with spaces
	5 3 2 4 5 84 1 54
	Enter the maximum element value you have in the array:
	84
	Sorted Array is:  [1 2 3 4 5 5 54 84]

	Running Time of CountingSort Algorithm is:  249.246µs


	Sample 2:
	❯ go run countingSort.go
	Enter an array with spaces
	5 8 6 9 1 3 2 7 4
	Enter the maximum element value you have in the array:
	9
	Sorted Array is:  [1 2 3 4 5 6 7 8 9]

	Running Time of CountingSort Algorithm is:  220.286µs


	Time Complexity:
		1. Ω(n+k) in best case
		2. O(n+k) in average case
		3. O(n+k) in worst case

		Space Complexity: O(k) in worst case

					where k is the max element in the array
*/
