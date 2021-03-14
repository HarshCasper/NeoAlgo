/*
Problem link : https://www.hackerrank.com/challenges/crush/problem

Problem description:
Starting with a 1-indexed array of zeros and a list of operations, for each query add a value to each the array element between two given indices, inclusive. 
Once all operations have been performed, return the maximum value in the array.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, m, a, b, k;
    cin >> n >> m;
    vector<ll> prefix_sum(n + 1, 0);
    for (ll queries = 1; queries <= m; queries++)
    {
        cin >> a >> b >> k;
        prefix_sum[a] += k;
        if ((b + 1) <= n)
        {
            prefix_sum[b + 1] -= k;
        }
    }
    ll answer = INT_MIN;
    for (ll index = 1; index <= n; index++)
    {
        prefix_sum[index] += prefix_sum[index - 1];
        answer = max(answer, prefix_sum[index]);
    }
    cout << answer << endl;
}

/*
Time Complexity  : O(n)
Space Complexity : O(n)
Input: 
5 3
1 2 100
2 5 100
3 4 100
Output:
200 
*/
