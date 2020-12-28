
// C++ Program for implementation of Cocktail shaker sort.

#include <bits/stdc++.h>
using namespace std;

//  function to sort the array using Cocktail sort
void Cocktail_shaker_sort(int a[], int n)
{
	int initial = 0;
	int end = n - 1;
	bool flag = true;
	while (flag) 
	{
		flag = false;
		
		// loop from left to right
		for (int i = initial; i < end; ++i) 
		{
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				flag = true;
			}
		}
		
		// if nothing moved, then array is sorted
		if (!flag)
			break;

		flag = false;

		--end;

        // comparing from right to left
		for (int i = end - 1; i >= initial; --i) 
		{
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				flag = true;
			}
		}

		++initial;
	}
}

// Function to print the sorted array 
void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

// Main function
int main()
{
	int no_element;
	cout << "Enter the no of element to be sorted: "; 
  	cin >> no_element;
	int a[no_element];

	// taking input 
	for(int x=0; x < no_element; x++){
		cin>>a[x];
	}

	int n = sizeof(a) / sizeof(a[0]);
	Cocktail_shaker_sort(a, n);
	printf("The Sorted array :\n");
	Print(a, n);
	return 0;
}

