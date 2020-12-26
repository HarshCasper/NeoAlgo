package main

import (
	"fmt"
)

const (
	PatternSize int = 100
)

func StringLast(key string, point string) int {
	word := KMP(key, point)
	if len(word) > 0 {
		return word[len(word)-1]
	}
	return -1
}

func StringFirst(key string, point string) int {
	word := KMP(key, point)
	if len(word) > 0 {
		return word[0]
	}
	return -1
}

func KMP(key string, point string) []int {
	new := preKMP(point)
	i := 0
	j := 0
	m := len(point)
	n := len(key)
	x := []byte(point)
	y := []byte(key)
	var value []int
	if m == 0 || n == 0 {
		return value
	}
	if n < m {
		return value
	}
	for j < n {
		for i > -1 && x[i] != y[j] {
			i = new[i]
		}
		i++
		j++

		//fmt.Println(i, j)
		if i >= m {
			value = append(value, j-i)
			//fmt.Println("find:", j, i)
			i = new[i]
		}
	}
	return value
}

func preKMP(x string) [PatternSize]int {
	var i, j int
	length := len(x) - 1
	var kmpNext [PatternSize]int
	i = 0
	j = -1
	kmpNext[0] = -1

	for i < length {
		for j > -1 && x[i] != x[j] {
			j = kmpNext[j]
		}
		i++
		j++
		if x[i] == x[j] {
			kmpNext[i] = kmpNext[j]
		} else {
			kmpNext[i] = j
		}
	}
	return kmpNext
}

// Test Code
func main() {
	fmt.Println("First Position String:")
	fmt.Println(StringFirst("cocacola", "co"))

	fmt.Println("\nLast Position String:")
	fmt.Println(StringLast("cocacola", "co"))
}

// Output
// First Position String: 0
// Last Position String: 4

// Time Complexity = O(n) Space Complexity = O(n)
