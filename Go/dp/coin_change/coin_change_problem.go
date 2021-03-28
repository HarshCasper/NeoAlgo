// Given a value N, if we want to make change for N cents,
// and we have infinite supply of each of S = { S1, S2, .. , Sm}
// valued coins, how many ways can we make the change?
// The order of coins doesn’t matter.

package main

import "fmt"

// function to count coins
func countCoins(coins []int, numberOfCoin, value int) int {
	// creating 2d slice
	dp := make([][]int, value+1)
	for itr := 0; itr <= value; itr++ {
		dp[itr] = make([]int, numberOfCoin)
	}

	// value if n = 0
	for i := 0; i < numberOfCoin; i++ {
		dp[0][i] = 1
	}

	// bottom up manner
	for i := 1; i < value+1; i++ {
		for j := 0; j < numberOfCoin; j++ {

			var x int
			if i-coins[j] >= 0 {
				x = dp[i-coins[j]][j]
			} else {
				x = 0
			}

			var y int
			if j >= 1 {
				y = dp[i][j-1]
			} else {
				y = 0
			}

			dp[i][j] = x + y
		}
	}
	return dp[value][numberOfCoin-1]
}

func main() {
	fmt.Print("Enter the number of coins : ")
	var numberOfCoin int
	fmt.Scan(&numberOfCoin)

	fmt.Print("Enter the value of coins : ")
	coins := make([]int, numberOfCoin)
	for itr := 0; itr < numberOfCoin; itr++ {
		fmt.Scan(&coins[itr])
	}

	fmt.Print("Enter the amount : ")
	var value int
	fmt.Scan(&value)

	count := countCoins(coins, numberOfCoin, value)

	fmt.Println("Number of coins : ", count)
}

// Time complexity : O(numberOfCoin * value)
// Space complexity : O(numberOfCoin * value)

// TEST CASE 1:
// Enter the number of coins : 3
// Enter the value of coins : 1 2 3
// Enter the amount : 4
// Number of coins :  4

// TEST CASE 2:
// Enter the number of coins : 4
// Enter the value of coins : 2 5 3 6
// Enter the amount : 10
// Number of coins :  5
