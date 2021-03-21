package main

import (
	"fmt"
	"math"
)

// Find takes a slice and looks for an element in it. If found it will
// return true otherwise it will return false.
func Find(slice []string, val string) (int, bool) {
	for i := 0; i < len(slice); i++ {
		if string(slice[i]) == val {
			return i, true
		}
	}
	return -1, false
}

func longestSubstring(value string) {
	if len(value) == 0 {
		fmt.Println("String is empty")
	} else {
		left := 0
		right := 0
		maxLength := 0 // max lenght of substring

		var uniqueChars []string // to store the visited chars.

		var start int // starting index for longest substring with non repeating char.
		var end int   // ending index for longest substring with non repeating char.

		for right < len(value) && left < len(value) {
			index, isThere := Find(uniqueChars, string(value[right]))
			if !isThere {
				uniqueChars = append(uniqueChars, string(value[right]))
				maxLength = int(math.Max(float64(maxLength), float64(len(uniqueChars))))
				if maxLength == len(uniqueChars) {
					// if the maxLenght == lenght of uniqeChars it might be the longest substring
					// with non repeating char.
					// si it's stroing the starting and ending index of that substring
					start = left
					end = right

				}
				right++
			} else {

				char := string(value[left])
				// finding the index of char that is repeatating in substring
				index, isThere = Find(uniqueChars, char)
				if isThere {
					// this simple removes the that char from this slice
					uniqueChars = append(uniqueChars[:index], uniqueChars[index+1:]...)
					left++
				}

			}
		}

		fmt.Print("Longest Substring Without Repeating Characters: ")
		fmt.Println(value[start : end+1])

	}
}

func main() {
	var input string
	fmt.Println("enter the string without space")
	fmt.Scanf("%s", &input)
	longestSubstring(input)
}

/*

	input/output sample

	enter the string without space
	pwwkew
	Longest Substring Without Repeating Characters: kew

	enter the string without space
	bbbbb
	Longest Substring Without Repeating Characters: b

	enter the string without space
	abcabcbb
	Longest Substring Without Repeating Characters: abc

*/
