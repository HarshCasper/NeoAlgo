/** 
-> Radix sort is based on counting sort
-> The following program sorts negative as well as 
positive integers.
-> Assuming the range is fixed, as ll capacity
is limited in any language, this sort takes
-> MAX_INT contains 10 decimal values
-> If range is not fixed, this sort takes O(kn) time
where k is #decimal places in the number
This works because of the nature of counting sort
-> Counting sort is a stable sort
**/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define K 10
#define M 10
#define DIF 2147483648

/* The idea behind sorting negative numbers too is below
-> A signed 32 bit integer goes from -2,147,483,648 to 2,147,483,647
and an unsigned integer from 0 to 4,294,967,295.
-> So you could just add 2,147,483,648 to the signed number to 
convert it to an unsigned one for sorting
then subtract to get back to signed numbers when you have finished sorting*/

void counting_sort(ll arr[], ll  n, ll p) {
    ll element = pow(10, p);
    ll divs = element / 10;
    ll count[M];
    for(ll i = 0; i < M; i++)
        count[i] = 0;
    for(ll i = 0; i < n; i++)
        count[(arr[i] % element) / divs] ++;
    for(ll i = 1; i < M; i++)
        count[i] += count[i-1];
    ll op[n];
    for(ll i = n-1; i >= 0; i--) {
        op[count[(arr[i] % element) / divs] - 1] = arr[i];
        count[(arr[i] % element) / divs] --;
    }
    // copying the array back
    for(ll i = 0; i < n; i++)
        arr[i] = op[i];
}

void radix_sort(ll arr[], ll n) {
    // apply counting sort for all decimal places
    for(ll i = 1; i <= K; i++)
        counting_sort(arr, n, i);
}

int main() {    
    ll n;
    cin >> n;
    ll arr[n];
    // Taking input
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        // Adding DIF to make negative numbers positive
        arr[i]+=DIF;
    }
    // perform the sort
    radix_sort(arr, n);

    // Outputting the sorted array
    for(ll i = 0; i < n; i++) {
        cout << arr[i]-DIF << ' ';
    }
    cout << '\n';
    return 0;
}

/**
Sample Input 1: 
8
175 45 75 90 802 24 2 66
Sample Output 1:
2 24 45 66 75 90 175 802

Sample Input 2: 
8
175 -45 -75 90 -802 24 1 66
Sample Output 2:
-802 -75 -45 1 24 66 90 175

Time complexity : O(n)
Space complexity : O(n)
**/
