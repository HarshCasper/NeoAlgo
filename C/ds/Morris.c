/*
Code Description:
Following is the implementation of Morris(Inorder) Traversal in a Tree that does not employ the use of recursion or a stack. 
The basic idea is to link predecessor back to current node so that we can trace back to top of the Tree. 
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

/* Function for Creation of a Node */
struct Node *create(int t)
{
	struct Node *temp=malloc(sizeof(struct Node));
	temp->data =t;
	temp->left = temp->right = NULL;
	return temp;
}

/* Function for Inserting Nodes in a Tree */
struct Node *Insert(struct Node *root,int data)
{
	
	if(root == NULL)
	{ 
		root = create(data);
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left,data);
	}
	else 
	{
		root->right = Insert(root->right,data);
	}
	
	return root;
	
}

/* Morris Inorder Traversal */
void Morris(struct Node* temp)
{
	struct Node  *q1;

	/* If the Tree is empty */
	if (temp == NULL)
	{
		return;
	}
	
	/* If Tree is not empty */
	while (temp != NULL)
	{
		/* If the tree only has right subtree */
		if (temp->left == NULL)
		{
			/* Print the root data then traverse the right subtree */
			printf("-->%d", temp->data);
			temp = temp->right;
		}
		
		/*If the left subtree exists */
		else 
		{
			/*Point q1 to left child of current node */
			q1 = temp->left;
			
			/* Traverse till the rightmost node of q1*/
			while (q1->right != NULL && q1->right != temp)
				q1 = q1->right;
				
			/* If the right child of the rightmost node is NULL */
			if (q1->right == NULL)
			{
				/* Make temp as the right child of q1 i.e. Rightmost Child of Left Child of Current Node */
				q1->right = temp;
				temp =temp->left;
			}	
			else 
			{
				/* Print root data and make temp point to it's right child */
				q1->right = NULL;
				printf("-->%d",temp->data);
				temp=temp->right;
			}
		}
	}
} 

/* Driver Function */
void main()
{
    struct Node *root = NULL;
    int i,n,val;
    
	printf("Enter no of nodes : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter value of node : ");
		scanf("%d",&val);
		root = Insert(root,val);
	}
	
    printf("\nMorris Order traversal\n");
    Morris(root);	      
}

/* 
COMPLEXITY:
Time Complexity : O(n)
Space Complexity : O(1)

OUTPUT:
Enter no of nodes : 6

Enter value of node : 9

Enter value of node : 5

Enter value of node : 3

Enter value of node : 7

Enter value of node : 2

Enter value of node : 6

Morris Order traversal
-->2-->3-->5-->6-->7-->9

*/
