/* Problem statement :
Given an unsorted array. Sort the array in such a way that the array looks like a wave array.
For example, if the given sequence arr has n elements then the sorted wave array looks like -
arr[0] >= arr[1] and arr[1] <= arr[2]
arr[2] >= arr[3] and arr[3] <= arr[4]
arr[4] >= arr[5] and arr[5] <= arr[6] And so on
For example, the given array : arr = { 4, 3, 5, 2, 3, 1, 2 } 
The above figure is a visual representation of the given arr and you can see we can express ‘arr’ in a waveform array because 
4>3 and 3<5 
5>2 and 2<3
3>1 and 1<2
And it follows the condition of wave array */

#include <bits/stdc++.h>
using namespace std;
vector<int> wave_sort(vector<int> &v, int n)
{
	for (int i = 0; i < n; i += 2)
	{
		/*If the current element is lesser in value than the previous and is not the first.
		then the values are swapped */
		if (v[i] < v[i - 1] and i != 0)
		{
			swap(v[i], v[i - 1]);
		}

		/*If the current element is lesser in value than the next and is not the last.
		then the values are swapped */
		if (v[i] < v[i + 1] and i != n - 1)
		{
			swap(v[i], v[i + 1]);
		}
	}

	return v;
}

int main()
{
	int n;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	wave_sort(v, n);
	
	//Printing the final vector
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}

/* Example 1:
Input[] : {20 80 40 35 10 15 70}
Output[] : {80 20 40 10 35 15 70}

Example 2:
Input[] = {12 20 45 60 5}
Output[] : {20 12 60 5 45}

Time Complexity: O(n) */
