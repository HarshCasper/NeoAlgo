/******************************************************************************
Author: @Suvraneel Bhuin

Inorder Traversal of a Binary Tree

Definition: Process all nodes of a tree by recursively processing the left subtree, then processing the root, and finally the right subtree
In-order traversal is mainly used to print the values, stored in the nodes of a binary search tree, in ascending order. 
Algorithm of Inorder(tree) Traversal
1.Traverse the left subtree, i.e., call Inorder(left-subtree)
2.Visit the root.
3.Traverse the right subtree, i.e., call Inorder(right-subtree)
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
int key;
struct node *lt;
struct node *rt;
}*root = NULL, *temp = NULL;
//root & temp are made global so that we dont need to pass those again & again

// Function to search the appropriate position to insert the new node
void search(struct node *t)
{
    if ((temp->key > t->key) && (t->rt != NULL))            //key > root node move down more right
        search(t->rt);
    else if ((temp->key > t->key) && (t->rt == NULL))       //if right node NULL, insert key
        t->rt = temp;
    else if ((temp->key < t->key) && (t->lt != NULL))       //key < root node move down more left */
        search(t->lt);
    else if ((temp->key < t->key) && (t->lt == NULL))       //if left node NULL, insert key
        t->lt = temp;
}

/* To insert a node in the tree */
void insert()
{
    int data;
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct node *)malloc(1*sizeof(struct node));
    temp->key = data;
    temp->lt = temp->rt = NULL;             //initialise lt & rt child as null

    if (root == NULL) 
    root = temp;
    else    
    search(root);    
}

/* recursive function to perform inorder (L-V-R) traversal of tree */
void inorder(struct node *t)
{
if (root == NULL)                                           //empty tree
{
    printf("No elements in a tree to display");
    return;
}

if (t->lt != NULL)                                          //  L    (Left)
    inorder(t->lt);                                         //  ↓       ↓
    printf("%d => ", t->key);                               //  V    (Visit)
if (t->rt != NULL)                                          //  ↓       ↓
    inorder(t->rt);                                         //  R    (Right)
}

//main driver
void main()
{
    int choice;
    printf("\n------------------------------------");
    printf("\n1 - Insert an element into tree");
    printf("\n2 - Inorder Traversal");
    printf("\n3 - Exit");
    printf("\n------------------------------------");

    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:    
            insert();
            break;

            case 2:
            printf("Inorder Traversal :\n");
            inorder(root);
            break;

            case 3:
            printf("Program terminated\n");
            exit(0);

            default :     
            printf("Invalid Choice entered");
            break;    
        }
    }
}

/*
Time Complexity : O(n)
Space Complexity: O(h)              (where h is the height of the Tree)

Sample Run:
------------------------------------
1 - Insert an element into tree     
2 - Inorder Traversal
3 - Exit
------------------------------------
Enter your choice : 1
Enter data of node to be inserted : 12

Enter your choice : 1
Enter data of node to be inserted : 4

Enter your choice : 1
Enter data of node to be inserted : 6

Enter your choice : 1
Enter data of node to be inserted : 9

Enter your choice : 1
Enter data of node to be inserted : 14

Enter your choice : 1
Enter data of node to be inserted : 17

Enter your choice : 1
Enter data of node to be inserted : 3

Enter your choice : 1
Enter data of node to be inserted : 19

Enter your choice : 2
Inorder Traversal :
3 => 4 => 6 => 9 => 12 => 14 => 17 => 19 =>
Enter your choice : 3
Program Terminated
*/
