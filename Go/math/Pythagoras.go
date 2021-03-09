package main

import (
	"fmt"
	"math"
)

func pythagoras(a, b float64) float64 {
	return math.Sqrt(math.Pow(a, 2.0) + math.Pow(b, 2.0))

}

func main() {
	fmt.Println(pythagoras(3.0, 4.0))
}

// Time Complexity - O(1)
// Space Complexity - O(1)
