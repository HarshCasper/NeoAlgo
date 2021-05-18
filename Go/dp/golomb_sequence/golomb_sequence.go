/* This program prints first n terms of the golomb sequence. n is the
number taken as input from the user. Golomb sequence is a non-decreasing
sequence of integers where the nth term of the sequence is equal to the
number of times n appears in the sequence. We use dynamic programming
approach to form the sequence.

The nth term of the golomb sequence is given by the formula:

Golomb(1) = 1 (Base case)
Golomb(n + 1) = 1 + Golomb(n + 1 - Golomb(Golomb(n))), for n > 1
*/

package main

import (
	"fmt"
	"os"
)

// This function prints the golomb sequence
func Print(array []int, number int) {

	// If the number given as input is 1
	if(number == 1) {
		fmt.Print("\nFirst term of the Golomb sequence is: ")
	} else {
		// Number given as input is greater than 1
		fmt.Print("\nFirst ", number, " terms of the Golomb sequence are: ")
	}

	// Iterate till the length of the array
	for i := 1; i < len(array); i++ {
		// And print the numbers
		fmt.Print(array[i], " ")
	}
	fmt.Print("\n")
}

// This function forms the golomb sequence
func golomb_seq(number int) {

	/* Initialize an array to store the number
	in a bottom-up manner.*/
	array := make([]int, number + 1)

	// Base cases/seeds
	array[0] = 0
	array[1] = 1

	// Iterate from 2 to the number
	for i := 1; i < number; i++ {
		/* Get the number at that position using the formula
		and add it to the array.*/
		array[i + 1] = 1 + array[i + 1 - array[array[i]]]
	}
	// Call the print function to print the golomb sequence
	Print(array, number)
}

func main() {

	// Take number as input from the user
	fmt.Print("Enter a number: ")
	var number int
	fmt.Scan(&number)

	// If the number is not positive, exit
	if(number <= 0) {
		fmt.Print("\nPlease enter a positive number.\n")
		os.Exit(0)
	}

	// Call the function to print the sequence
	golomb_seq(number)
}

/*

Sample I/O:

1)
Enter a number: 16

First 16 terms of the Golomb sequence are: 1 2 2 3 3 4 4 4 5 5 5 6 6 6 6 7

2)
Enter a number: -21

Please enter a positive number.

*/
