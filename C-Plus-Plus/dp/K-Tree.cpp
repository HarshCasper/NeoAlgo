/*
problem link: https://codeforces.com/problemset/problem/431/C

Problem description:
A k-tree is an infinite rooted tree where:
- each vertex has exactly k children.
- each edge has some weight.
- edge weights will be in order 1,2,..k from left most child to right most child
  of every node in the tree

count number of paths of total weight n (the sum of all weights of the edges in the path),
starting from the root of a k-tree and also containing at least one edge of weight at least d
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[105][2];
int Number_of_Paths(int n, int k, int d, bool dcaught)
{
	// base case.
	if (n == 0)
	{
		return dcaught == true;
	}
	/* memoization step: checking whether the current required answer is already caluculated or not
	   if yes then we will simply return the answer.
	*/
	if (dp[n][dcaught] != -1)
	{
		return dp[n][dcaught];
	}
	// cnt variable has number of paths
	int cnt = 0;
	// min(n,k) is used because including edges with weight greater than n wont help us.
	for (int weight = 1; weight <= min(n, k); weight++)
	{
		/* if weight is >=d then we pass decaught as true
		   else we pass its current value only
		*/
		if (weight >= d)
		{
			cnt = (cnt % mod + Number_of_Paths(n - weight, k, d, true) % mod) % mod;
		}
		else
		{
			cnt = (cnt % mod + Number_of_Paths(n - weight, k, d, dcaught) % mod) % mod;
		}
	}
	// according to dp state the required answer will be at dp[n][dcaught]
	return dp[n][dcaught] = cnt;
}

int main()
{

	memset(dp, -1, sizeof(dp));
	int n, k, d;
	cin >> n >> k >> d;
	int ans = Number_of_Paths(n, k, d, false);
	cout << ans << endl;
	return 0;
}

/*
Time complexity:O(n*k)
Space complexity:O(n)
Input: 4 3 2
output:6
*/
