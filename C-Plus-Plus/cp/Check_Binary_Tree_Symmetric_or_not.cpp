#include<iostream>
using namespace std;

struct TreeNode{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};

TreeNode* InsertNode(int n)
{
	TreeNode* t = new TreeNode;
	t->value = n;
	t->left = NULL;
	t->right = NULL;
	return t;
}

bool If_Mirror_Image(TreeNode* l, TreeNode* r)
{
	if(l==NULL || r==NULL){
		if(l==r){
			return true;
		}
		else{
			return false;
		}
	}
	
	if(l->value!=r->value){
		return false;
	}
																									
	return (If_Mirror_Image(l->left,r->right)&&If_Mirror_Image(l->right,r->left));		//check if l's left subtree is mirror image of r's right subtree and l's right subtree is mirror image of r's left subtree    
}

bool checkSymmetric(TreeNode* N)
{
	if(N==NULL)
	{
		return true;
	}
	return If_Mirror_Image(N->left,N->right);											//check if left subtree and right subtree are mirror image of each other
}

int main(){
	TreeNode* root = InsertNode(5);
	root->left = InsertNode(6);
	root->right = InsertNode(6);
	root->left->left = InsertNode(3);
	root->left->right = InsertNode(2);
	root->right->left = InsertNode(2);
	root->right->right = InsertNode(3);
	string s = (checkSymmetric(root)==true) ? "Given binary tree is symmetric." : "Given binary tree is not symmetric";
	cout<<s;
	return 0;
}

/*
Time Complexity : O(N);
Here we have given following binary tree as input:
	5
   / \
  6   6
 / \ / \
3  2 2  3 
This binary tree is symmetric, so output should be - "Given binary tree is symmetric."

Suppose if input binary tree is:
    10
   / \
  6   6
 /   / 
4    4 
This binary tree is not symmetric, so output will be - "Given binary tree is not symmetric."
*/

