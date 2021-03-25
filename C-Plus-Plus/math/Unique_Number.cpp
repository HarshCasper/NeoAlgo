/*

You are given an integer array nums. The unique elements of an array are 
the elements that appears exactly once in the array. Return the sum of all 
Unique elements of nums.

INPUT : [1, 5, 2, 6, 5]
OUTPUT : 9

Explanation : Unique elements are [1, 2, 6] and the Sum is 9

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr1[100], n,ctr=0,sum=0;
    int i, j, k;	
    
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++){
        cin>>arr1[i];
    }
    
    cout<<"Unique elements in the array are: ";
    for(i=0; i<n; i++){
        ctr=0;
        for(j=0,k=n; j<k+1; j++){
            if (i!=j){
		        if(arr1[i]==arr1[j]){
                 ctr++;
            }
         }
    }        
    
    if(ctr==0){
      cout<<arr1[i]<<",";
      sum+=arr1[i];
     }
    }    
    cout<<endl<<"Sum of Unique elements : "<<sum;
    return 0;
}