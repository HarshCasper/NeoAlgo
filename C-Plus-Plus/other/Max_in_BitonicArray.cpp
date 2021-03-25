/*
Find the maximum element in Bitonic array
==========================================
A bitonic array is an array of integers which is initially
increasing and then decreasing.
An efficient solution to find the maximum element 
in bitonic array is by using binary search.
Given an array of integers which is initially increasing
and then decreasing, find the maximum value in the array.
*/

#include<bits/stdc++.h>
using namespace std;

/* This function is used to find maximum 
element in bitonic array
*/
int findMax(int arr[],int low,int high){
	/* Base Case: Only one element is present in arr[low..high]*/
   if (low == high) 
     return arr[low]; 
     
    /* If there are two elements and first is greater then 
      the first element is maximum */
   if ((high == low + 1) && arr[low] >= arr[high]) 
      return arr[low];
	  
	/* If there are two elements and second is greater then 
      the second element is maximum */
   if ((high == low + 1) && arr[low] < arr[high]) 
      return arr[high];
	  
	int mid = (low + high)/2;   /*low + (high - low)/2;*/
	/* If we reach a point where arr[mid] is greater than both of 
     its adjacent elements arr[mid-1] and arr[mid+1], then arr[mid] 
     is the maximum element*/
   if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) 
      return arr[mid]; 
  
    /* If arr[mid] is greater than the next element and smaller than the previous  
    element then maximum lies on left side of mid */
   if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) 
      return findMax(arr, low, mid-1); 
   else /* when arr[mid] is greater than arr[mid-1] and smaller than arr[mid+1] */
      return findMax(arr, mid + 1, high);   
}


//Drivers' Code
int main()
{
	int size;
   cout<<"Enter the size of the Array:";
	cin>>size;
	int arr[size]; //declaring the array 
	cout<<"Enter the elements of the Array:";
	for(int i=0;i<size;i++)
	  cin>>arr[i];
	cout<<"The maximum element is: "<<findMax(arr,0,size-1)<<endl;
	return 0;
}
/*

    Time Complexity: O(Logn)
    Auxilary Space  Complexity:O(1)

    Testcase '1':
    Enter the size of the Array:11
    Enter the elements of the Array:8 10 20 80 100 200 400 500 3 2 1
    The maximum element is: 500

    Testcase '2':
    Corner case (No decreasing part)
    Enter the size of the Array:5
    Enter the elements of the Array:10 20 30 40 50
    The maximum element is: 50

    Testcase '3':
    Corner case (No increasing part)
    Enter the size of the Array:5
    Enter the elements of the Array:120 100 80 20 0
    The maximum element is: 120
*/

