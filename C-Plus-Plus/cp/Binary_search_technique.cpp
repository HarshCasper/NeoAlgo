/*
Algorithm for printing the occurrence of the given number in the list/array using Binary Search

inputs: 
	Size of array/list
	Elements in the array/list
	A number whose occurrence is to be printed 
Program should do :
	Find the occurrence of the given number using the above technique
Sample Test Case:
	Input :
	5
	1 4 2 3 4
	4
	Output:
	Occurence of '4': 2

	Space Complexity - O(1) 
	Time complexity - logn
*/


//BinarySearch() to search the elements and count the occurrence

#include<bits/stdc++.h> //header file 
using namespace std; //for standard cin and cout
int BinarySearch(int arr[],int n,int x,bool searchfirst)
{
	int first=0,last=n-1,result=-1;//first and last variables to store first and last element of array
	while(first<=last)			//result variable to store the occurrence
	{
		int mid = first + ((last - first) / 2);
		if(arr[mid]==x)
		{
			result=mid;
			if(searchfirst) 	//searchfirst - a bool type varible to search the first element of occurrence
				last=mid-1;		
			else
				first=mid+1;

		}
		else if(x<arr[mid]) last=mid-1;
		else first=mid+1;
	}
	return result;
}

//main() function to take the number of elements
int main()
{
	int arr[50],n;
	cout<<"Enter the size of array:"<<endl; //size of array
	cin>>n;
	cout<<"Enter the elements in an array(in ascending order):"<<endl;  //elements in ascending order
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int x;
	cout<<"Enter a number to find its Occurrence :"<<endl;  //variable whose occurrence is to be find out
	cin>>x;
	int firstIndex= BinarySearch(arr,sizeof(arr)/sizeof(arr[0]),x,true); //firstIndex to save the ruturn value
	if(firstIndex==-1)
	{
		cout<<"Occurrence of "<<x<<" : "<<0<<endl; //if occurrence not found

	}
	else
	{
		int lastIndex= BinarySearch(arr,sizeof(arr)/sizeof(arr[0]),x,false); //lastIndex to save the return value
		cout<<"Occurrence of "<<x<<" :"<<lastIndex-firstIndex +1<<endl; //subtracting lastindex from firstindex to get the occurrence
	}
	return 0;
}
