/*
 Introduction
 Given Postorder and Inorder traversals, construct the binary tree.Output the Preorder Traversal of the Tree
 Inorder Traversal = left Root Right
 Postorder Traversal = Left Right Root
*/

/* Code/Solution */
#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node.  */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

//Preorder resulatant vector
vector<int> preoderRes;

//Function to allocate new node with given data
TreeNode *newNode(int data)
{
	TreeNode *node = new TreeNode();
	node->val = data;
	node->left = node->right = NULL;
	return (node);
}

TreeNode *helper(vector<int> inorder, vector<int> postorder, int Instart, int InEnd, int Poststart, int PostEnd)
{

	//Base Condition
	if (Instart > InEnd)
		return NULL;

	//The last element of the Postorder traversal gives the Root of the Tree
	int rootVal = postorder[PostEnd];
	TreeNode *root = newNode(rootVal);
	int rootIndex;
	//calling for left
	for (rootIndex = Instart; rootIndex <= InEnd; rootIndex++)
	{
		//We have completely traversed left Subtree
		if (inorder[rootIndex] == rootVal)
			break;
	}
	//length of left Tree
	int leftTree = rootIndex - Instart;
	//Length of right Tree
	int rightTree = InEnd - rootIndex;

	//Recursively building the left subTree
	root->left = helper(inorder, postorder, Instart, rootIndex - 1, Poststart, Poststart + leftTree - 1);
	//Recursively building the Right subTree
	root->right = helper(inorder, postorder, rootIndex + 1, InEnd, PostEnd - rightTree, PostEnd - 1);
	return root;
}

TreeNode *buildTree(vector<int> inorder, vector<int> postorder)
{

	int len = inorder.size();

	//helper function recursively constructs the Tree
	// takes inorder , preorder , start and end of preorder and postorder
	return helper(inorder, postorder, 0, len - 1, 0, len - 1);
}

void preoderTraversal(TreeNode *root)
{
	//Base Condittion
	if (root == NULL)
		return;
	preoderRes.push_back(root->val);
	preoderTraversal(root->left);
	preoderTraversal(root->right);
}
//Driver Code
int main()
{
	cout << "Enter the size of array : ";
	int n;
	cin >> n;
	cout << "Enter the inorder traversal : ";
	vector<int> inorder;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		inorder.push_back(x);
	}
	cout << "Enter the postorder traversal : ";
	vector<int> postorder;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		postorder.push_back(x);
	}
	//buildTree function returns root of the newly formed Tree
	TreeNode *root = buildTree(inorder, postorder);
	cout << "The Preoder Traversal of the Tree is : ";
	preoderTraversal(root);
	for (int i = 0; i < preoderRes.size(); i++)
		cout << preoderRes[i] << " ";
	cout << endl;
	return 0;
}

/*
 Input:
 0 <= node->val < 1000000000
 Sample Test Case :
 Input Format : 
 Example : 
 Enter the size of array : 8
 Enter the inorder traversal   : 4 8 2 5 1 6 3 7
 Enter the postorder traversal : 8 4 5 2 6 7 3 1
 
 Output Format :
 Example : ( Output to the above input example ) 
 The Preoder Traversal of the Tree is : 1 2 4 8 5 3 6 7
 
 Time/Space Complexity
 Time Complexity for performing the given operation : O(n^2)
 Time Complexity for performing the traversal of the binary tree : O(n)
   Where n is the no.of nodes 
 Space Complexity : O(1) 
*/
