/* Given two sequences, find the length of longest subsequence present
in both of them. A subsequence is a sequence that appears in the
same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc
are subsequences of “abcdefg”. So, the answer will be the longest
length i.e. 5
*/

package main

import "fmt"

// function to find the maximum
func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// longest common subsequence function
func lcs(X, Y string, m, n int) int {
	// creating 2d array
	L := make([][]int, m+1)
	for itr := 0; itr <= m; itr++ {
		L[itr] = make([]int, n+1)
	}

	// bottom up fashion
	for i := 0; i <= m; i++ {
		for j := 0; j <= n; j++ {
			if i == 0 || j == 0 {
				L[i][j] = 0
			} else if X[i-1] == Y[j-1] {
				L[i][j] = L[i-1][j-1] + 1
			} else {
				L[i][j] = max(L[i-1][j], L[i][j-1])
			}
		}
	}

	return L[m][n]
}

func main() {
	var str1 string
	var str2 string

	fmt.Print("Enter the 1st string : ")
	fmt.Scan(&str1)

	fmt.Print("Enter the 2nd string : ")
	fmt.Scan(&str2)

	m := len(str1)
	n := len(str2)

	if m < n {
		fmt.Println("Length of LCS is: ", lcs(str1, str2, m, n))
	} else {
		fmt.Println("Length of LCS is: ", lcs(str2, str1, n, m))
	}
}

/*
TIME COMPLEXITY: O(M*N)
SPACE COMPLEXITY: O(M*N)


OUTPUT

TEST CASE 1:
Enter the 1st string : NEOALGO
Enter the 2nd string : ALGORITHM
Length of LCS is:  4

TEST CASE 2:
Enter the 1st string : ABQWERTYCD
Enter the 2nd string : QWERTY
Length of LCS is:  6
*/
