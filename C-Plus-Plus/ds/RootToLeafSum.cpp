/*
Introduction -
Given the root of a binary tree where each node has a value 0 or 1.
Each root-to-leaf path represents a binary number starting with the most significant bit.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
Find the sum of these numbers.  
*/

//  Code / Solution

#include <bits/stdc++.h>
using namespace std;

//Define Node as structure
struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

//Function to allocate new node with given data
TreeNode *newNode(int data)
{
	TreeNode *node = new TreeNode();
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

//Function to create Binary Tree from preorder traversal
TreeNode *buildTree()
{

	//Input
	int d;
	cin >> d;

	//If d is -1 then return NULL
	if (d == -1)
		return NULL;

	//Place data at current node
	TreeNode *root = newNode(d);

	//recursively build Left and Right Subtrees
	root->left = buildTree();
	root->right = buildTree();

	return root;
}
//This stores the ans ie sum of binary numbers from root to leaf
int total_sum = 0;
//This stores the ans of single path from root to leaf
int curr_sum = 0;

//Function for preorder traversal of binary tree
void preorder(TreeNode *root, int curr_sum)
{
	//Base Condition
	if (root == NULL)
		return;
	//converting base 2 to base 10
	curr_sum = curr_sum * 2 + root->data;
	//When we encounter leaf node
	if (root->left == NULL && root->right == NULL)
		//Path found
		total_sum += curr_sum;
	preorder(root->left, curr_sum);
	preorder(root->right, curr_sum);
}

//Function to find sum of root to leaf
int sumOfRootToLeaf(TreeNode *root)
{

	//Base Condition
	if (root == NULL)
		return 0;
	//Root to left traversal is DFS preorder traversal Root->left->right
	preorder(root, 0);
	return total_sum;
}

int main()
{

	//Create the Tree
	cout << "Enter the binary tree elements preorder wise and enter -1 for NULL nodes : ";
	TreeNode *root = buildTree();
	cout << "Sum of root to leaf Binary Numbers is: " << sumOfRootToLeaf(root);
	return 0;
}

/*

   Sample TestCase-1
   Input Binary Tree : Enter the binary tree elements preorder wise and enter -1 for NULL nodes : 1 0 0 -1 -1 1 -1 -1 1 0 -1 -1 1 -1 -1
        1   
     /     \
    0       1
  /   \    /  \
 0    1   0    1
 
    Output: Sum of root to leaf Binary Numbers is: 22
 
   Sample TestCase-2
   Input Binary Tree :
   Enter the binary tree elements preorder wise and enter -1 for NULL nodes : 0 -1 -1 
       
    Output: Sum of root to leaf Binary Numbers is: 0
    
   Time Complexity: O(n)
    Where n is the no.of nodes 
   Space Complexity : O(n) 
    Where n is the no.of nodes

*/

