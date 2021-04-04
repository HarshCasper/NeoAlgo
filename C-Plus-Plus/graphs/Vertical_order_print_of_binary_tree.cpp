/*
Vertical order print of binary tree
====================================
Given a binary tree, print it in vertical manner
eg:
           1
        /    \
       2      3
      / \   /   \
     4   5  6   7
               /  \
              8   9
Vertical Print:
4
2
1 5 6
3 8
7
9

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include<map>
#include <vector>
using namespace std;

// Node class
class node {
public:
	int data;
	node *left = NULL;
	node *right = NULL;

	node(int d) {
		data = d;
	}
};

// builds tree for pre-order input
node* buildTree() {
	int d; cin >> d;

	//  Base Case
	if (d == -1) {
		return NULL;
	}

	node *root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

// Recursive function to mark position of nodes
void markNodes(node* root, int pos, map<int, vector<int>> &mp) {

	if (root == NULL) {
		return;
	}

	mp[pos].push_back(root->data);
	markNodes(root->left, pos - 1, mp);
	markNodes(root->right, pos + 1, mp);
}

// prints vertical order
void verticalPrint(node* root) {
	map<int, vector<int>> mp;
	markNodes(root, 0, mp);

	for (auto it : mp) {
		for (auto x : it.second) {
			cout << x << " ";
		} cout << endl;
	}

}

// Driver code
int main() {

	node *root = buildTree();
	verticalPrint(root);
}

/*
Sample Input:
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 -1 13 -1 -1

Sample Output:
1
10 9
8 6
7 3
14
13
*/