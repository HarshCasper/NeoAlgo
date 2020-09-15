// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;

// Function that returns Yes if
// the array is mirror-inverse
bool mirror_inverse(int arr[], int n)
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
                     cin >> arr[j];
                }
		if (mirror_inverse(arr,n))
			cout << "Yes";
		else
			cout << "No";
		return 0;
}



/*
Enter size of array
5
Input - 
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
Output - Yes

*/

