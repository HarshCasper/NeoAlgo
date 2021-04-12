/*Bubble Sort Algorithm is the simplest sorting algorithm in which each element is compared to its adjacent element 
and if first elememt is greater than second element ,then the swapping occurs.
The swapping occurs till the array is sorted.
*/
#include <bits/stdc++.h>			//Header file
using namespace std;	//For cin and cout
void bubblesort(int[], int);
int main()
{
	int n, arr[100], num;	//Declarartion of required variables
	cout << "Enter the number of elements of the array: ";
	cin >> n;	//Getting the number of elements of the array from the user
	cout << endl << "Enter the elements of the array to be sorted: " << "\n";
	for (int i = 0; i < n; i++)
	{
		//For loop for taking elements of the array from the user, can be space-seperated as well
		cin >> num;
		arr[i] = num;
	}
	bubblesort(arr, n);
	cout << "Array after sorting is:" << endl;
	for (int i = 0; i < n; i++)
	{
		//For loop for printing out the array after sorting
		cout << arr[i] << " ";
	}
}
void bubblesort(int arr[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		bool sorted = true;	// declaring a sorted variable which will check if array is already sorted or not
		for (int j = 0; j < n - 1 - i; j++)
		{
			//Inner for loop
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];	//Swapping the elements, temp is used to store the temporary variable
				arr[j + 1] = arr[j];
				arr[j] = temp;
				sorted = false;	// sorted value will be updated to false if there is swapping of elements occured 
			}
		}
		if (sorted)
		{
			break;
		}
	}
}
/*
Sample Output
Enter the number of elements of the array: 5
Enter the elements of the array to be sorted:6 5 2 3 1
Array after sorting is:
1 2 3 5 6

Time complexities:
Worst Case:O(n2)
Best Case:O(n)    
Average Case:O(n2)  

Space Complexity: Auxilary Space:O(2) because of variable temp and sorted.  
*/

