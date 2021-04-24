/* This program calculates nth term of the fibonacci sequence using
Dynamic Programming in Go. In DP, we follow bottom-up approach to
reach to the desired solution. Doing this prevents multiple calls
to same function input as in the case of recursion.*/

package main

import (
	"fmt"
	"os"
)

// This function returns the nth term in the fibonacci sequence
func fibonacci(number int) int {

	// Decalre an array to store values in a bottom-up manner
	array := make([]int, number + 2)

	// Base case/seeds
	array[0] = 0
	array[1] = 1

	// Run the for loop constructing the sequence till number is reached
	for i := 2; i <= number; i++ {
		array[i] = array[i - 1] + array[i - 2]
	}

	// Return the nth term
	return array[number]
}

func main() {

	// Take user input
	fmt.Print("Enter a number: ")
	var number int
	fmt.Scan(&number)

	// If number is less than 0, exit
	if(number < 0) {
		fmt.Print("\nPlease enter a non-neagtive number.", "\n")
		os.Exit(0)
	}

	// Call the function and print the nth term in the fibonacci sequence
	var result int = fibonacci(number)
	fmt.Print("\nThe term at position ", number, " in the fibonacci sequence is ", result, ".\n")
}

/*
Sample I/O:

1)
Enter a number: 16

The term at position 16 in the fibonacci sequence is 987.

2)
Enter a number: -12

Please enter a non-neagtive number.

*/
