/*Below code is an implementation of factorial in Go. Factorial
of a number n is defined as:
	fact(n) = n * (n - 1) * (n - 2) ........ * 1 
The code contains a factorial function which calculates the
factorial of the number iteratively.*/

package main

import (
	"fmt"
)

// This function calculates the factorial
func factorial(number int) uint64 {

	// Decalring variable to store the factorial
	var factorial_number uint64 = 1

	if(number >= 0) {
		// Multiply 1 * 2 * .... * (n) using for loop
		for i:=1; i <= number; i++ {
			// Type conerting i to uint64 for multiplication
			factorial_number = factorial_number * uint64(i)
		}
	} else {
		// If number is negative return 0
		return 0
	}
	// Return the factorial
	return factorial_number
}

func main() {

	// Taking a number as input from the user
	var number int
	fmt.Print("Enter a number to find its factorial: ")
	fmt.Scan(&number)

	// Calling the factorial function
	var factorial_value uint64 = factorial(number)

	/* If the returned value is zero, the number is negative
	   Else, the factorial of the number is printed.*/
	if(factorial_value == 0) {
		fmt.Print("Please enter a positive number.\n")
	} else {
		fmt.Print("Factorial of ", number, " is ", factorial_value, "\n")
	}
}

/* Sample I/O:

a) 
Enter a number to find its factorial: -3
Please enter a positive number.

b)
Enter a number to find its factorial: 11
Factorial of 11 is 39916800

Time Complexity - O(n)
Space Complexity - O(1)

*/

