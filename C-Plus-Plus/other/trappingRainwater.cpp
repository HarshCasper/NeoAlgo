#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{

	// indices to traverse the array
	int left = 0;
	int right = n-1;

	// To store Left max and right max 
	// for two pointers left and right
	int left_max = 0;
	int right_max = 0;

	// To store the total amount 
	// of rain water trapped
	int result = 0;
	while (left <= right)
	{

	// We need check for minimum of left 
	// and right max for each element
	if(right_max <= left_max)
	{

		// Add the difference between 
		// current value and right max at index r
		result += max(0, right_max-arr[right]);

		// Update right max
		right_max = max(right_max, arr[right]);

		// Update right pointer
		right -= 1;
	}
	else
	{ 

		// Add the difference between 
		// current value and left max at index l
		result += max(0, left_max-arr[left]);

		// Update left max
		left_max = max(left_max, arr[left]);

		// Update left pointer
		left += 1;
	}
	}
	return result;
}

// Driver code
int main() {
  int n;
  int arr[n];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
	cout << maxWater(arr, n) << endl;
	return 0;
}
