#include<iostream>
using namespace std;
 
//creating structure for node
struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

// Insert Function
Node* Insert(Node *root,char data) {
	//if root have no value
	//then create a node and insert values
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	//check if data is less than root value
	//then insert into left subtree
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	//check if data is less than root value
	//then insert into right subtree
	else 
		root->right = Insert(root->right,data);
	return root;
}

//Inorder Function
void Inorder(Node *root) {
	// if tree is empty then return
	if(root == NULL) return;
	//visit left subtree
	Inorder(root->left);
	//Print data
	printf("%c ",root->data);
	//Visit right subtree   
	Inorder(root->right);  
}
//Main Function began
int main() {
	Node* root = NULL;
	//input values
	root = Insert(root,'M'); 
	root = Insert(root,'B');
	root = Insert(root,'Q');
	root = Insert(root,'Z'); 
	root = Insert(root,'A'); 
	root = Insert(root,'C');
	//Print Nodes in Preorder. 
	cout<<"\tOUTPUT\n";
	cout<<"In-order traversal : ";
	Inorder(root);
	cout<<"\n";
}
//Main Ends

/*Sample Input Output

Input -> M B Q Z A C

	OUTPUT
Postorder traversal : A B C M Q Z 

Time Complexity: O(n)
*/