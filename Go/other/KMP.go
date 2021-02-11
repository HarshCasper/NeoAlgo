package main

import (
	"fmt"
)

const (
	Size int = 100
)

func SearchNext(target string, point string) int {
	Solution := KMP(target, point)
	if len(Solution) > 0 {
		return Solution[len(Solution)-1]
	}

	return -1
}

func SearchString(target string, point string) int {
	Solution := KMP(target, point)
	if len(Solution) > 0 {
		return Solution[0]
	}

	return -1
}

func KMP(target string, point string) []int {
	next := preKMP(point)
	i := 0
	j := 0
	m := len(point)
	n := len(target)

	x := []byte(point)
	y := []byte(target)
	var sol []int

	if m == 0 || n == 0 {
		return sol
	}

	if n < m {
		return sol
	}

	for j < n {
		for i > -1 && x[i] != y[j] {
			i = next[i]
		}
		i++
		j++

		if i >= m {
			sol = append(sol, j-i)
			i = next[i]
		}
	}

	return sol
}

func preKMP(x string) [Size]int {
	var i, j int
	length := len(x) - 1
	var KMPnext [Size]int
	i = 0
	j = -1
	KMPnext[0] = -1

	for i < length {
		for j > -1 && x[i] != x[j] {
			j = KMPnext[j]
		}

		i++
		j++

		if x[i] == x[j] {
			KMPnext[i] = KMPnext[j]
		} else {
			KMPnext[i] = j
		}
	}
	return KMPnext
}

// Input code

func main() {
	fmt.Println("Search First Position String:")
	fmt.Println(SearchString("coding", "di"))

	fmt.Println("\nSearch Last Position String:")
	fmt.Println(SearchNext("coding", "in"))
}

// Output:

// Search First Position String:
// 2
// Search Last Position String:
// 3

// Time Complexity = O(n) Space Complexity = O(n)
