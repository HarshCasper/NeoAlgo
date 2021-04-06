/**
 * 
 * Given an array of type integers, having n element.
 * Reverse array element at same memory address in o(n/2) time complexity
 * 
 * Input:
 * First line of input N, contains size of an array.
 * Next N line contains elements of array.
 * 
 * Output:
 * print element of array in which arranged in reverse order.
 *
 * Example:
 * Input:
 * 4
 * 1 2 3 4
 * 
 * 
 * Output:
 * 4 3 2 1
 * 

*/

#include<iostream>
using namespace std;

//function for reverse array in o(n/2) time complexity
void reverse_array(int arr[] ,int length)
{
	for(int i=0;i<length/2;i++)
	{
		int temp = arr[i];
		arr[i] = arr[length-i-1];
		arr[length-i-1] = temp;
	}
}


int main() 
{
	int N;
	cin>>N;
	int arr[N];
	
	//take array element input from user
	for(int i=0;i<N;i++) 
	{
		cin>>arr[i];
	}
	
	//call function reverse_array 
	reverse_array(arr,N);
	
	//print array element after calling reverse function
	for(int i=0;i<N;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0; 
}