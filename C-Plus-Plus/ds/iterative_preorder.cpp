// C++ program to implement iterative preorder traversal
#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the given data and
NULL left and right pointers.*/
struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node* root)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty stack and push root to it
	stack<node*> nodeStack;
	nodeStack.push(root);

	/* Pop all items one by one. Do following for every popped item
	a) print it
	b) push its right child
	c) push its left child
	Note that right child is pushed first so that left is processed first */
	while (nodeStack.empty() == false) {
		// Pop the top item from stack and print it
		struct node* node = nodeStack.top();
		printf("%d ", node->data);
		nodeStack.pop();

		// Push right and left children of the popped node to stack
		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}
}

// Driver program to test above functions
int main()
{
	/* Constructed binary tree is
			10
		/ \
		8	 2
	/ \ /
	3	 5 2
*/
	struct node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);
	iterativePreorder(root);
	return 0;
}
