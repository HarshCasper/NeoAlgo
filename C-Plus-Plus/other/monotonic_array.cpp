/*Given an array arr[] of N elements where N ≥ 2, the task is to check the type of array whether it is:

Increasing.
Decreasing.
Increasing then decreasing.
Decreasing then increasing.
*/



#include <bits/stdc++.h>
using namespace std;


void check(int a[], int n)
{

	// If the first two and the last two elements of the array are in increasing order
	if (a[0] <= a[1] && a[n - 2] <= a[n - 1])
		cout << "Increasing";

	// If the first two and the last two elements of the array are in decreasing order
	else if (a[0] >= a[1] && a[n - 2] >= a[n - 1])
		cout << "Decreasing";

	// If the first two elements of the array are in increasing order and the last two elements of the array are in decreasing order
	else if (a[0] <= a[1] && a[n - 2] >= a[n - 1])
		cout << "Increasing then decreasing";

	// If the first two elements of the array are in decreasing order and the last two elements of the array are in increasing order
	else
		cout << "Decreasing then increasing";
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

	check(a, n);

	return 0;
}

/*
n =5

Input: a[] = {1, 2, 3, 4, 5}
Output: Increasing


n = 4 

Input: arr[] = {1, 2, 4, 3}
Output: Increasing then decreasing
*/