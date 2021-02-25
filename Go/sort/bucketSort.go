/*
Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets.
Each bucket is then sorted individually, either using a different sorting algorithm,
or by recursively applying the bucket sorting algorithm.Bucket sort is mainly useful when input is uniformly distributed
over a range. Bucket sort can be implemented with comparisons and therefore can also be considered a comparison sort algorithm.
*/

package main

import (
	"container/heap"
	"fmt"
)

func main() {
	arr_i := []int{1, -1, 23, -2, 23, 123, 12, 1}
	BucketSort(arr_i)
	fmt.Println("Sorted array after BucketSort is :", arr_i)
}

type IntArr []int

func (h IntArr) Len() int           { return len(h) }
func (h IntArr) Less(i, j int) bool { return h[i] < h[j] }
func (h IntArr) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntArr) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntArr) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func BucketSort(arr []int) {
	bucket := make([]IntArr, 10)

	max := arr[0]
	for _, elem := range arr {
		if elem > max {
			max = elem
		}
	}

	min := arr[0]
	for _, elem := range arr {
		if elem < min {
			min = elem
		}
	}

	width := (max-min)/10 + 1

	for _, elem := range arr {
		x := (elem - min) / width
		heap.Push(&bucket[x], elem)
	}

	for i := 0; i < 10; i++ {
		heap.Init(&bucket[i])
	}

	index := 0
	for i := 0; i < 10; i++ {
		for j := 0; j < len(bucket[i]); j++ {
			arr[index] = heap.Pop(&bucket[i]).(int)
			index++
		}
	}
}

/*
Output:
Sorted array after BucketSort is : [-2 -1 12 23 123 123 12 1]
	
--------------------------------
Time Complexities:
O(n+k): average time complexity
O(n²): worst time complexity

Space Complexity: O(n+k)

*/