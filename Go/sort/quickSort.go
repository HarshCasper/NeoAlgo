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

	fmt.Println("Sorted Array is: ", QuickSort(intArray, 0, len(intArray)-1))

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
