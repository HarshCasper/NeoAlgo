/*
DESCRIPTION -
Threaded binary tree are used to make faster inorder traversal without using stack or recursion.
It stores the inorder successor, if the right node is empty.
And stores the inorder predecessor if left node is empty.
- There are functions to add, delete and search for an element.
- Also the inorder for the tree. 
*/
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#define COUNT 10
using namespace std;

typedef struct Node
{
	int data;
	// 1 for address of child, 0 address of parent
	int leftflag, rightflag;
	struct Node *left, *right;

}

Node;
void add(Node **p, int v)
{
	Node *newnode = (Node*) malloc(sizeof(Node));
	newnode->data = v;
	// by default both the flags will be 0
	newnode->leftflag = 0;
	newnode->rightflag = 0;
	// if its the root node it will have no inorder predecessor or successor
	if (*p == NULL)
	{
		newnode->left = NULL;
		newnode->right = NULL;
		*p = newnode;
	}
	else
	{
		Node *temp = *p;
		// This loop will find the inorder predecessor or successor
		while (1)
		{
			if (temp->data > v && temp->leftflag == 1)
				temp = temp->left;
			else if (temp->data < v && temp->rightflag == 1)
				temp = temp->right;
			else
				break;
		}

		// temp is now the inorder predecessor or successor
		// This will update the new node that is created with the links to its inorder predecessor or successor
		if (temp->data < v)
		{
			newnode->right = temp->right;
			// points at the child
			temp->right = newnode;
			temp->rightflag = 1;
			// points at the parent
			newnode->left = temp;
		}
		else
		{
			newnode->left = temp->left;
			// points at the child
			temp->left = newnode;
			temp->leftflag = 1;
			// points at the parent
			newnode->right = temp;
		}
	}
}

void inorder(Node *p)
{
	while (1)
	{
		// goes to left most
		while (p->leftflag)
			p = p->left;
		cout << p->data << " ";
		// right flag must be 0 so that it goes to the parent and not the child
		while (!p->rightflag)
		{
			p = p->right;
			if (p == NULL)
				return;
			cout << p->data << " ";
		}

		p = p->right;
	}
}

// returns 1 if present else 0
int TBTsearch(Node *p, int value)
{
	while (1)
	{
		// left flag must be 1 to make sure it goes to the child and not the parent
		if (p->data > value && p->leftflag)
		{
			p = p->left;
		}

		// right flag must be 1 to make sure it goes to the child and not the parent
		else if (p->data < value && p->rightflag)
		{
			p = p->right;
		}
		else
		{
			// the element has been found or reached the end and value is not found so does not exist in the tree 
			break;
		}
	}

	if (p->data == value)
	{
		return 1;
	}

	return 0;
}

int main()
{
	/*
	This is how the tree will look like
	- means the flag values for that node is 1

	                    -50-
	                   /   \
	                 40    -70-
	                      /    \
	                     60    80

	*/
	Node *root = NULL;
	int option, element;
	cout << "MENU\n\nEnter 1. Insert an element\nEnter 2. Inorder of the tree\nEnter 3. Search for an element\nEnter 4. Exit\n";

	while (option != 4)
	{
		cout << "\nEnter your option: ";
		cin >> option;

		if (option == 1)
		{
			cout << "Enter the element you want to insert: ";
			cin >> element;
			add(&root, element);
			cout << element << " has been inserted into the tree.\n";
		}
		else if (option == 2)
		{
			inorder(root);
			cout << endl;
		}
		else if (option == 3)
		{
			cout << "Enter the element you want to search: ";
			cin >> element;
			cout << TBTsearch(root, element) << endl;
		}
		else if (option != 4)
		{
			cout << "Enter a valid number!\n";
		}
	}

	cout << "Exiting.... ";
	return 0;
}

// Contributed by Vaishnavi Shah
