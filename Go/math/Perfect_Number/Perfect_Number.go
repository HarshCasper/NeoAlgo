/* This program written in Go checks if a number is a perfect
number. A perfect number is a number which is equal to the sum
of its divisors (excluding the number itself).*/

package main

import (
	"fmt"
	"os"
)

// This function checks if a number is a perfect number
func is_perfect(number int) int {

	// This variable stores the sum of divisors of number
	sum_of_divisors := 0
	// Iterate from 1 till the number
	for i := 1; i < number; i++ {
		if(number % i == 0) {
			// Add divisors
			sum_of_divisors += i
		}
	}
	// If the sum of divisors is equal to the number
	if(sum_of_divisors == number) {
		// Return 1
		return 1
	}
	// Else return -1
	return -1
}

func main() {

	// Take number as input from the user
	fmt.Print("Enter a number to check if it's a perfect number: ")
	var number int
	fmt.Scan(&number)

	// If the number is non-positive, exit
	if(number <= 0) {
		fmt.Print("\nPlease enter a positive number.\n")
		os.Exit(0)
	}

	// Call the function
	var result int = is_perfect(number);

	// If the result is 1, the number is a perfect number
	if(result != -1) {
		fmt.Print("\nThe number ", number, " is a perfect number.\n")
	} else {
		// Else it is not
		fmt.Print("\nThe number ", number, " is not a perfect number.\n")
	}
}

/*
Sample I/O:

1)
Enter a number to check if it's a perfect number: 28

The number 28 is a perfect number.

2)
Enter a number to check if it's a perfect number: 12

The number 12 is not a perfect number.

3)
Enter a number to check if it's a perfect number: -2

Please enter a positive number.

*/
