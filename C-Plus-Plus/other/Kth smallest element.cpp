/* Q Kth smallest element 

Given an array a[] and a number K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array.
It is given that all array elements are distinct. */


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//find the kth samllest Element
void kthSmallestElement(int arr[], int size, int k){

    priority_queue <int> maxHeap;
    
    for(int i = 0; i < size; i++){
        maxHeap.push(arr[i]);
        
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    cout<< maxHeap.top();
}

int main()
{
    int size, k; 
    cin >> size >> k;
    int arr[size];

    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    // arr={7, 5, 9, 8, 6, 4, 10}

    kthSmallestElement(arr, size, k);  
    
    return 0;
}

// Input 
// size=7 k=3
// 7 5 9 8 6 4 10
// Output
// 6