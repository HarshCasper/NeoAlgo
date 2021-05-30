/* 
CODE DESCRIPTION:
Following is the implementation to create a new binary tree which is a mirror image of the given binary tree.
*/
#include <stdio.h>
#include <stdlib.h>
/* Defining The structure of a Tree Node */
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

int count = 1;

/* Function for Inserting Nodes in a Tree */
struct Node* insert(struct Node *root, int value)
{
	if (root == NULL)
	{
		root = (struct Node*) malloc(sizeof(struct Node));
		root->left = root->right = NULL;
		root->data = value;
		count++;
	}
	else if (count % 2 == 0)
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);
	
	return root;
}

/* Function to print Nodes of a Tree */
void inorder(struct Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    inorder(temp->left);
    printf("--->%d", temp->data);
    inorder(temp->right);
}

/* Function to Find Mirror of the Binary Tree */
void Mirror(struct Node *temp)
{
	/* If tree is NULL */
	if(temp == NULL)
	{
		return;
	}
	/* If leaf node present */
	if(temp ->right == NULL && temp->left == NULL)
	{
		return;
	}
	/* If node has a left child */
	if(temp->left)
		Mirror(temp->left);
	/* If node has a right child */
	if(temp->right)
		Mirror(temp->right);
	/* Interchanging left and right pointers */
	struct Node *temp1 = temp->left;
	temp->left = temp->right;
	temp->right = temp1;
		
}

/* Driver Function */
void main()
{
    struct Node *root = NULL;
    int value;
    
    printf("Enter value of node:To quit enter 0\n");
	scanf("%d", &value);
	
	while (value != 0)
	{
		root = insert(root, value);
		scanf("%d", &value);
	}

	printf("\nBinary Tree\n");
	inorder(root);
	
	printf("\nMirror of a Binary Tree\n");
	Mirror(root);
	
	inorder(root);
	   
}
/*
COMPLEXITY
Time complexity : O(n)
Space complexity : O(n)

OUTPUT:
Enter value of node:To quit enter 0
1
2
3
4
5
0

Binary Tree
--->4--->2--->1--->3--->5
Mirror of a Binary Tree
--->5--->3--->1--->2--->4
*/
