/*
* You will be given a list of integers arr , and a single integer K . You must create an array of length K from elements of arr such that its unfairness is minimized.
* Call that array arr. Unfairness of an array is calculated as max(arr') - min(arr')
* Complexity: O(Nlog(N))
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];

    }
    sort(A, A + n);
    long min = A[n - 1];
    for (int i = 0; i <= n - k; i++)
    {
        if (A[k + i - 1] - A[i] < min)
            min = A[k + i - 1] - A[i];
    }
    cout << min << endl;
    /*
    * Input: 
    *   7
        3
        10
        100
        300
        200
        1000
        20
        30
    * Output:
        20
    */
    return 0;
}