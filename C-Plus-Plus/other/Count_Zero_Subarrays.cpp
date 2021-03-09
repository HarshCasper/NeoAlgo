#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
  1. Brute force : TC => O(n^2)
     => Looped over all the subarrays and found out the zero sum subarrays
*/
ll Count_subarrays_brute(ll arr[], ll n)
{
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
                cnt++;
        }
    }
    return cnt;
}
/*
  2. Optimised solution : TC => O(n)
    => Used Hashmap to keep track of repeated sums which indicates the presence of a zero sum subarray
*/
ll Count_Subarrays_Optimised(ll arr[], ll n)
{
    ll cnt = 0;
    unordered_map<ll, ll> m;
    m[0] = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m.find(sum) != m.end())
        {
            cnt += m[sum];
        }
        m[sum]++;
    }
    return cnt;
}

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << Count_subarrays_brute(a, n) << endl;     // Brute force
    cout << Count_Subarrays_Optimised(a, n) << endl; // Optimised
    return 0;
}