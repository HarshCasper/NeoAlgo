/* This program calculates the GCD(Greatest Common Divisor)
of two numbers given as input.*/

package main

import (
	"fmt"
)

// This function finds the minimum of two numbers and returns it
func min(n1, n2 int) int {
	if(n1 < n2) {
		return n1
	} else {
		return n2
	}
}

// This function calculates the GCD.
func is_gcd(n1, n2 int) int {

	// Find the minimum of two numbers
	var min int = min(n1, n2)
	var result int

	// Iterate till the minimum
	for i := 1; i <= min; i++ {
		// It it divides both n1 and n2
		if(n1 % i == 0 && n2 % i == 0) {
			// Set it as gcd
			result = i
		}
	}
	// After completion return the GCD
	return result
}

func main() {

	// Take two numbers as input from the user
	fmt.Print("Enter two numbers followed by spaces: ")
	var n1, n2 int
	fmt.Scan(&n1, &n2)

	// Call the GCD function
	var result int = is_gcd(n1, n2)

	// Print the result
	fmt.Print("\nGCD of ", n1, " and ", n2, " is ", result, "\n")
}

/* Sample I/O:

Enter two numbers followed by spaces: 100 12

GCD of 100 and 12 is 4

*/
