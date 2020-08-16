#include<bits/stdc++.h> //header file 
using namespace std; //for cin and cout



/*c++ program to implement binary search technique

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
*/

//sorting the elements in ascending order
void Bubblesort(int arr[],int size)
{
	int temp;//temporary variable to swap variable
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1;--i,j++)
		{if(arr[j]>arr[j+1])
			{//swapping the values
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}

		}
	}
}
//Binary search for searching the element
int Bsearch(int arr[],int n,int x,bool searchfirst)
{
	Bubblesort(arr,n);
	int low=0,high=n-1,result=-1;//low and high variables to store first and last element of array
	while(low<=high)			//result variable to store the occurrence
	{
		int mid = (low+high)/2;
		if(arr[mid]==x)
		{
			result=mid;
			if(searchfirst) 	//searchfirst - varible to search the first element of occurrence
				high=mid-1;
			else
				low=mid+1;

		}
		else if(x<arr[mid]) high=mid-1;
		else low=mid+1;
	}
	return result;
}
int main()
{	//array to store the elements
	int arr[50],n;
	cout<<"Enter the size of array:"<<endl;
	cin>>n;
	cout<<"Enter the elements in an array:"<<endl;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	Bubblesort(arr,n); //calling Bubblesort to sort the elements entered
	int x;
	cout<<"Enter a number  :"<<endl;
	cin>>x;
	int firstIndex=Bsearch(arr,sizeof(arr)/sizeof(arr[0]),x,true); //firstIndex to save the ruturn value
	if(firstIndex==-1)
	{
		cout<<"Occurrence of "<<x<<" : "<<0<<endl;

	}
	else
	{
		int lastIndex=Bsearch(arr,sizeof(arr)/sizeof(arr[0]),x,false); //lastIndex to save the return value
		cout<<"Occurrence of "<<x<<" :"<<lastIndex-firstIndex +1<<endl; //subtracting lastindex from firstindex to get the occurrence
	}
	return 0;
}