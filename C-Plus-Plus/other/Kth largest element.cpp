/*
Q Kth largest element 

Given an array a[] and a number K where K is smaller than size of array, 
the task is to find the Kth largest element in the given array.
It is given that all array elements are distinct. */


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//find the kth largest Element
void kthLargestElement(int a[], int size, int k){

    priority_queue <int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < size; i++){
        minHeap.push(a[i]);
        
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    cout<< minHeap.top();
}

int main()
{
    int size, k; 
    cin >> size >> k;
    int a[size];

    for (int i = 0; i < size; i++){
        cin >> a[i];
    }

    // a={7, 5, 9, 8, 6, 4, 10}

    kthLargestElement(a,size,k);  
    
    return 0;
}

/*
Input 
size=7 k=3
7 5 9 8 6 4 10
Output
8

Space complexity => O(k)
Time complexity => O(nlogk)
*/