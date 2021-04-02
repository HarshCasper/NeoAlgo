/*
Median of a stream of running integers
======================================
Print the median of given numbers while keep taking in new numbers

Concept:
We maintain two heaps - a minHeap and a maxHeap. minHeap contains numbers greater than the current median and
maxHeap contains numbers less than equal to the current median.
Note that if the number of elements in both the heaps are equal then median will be equal to the average of the
topmost elements of the two heaps. If any heap contains more elements than the other heap then its topmost element will
be the current median. Also note that the maximum difference in the number of elements between the two heaps should always be
less than equal to 1.

|n(minHeap) - n(maxHeap)|<=1

If we are in a situation where inserting an element causes increase in this difference, then we must transfer an element
from one heap to other to settle this.

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

#include <iostream>
#include<queue>
using namespace std;

// Prints median in a running stream of integers
void getMedian(int a[], int n) {
	// Declare a maxHeap and a minHeap
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	// Push in maxheap
	maxHeap.push(a[0]);

	// current median
	// When count of numbers is 1, median is equal to the number itself
	double curr = a[0];
	// Print current median
	cout << curr << " ";

	//  While numbers are being inputted
	for (int i = 1; i < n; i++) {
		int num = a[i];
		// INSERTION:

		// If num is greater than current median
		if (num > curr) {
			// Insert in minHeap
			// If size of minHeap is more
			if (minHeap.size() >= maxHeap.size() + 1) {
				// shift one element from minHeap to maxHeap
				int num = minHeap.top();
				minHeap.pop();
				maxHeap.push(num);
			}
			// Insert in minHeap
			minHeap.push(num);
		}

		// If num is less than equal to the current median
		else {
			// Insert in maxHeap
			// If size of maxHeap is more
			if (maxHeap.size() >= minHeap.size() + 1) {
				// shift one element from maxHeap to minHeap
				int num = maxHeap.top();
				maxHeap.pop();
				minHeap.push(num);
			}
			// Insert in maxHeap
			maxHeap.push(num);
		}

		// PRINTING:

		/// If sizes are equal, avearge must be taken
		if (minHeap.size() == maxHeap.size()) {
			curr = (minHeap.top() + maxHeap.top()) * 1.0 / 2.0;
			cout << curr << " ";
		}
		// else topmost element of heap with greater size is printed
		else if (minHeap.size() > maxHeap.size()) {
			curr = minHeap.top();
			cout << curr << " ";
		}
		else {
			curr =  maxHeap.top();
			cout << curr << " ";
		}
	}
}

// Driver code
int main() {

	// Take input
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	getMedian(a, n);
}

/*
Input:
4
5 15 1 3

Output:
5 10 5 4

Explanation:
Median of {5} -> 5
Median of {5, 15} -> 10
Median of {5, 15, 1} -> 5
Median of {5, 15, 1, 3} -> 4
*/
