//Author : @belikesayantan

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

	fmt.Println("Sorted Array is: ", MergeSort(intArray))

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

// MergeSort Algorithm Time Complexity : O(nlogn)
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
