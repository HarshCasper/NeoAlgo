#include<iostream>
#include<queue>
using namespace std;

//Creating nodes using structures
struct Node {
	char data;
	Node *left;
	Node *right;
};

// Function to print Nodes in a binary tree in Level order fashion
void LevelOrder(Node *root) 
{ //Base condition

	if(root == NULL) 
	  return;

	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) 
	{
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
// Function to Insert Node in a Binary Tree
Node* Insert(Node *root,char data) 
{
	if(root == NULL) 
	{
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}
//Main function starts 
int main() 
{
	
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	//Print Nodes in Level Order. 
	LevelOrder(root);
}
//Main Function ends

/*Sample input output
/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
			
			output: M B Q A C Z
    
	Another Example 
	
	              F
	              /\
	             D  J
	            /\  /\
	           B  E G K
              /\	 \
	         A  C     I
	                  /
	                  H
	Output: F D J B E G K A C I H
	*/
