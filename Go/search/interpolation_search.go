package main
import "fmt"
 
func Search(array []int, number int) int {
	
	low := 0
	high := len(array)-1
 
    for {
	var key int
	var size int
	
        if high == low {
            key = high
        
	} else {
		size = high - low
		key = low + (int(float64(size-1)*(float64(number-array[0])/float64(array[len(array)-1]-array[0]))))
        }
 
        if array[key] == number {
		return key
        }
 
        if array[key] > number {
            high = key - 1
        
	} else {
            low = key + 1
        }
    }
}

// Input

func main(){
    items := []int{1, 16, 28, 37, 49, 52, 60, 75, 85, 99, 105}
    fmt.Println(Search(items,85))
}

// Output = 8


// Time Complexity = O(n)
// Space Complexity = O(n)
