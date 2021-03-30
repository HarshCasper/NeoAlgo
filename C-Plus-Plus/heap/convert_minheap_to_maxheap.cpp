/* write a program to convert the given array representation of min Heap to max Heap in O(n) time in c++. */


#include<bits/stdc++.h>
using namespace std;

void maxheapify(int arr[], int i, int n)
{   
    int r = 2*i + 2;
    int l = 2*i + 1;
	
	int larg = i;
	
    if (l < n && arr[l] > arr[i])
    {
		larg = l;
    }
	if (r < n && arr[r] > arr[larg])
    {
		larg = r;
    }
	if (larg != i)
	{

		swap(arr[i], arr[larg]);
        maxheapify(arr, larg, n);
	}
}

void converttomaxheap(int arr[], int n)
{

	for (int i = (n-2)/2; i >= 0; --i)      

		maxheapify(arr, i, n);

}

void print(int* arr, int size)
{

	for (int i = 0; i < size; ++i)

		cout<<arr[i];
}

int main()
{
	
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	cout<<"Min Heap array : ";
	print(arr, n);
    cout<<endl;
    converttomaxheap(arr, n);
    cout<<"Max Heap array : ";
	print(arr, n);
    return 0;

}

/*
n= 10

Input = 10 14 19 26 31 42 27 44 35 33 

Mean Heap array : 
10 14 19 26 31 42 27 44 35 33 

Max Heap array : 
44 35 42 26 33 19 27 10 14 31 

Time Complexity : O(n)

*/