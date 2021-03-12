package main

import "fmt"

func Sieve(n int) {

	prime := make([]bool, n+1)

	for itr := 0; itr <= n; itr++ {
		prime[itr] = true
	}

	for p := 2; p*p <= n; p++ {
		if prime[p] == true {
			for x := p * p; x <= n; x += p {
				prime[x] = false
			}
		}
	}

	for p := 2; p <= n; p++ {
		if prime[p] == true {
			fmt.Print(p, " ")
		}
	}
}

func main() {
	var num int

	fmt.Print("Enter the range: ")
	fmt.Scan(&num)
	Sieve(num)
}

// TIME COMPLEXITY: O(n*log(log(n)))
// SPACE COMPLEXITY: O(n)

// TEST CASE 1:
// Enter the range: 50
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

// TEST CASE 2:
// Enter the range: 100
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

