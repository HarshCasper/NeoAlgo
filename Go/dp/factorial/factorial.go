/* This code is an implementation of factorial in Go using Dynamic 
Programming. In DP, we follow bottom-up approach to reach to the 
desired solution. Doing this prevents multiple calls to same function
input as in the case of recursion.*/

package main

import (
	"fmt"
	"os"
)

// This function takes a number as input and returns its factorial
func factorial(number int) int {

	// Make an array to store the factorial in a bottom-up manner
	array := make([]int, number+1)
	// Set 0! to be 1
	array[0] = 1

	// Run a loop from 1 to the number
	for i := 1; i <= number; i++ {
		array[i] = i * array[i - 1]
	}
	// Return the factorial
	return array[number]
}

func main() {

	// Take number as input from the user
	fmt.Print("Enter a number to calculate its factorial: ")
	var number int
	fmt.Scan(&number)

	// If the number is less than 0, return
	if(number < 0) {
		fmt.Print("\nPlease enter a non-negative number.", "\n")
		os.Exit(0)
	}

	// Call the factorial function and print the factorial
	var result int = factorial(number)
	fmt.Print("\nFactorial of ", number, " is: ", result, "\n")
}

/*
Sample I/O:

1)
Enter a number to calculate its factorial: 11

Factorial of 11 is: 39916800

2)
Enter a number to calculate its factorial: -32

Please enter a non-negative number.

*/
