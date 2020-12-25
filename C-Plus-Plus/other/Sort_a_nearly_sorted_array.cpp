/* Sort a nearly sorted (or K sorted) array 

Given an array of n elements, where each element is at most k away from its target position. 
The task is to print array in sorted form.
*/


#include <bits/stdc++.h>
using namespace std;

//sort the array (nearly sorted array)
void sorted(int arr[], int n, int k){

      priority_queue<int,vector<int>, greater<int>> maxHeap;

    for(int i = 0; i < n; i++){
        
        if(maxHeap.size() < k){
            maxHeap.push( arr[i] );
            continue;
        }
        
        maxHeap.push( arr[i] );
        
        cout << maxHeap.top() <<" ";
        maxHeap.pop();
    }
    
    while(maxHeap.size() > 0){
        cout << maxHeap.top() <<" ";
        maxHeap.pop();
    }
}

int main()
{
    int n,k;
    cout << "Enter the value of N and K : ";
    cin >> n >> k;
    int arr[n];
    
    cout << "Enter the nearly sorted (or K sorted) array : ";

    for (int i = 0; i < n; i++){
        cin >> arr[i];    
    }
    
    cout << "Sorted Array is : " << endl;

    sorted(arr, n, k);
     
    return 0;
}

/*
Input 
Enter the value of N and K : 6 3                                   
Enter the nearly sorted (or K sorted) array : 2 6 3 12 56 8        

Output
Sorted Array is :                                                  
2 3 6 8 12 56 

space complexity = O(k)
time complexity = O(nlogk)
*/