#include <bits/stdc++.h>
using namespace std;


    // function to find the max subarray sum 
  void solution(int arr[] , int n){

    int currentSum = arr[0];
    int overallSum = arr[0];

    for(int i=0;i<n;i++){
        if( currentSum >= 0){
            currentSum+=arr[i];
        }else{
            currentSum = arr[i];
        }

        if(currentSum > overallSum){
            overallSum = currentSum;
        }
    }

    cout<<"The max subarray sum is "<<overallSum;

  
}

int main(){

    int n;
    cout<<"Enter the size of the array";
    cin>>n;
    cout<<"Enter the elements of the array";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    solution(arr, n);

    return 0;
}


// I/P and O/P: 

// 1.
//     Enter the size of the array 8                                                                                                   
//     Enter the elements of the array -2 -3 4 -1 -2 1 5 -3                                                                            
//     The max subarray sum is 7

// 2.
//     Enter the size of the array 9                                                                                                  
//     Enter the elements of the array -3 1 -8 4 -1 2 1 -5 5                                                                          
//     The max subarray sum is 6


// Time complexity : O(n)
// Space complexity : O(1)