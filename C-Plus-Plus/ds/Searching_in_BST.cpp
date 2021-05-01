/*
Let's say we want to search for the number, what we'll do is we'll start at the root, and then we will compare 
the value to be searched with the value of the root if it's equal we are done with the search if it's lesser 
we know that we need to go to the left subtree because in a binary search tree all the elements in the left 
subtree are lesser and all the elements in the right subtree are greater. Searching an element in the 
binary search tree is basically this traversal in which at each step we will go either towards left or right 
and hence in at each step we discard one of the sub-trees. If the tree is balanced, we call a tree balanced if 
for all nodes the difference between the heights of left and right subtrees is not greater than one, 
we will start with a search space of n nodes and when we will discard one of the sub-trees 
we will discard n/2 nodes so our search space will be reduced to n/2 and then in the next step 
we will reduce the search space to n/4 and we will go on reducing like this till we find the element or 
till our search space is reduced to only one node.
*/

#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	// constructor
	node(int x){				
		data = x;
		left = nullptr;
		right = nullptr;
	}

};

node* Insert_into_bst(node* root, int data){

	// make new node
	if(root == nullptr){				
		root = new node(data);
		return root;
	}

	else if(data < root->data){
		root->left = Insert_into_bst(root->left,data);
	}
	else{
		root->right = Insert_into_bst(root->right,data);
	}

	return root;
}

node* Create_BST(){

	// root node
	int data;
	cout<<"Enter the data for the node: "<<endl;
	cin >> data;

	node* root = nullptr;

	while(data!= -1){ 
		root = Insert_into_bst(root, data);
		cin >> data;
	}

	return root;
}

bool search(node* root, int key){

	if(root == nullptr)
		return false;

	if(root->data == key)
		return true;

	else if(root->data > key){
		search(root->left, key);
	}
	else{
		search(root->right, key);
	}	
}

int main(){

	node* root = Create_BST();
	int element;
	cout<<"Enter the element to search: "<<endl;
	cin >> element;
	cout<<"The result is: ";
        cout << boolalpha << search(root, element);
	return 0;
}

/* 
	Test Case :

	Input :
	Enter the data for the node:
	1 2 3 4 5 6 -1
	Enter the element to search:	
	4
	
	Outout : 
	The result is: true

	Time Complexity: O(n), in worst case (when BST is a right skew tree).
	Space Complexity: O(n), for recursive stack.

 */
