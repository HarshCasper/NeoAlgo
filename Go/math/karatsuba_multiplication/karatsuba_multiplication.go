package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

// multiply takes in two numbers as string
// and multiply them in recursive way
func multiply(first, second string) string {
	// if the number are small we don't need to use
	// karatsuba multiplication
	if len(first) < 2 || len(second) < 2 {
		intA, _ := strconv.Atoi(first)
		intB, _ := strconv.Atoi(second)
		return strconv.Itoa(intA * intB)
	}

	if len(first)%2 == 1 {
		first = "0" + first
	}
	if len(second)%2 == 1 {
		second = "0" + second
	}

	// makeing the length of both number same
	// added to fix uneven length factors
	first, second = addZeroFront(first, second)

	// split strings from middle
	mid := getMiddle(first, second)
	firstRight, firstLeft := splitNum(first, mid)
	secondRight, secondLeft := splitNum(second, mid)

	// making recursive calls
	// for multiplication
	leftMultiplication := multiply(firstLeft, secondLeft)
	rightMultiplication := multiply(add(firstLeft, firstRight), add(secondLeft, secondRight))
	temp := multiply(firstRight, secondRight)

	t0 := sub(sub(rightMultiplication, temp), leftMultiplication)
	t1 := add(addZeroEnd(leftMultiplication, mid*2), addZeroEnd(t0, mid))
	t2 := add(t1, temp)
	return trim(t2)
}

func getMiddle(first, second string) int {
	mid := math.Max(float64(len(first)), float64(len(second)))
	return int(mid / 2)
}

func splitNum(s string, mid int) (string, string) {
	right := s[mid:]
	left := s[:mid]
	return right, left
}

func addZeroFront(first, second string) (string, string) {
	if len(first) < len(second) {
		first = strings.Repeat("0", len(second)-len(first)) + first
	} else {
		second = strings.Repeat("0", len(first)-len(second)) + second
	}
	return first, second
}

func addZeroEnd(s string, mid int) string {
	return s + strings.Repeat("0", mid)
}

func trim(s string) string {
	for s[:1] == "0" && len(s) > 1 {
		s = s[1:]
	}
	return s
}

func add(first, second string) string {
	var sum string
	var carry int
	first, second = addZeroFront(first, second)

	for i := len(first) - 1; i >= 0; i-- {
		intA, _ := strconv.Atoi(first[i : i+1])
		intB, _ := strconv.Atoi(second[i : i+1])

		sumDigit := intA + intB + carry
		carry = 0

		if sumDigit >= 10 {
			sumDigit -= 10
			carry = 1
		}

		sum = strconv.Itoa(sumDigit) + sum
	}

	// handle carry after for-loop terminates
	if carry != 0 {
		return strconv.Itoa(carry) + sum
	}

	return sum
}

func sub(first, second string) string {
	var sum string
	var carry int
	first, second = addZeroFront(first, second)

	for i := len(first) - 1; i >= 0; i-- {
		intA, _ := strconv.Atoi(first[i : i+1])
		intB, _ := strconv.Atoi(second[i : i+1])

		sumDigit := intA - intB - carry
		carry = 0

		if sumDigit < 0 {
			sumDigit += 10
			carry = 1
		}

		sum = strconv.Itoa(sumDigit) + sum
	}
	return sum
}

func main() {
	firstNumberInput, secondNumberInput := 0, 0

	fmt.Println("enter first number:")
	fmt.Scanf("%d", &firstNumberInput)
	fmt.Println("enter second number:")
	fmt.Scanf("%d", &secondNumberInput)

	// converting both number to positve number because
	// this program work only on posotive numbers
	firstNumber := int(math.Abs(float64(firstNumberInput)))
	secondNumber := int(math.Abs(float64(secondNumberInput)))

	fmt.Println("the multiplication result is:")
	rawResult := multiply(strconv.Itoa(firstNumber), strconv.Itoa(secondNumber))

	result := ""
	// if the any input is negative then
	// we will add minus sign before result
	if firstNumberInput < 0 && secondNumberInput < 0 {
		result = rawResult
	} else if firstNumberInput < 0 {
		result = "-" + rawResult
	} else if secondNumberInput < 0 {
		result = "-" + rawResult
	} else {
		result = rawResult
	}
	fmt.Println(result)
}

/*
	time complexity : O(n^1.585)
	space complexity : O(n)

	input/output sample

	enter first number:
	111111
	enter second number:
	222222
	the multiplication result is:
	24691308642

	enter first number:
	-54454644
	enter second number:
	454634
	the multiplication result is:
	-24756932620296

	enter first number:
	-4454545
	enter second number:
	-1314544
	the multiplication result is:
	5855695402480
*/
