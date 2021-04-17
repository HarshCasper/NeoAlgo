/* This code checks if a number is a magic number.
Magic number - We find the recursive sum of digits
of number till a single digit. If the single digit 
is 1, then it is a magic number, else it is not.*/

package main

import (
	"fmt";
)

// This function finds sum of digits of a number
func sum_of_digits(n int) int {
	var sum int = 0
	for n != 0 {
		sum += n % 10
		n = n / 10
	}
	// Returning the sum
	return sum
}

// This function checks if number is a magic number
func check_magic_number(number int) int {
	var first int

	// Find the sum of digits of number
	first = sum_of_digits(number)

	/* Till we get a single digit, recursively
	call the sum function*/
	for first >= 10 {
		first = sum_of_digits(first)
	}

	// If the sum becomes 1, return 1 else -1
	if(first == 1) {
		return 1
	} else {
		return -1
	}
}

func main() {

	// Take number as input from the user
	var number int
	fmt.Print("Enter a number to check if it is a magic number: ")
	fmt.Scan(&number)

	// Call the magic number checker function
	var result int = check_magic_number(number)

	/* If returned value is 1, then the number is
	a magic number, else it is not*/
	if(result == 1) {
		fmt.Print("\nThe number ", number, " is a magic number.\n")
	} else {
		fmt.Print("\nThe number ", number, " is not a magic number.\n")
	}
}

/* Sample I/O:

Enter a number to check if it is a magic number: 1729

The number 1729 is a magic number.

*/

