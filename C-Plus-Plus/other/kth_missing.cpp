/* Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
   Find the kth positive integer that is missing from this array. */
   
#include<bits/stdc++.h>
using namespace std;

/* Function that returns the kth positive integer that is missing  */
int findkthMissing(int arr[],int size,int k){
	/* We Apply Binary search as the array is already sorted
	   It can be found that at any given index how many numbers are 
	   missing.
	*/
	int low=0,high=size-1;
	while(low <= high){
		int mid=low+(high-low)/2 ; /* to avoid integer overflow */
		if(arr[mid]-1-mid <= k) 
		 low=mid+1;
		else
		high=mid+1;
	}
	/* here low is the first index that gives atleast k missing numbers .
	   It may have more missing numbers than we need so we are intrested in low-1 */
	   return low+k; /* kth smallest positive integer   */
}

int main(){
	int size,k; 
	cout<<"Enter the size of Array : ";
	cin>>size;
	cout<<"Enter the value of k : ";
	cin>>k;
	int arr[size]; 
	cout<<"Enter the elements of the array :";
	for(int i=0;i<size;i++)
	cin>>arr[i];
	int kthmissing=findkthMissing(arr, size , k);
	cout<<"Kth missing number is :" <<" "<<kthmissing<<endl;
	return 0;
}

/*
   Test Case 1-
   Input:
   Enter the size of Array : 5
   Enter the value of k : 5
   Enter the elements of the array : 2 3 4 7 11
   Output :Kth missing number is : 9
    
   Test Case 2-
   Enter the size of Array : 4
   Enter the value of k : 2
   Enter the elements of the array : 1 2 3 4
   Output :Kth missing number is : 6
   
   Time Complexity : O(log(size))
   Auxilary Space Complexity : O(1)
   
*/