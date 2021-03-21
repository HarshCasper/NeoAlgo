// Converting Integer number to its Roman form
// Whenever user type any integer value, they will get the roman value for a particular integer value.

package main

import "fmt"

func main() {
	var number int
	fmt.Print("Enter a number : ")
	fmt.Scan(&number)
	fmt.Println("Roman number of", number, "is", calIntToRoman(number))
}

// applying simple mathematics
// checking of respective roman number for each digit

func calIntToRoman(number int) string {
	result := ""

	j := 1

	// storing integer value
	// help to convert it's respective roman number
	intValue := [13]int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	romanValue := [13]string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}

	// iterating integer and roman value
	// the number contains perticular integer value, based on that adds it's roman value
	for i := 0; i < 13; i++ {
		if number >= intValue[i] {
			f := number / intValue[i]
			number = number % intValue[i]
			for j <= f {
				result = result + romanValue[i]
				j++
			}
		}
		j = 1
	}
	return result
}

// Sample Input/Output
// Input : Enter a number : 15
// Output : Roman number of 15 is XV
