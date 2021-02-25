/*
Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets.
Each bucket is then sorted individually, either using a different sorting algorithm,
or by recursively applying the bucket sorting algorithm.Bucket sort is mainly useful when input is uniformly distributed
over a range. Bucket sort can be implemented with comparisons and therefore can also be considered a comparison sort algorithm.
*/

package main

import (
    "fmt"
    "os"
    "strconv"
)

//to sort the individual bucket
func insertionSort(array []float64) {
    for i := 0; i < len(array); i++ {
        temp := array[i]
        j := i - 1
        for ; j >= 0 && array[j] > temp; j-- {
            array[j + 1] = array[j]
        }
        array[j + 1] = temp
    }
}

func bucketSort(array []float64, bucketSize int) []float64 {
    var max, min float64
    for _, n := range array {
        if n < min {
            min = n
        }
        if n > max {
            max = n
        }
    }
	
    nBuckets := int(max-min) / bucketSize + 1
    buckets := make([][]float64, nBuckets)
    for i := 0; i < nBuckets; i++ {
        buckets[i] = make([]float64, 0)
    }

    for _, n := range array {
        idx := int(n-min) / bucketSize
        buckets[idx] = append(buckets[idx], n)
    }

    sorted := make([]float64, 0)
    for _, bucket := range buckets {
        if len(bucket) > 0 {
            insertionSort(bucket)
            sorted = append(sorted, bucket...)
        }
    }
    return sorted
}

func main() {
    var x int
    fmt.Printf("Enter the size of the array : ")
    fmt.Scan(&x)
    fmt.Printf("Enter the elements of the array : ")
    a := make([]float64, x)
    for i := 0; i < x; i++ {
        fmt.Scan(&a[i])
    }
 
	// A copy of the array 'a' is assigned to 'array' 
    array := a    
    for _, arg := range os.Args[1:] {
        if n, err := strconv.ParseFloat(arg, 64); err == nil {
            array = append(array, n)
        }
    }
	
    fmt.Printf("The array before sorting is %v\n", array)
    array = bucketSort(array, 5)
    fmt.Printf("The array after sorting is %v\n", array)
}

/*
Input:
Enter the size of the array : 3                                                                                               
Enter the elements of the array : 2 8 5 
	
Output :
The array before sorting is [2 8 5]                                                                                           
The array after sorting is [2 5 8] 
	
--------------------------------
Time Complexities:
O(n+k): average time complexity
O(n²): worst time complexity

Space Complexity: O(n+k)

*/