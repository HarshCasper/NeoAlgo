/**
Given an array, fing the next lexicographical largest permutation
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    int k = A.size()-1;
    while(A[k-1] >= A[k] && k > 0)
        k--;
    if(k == 0)
        reverse(A.begin(), A.end());
    else {
        int t = A[k-1];
        int m = k;
        for(int i=k+1; i<A.size(); i++)
            if(A[i] > t && A[i] < A[k])
                m = i;
        A[k-1] = A[m];
        A[m] = t;
        sort(A.begin()+k, A.end());
    }
    return A;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    nextPermutation(arr);
    cout << "The next permutation of the array is : \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}

/**

Input :
6
5 3 4 9 7 6
Output :
6
5 3 4 9 7 6

Time Complexity : O(nlogn)
Space Complexity : O(n)

**/