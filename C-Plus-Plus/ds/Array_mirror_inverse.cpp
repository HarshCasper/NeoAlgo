// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;

// Function that returns true if
// the array is mirror-inverse
bool mirr_inv(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[arr[i]] != i)
			return false;
        else
            return true;
	}
	return true;
}

int main()
{
		int n;
		cout<<"Enter size of array ";
		cin>>n;
		int arr[n];
		int k;
		for(int j=0;j<n;j++)
        {

        cout<<"enter elements "<< j <<" of array";
            cin>>k;
            arr[j]=k;
        }
		//int arr[] = { 4, 3,2, 1, 0 };

		//this->m=n;
		//int n = sizeof(arr)/sizeof(arr[0]);
		if (mirr_inv(arr,n))
			cout << "My Array is Mirror inverse";
		else
			cout << "My Array is not Mirror inverse";
		return 0;
/*
Enter size of array
5
Sample Input -
enter elements 0 of array
4
enter elements 1 of array
3
enter elements 2 of array
2
enter elements 3 of array
1
enter elements 4 of array
0
My output of my sample input 
My Array is Mirror inverse
*/
}
