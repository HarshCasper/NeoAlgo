#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int kadane (ll arr[], ll n)
{
  ll max_so_far = arr[0];

  ll max_ending_here = arr[0];

  for (ll i = 1; i < n; i++)
    {
      max_ending_here = max_ending_here + arr[i];
      max_ending_here = max (max_ending_here, arr[i]);

      max_so_far = max (max_so_far, max_ending_here);
    }

  return max_so_far;
}

int main ()
{
  ll n;
  cin >> n;
  ll arr[n];
  for (ll i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

  cout << "" << kadane (arr, n);

  return 0;
}

/*

Time Complexity : O(n)
Space Complexity: O(1)

Sample Input: 

8
-2 1 -3 4 -1 2 1 -5 4

Sample Output:

6

*/
