/**An array element is a peak if it is NOT smaller than
its neighbours. For corner elements, we need to
consider only one neighbour.
Since an array always have a maximum value therefore an peak element always be there and there can be many peak element.
Approach :If the middle element is not the peak element, then check if the element on the right side is greater than the middle element 
then there is always a peak element on the right side. 
If the element on the left side is greater than the middle element then there is always a peak element on the left side.
**/
#include <bits/stdc++.h>
using namespace std;

// recursive approach
int find_peak_recursive(vector<int> v, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		// for corner cases
		if (mid == 0 || mid + 1 == v.size())
		{
			if (mid == 0)
			{
				if (v[0] >= v[1])
					return v[0];
				else
					return v[1];
			}
			else
			{
				if (v[mid] >= v[mid - 1])
					return v[mid];
				else
					return v[mid - 1];
			}
		}
		else if (v[mid] >= v[mid - 1] && v[mid] >= v[mid + 1])
			return v[mid];

		else if (v[mid] < v[mid + 1])
			return find_peak_recursive(v, mid + 1, r);

		else
			return find_peak_recursive(v, l, r - 1);
	}

	return -1;
}

// using while loop approach
int find_peak_iter(vector<int> arr)
{
	int start = 0, n = arr.size();
	int end = n - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (mid - 1 >= 0 && mid + 1 < n)
		{
			if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
			{
				return arr[mid];
			}
			else if (arr[mid] < arr[mid - 1])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		// for corner cases
		else if (mid == 0)
		{
			if (arr[0] > arr[1])
			{
				return arr[0];
			}
			else
			{
				return arr[1];
			}
		}

		// for corner cases
		else if (mid == n - 1)
		{
			if (arr[n - 1] > arr[n - 2])
			{
				return arr[n - 1];
			}
			else
			{
				return arr[n - 2];
			}
		}
	}

	return -1;
}

int main()
{
	int n;
	cout << "Enter the number of elements in the array : ";
	cin >> n;
	vector<int> v(n);
	cout << "\nEnter the elements of the array : \n";
	for (int i = 0; i < n; i++)
	{
	    cin >> v[i];
	}

	int peak_recursive = find_peak_recursive(v, 0, n - 1);
	cout << "Peak element (Recursive approach) : " << peak_recursive << "\n";

	int peak_iter = find_peak_iter(v);
	cout << "Peak element (Iterative approach) : " << peak_iter << "\n";

	return 0;
}

/**
Eg. :
Input: 
Enter the number of elements in the array : 7
Enter the elements of the array : 10 20 15 2 23 90 67

Output: 
Peak element (Recursive approach) : 90
Peak element (Iterative approach) : 20

Time Complexity : O(log(N))
Space Complexity : O(N)
**/
