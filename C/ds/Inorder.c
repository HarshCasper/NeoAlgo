/*
Inorder Traversal 
Definition of In Order traversal : Process all nodes of a tree by recursively processing the left subtree, then processing the root, and finally the right subtree
In-order traversal is mainly used to print the values, stored in the nodes of a binary search tree, in ascending order. 
Algorithm of Inorder(tree) Traversal
1.Traverse the left subtree, i.e., call Inorder(left-subtree)
2.Visit the root.
3.Traverse the right subtree, i.e., call Inorder(right-subtree)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
	int data;
	struct node * left;
	struct node * right;
}

node;
int count = 1;
node* insert(node *tree, int digit)
{
	if (tree == NULL)
	{
		tree = (node*) malloc(sizeof(node));
		tree->left = tree->right = NULL;
		tree->data = digit;
		count++;
	}
	else if (count % 2 == 0)
		tree->left = insert(tree->left, digit);
	else
		tree->right = insert(tree->right, digit);
	return tree;
}

void inorder(node *t)
{
	if (t != NULL)
	{
		inorder(t->left);
		printf("%d ", t->data);
		inorder(t->right);
	}
}

main()
{
	node *root = NULL;
	int digit;
	puts("Enter integer:To quit enter 0");
	scanf("%d", &digit);
	while (digit != 0)
	{
		root = insert(root, digit);
		scanf("%d", &digit);
	}

	printf("\nThe inorder traversal of tree is:\n");
	inorder(root);
	getchar();
}


/*

Sample Input:
Enter integer:To quit enter 0                                                                                                   
12 4 6 9 14 17 3 19 0

Sample Output:
The inorder traversal of tree is:                                                                                               
19 17 9 4 12 6 14 3

Time Complexity: O(n)
Space Complexity: O(n)
*/
