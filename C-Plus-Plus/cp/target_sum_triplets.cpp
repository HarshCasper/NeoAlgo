#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//triplets printing function
void printtriplets(int* arr,int n,int sum)
{
	//sorting array initially
	sort(arr,arr+n);
	cout<<"The triplet sets are:"<<endl; 
	for(int i =0;i<n-1;i++)
	{
		int left=i+1;
		int right=n-1;
		int current=arr[i];
		while (left < right) 
		{ 
                    if (current + arr[left] + arr[right] == sum) 
	            { 
			    // Print elements if it's sum is given sum.
				//printing elements in ascending order 
                            cout<<current<<", "<<arr[left]<<" and "<<arr[right]<<endl;
                            left++; 
                            right--; 
                    } 
  
                    // If current sum is less than 'sum' then increment the left index
                    else if (current + arr[left] + arr[right] < sum) 
                    left++; 
  
                    // if current sum is greater than  'sum', then decrement the right index 
                    else
                    right--; 
                } 
	 }
}

//Main function
int main() 
{
	int end,target;
	cout<<"Enter the no. of elements in array you want to enter"<<endl; 
	cin >> end;
	
	int* input = new int[end];
	cout<<"Enter elements"<<endl;
	for(int ind=0;ind<end;ind++)
		cin >> input[ind];
	
	cout<<"Enter target"<<endl;	
	cin>>target;
	printtriplets(input,end,target);
	delete[] input;
	return 0;
}
