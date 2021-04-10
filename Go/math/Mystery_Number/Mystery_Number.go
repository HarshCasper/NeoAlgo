/* Below checks checks if a number is a mystery number.
Mystery number - A number that can be represented by sum
of two numbers, such that the two numbers are reverse of
each other.*/

package main

import (
	"fmt"
	"strconv"
)

/* This function takes a number as a input and returns
a number with the digits reversed*/
func rev(number int) int {

	var reverse string
	for number > 0 {
		/* The number is broken into pieces by taking mod 10.
		Each digit is converted to string and concatenated.*/
		str := strconv.Itoa(number % 10)
		reverse += str
		number = number / 10
	}
	// Finally the reversed string is converted back to integer
	revs, err := strconv.Atoi(reverse)
	if(err == nil) {
		// If there were no errors we return the number
		return revs
	}
	return -1
}

// This function checks if the number is a mystery number
func mystery(number int) int {

	// We iterate till the middle of the number
	var distance int = number / 2
	for i:= 1; i <= distance; i++ {
		// Check the sum of number with its reverse
		if(i + rev(i) == number) {
			// If its is equal to the given number we return and print
			fmt.Print("\nThe two digits are: ", i, " ", rev(i))
			return 1
		}
	}
	// Else return -1
	return -1
}

func main() {

	// Taking number as input from the user
	fmt.Print("Enter a number to check if it's a mystery number: ")
	var number int
	fmt.Scan(&number)

	// Calling the mystery function
	var result int = mystery(number)

	// If the result is 1, the number is a mystery number
	if(result == 1) {
		fmt.Print("\nThe number ", number, " is a mystery number.\n")
	} else {
		// Else it is not a mystery number
		fmt.Print("\nThe number ", number, " is not a mystery number.\n")
	}
}

/* Sample I/O:

Enter a number to check if it's a mystery number: 33

The two digits are: 12 21
The number 33 is a mystery number.

*/
