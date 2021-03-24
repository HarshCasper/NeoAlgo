/*Inorder successor of a node is the next node in inorder traversal of the BST.
There is no inorder successor of the last node in inorder traversal of the BST.
Inorder predecessor of a node is the previous node in inorder traversal of the BST.
There is no inorder predecessor of the first node in inorder traversal of the BST.
*/

#include <stdio.h>
#include <stdlib.h>

struct tree
{
	struct tree * lptr;
	int data;
	struct tree * rptr;
};

//Insert function of BST
void insert(struct tree **b, int n)
{
	if (*b == NULL)
	{
		struct tree *new = (struct tree *) malloc(sizeof(struct tree));
		new->data = n;
		new->lptr = new->rptr = NULL;
		*b = new;
	}
	else
	{
		if ((*b)->data > n)
			insert(&((*b)->lptr), n);
		else
			insert(&((*b)->rptr), n);
	}
}

//Inorder display function using recursion
void inorder(struct tree *b)
{
	if (b != NULL)
	{
		inorder(b->lptr);
		printf("%d  ", b->data);
		inorder(b->rptr);
	}
}

//Function to find inorder predecessor of a node
int in_pre(struct tree *b, int node)
{
	struct tree *x = b, *xpre;
	int pre, flag = 0;
	while (x != NULL && x->data != node)
	{
		if (x->data > node)
			x = x->lptr;
		else
		{
			flag = 1;
			pre = x->data;
			x = x->rptr;
		}
	}

	if (x == NULL)
	{
		printf("Node not present in tree\n");
		return 0;
	}

	if (x->lptr != NULL)
	{
		xpre = x->lptr;
		while (xpre->rptr != NULL)
		{
			xpre = xpre->rptr;
		}

		printf("Predecessor of %d is %d\n", node, xpre->data);
		return 0;
	}
	else if (flag == 1)
		printf("Predecessor of %d is %d\n", node, pre);
	else
		printf("Predecessor of %d does not exist\n", node);
}

//Function to find inorder successor of a node
int in_succ(struct tree *b, int node)
{
	struct tree *x = b;
	int xsucc, f = 0;
	while (x != NULL && x->data != node)
	{
		if (x->data > node)
		{
			f = 1;
			xsucc = x->data;
			x = x->lptr;
		}
		else
			x = x->rptr;
	}

	if (x == NULL)
	{
		printf("Node not present in tree\n");
		return 0;
	}

	if (x->rptr != NULL)
	{
		x = x->rptr;
		while (x->lptr != NULL)
			x = x->lptr;
		printf("Successor of %d is %d\n", node, x->data);
		return 0;
	}
	else if (f == 1)
		printf("Successor of %d is %d\n", node, xsucc);
	else
		printf("Successor of %d does not exist\n", node);
}

int main()
{
	struct tree *root = NULL;
	char c;
	int ch, n;
	do {
		printf("\nMenu:\n1.Insert\t\t\t\t2.Inorder display\n3.Inorder Predecessor of a node\t\t4.Inorder Successor of a node\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				{
					printf("Enter data: ");
					scanf("%d", &n);
					insert(&root, n);
					break;
				}

			case 2:
				{
					if (root == NULL)
						printf("Tree is empty\n");
					else
					{
						printf("In-order Display: ");
						inorder(root);
						printf("\n");
					}

					break;
				}

			case 3:
				{
					if (root == NULL)
						printf("Tree is empty\n");
					else
					{
						printf("Enter the node for which you want inorder predecessor: ");
						scanf("%d", &n);
						in_pre(root, n);
					}

					break;
				}

			case 4:
				{
					if (root == NULL)
						printf("Tree is empty\n");
					else
					{
						printf("Enter the node for which you want inorder successor: ");
						scanf("%d", &n);
						in_succ(root, n);
					}

					break;
				}

			default:
				printf("Not a choice\n");
				break;
		}

		printf("Do you want to continue:(Y/y) ");
		scanf(" %c", &c);
	} while (c == 'Y' || c == 'y');
	return 0;
}

/*
Time Complexity:
Insertion - O(n)
Inorder display - O(n)
Inorder predecessor function - O(n)
Inorder successor function - O(n)

Space Complexity: O(n)

Sample Output: 
Menu:
1.Insert                                2.Inorder display
3.Inorder Predecessor of a node         4.Inorder Successor of a node
Enter your choice: 1
Enter data: 3
Do you want to continue:(Y/y) y
Menu:
1.Insert                                2.Inorder display
3.Inorder Predecessor of a node         4.Inorder Successor of a node
Enter your choice: 1
Enter data: 5
Do you want to continue:(Y/y) y
Menu:
1.Insert                                2.Inorder display
3.Inorder Predecessor of a node         4.Inorder Successor of a node
Enter your choice: 1
Enter data: 9
Do you want to continue:(Y/y) y
Menu:
1.Insert                                2.Inorder display
3.Inorder Predecessor of a node         4.Inorder Successor of a node
Enter your choice: 1
Enter data: 14
Do you want to continue:(Y/y) y
Menu:
1.Insert                                2.Inorder display
3.Inorder Predecessor of a node         4.Inorder Successor of a node
Enter your choice: 2
In-order Display: 3  5  9  14  
Do you want to continue:(Y/y) y
Menu:
1.Insert                                2.Inorder display
3.Inorder Predecessor of a node         4.Inorder Successor of a node
Enter your choice: 3
Enter the node for which you want inorder predecessor: 5
Predecessor of 5 is 3
Do you want to continue:(Y/y) y
Menu:
1.Insert                                2.Inorder display
3.Inorder Predecessor of a node         4.Inorder Successor of a node
Enter your choice: 4
Enter the node for which you want inorder successor: 9
Successor of 9 is 14
Do you want to continue:(Y/y) n
*/
