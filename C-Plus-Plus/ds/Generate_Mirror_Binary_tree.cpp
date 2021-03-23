// Generating a Mirror Binary Tree from given Binary Tree
// -----------------------------------------------------------
// Input Format :
// For the tree 

//         5
//        / \
//       3   6
//      / \
//     2   4

// Input should be like -> 5 3 2 -1 -1 4 -1 -1 6 -1 -1 

// where -1 indicates that node's left/right child is NULL;
// -----------------------------------------------------------
// Sample Input : 

// 5 3 2 -1 -1 4 -1 -1 6 -1 -1 
// -----------------------------------------------------------
// Sample Output :

// Inorder Traversals =>
// Original Binary Tree : 
// 6 5 4 3 2 
// Mirror Binary Tree (using Recursive Method) : 
// 6 5 4 3 2 
// Mirror Binary Tree (changing the original tree) : 
// 6 5 4 3 2 
// -----------------------------------------------------------

#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* buildTree(){
	int d;
	cin >> d;
	if(d==-1){
		return NULL;
	}
	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void inorderTraversal(node* root){
	if (root == NULL) 
        return; 
    inorderTraversal(root->left); 
    cout << root->data << " "; 
    inorderTraversal(root->right); 
}

// METHOD 1 - Recursive Approach
void generateMirrorTree(node* root, node* &mirror){
	if(root==NULL){
		mirror = NULL;
		return;
	}
	mirror = new node(root->data);
	generateMirrorTree(root->left, mirror->right);
	generateMirrorTree(root->right,mirror->left);
}

// METHOD 2 - Making the mirror tree in the same original b.tree
node* generateMirrorTree2(node* root){
	if(root == NULL){
		return root;
	}
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	if(root->left){
		generateMirrorTree2(root->left);
	}
	if(root->right){
		generateMirrorTree2(root->right);
	}
	return root;
}

int main(){
	
	node* root = buildTree();
	node* mirror = NULL;
	generateMirrorTree(root,mirror);
	node* mirror2 = generateMirrorTree2(root);

	cout << "Inorder Traversals => \n";
	cout << "Original Binary Tree : \n";
	inorderTraversal(root);
	cout << "\n";

	cout << "Mirror Binary Tree (using Recursive Method) : \n";
	inorderTraversal(mirror);
	cout << "\n";
	
	cout << "Mirror Binary Tree (changing the original tree) : \n";
	inorderTraversal(mirror2);
	cout << "\n";

}
