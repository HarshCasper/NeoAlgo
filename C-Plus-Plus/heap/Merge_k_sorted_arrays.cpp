/*
Merge K sorted arrays
=====================
Given K sorted arrays, merge all of them into a single sorted array

M-> Total number of elements
Time Complexity: O(MlogM)
Space Complexity: O(M)
*/
#include <iostream>
#include<queue>
using namespace std;

// Node class
class Node {
public:
	int value; // Stores value of the node
	int i; // Stores row number of the node
	int j; // Stores column number of the node

	// Constructor
	Node(int value, int i, int j) {
		this->value = value;
		this->i = i;
		this->j = j;
	}
};

// Comparator class for priority_queue
class NodeCompare {
public:
	bool operator()(Node a, Node b) {
		return a.value > b.value;
	}
};

// Merges k sorted arrays
void merge(vector<vector<int>> a, int k) {

	// minHeap declared
	priority_queue<Node, vector<Node>, NodeCompare> pq;

	// pq must be initialised with the first elements of all the k arrays
	for (int i = 0; i < k; i++) {
		Node node(a[i][0], i, 0); // node is located at the ith row and 0th column
		pq.push(node);
	}

	// Stores final array
	vector<int> ans;

	// While pq is not empty
	while (pq.size()) {
		// Consider the topmost element of pq
		Node f = pq.top();
		pq.pop();
		// Topmost element must be stored in ans
		ans.push_back(f.value);

		// Push next element of same row into the pq
		int row = f.i;
		int col = f.j;

		if (col + 1 < a[row].size()) {
			Node new_node(a[row][col + 1], row, col + 1);
			pq.push(new_node);
		}
	}

	// Print ans
	for (auto x : ans) {
		cout << x << " ";
	}
}

// driver code
int main() {

	int k; cin >> k;

	vector<vector<int>> a(k);

	for (int i = 0; i < k; i++) {
		int n; cin >> n;
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			a[i].push_back(x);
		}
	}

	merge(a, k);
}

/*
Input:
3
4
2 6 12 15
4
1 3 14 15
4
3 5 8 10

Output:
1 2 3 3 5 6 8 10 12 14 15 15
*/