// Golang Program to check whether a given number is an Armstrong number or not

/*
  In recreational number theory, an Armstrong number (also known as narcissistic number)
  is a number that is equal to the sum of its own digits, each raised to the power of
  the total number of digits.
  For example, in the case of 3 digit numbers,
  153 is an Armstrong number as 153 = 1*1*1 + 5*5*5 + 3*3*3
*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	// taking an 'n' digit number as input
	var number int
	fmt.Print("\n Enter a number : ")
	fmt.Scan(&number)
	// displaying results after calling isArmstrong()
	if isArmstrong(number) {
		fmt.Printf(" %d is an Armstrong number", number)
	} else {
		fmt.Printf(" %d is NOT an Armstrong number", number)
	}
}

// function to check whether a number is Armstrong or not
func isArmstrong(number int) bool {
	sum := 0
	digit := 0
	copyNum := number
	/* getting the number of digits of the integer by
	   converting it to a string and finding its length */
	numberOfDigits := len(strconv.Itoa(number))
	for {
		// discarding negative integers
		if copyNum <= 0 {
			break
		}
		temp := 1
		// extracting last digit
		digit = copyNum % 10
		// raising it to the power of number of digits
		for i := 0; i < numberOfDigits; i++ {
			temp = temp * digit
		}
		// storing the resulting number in sum
		sum += temp
		copyNum = copyNum / 10
	}
	// returning true if the number is equal to sum
	return number == sum
}

/*
	Time Complexity = O(log(n))
	Space Complexity = O(1)

	Sample inputs and outputs:

	i/o 1 -
	 Enter a number: 153
	 153 is an Armstrong number.

	i/o 1 -
	 Enter a number: 369
	 369 is NOT an Armstrong number.

	i/o 3 -
	 Enter a number: 370
	 370 is an Armstrong number.
*/
