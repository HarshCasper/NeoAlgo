/*
You've heard of 0-N knapsack. Below
is the problem statement for the same.
Given two integer arrays val[0..n-1] 
and wt[0..n-1] which represent values 
and weights associated with n items
respectively. Also given an integer
cap which represents knapsack capacity,
find out the maximum value subset of 
val[] such that sum of the weights of 
this subset is smaller than or equal 
to cap. You cannot break an item, either
pick the complete item,or don’t pick it
(0-1 property).There is a little twist 
for 0-N knapsack. You can pick an element
more than once. Now you have to find 
maximum value multi subset of val[]
such that sum of the weights of this 
subset is smaller than or equal to cap.
Note: Maximum value subset means the 
subset with maximum sum of all the 
values in subset.
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll dp[1000] = {
    0
};
ll Zero_N_Knapsack(ll cap,
    ll val[], ll W[], ll n)
{
    for (ll i = 0; i <= cap; i++) {
        for (ll j = 0; j < n; j++) {
            if (val[j] <= i) {
                dp[i] = max(dp[i], dp[i - val[j]] + W[j]);
            }
        }
    }
    return dp[cap];
}

int main()
{
    ll n, cap, i, j;
    cin >> n >> cap;
    ll val[n];
    for (i = 0; i < n; i++)
        cin >> val[i];
    ll wt[n];
    for (i = 0; i < n; i++)
        cin >> wt[i];
    std::map<ll, ll> A;
    for (i = 0; i < n; i++) {
        map<ll, ll>::iterator M = A.find(val[i]);
        if (M != A.end()) {
            if (M->second < wt[i])
                M->second = wt[i];
        }
        else {
            A.insert(make_pair(val[i], wt[i]));
        }
    }
    ll T = A.size();
    i = 0;
    cout << Zero_N_Knapsack(cap, val, wt, n);
    return 0;
}

/*
TimeComplexity=O(n*W)
Auxiliary Space=O(W)
n=No. of Items
W=Capacity of Knapsack
Sample Input
5 11
3 2 4 5 1
4 3 5 6 1
Sample Output
16
*/

