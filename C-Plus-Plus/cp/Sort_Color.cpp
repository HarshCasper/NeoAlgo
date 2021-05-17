/*
Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]

Example 4:
Input: nums = [1]
Output: [1]

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.

link to the problem: https://leetcode.com/problems/sort-colors/
*/

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class Sort_Col {
	int n;
	int a[MAX];
  public:
	void sort_colors(int a[]) {
		int lo = 0;
		int hi = n - 1;
		int mid = 0;

		// Iterate till all the elements
		// are sorted
		while (mid <= hi) {
			switch (a[mid]) {

			// If the element is 0
			case 0:
				swap(a[lo++], a[mid++]);
				break;

			// If the element is 1 .
			case 1:
				mid++;
				break;

			// If the element is 2
			case 2:
				swap(a[mid], a[hi--]);
				break;
			}
		}
	}

	void set_data() {
		cout << "Enter number of elements: " << endl;
		cin >> n;
		cout << "Input Numbers:" << endl;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
	}

	void display() {
		sort_colors(a);

		cout << "[";
		for (int i = 0; i < n; i++) {
			cout << a[i] << "  ";
		}
		cout << "]";
	}

};

int main() {
	Sort_Col sc;
	sc.set_data();
	sc.display();
	return 0;
}


/*
Complexity Analysis:
Time Complexity: O(n) as only one traversal of the array is needed.
Space Complexity: O(1) as no extra space is required.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]

Example 4:
Input: nums = [1]
Output: [1]
*/
