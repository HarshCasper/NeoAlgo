/*
Introduction -
Given the root of a binary tree where each node has a value 0 or 1.
Each root-to-leaf path represents a binary number starting with the most significant bit.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
Find the sum of these numbers.  
*/

//  Code / Solution

#include<bits/stdc++.h>
using namespace std;

//Define Node as structure
struct TreeNode 
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
 
//Function to allocate new node with given data
TreeNode* newNode(int data)
{
	TreeNode *node=new TreeNode();
	node->data=data;
	node->left=node->right=NULL;
	return (node);
}

int total_sum=0; //This stores the ans ie sum of binary numbers from root to leaf
int curr_sum=0; //This stores the ans of single path from root to leaf

//Function for DFS preorder traversal of binary tree
void preorder(TreeNode *root,int curr_sum){
	//Base Condition
	if(root==NULL)
	return ;
	curr_sum=curr_sum*2+root->data; //converting base 2 to base 10
	//When we encounter leaf node
	if(root->left==NULL && root->right==NULL)
	total_sum+=curr_sum; //Path found
	preorder(root->left,curr_sum);
	preorder(root->right,curr_sum);
}

//Function to find sum of root to leaf
int sumOfRootToLeaf(TreeNode *root){
	
	//Base Condition
	if(root==NULL)
	return 0;
	//Root to left traversal is DFS preorder traversal Root->left->right
	preorder(root,0);
	return total_sum;
}

int main(){
	TreeNode* root=newNode(1);
	root->left=newNode(0);
	root->right=newNode(1);
	root->left->left=newNode(0);
	root->left->right=newNode(1);
	root->right->left=newNode(0);
	root->right->right=newNode(1);
	cout<<"Sum of root to leaf Binary Numbers is: "<<sumOfRootToLeaf(root);
	return 0;
}

/*

   Sample TestCase-1
   Input Binary Tree :
        1   
     /     \
    0       1
  /   \    /  \
 0    1   0    1
 
   Output: Sum of root to leaf Binary Numbers is: 22
 
   Sample TestCase-2
   Input Binary Tree :
       0
       
   Output: Sum of root to leaf Binary Numbers is: 0
    
    Sample TestCase-3
    Input Binary Tree :
       1
       
   Output: Sum of root to leaf Binary Numbers is: 1
   
    
   Time Complexity: O(n)
    Where n is the no.of nodes 
   Space Complexity : O(n) 
    Where n is the no.of nodes

*/

