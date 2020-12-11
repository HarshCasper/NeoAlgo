//Q Kth largest element 

// Given an array a[] and a number K where K is smaller than size of array, 
// the task is to find the Kth largest element in the given array.
// It is given that all array elements are distinct.

//Input 
// n=7 k=3
// 7 5 9 8 6 4 10
// Output
// 8

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // a={7, 5, 9, 8, 6, 4, 10}
        
    priority_queue<int, vector<int>, greater<int>> minh;
    
    for(int i = 0; i < n; i++){
        minh.push(a[i]);
        
        if(minh.size() > k){
            minh.pop();
        }
    }
    cout<< minh.top();
    
    return 0;
}