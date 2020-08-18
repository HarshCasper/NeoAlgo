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

	fmt.Println("Sorted Array is: ", InsertionSort(intArray))

}

// InsertionSort Algorithm Time Complexity : O(n^2)
func InsertionSort(arr []int) []int {
	if len(arr) == 0 {
		return nil
	}

	if len(arr) == 1 {
		return arr
	}

	for i := 0; i < len(arr); i++ {
		j := i
		key := arr[j]

		for i > 0 && key < arr[i-1] {
			arr[i] = arr[i-1]
			i--
		}
		arr[i] = key

	}

	return arr
}
