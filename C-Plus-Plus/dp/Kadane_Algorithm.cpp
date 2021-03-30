/*Kadane's Algorithm implementation
We use Kadane's algorithm when we need to find Maximum Array Sum .
The subarrays consist of both positive and negative numbers. Also it can be
modified to solve the variations as well */
# include <bits/stdc++.h>
using namespace std;

int kadane_1(int arr[], int arr_len)
{
	int max_sum = INT_MIN;
	int curr_sum = 0;

	for (int ind = 0; ind < arr_len; ind++)
	{
		// take sum of all the elements in the array
		curr_sum += arr[ind];
		//for maximum sum subarray when we comes across negative numbers the sum
		// made 0 as it reduces the sum
		if (curr_sum < 0)
			curr_sum = 0;
		max_sum = max(curr_sum, max_sum);
	}
	return max_sum ;
}
// we can also implement kadane's algorithm by storing current maximum sum and
// taking maximum of current sum + a[i] and a[i] in place of reducing negative sum to 0
int kadane_2(int arr[], int arr_len)
{
	int curr_sum_arr[arr_len];
	curr_sum_arr[0] = arr[0];
	for (int ind = 1; ind < arr_len; ind++) {
		curr_sum_arr[ind] = max(arr[ind], (curr_sum_arr[ind - 1] + arr[ind]));
	}
	int ans = INT_MIN;
	for (int ind = 0; ind < arr_len; ind++)
	{
		ans = max(ans, curr_sum_arr[ind]);
	}
	return ans;
}
int main()
{
	int arr_len; // length of array
	cin >> arr_len;
	int arr[arr_len];
	for (int ind = 0; ind < arr_len; ind++)
		cin >> arr[ind];
	cout << kadane_1(arr, arr_len);
	cout << '\n';
	cout << kadane_2(arr, arr_len);
	cout << '\n';

	return 0;
}
