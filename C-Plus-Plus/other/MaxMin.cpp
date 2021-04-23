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
    cout << "Enter each elemnent in the array:" << endl;
    for (int i = 0; i < n; i++) {    
        cin >> A[i];
    }
    //Sort all elements in the array
    sort(A, A + n);
    long min = A[n - 1];
    //Find Min Element according to the equation
    for (int i = 0; i <= n - k; i++)
    {
        if (A[k + i - 1] - A[i] < min)
            min = A[k + i - 1] - A[i];
    }
    cout << min << endl;
    /*
    * Sample Input/Output:
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

    * Time Complexity: O(N(Log(N))
    * Space Complexity: O(N)
    */
    return 0;
}