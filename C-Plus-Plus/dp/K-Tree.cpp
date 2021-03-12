/*
problem statement original link: https://codeforces.com/problemset/problem/431/C
why are we using dynamic programming:
At every node we are having k different choises to include in our path.
So whenever we have to deal all the possible choises and pick the best out of them
then we can use recusrsion . but due to overlapping subproblems it wont be an efficient
approach.To optimize recusive solution we use dynamic programming.

**dcaught variable says whether there is atleast one edge with weight atleast d in the current path 
(dp state)
dp[i][j] means the number of paths from root with sum of edges is i and truth value
of :there is atleast one edge with weight atleast d is j
so basically our answer is dp[n][dcaught] (according to dp state).
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[105][2];
int Number_of_Paths(int n, int k, int d, bool dcaught)
{
    /* base case: found a path with required sum of edges
       we need to return 1 if dcaught is true
       else it cant be included in the answer
    */
    if (n == 0)
    {
        return dcaught == true;
    }
    /* memoization step: checking whether the current required answer is already caluculated or not
       if yes then simply return the answer
    */
    if (dp[n][dcaught] != -1)
    {
        return dp[n][dcaught];
    }
    // cnt variable has the number of paths
    int cnt = 0;
    // min(n,k) because including edges with weight greater than n is useless
    for (int weight = 1; weight <= min(n, k); weight++)
    {
        /* if weight is >=d then we pass decaught further as true
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
    /* memset is used to fill the dp matrix with -1
      why -1? it's not a possible answer in this problem
    */
    memset(dp, -1, sizeof(dp));
    int n, k, d;
    cin >> n >> k >> d;
    int ans = Number_of_Paths(n, k, d, false);
    cout << ans << endl;
    return 0;
}

/*
Time complexity:O(n*k)
Input: 4 3 2
output:6
*/
