/*
Given an array of integers, find anyone combination of four elements in the array whose sum is equal to a given value X.
The Naive solution is to run 4 loops and 4 numbers that sum up to 4.
Here it is implemented using hashing which gives the most optimal solution
*/

#include<bits/stdc++.h>
using namespace std;

/* Function to find combination of 4 elements that sum to given sum */
void findFourElements(int arr[], int n, int sum) {
	/* Store sums of all pairs in a hash table */
	map<int, pair<int, int> >ump;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			ump[arr[i] + arr[j]] = {i, j};
	}

	/* Traverse through all pairs and search for X - (current pair sum) */
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int X = arr[i] + arr[j];

			/* If X - sum is present in hash table */
			if (ump.find(sum - X) != ump.end()) {
				/* Making sure that all elements are distinct array elements and an element
				   is not considered more than once */
				pair<int, int>p = ump[sum - X];
				if (p.first != i && p.first != j
				        && p.second != i && p.second != j) {
				    
					cout <<"The 4 numbers that sum to the given sum are: "<< arr[i] << "," << arr[j] << ","
					     << arr[p.first] << "," << arr[p.second];
					return ;
				}
			}
		}
	}
}
//Drivers Code
int main() {
	int n; // Size of array
	cout<<"Enter the size of array: ";
	cin >> n;
	int sum;
	cout<<"Enter the required Sum: ";
	cin >> sum;
	int arr[n]; //Initialising Array of size n
	cout<<"Enter the elements of the Array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	 //Function to find the 4 numbers that sum upto given sum
	findFourElements(arr, n, sum);
	return 0;
}

/*
   Time Complexity: O(n)
   Auxilary Space Complexity: O(n)

   Input:  n=6
           sum=91
           a[n]={10 ,20 ,30 ,40 ,1 ,2}
   Output: 20, 30, 40, 1
*/

