// Red Black Tree implementation in C++ (creation,insertion,traversal)

#include <bits/stdc++.h>
using namespace std;

// structure of a node
struct Node {
	int data; 
	Node *parent; // pointer to the parent
	Node *left; // pointer to left child
	Node *right; // pointer to right child
	int color; // 1 -> Red, 0 -> Black
};

typedef Node *NodePtr;

// class RBTree implements the operations in Red Black Tree
class RBTree {
	NodePtr root;
	NodePtr TNULL;

	// initializes the nodes with appropirate values
	// all the pointers are pointing to the null pointer
	void initializeNULLNode(NodePtr node, NodePtr parent) {
		node->data = 0;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}

	void pre_Order(NodePtr node) {
		if (node != TNULL) {
			
 		string sColor = node->color?"RED":"BLACK";
		   cout<<node->data<<"("<<sColor<<")  ";
			pre_Order(node->left);
			pre_Order(node->right);
		} 
	}

	void in_Order(NodePtr node) {
		if (node != TNULL) {
			in_Order(node->left);
			string sColor = node->color?"RED":"BLACK";
		   cout<<node->data<<"("<<sColor<<")  ";
			in_Order(node->right);
		} 
	}

	void post_Order(NodePtr node) {
		if (node != TNULL) {
			post_Order(node->left);
			post_Order(node->right);
			string sColor = node->color?"RED":"BLACK";
		   cout<<node->data<<"("<<sColor<<")  ";
		} 
	}

	// fix the red-black tree
	void fixInsert(NodePtr k){
		NodePtr u;
		// when parent is red
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left; // uncle
				if (u->color == 1) {
					// when uncle is also red
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} else {  
					if (k == k->parent->left) {
						k = k->parent;
						rightRotate(k);
					}
					
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			} else {
				u = k->parent->parent->right; // uncle

				if (u->color == 1) {
					
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;	
				} else {
					if (k == k->parent->right) {
						
						k = k->parent;
						leftRotate(k);
					}
					
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
	}

public:
	RBTree() {
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}

	// Pre-Order traversal
	// Node->Left Subtree->Right Subtree
	void preorder() {
cout<<"PREORDER:- ";
		pre_Order(this->root);
		cout<<endl;
	}

	// In-Order traversal
	// Left Subtree -> Node -> Right Subtree
	void inorder() {
cout<<"INORDER:- ";
		in_Order(this->root);
		cout<<endl;
	}

	// Post-Order traversal
	// Left Subtree -> Right Subtree -> Node
	void postorder() {
cout<<"POSTORDER:- ";
		post_Order(this->root);
		cout<<endl;
	}

	
	// rotate left at node x
	void leftRotate(NodePtr x) {
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != TNULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	void rightRotate(NodePtr x) {
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != TNULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	// insert the key to the tree
	// and adjust the tree accordingly
	void insert(int key) {
		
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1; // new node must be red

		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != TNULL) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			} else {
				x = x->right;
			}
		}

		// y is parent of x
		node->parent = y;
		if (y == nullptr) {
			root = node;
		} else if (node->data < y->data) {
			y->left = node;
		} else {
			y->right = node;
		}

		// if new node is a root node, simply return
		if (node->parent == nullptr){
			node->color = 0;
			return;
		}

		// if the grandparent is null, simply return
		if (node->parent->parent == nullptr) {
			return;
		}

		// Fix the tree
		fixInsert(node);
	}

	NodePtr getRoot(){
		return this->root;
	}


};

int main() {
	RBTree tree;
int n,i,nod;
cout<<"total no. of nodes\n";
cin>>n;
cout<<"enter nodes\n";
for(i=0;i<n;i++){
	cin>>nod;
	tree.insert(nod);
}
tree.inorder();
tree.postorder();
tree.preorder();

	return 0;
}
/* output:
total no. of nodes
5
enter nodes
8
5
15
17
18
INORDER:- 5(BLACK)  8(BLACK)  15(RED)  17(BLACK)  18(RED)  
POSTORDER:- 5(BLACK)  15(RED)  18(RED)  17(BLACK)  8(BLACK)  
PREORDER:- 8(BLACK)  5(BLACK)  17(BLACK)  15(RED)  18(RED) */
