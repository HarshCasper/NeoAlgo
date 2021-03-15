// Program to find the maximum and minimum value in a Binary search Tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node * left;
	struct Node * right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node *temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input 
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str;)
		ip.push_back(str);

	// Create the root of the tree
	Node *root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size())
	{

		// Get and remove the front of the queue
		Node *currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N")
		{

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N")
		{

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}
// function to find the minimum value in a BST
int minValue(Node *root)
{
	Node *temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->data;
}
// function to find the maximum value in a BST
int maxValue(Node *root)
{
	Node *temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp->data;
}

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		getline(cin, s);
		Node *root = buildTree(s);
		cout << "Minimum value in the tree is: " << minValue(root) << endl;
		cout << "Maximum value in the tree is: " << maxValue(root) << endl;
	}
	return 0;
}

// Sample I/O
// Input: 5 4 6 3 N N 7 1 N N N (Level order traversed tree)
// The maximum value in the BST will be the right most node of the right sub-tree
// The minimum value in the BST will be the left most node of the left sub-tree
// Output:
// Minimum value in the tree is: 1
// Maximum value in the tree is: 7

// Complexity:
// Time complexity: O(Height of tree)
// Space complexity: O(1)
