/* 
   Find number of subsets with given difference between their sums 
 
   This approach uses dynamic programming and subset sum problem to find the count 
   of subsets whose difference is given. To count the subsets with a given a sum, we need a sum in this problem
   which can be found out by using the formula (diff + sum(arr))/2 explained below.
*/

#include <bits/stdc++.h>
using namespace std;
int dp[20001][20001];

int countSubsets(int arr[], int n, int sum)
{
	if (dp[n][sum] != -1)
		return dp[n][sum];
	// base case
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	if (arr[n - 1] <= sum)
		return dp[n][sum] = countSubsets(arr, n - 1, sum - arr[n - 1]) + countSubsets(arr, n - 1, sum);
		
	return dp[n][sum] = countSubsets(arr, n - 1, sum);
}

int subsetsDiff(int arr[], int n, int diff)
{
	int arr_sum = 0;
	// sum of the array
	for (int i = 0; i < n; i++)
		arr_sum += arr[i];
    /*
    Let there be two subsets with sum s1 and s2 respectively
	s1 + s2 = arr_sum
	s1 - s2 = diff
	so solving the above equations, we get:
	s1 = (diff + arr_sum)/2
	Therefore, we will find number of subsets with sum as s1
    */
	int sum = (diff + arr_sum) / 2;
	
	return countSubsets(arr, n, sum);
}

int main()
{
	// dp table
	memset(dp, -1, sizeof(dp));
	int n, diff; 
	cin >> n >> diff;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << subsetsDiff(arr, n, diff);
	
	return 0;
}

/* 
 
 Sample I/O:
 First line contains two integers n and diff denoting size of array 
 and the required difference
 Next line contains n spaced integers
 4 1
 1 1 2 3

 Output: 3

 Explanation:
 Three pairs of subsets:
 1.[1, 1, 2] and[3]
 2.[1, 2] and[1, 3]
 3.[1, 3] and[1, 2] (Because there are two 1's, so repitition of pairs is there)
*/

/*
 Complexity Analysis: 
 Time Complexity: O(sum*n), where sum is the ‘sum’ in the function subsetsDiff and ‘n’ is the size of array.
 Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
*/
