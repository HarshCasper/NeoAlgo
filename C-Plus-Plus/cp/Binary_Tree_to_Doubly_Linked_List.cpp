/*
This code gets the values of binary tree from the user and then convert the binary tree to doubly linked list.
The formed Doubly linked list will have elements in the same order as that of inorder traversal of binary tree. 
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int value;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

TreeNode* newNode(int n){
	TreeNode* t = new TreeNode;
	t->value = n;
	t->left = NULL;
	t->right = NULL;
}

//This function inserts node into the binary tree
TreeNode* insert(TreeNode* t, queue<TreeNode* > &q, int v){		
	TreeNode* temp = newNode(v);
	if(v==-1){
		temp = NULL;
	}
	if(t==NULL){
		t = temp;
	}
	else if(q.front()->left==NULL){
		q.front()->left = temp;
	}
	else{
		q.front()->right = temp;
		q.pop();
	}
	q.push(temp);
	return t;
}

//This function converts given vector into Binary Tree
TreeNode* make_tree(vector<int> v){		
	queue<TreeNode* > q;
	TreeNode* t = NULL;
	for(int i=0;i<v.size();i++){
		t = insert(t,q,v[i]);
	}
	return t;
}

//This function prints all the elements of doubly linked list
void print_elements(TreeNode* &T){		
	TreeNode* temp = T;
	cout<<"The elements of doubly linked list are: ";
	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp = temp->right;
	}
}

//This function converts Binary tree to doubly linked list
void to_dll(TreeNode* T, TreeNode* &temp){		
	if(T==NULL){
		return;
	}
	to_dll(T->right,temp);
	T->right = temp;
	
	if(temp!=NULL){
		temp->left = T;
	}
	temp = T;
	to_dll(T->left,temp);
}

void to_doubly_linked_list(TreeNode* T){		
	TreeNode* h = NULL;
	to_dll(T,h);
	print_elements(h);
}

int main(){
	cout<<"Enter number of nodes of binary tree: "<<endl;
	int node;		//number of nodes of binary tree
	cin>>node;
	
	cout<<"Enter the values of nodes level by level and enter -1 if node is NULL: "<<endl;
	vector<int> binary_tree_values;
	
	while(node){		//asking user for elements of Binary tree
		int node_value;
		cin>>node_value;
		binary_tree_values.push_back(node_value);
		node--;
	}
	
	cout<<"Making binary tree from the vector..."<<endl;
	TreeNode* T = make_tree(binary_tree_values);
	
	cout<<"Converting Binary tree to doubly linked list..."<<endl;
	to_doubly_linked_list(T);
	
	return 0;
}

/*
Time Complexity : O(N)
Space Complexity : O(N)

Here if we give following binary tree as input:
    5
   / \
  6   8
 / \ / \
3  4 9  2 
i.e,

if input is -

Enter number of nodes of binary tree: 
7
Enter the values of nodes level by level and enter -1 if node is NULL:
5 6 8 3 4 9 2

The output will be -

Making binary tree from the vector...
Converting Binary tree to doubly linked list...
The elements of doubly linked list are: 3 6 4 5 9 8 2
*/

