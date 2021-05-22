/*Problem Statement: “Given an integer arrays representing the height of each stack of coins and the number of coin stacks, calculate the minimum number of straight lines that pass through all the coins (minimum number of steps to collect these coins).”*/


// Hints: Divide and Conquer
#include <iostream>
using namespace std; 

// returns minimum of two numbers
int min2(int a, int b){
  return a < b ? a : b;
}

/* 
   Utility method, called recursively to collect
   coins from `l` to `r` using the height array
   assuming that h height has already been collected
*/
int minimumStepsUtil(int l, int r, int h, int height[]) { 
	// base condition: all coins already collected 
	if (l >= r) 
		return 0; 

	// find minimum height index
	int m = l; 
	for (int i = l; i < r; i++) 
		if (height[i] < height[m]) 
			m = i; 
/* 
    Calculate min steps by: 
		a) collecting all vertical line coins 
       (total r - l) 
		b) collecting all lower horizontal line coins
       recursively on left and right segments 
  */
	return min2(r - l, 
			minimumStepsUtil(l, m, height[m], height) + 
			minimumStepsUtil(m + 1, r, height[m], height) + 
			height[m] - h); 
} 

/*
    calls the recursive utility function
    and returns the minimum number of steps
    using height array
*/
int minimumSteps(int height[], int N) { 
	return minimumStepsUtil(0, N, 0, height); 
} 

// Testing minimumSteps() method
int main() { 
	int height[] = { 2, 1, 2, 5, 1 }; 
	int N = sizeof(height) / sizeof(int); 

	cout << minimumSteps(height, N) << endl; 
	return 0; 
}

/* Time Complexity: O(n^2)O(n
​2
​​ )

First we start horizontally from the bottom, we can get rid of the lowest coin row and collect the maximum possible number of coins since the bottom rows are guaranteed to be filled. We’ll work on coin stacks from left, stackl, to right, stackr, in each recursion step.

Save the height of the smallest stack to m. Remove m horizontal lines, after which the stack will have two parts remaining: l to m and m + 1 to r. We’ll use these as subarrays.

We then make a recursive call on each subarray to repeat horizontal coin collection.

Since coins may also be collected using vertical lines, we then choose the minimum of the result of recursive calls and r – l.

Using (r – l) vertical lines, we can always collect all coins vertically. */

