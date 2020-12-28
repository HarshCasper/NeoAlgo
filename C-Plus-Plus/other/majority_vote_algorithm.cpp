// The Boyer–Moore majority vote algorithm in C++
// This algorithm finds a majority element, if there is one: i.e, an element that occurs repeatedly for more than half of the elements of the input.

#include <bits/stdc++.h>
using namespace std;

// To find majority element
int majority(int arr[], int arrsize) {
	int index = 0, count = 1;
	// finding num to check majority
	for (int i = 1; i < arrsize; i++) {
		if (arr[index] == arr[i])
			count++;
		else
			count--;
		if (count == 0) {
			index = i;
			count = 1;
		}
	}
	int num = arr[index];
	for (int i = 0; i < arrsize; i++)
		if (arr[i] == num)
			count++;
	// checking for majority
	if (count > arrsize / 2)
		return num;
	else
		return -1;
}

int main() {
	int n;
	cout << "Enter no of elements:";
	cin >> n;
	cout << "\nEnter elements: ";
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int result = majority(arr, n);
	if (result != -1)
		cout << "Majority of a sequence is " << result << endl;
	else
		cout << "There is no majority \n";
	return 0;
}

/*input/output:
 Enter no of elements:5
 Enter elements: 1 1 1 1 2
 Majority of arr sequence is 1

 Enter no of elements:5
 Enter elements: 1 2 3 2 4
 There is no Majority.

 Time complexity : O(n)
 Space complexity: O(1)
 */
