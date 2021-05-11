#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll power(ll a, ll b)
{
    long res = 1;
    while (b > 0)
    {
        if ((b & 1) != 0) // b&1 returns 1 if b is odd else it returns 0
        {
            res = (res % mod * a % mod) % mod;  // (res * a) % mod = (res % mod * a % mod) % mod
        }
        a = (a % mod * a % mod) % mod; // (a * a) % mod = (a % mod * a % mod) % mod
        b = b >> 1;  // b=b>>1 perform b=b/2
    }
    return res;
}
//main:
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans;
        ans = power(a, b);
        cout << ans;
        cout << endl;
    }
    return 0;
}
/* 
Fast Power Calculation Complexity - O(n)

Input Format
1st line of input contains a single integer as number of test cases.
2nd line contains two integers a and b.

Output Format
Output a single integer a^b since this number can be very large therefore perform modulo operation with 1e9+7

Sample Input : 
4
2 3
25 2
10 50
30 35

Sample Output:
8
625
319300014
81812392

*/
