// CPP program to find maximum length subarray with sum = k.
#include<bits/stdc++.h>
using namespace std;

// Function for finding max length subarray with sum k
int MaxLen(int arr[], int n, int k){ 
    int sum = 0, maxLength = 0; 
    // create a unordered map to keep track of subarray sum with its length.
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) { 
        //sum=sum+arr[i];
        sum += arr[i]; 

        //if sum = k found then icrease maxLength with 1
        if (sum == k) 
            maxLength = i + 1; 
        
        //checking whether sum is present in map or not, 
        //if sum is not present in map do enter it.
        if (map.find(sum) == map.end()) 
            map[sum] = i;

        //Again check that sum is present in map or not     
        if (map.find(sum - k) != map.end()) { 
            // updation of maxLength
            if (maxLength < (i - map[sum - k])) 
                maxLength = i - map[sum - k]; 
        } 
    } 
    return maxLength; 
}

int main(){
    int n, arr[100], length, k;

    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"\nEnter Array : ";
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<"\nEnter value of k : ";
    cin>>k;
    
    //function calling for Finding max length subarray with sum k.
    length=MaxLen(arr, n , k);
    cout<<"Max Length of Subarray with sum "<<k<<" = "<<length;
    return 0;
}

/*
Time Complexity : O(n)
Auxiliary space Complexity : O(n)
*/

/*

----Inputs----
Enter size of array : 6
Enter Array : 1 2 8 1 1 2
Enter value of k : 10

----Output----
Length of Subarray with sum 10 = 3

*/
