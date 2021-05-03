/*
   This program will print ZigZag traversal of tree by using concept of Depth First Search with some modification
 */

#include <bits/stdc++.h>
using namespace std;

struct node {
	node(int x): data(x), left_child(NULL), right_child(NULL) {}
	int data;
	node *left_child;
	node *right_child;
};

class bin_tree {
	node *root;
  public:
	// constructor of tree
	bin_tree() {
		root = NULL;
	}
	void insert_data(int x) {
		//if tree is empty
		if (!root) {
			node *tnode = new node(x);
			root = tnode;
		}
		//if tree if not empty
		else {
			node *temp = root;
			while (1) {
				//if data to be inserted is less then the data of current node
				if (x < temp->data ) {
					//if left child of current node is node present
					///we simple add new node with the data to be inserted
					if (!temp->left_child) {
						node *tnode = new node(x);
						temp->left_child = tnode;
						break;
					}
					//else we change the current node pointer 
					//with pointer of left child node pointer
					else
						temp = temp->left_child;
				}
				//if data to be inserted is grater then 
				//or equal to the data of current node
				else {
					//if right child of current node is node present 
					//we simple add new node with the data to be inserted
					if (!temp->right_child) {
						node *tnode = new node(x);
						temp->right_child = tnode;
						break;
					}
					//else we change the current node pointer 
					//with pointer of left child node pointer
					else
						temp = temp->right_child;
				}
			}
		}
	}
	void zigzag(node*);
	void zigzag_traversal_of_tree();
};

void bin_tree :: zigzag_traversal_of_tree() {
	zigzag(root);
}

void bin_tree :: zigzag(node* r) {
	//if no node is found
	if (!r)
		return;
    // declare two stacks to store nodes at current level and next level
	stack<struct node*> currentlevel; 
    stack<node*> nextlevel; 
  
    // push the root 
    currentlevel.push(root); 
  
    // check if stack is empty    
    bool lefttoright = true; 
    while (!currentlevel.empty()) { 
  
        // pop out of stack 
        node* temp = currentlevel.top(); 
        currentlevel.pop(); 
  
        // if not null 
        if (temp) { 
  
            // print the data in it 
            cout << temp->data << " "; 
  
            // store data according to current 
            // order. 
            if (lefttoright) { 
                if (temp->left_child) 
                    nextlevel.push(temp->left_child); 
                if (temp->right_child) 
                    nextlevel.push(temp->right_child); 
            } 
            else { 
                if (temp->right_child) 
                    nextlevel.push(temp->right_child); 
                if (temp->left_child) 
                    nextlevel.push(temp->left_child); 
            } 
        } 
  
        if (currentlevel.empty()) { 
            lefttoright = !lefttoright; 
            swap(currentlevel, nextlevel); 
        } 
    } 
}

int main() {
	bin_tree t;
	int n;
	cout << "Enter number of elements in tree: ";
	cin >> n;
	cout << "Enter elements to insert in  tree: ";
	while (n--) {
		int k; cin >> k;
		t.insert_data(k);
	}
	cout << "\nZigzag Traversal of tree:";
	t.zigzag_traversal_of_tree();
	return 0;
}

/*
	Sample case 1:
	
	Enter number of elements in tree: 8
	Enter elements to insert in  tree: 50 40 60 55 30 56 70 45
	Zigzag View of tree : 50 60 40 30 45 55 70 56
	     50
	  /     \
	 /       \
	40        60
	/   \     /   \
	/     \   /     \
	30    45  55      70
	        \
	         \
	         56

	.....................................................................
	Sample case 2:
	Enter number of elements in tree: 10
	Enter elements to insert in  tree: 50 40 30 45 60 55 54 70 75 72
	Left View of tree : 50 60 40 30 45 55 70 75 54 72
	     50
	  /     \
	 /       \
	40        60
	/   \     /   \
	/     \   /     \
	30    45   55      70
	       /        \
	      /          \
	      54        75
	                /
	               /
	               72
   
Time Complexity: O(n) 
Space Complexity: O(n)
*/
