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

int main() {

	// For taking in input
	int n;

	// Declare a maxHeap and a minHeap
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	// Input first number
	cin >> n;
	// Push in maxheap
	maxHeap.push(n);

	// current median
	double curr = n; // When count of numbers is 1, median is equal to the number itself
	// Print current median
	cout << curr << " ";

	//  While numbers are being inputted
	while (cin >> n) {

		// INSERTION:

		// If n is greater than current median
		if (n > curr) { // Insert in minHeap

			// If size of minHeap is more
			if (minHeap.size() >= maxHeap.size() + 1) {
				// shift one element from minHeap to maxHeap
				int num = minHeap.top();
				minHeap.pop();
				maxHeap.push(num);
			}
			// Insert in minHeap
			minHeap.push(n);
		}

		// If n is less than equal to the current median
		else { // Insert in maxHeap

			// If size of maxHeap is more
			if (maxHeap.size() >= minHeap.size() + 1) {
				// shift one element from maxHeap to minHeap
				int num = maxHeap.top();
				maxHeap.pop();
				minHeap.push(num);
			}
			// Insert in maxHeap
			maxHeap.push(n);
		}

		// PRINTING:

		/// If sizes are equal, avearge must be taken
		if (minHeap.size() == maxHeap.size()) {
			curr = (minHeap.top() + maxHeap.top()) * 1.0 / 2.0;
			cout << curr << " ";
		} // else topmost element of heap with greater size is printed
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

/*
Input:
5 15 1 3

Output:
5 10 5 4

Explanation:
Median of {5} -> 5
Median of {5, 15} -> 10
Median of {5, 15, 1} -> 5
Median of {5, 15, 1, 3} -> 4
*/
