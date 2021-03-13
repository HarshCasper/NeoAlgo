/* C++ program to solve Trapping Rainwater problem.An array of non-negative integers are given which
represent an elevation height each of width 1, the
goal is to compute total water trapped after raining*/

#include<bits/stdc++.h>
using namespace std;

int trapWater(int arr[], int n){
	// Initialize output
	int result = 0;
	// Maximum element on left and right
	int left_max = 0, right_max = 0;
	// Indices to traverse the matrix
	int left =0, right = n-1;

	while(left <= right){
		if(arr[left] < arr[right]){
			if(arr[left] > left_max)
				// Update max in left
				left_max = arr[left];
			else
				// Water trapped on current index is max - current height
				result += left_max - arr[left];
			left++;
		}else{
			if(arr[right] > right_max)
				// Update max in right
				right_max = arr[right];
			else
				result += right_max - arr[right];
			right--;
		}
		return result;
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << "Maximum water that can be accumulated is "<< trapWater(arr,n);
}

/*

Input -

n = 5
arr[n] = {3,0,2,0,4}

Sample Output -

Maximum water that can be accumulated is 7

Explanation -

Three units of water can be stored at indexes 1 and 3 and 
1 unit at index 2

Time Complexity : O(n)
Space Complexity : O(1) 

*/

