// C++ program to delete a node in binary search tree!!!
//brief description of the concept of deletion-
/*When we delete a node, three possibilities arise. 
1) Node to be deleted is leaf: Simply remove from the tree. 

              5                            5
           /     \         delete(2)     /   \
          3      7       --------->    3     7 
         / \  /  \                     \    /  \ 
       2   4  6   8                   4    6   8
2) Node to be deleted has only one child: Copy the child to the node and delete the child 

              5                           5
           /     \         delete(3)   /   \
          3      7       --------->   4    7
            \   /  \                       /  \ 
            4  6   8                      6   8
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder 
successor to the node and delete the inorder successor. Note that inorder predecessor can also be used. 
 

              5                            6
           /     \         delete(5)    /   \
          4      7       --------->    4    7
                 /  \                        \ 
                6   8                        8
The important thing to note is, inorder successor is needed only when right child is not empty. 
In this particular case, inorder successor can be obtained by finding the minimum value in right child 
of the node.*/

//code
#include <bits/stdc++.h>
using namespace std;

struct node {
	int key;
	struct node *l,*r;
};

//Function to create a new BST node

struct node* new_node(int value)
{
	struct node* temp
	= (struct node*)malloc(sizeof(struct node));
	temp->key = value;
	temp->l = temp->r = NULL;
	return temp;
}

//Inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->l);
		cout << root->key;
		inorder(root->r);
	}
}

//Function to insert a new node with given key in BST//

struct node* insert(struct node* node, int key)
{
	//If the tree is empty, return a new node //
	if (node == NULL)
		return new_node(key);

	// Otherwise, recur down the tree //
	if (key < node->key)
		node->l = insert(node->l, key);
	else
		node->r = insert(node->r, key);

	//return the (unchanged) node pointer //
	return node;
}
//function to search for the minimum value in the BST
struct node* minValueNode(struct node* node)
{
	struct node* present = node;

	/* loop down to find the leftmost leaf */
	while (present && present->l!= NULL)
		present = present->l;

	return present;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is 
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < root->key)
		root->l = deleteNode(root->l, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > root->key)
		root->r = deleteNode(root->r, key);

	// if key is same as root's key, then this is the node to be deleted
	else {
		// node with only one child or no child
		if (root->l == NULL) {
			struct node* temp = root->r;
			free(root);
			return temp;
		}
		else if (root->r == NULL) {
			struct node* temp = root->l;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		struct node* temp = minValueNode(root->r);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->r = deleteNode(root->r, temp->key);
	}
	return root;
}

// Driver Code
int main()
{
	struct node* root = NULL;
	root = insert(root, 1);
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 7);
	root = insert(root, 14);
	root = insert(root, 9);

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 2\n";
	root = deleteNode(root,2);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 5\n";
	root = deleteNode(root, 5);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 14\n";
	root = deleteNode(root, 14);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	return 0;
}

/*test cases-
1.input-2
  output-157914
  
2.input-5
  output-17914
  
3.input-14
  output-179  */
