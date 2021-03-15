/* COUNT OF LEAF NODES IN BINARY SEARCH TREE
    Binary Search Tree is a special type of binary tree where 
    1. The value of all the nodes in the left sub-tree is less than or equal to the value of the root.
    2. The value of all the nodes in the right sub-tree is greater than value of the root.
    3. This rule will be recursively applied to all the left and right sub-trees of the root.

    Leaf node is a node which does not have left or right child
    No. of leaf nodes varies with the order in which the nodes are inserted
*/

#include <stdio.h>
#include <stdlib.h>

/* Declare treeNode with data , rc (right child) and lc (left child )
    Initially count of leaf nodes is set as 0
*/
typedef struct treeNode
{
    int data;
    struct treeNode *lc;
    struct treeNode *rc;
} treeNode;

int count = 0;

//to insert a node into BST
treeNode *insertIntoTree(treeNode *root, int data)
{
    //If tree is empty insert as root node
    if (root == NULL)
    {
        treeNode *ptr;
        ptr = malloc(sizeof(treeNode));
        ptr->data = data;
        ptr->lc = NULL;
        ptr->rc = NULL;
        root = ptr;
    }
    else
    {
        // insert recursively in accordance with BST properties
        if (root->data >= data)
        {
            root->lc = insertIntoTree(root->lc, data);
        }
        else if (root->data < data)
        {
            root->rc = insertIntoTree(root->rc, data);
        }
    }
    return root;
}

//to count the leaf nodes
int leaf_nodes(treeNode *root)
{
    //If tree is not empty
    if (root)
    {
        //If the node doesn't have any child increment count
        if (root->lc == NULL && root->rc == NULL)
            count++;
        else
        {
            //recursively check left and right sub-trees
            if (root->lc)
                leaf_nodes(root->lc);
            if (root->rc)
                leaf_nodes(root->rc);
        }
    }
    return count;
}

// driver code
void main()
{
    //Initialize tree as empty
    treeNode *root;
    root = NULL;
    int n, data;
    //Accept the no. of elements and elements as user input
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insertIntoTree(root, data);
    }

    printf("\nNo. of leaf nodes in the binary search tree = %d", leaf_nodes(root));
    printf("\n");
}

/*
    Sample input:
    7
    1 6 2 5 3 8 4

    Sample output:
    No. of leaf nodes in the binary search tree = 2
*/

/*
    Time complexity : O(n)
    Space complexity : O(n)
*/
