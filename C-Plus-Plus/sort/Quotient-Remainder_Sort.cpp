/*Implementation of Quotient-Remainder Sorting algorithm (non-negative numbers only) in C++*/ 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function for QR-Sort Algorithm implementation.
vector < ll > func(vector < ll > a, ll n) {
  vector < ll > ans;
  /*Make a vector (v) of list of pair of type { arr[i] / n , arr[i]}.The index of vector represents remainder.*/
  vector < list < pair < ll, ll >>> v(n);
  for (ll i = 0; i < n; i++) {
    ll r = a[i] % n;
    v[r].push_back(make_pair(a[i] / n, a[i]));
  }
  /*Add delimiter {-1,-1} for each index in the vector*/
  for (ll i = 0; i < n; i++) {
    v[i].push_back(make_pair(-1, -1));
  }
  /*Run the loop until the size of output array is not equal to input array. */
  while (ans.size() != n) {
    for (ll i = 0; i < n; i++) {
      while (!v[i].empty()) {
        pair < ll, ll > p = v[i].front();
        v[i].pop_front();
        if (p.first == -1) {
          /*Delimiter found break the loop*/
          break;
        } else {
          if (p.first == 0) {
            ans.push_back(p.second); /*Add the array element in the output array*/
          } else {
            v[p.first % n].push_back(make_pair(p.first / n, p.second));
          }
        }
      }
    }
    /* Adding delimiter for next pass.*/
    for (ll i = 0; i < n; i++) {
      v[i].push_back(make_pair(-1, -1));
    }
  }
  return ans;
}

int main() {
  ll n;
  cout << "Enter input size" << endl;
  cin >> n;
  vector < ll > a(n);
  vector < ll > ans;
  cout << "Enter input array:" << endl;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << endl;
  if (n != 1) {
    ans = func(a, n);
  } else {
    ans.push_back(a[0]);
  }
  cout << "Output array:" << endl;
  for (ll i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

/* Sample example:
   Enter input size:
   5
   Enter input array:
   15 2 89 0 3
   Output array:
   0 2 3 15 89

   Time Complexity:-
         T(n)= { O(1) if n=1,
                 O(n*log(m base n) +n) if n>1
               }
   Space Complexity = O(2*n) */
