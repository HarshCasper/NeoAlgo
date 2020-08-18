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

	fmt.Println(("Enter the maximum element value you have in the array:"))
	m, err := reader.ReadString('\n')
	m = strings.TrimSpace(m)
	max, _ := strconv.Atoi(m)

	fmt.Println("Sorted Array is: ", CountingSort(intArray, max))

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
