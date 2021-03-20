/*
Implementation of Quotient-Remainder Sorting algorithm (non-negative numbers only) in C++
*/

#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <utility>

using namespace std;

// Function for QR-Sort Algorithm implementation.
vector < int64_t > func(vector < int64_t > a, int64_t n) {
    vector < int64_t > ans;
    // Vector (v) of list of pair of type { arr[i] / n , arr[i]}.
    //  The index of vector represents remainder.
    vector < list < pair < int64_t, int64_t >>> v(n);
    for (int64_t i = 0; i < n; i++) {
        int64_t r = a[i] % n;
        v[r].push_back(make_pair(a[i] / n, a[i]));
    }
    // Add delimiter {-1,-1} for each index in the vector
    for (int64_t i = 0; i < n; i++) {
        v[i].push_back(make_pair(-1, -1));
    }
    // Run the loop until the size of output array is not equal to input array.
    while (ans.size() != n) {
        for (int64_t i = 0; i < n; i++) {
            while (!v[i].empty()) {
                pair < int64_t, int64_t > p = v[i].front();
                v[i].pop_front();
                if (p.first == -1) {
                    // Delimiter found break the loop
                    break;
                } else {
                    if (p.first == 0) {
                        // Add the array element in the output array
                        ans.push_back(p.second);
                    } else {
                        int64_t r1 = p.first % n;
                        int64_t q1 = p.first / n;
                        v[r1].push_back(make_pair(q1, p.second));
                    }
                }
            }
        }
        // Adding delimiter for next pass.
        for (int64_t i = 0; i < n; i++) {
            v[i].push_back(make_pair(-1, -1));
        }
    }
    return ans;
}

int main() {
    int64_t n;
    cout << "Enter input size" << "\n";
    cin >> n;
    vector < int64_t > a(n);
    vector < int64_t > ans;
    cout << "Enter input array:" << "\n";
    for (int64_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "\n";
    if (n != 1) {
        ans = func(a, n);
    } else {
        ans.push_back(a[0]);
    }
    cout << "Output array:" << "\n";
    for (int64_t i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
   Sample example:
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
   Space Complexity = O(2*n)
*/
