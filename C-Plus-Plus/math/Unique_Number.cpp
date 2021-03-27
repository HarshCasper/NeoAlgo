/*

You are given an integer array nums. The unique elements of an array are 
the elements that appears exactly once in the array. Return the sum of all 
Unique elements of nums.

*/

#include <bits/stdc++.h>
using namespace std;



int uniqueNum(int n){
    int i, j, k, arr[100], ctr=0, sum=0;
    
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Unique elements in the array are: ";
    for(i=0; i<n; i++){
        ctr=0;
        for(j=0,k=n; j<k+1; j++){
            if (i!=j){
		        if(arr[i]==arr[j]){
                 ctr++;
            }
         }
    }        
    
    if(ctr==0){
      cout<<arr[i]<<",";
      sum+=arr[i];
     }
    }
    cout<<endl;
    cout<<"Sum of Unique elements : "<<sum;
}


int main(){
    int n;
    
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    
    uniqueNum(n);
    
    return 0;
}



/*

INPUT : [1, 5, 2, 6, 5]
OUTPUT : 9

Explanation : Unique elements are [1, 2, 6] and the Sum is 9

*/