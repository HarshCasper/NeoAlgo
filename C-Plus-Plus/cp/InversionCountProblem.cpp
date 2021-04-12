//Given an array, find the inversion count for the array.
//Inversion count of an array:- It indicates how far the array is from being a sorted array. For a sorted array, it is zero.
//Sorted Array:- An array in arranged in a particular order (for this question its acsending order)

/* 
  Why we use Merge Sort approach?
  If we will use simple approach, i.e., traverse through the array, and for every index, 
  find the number of smaller elements on its right side of the array, using a nested loop 
  and sum up the counts for all index in the array and print the sum, 
  it will take O(n^2) Time Complexity.
  Instead, we will use Merge Sort approach(Algorithm given below) to reduce Time Complexity to O(nlogn).
*/  

/*
  Algorithm:- 
   1. The idea is similar to merge sort, divide the array into two equal
      or almost equal halves in each step until the base case is reached.
   2. Create a function merge that counts the number of inversions when two halves of the array are merged, 
      create two indices i and j, i is the index for the first half, and j is an index of the second half. 
      If a[i] is greater than a[j], then there are (mid – i) inversions because left and right subarrays
      are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
   3. Create a recursive function to divide the array into halves and find the answer by summing the
      number of inversions in the first half, the number of inversion in the second half and
      the number of inversions by merging the two.
   4. The base case of recursion is when there is only one element in the given half.
   5. Print the answer.
*/


/*----CODE----*/
#include <bits/stdc++.h>

using namespace std;

//This Function merges the two parts of sorted arrays into a single array after merge sort is being performed.
int merge(int arr[], int temp[], int left, int mid, int right)
{	
	int i, j, k;
	
  	//For keeping the track of how many times an array is not sorted
	int invCount = 0; 

  	// i is index for left subarray
	i = left;
  	//j is index for right subarray 
	j = mid; 
  	//k is index for resultant merged subarray
	k = left; 
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
      
        		//This is a bit difficult, it would be better if you understand merge sort first.
			invCount = invCount + (mid - i);
		}
	}

	// Copy the remaining elements of left subarray(if there are any) in temp array.
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	// Copy the remaining elements of right subarray(if there are any) in temp array.
	while (j <= right)
		temp[k++] = arr[j++];

	//Copy back the merged elements to original array
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

  	//It will return inversion count, which we will add to invSum in _mergeSort function.
	return invCount;
}

//This function will sort the input array by dividing it into two parts and returns the number of inversions in an array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, invSum = 0;
	if (right > left) {
		// Divide the array into two parts and call _mergeSortAndCountInv() for each of the parts 
		mid = (right + left) / 2;

		// Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging.
		invSum += _mergeSort(arr, temp, left, mid);
		invSum += _mergeSort(arr, temp, mid + 1, right);

		/*Merge the two parts*/
		invSum += merge(arr, temp, left, mid + 1, right);
	}
  	//Final answer which is stored in ans in int main().
	return invSum;
}

// This function sorts the input array using Merge Sort and returns the number of inversions in the array 
int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

//Main Function
int main()
{
  	//Size of an array = n.
	int n;

  	//Input 
	cout << "Enter the size of array, n: ";
  	cin >> n;
	
	//Array of size n = arr[n] 
  	int arr[n];
	
	cout << "Enter elements of array: ";
  
  	//Taking array as an input
  	for(int i = 0; i < n; i++) {
    		cin >> arr[i];
  	}

  	//Performing Merge sort on array arr to find number of inversions.
	int ans = mergeSort(arr, n);

  	//Print the answer.
	cout << "Number of inversions are " << ans;
	return 0;
}

/*
	Test cases:
 	INPUT:-
	Enter the size of array, n: 5
 	Enter elements of array: 5 3 8 9 6
 	OUTPUT:-
 	Number of inversions are 3
    
	Test cases:
 	INPUT:-
	Enter the size of array, n: 8
 	Enter elements of array: 90 87 75 66 53 42 38 15
 	OUTPUT:-
 	Number of inversions are 28
	
	Time complexity: O(N logN)
	Space complexity: O(N)
*/
