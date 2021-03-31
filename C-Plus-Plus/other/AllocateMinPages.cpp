/* Given number of pages in n different books and m students.
   The books are arranged in Random order of number of pages.It is not compulsory to sort the Array.
   Every student is assigned to read some consecutive books.
   The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
   Solution of this problem can be improved using the Binary Search Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

/* Utility function to check if current minimum value is feasible or not. */
bool isValid(int arr[],int size,int students,int mid){
	int student=1;
	int sum=0;
	for(int i=0;i<size;i++){
		sum+=arr[i];
		if(sum>mid){ /* If the sum exceeds the current minimum value then increase the count of students */
			student++;
			sum=arr[i]; //Reinitializing the sum with the current element of the Array
		}
		if(student >students) /* If the count of student till now becomes greater than the the students then return false */
		return false;
	}
	return true;
}

/* function to find minimum pages */
int findPage(int arr[],int size,int students){
	/* Base Condition */
	if(size<students) /* As mentioned in the condition , each student must have atleast one book */
	   return -1;
	
	/* Finding maximum in array */
	int maxi=INT_MIN;/*maxi will be the starting element of binary search for improving complexity */
	for(int i=0;i<size;i++){
		if(arr[i]>maxi)
		maxi=arr[i];
	}
	
	/* Finding sum of array */
	int sum{0};/* sum represents the end element in the worst case */
	for(int i=0;i<size;i++)
	sum+=arr[i];
	
	int start=maxi;
	int end=sum;
	int res=-1; /* Initialising the result with -1 */
	while(start<=end){
		int mid=start+(mid-start)/2; /* to avoid integer overflow */
		if(isValid(arr,size,students,mid)){
			res=mid;
			end=mid-1; /* to search the minimum number of pages */
		}
		else
		start=mid+1;
	}
	return res;
}

/* Drivers Code */
int main(){
	int size; //size of the array 
	cout<<"Enter the Size of the Array :";
	cin>>size;
	int students; //number of students
	cout<<"Enter the Number of students :";
	cin>>students;
	int arr[size]; // array represents number of pages in the different book
	cout<<"Enter the No of pages in every book :";
	for(int i=0;i<size;i++)
	cin>>arr[i];
	cout<<"Minimum number of pages : "<<findPage(arr,size,students);
	return 0; 
}

/*
   Time Complexity : O(size*log(sum(arr[]))
   Auxilary Space Comlexity : O(1)
   
   TestCase 1:
   Input:Enter the size of the Array :4
         Enter the Number of students :2
         Enter the No of pages in every book :10 20 30 40
  Output:Minimum number of pages :60
    
    TestCase 2:
    Input:Enter the Size of the Array :4
          Enter the Number of students :2
          Enter the No of pages in every book :12 34 67 90
   Output:Minimum number of pages : 113
         
*/
