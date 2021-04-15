// THIS IS THE ADVANCED VERSION OF THE CLASSICAL TILING PROBLEM IN DP
/* in this code....the floor is given to be of size (n X m) and tiles are of size (m X 1)
   We need to find the number of ways to tile the floor using the nx1 tiles
   
   APPROACH- we use the bottom up DP to find the number of ways to tile the floor.
             if we place the tile horizontally then we have n-1 ways to tile the floor4
             if n > = m then we can place the tile vertically and then we have n-m ways to tile the floor
             Then we simply add the total ways to get the number of ways to tile the floor

             
*/
#include <iostream>
#define mod 1000000007
#define ll long long
using namespace std;

ll numWays(ll n, ll m)
{
    ll dp[n + 1];
    // there is one way to tile  the mx1 floor so dp[1]= 1;
    dp[0] = dp[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (i >= m)
        {
            dp[i] = (dp[i - 1] + dp[i - m]) % mod;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp[n];
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << numWays(n, m) << endl;
    }
    return 0;
}

/*
Input: n = 4, m = 4
Output: 2
Explanation: There is two ways to tile the
given floor.One way is to place 1 x 4 size 
of tile vertically and another one is to 
place them horizontally.


Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
*/