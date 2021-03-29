/*C++ Program to sort an array in wave form*/ 
/* Sort the Given unsorted array of integers into a wave like array. An array 
‘a[0..n-1]’ is sorted in wave  form if a[0] >= a[1] <= a[2] >= a[3] <= a[4] >= ….. */




#include<iostream>
using namespace std;


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void converttoWave(int a[], int n)
{
	// Traverse all even elements
	for (int i = 0; i < n; i+=2)
	{
		// If current even element is smaller than previous

		if (i>0 && a[i-1] > a[i] )
			swap(&a[i], &a[i-1]);

		// If current even element is smaller than next

		if (i<n-1 && a[i] < a[i+1] )
			swap(&a[i], &a[i + 1]);
	}
}

int main()
{
    int n;
    cin>>n;

	int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
	converttowave(a, n);

	for (int i=0; i<n; i++)
	cout << a[i] << " ";
	return 0;
}

/*

n = 5

Input:  3,1,7,2,8

Output: 1,7,2,8,3

Time Complexity : O(n)
Space Complexity: O(1)

*/