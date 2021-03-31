/*  
This code checks if a binary tree is symmetric or not,
here we have a function "Check_Symmetry" which at first calculate the height of the given binary tree and then checks 
if all the levels of the given Binary tree are forming a palindrome or not, using "is_level_palindrome" function.
If all the level forms palindrome then it represent that the given binary tree is symmetric otherwise it is not symmetric.
If at the given level if some value is 'NULL', then we consider it as 'INT_MIN' while checking if level is palindrome or not.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
};

TreeNode* newNode(int n){
	TreeNode* t = new TreeNode;
	t->value = n;
	t->left = NULL;
	t->right = NULL;
	return t;
}

//this function calculate the height of the Binary Tree  
int height(TreeNode* A){		 
	if(A==NULL){
		return 0;
	}
	return 1 + max(height(A->left),height(A->right));
}

//This gives us the vector of values of all the nodes at the given height
void level_order(TreeNode* A, int h, vector<int> &v){ 		 
	if(A==NULL){
		v.push_back(INT_MIN);
		return;
	}
	if(h==1){
		v.push_back(A->value);
		return;
	}
	level_order(A->left,h-1,v);
	level_order(A->right,h-1,v);
}

// This function checks if particular level of given binary tree forms palindrome
bool is_level_palindrome(TreeNode* A, int h){		
	vector<int> v;
	level_order(A,h,v);
	for(int i=0;i<v.size()/2;i++){
		if(v[i]!=v[v.size()-1-i]){
			return false;
		}
	}
	return true;
}

//This function checks if given binary tree is symmetrical
bool Check_Symmetry(TreeNode* A){		   
	int h = height(A);
	for(int i=1;i<=h;i++){
		if(!is_level_palindrome(A,i)){
			return false;
		}
	}
	return true;
}

int main(){
	TreeNode* T = newNode(5);
	T->left = newNode(6);
	T->right = newNode(6);
	T->left->left = newNode(3);
	T->left->right = newNode(8);
	T->right->left = newNode(8);
	T->right->right = newNode(3);
	
	if(Check_Symmetry(T)){
		cout<<"Given Binary Tree is Symmetric."<<endl;
	}
	
	else{
		cout<<"Given Binary Tree is not Symmetric."<<endl;
	}
	
	return 0;
}

/*
Time Complexity : O(2^N)
Space Complexity : O(N)

Here we have given following binary tree as input:
    5
   / \
  6   6
 / \ / \
3  8 8  3 
This binary tree is symmetric, so output should be - "Given binary tree is symmetric."
*/

