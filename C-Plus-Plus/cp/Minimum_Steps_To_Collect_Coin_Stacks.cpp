/*Problem Statement: “Given an integer arrays representing the height of each stack of coins
 and the number of coin stacks, calculate the minimum number of straight lines that pass 
 through all the coins (minimum number of steps to collect these coins).”*/

// Hints: Divide and Conquer
#include <bits/stdc++.h>
using namespace std;

// returns minimum of two numbers
int min2(int a, int b) {
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
  int n;
  cout << "Enter the number of coin stacks:" << endl;
  cin >> n;
  int height[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter the height of " << i + 1 << " coin stack:" << endl;
    cin >> height[i];
  }
  int ans = minimumSteps(height, n);
  cout << "Minimum number of straight lines that pass through all the coins are:" << ans;
}

/* Time Complexity: O(n^2)
Space Complexity: O(n)
 */