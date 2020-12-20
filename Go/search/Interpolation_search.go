package main
import "fmt"

func Search(array []int, num int) int {

	min := array[0]
	max := array[len(array)-1]

	low := 0
	high := len(array)-1

	for {
		if num < min {
			return low
		}

		if num > max {
			return high + 1
		}

		var guess int
		if high == low {
			guess = high
		} else {
			size := high - low
			key := int(float64(size-1) * (float64(num-min) / float64(max-min)))
			guess = low + key
		}

		if array[guess] == num {
			for guess > 0 && array[guess-1] == num {
				guess--
			}
			return guess
		}

		if array[guess] > num {
			high = guess - 1
			max = array[high]
		} else {
			low = guess + 1
			min = array[low]
		}
	}
}

// Test Case

func main(){
	items := []int{1, 12, 24, 34, 43, 57, 60, 72}
	fmt.Println(Search(items,34))
}

// Output = 3

// Time Complexity = O(n)
// Space Complexity = O(n)
