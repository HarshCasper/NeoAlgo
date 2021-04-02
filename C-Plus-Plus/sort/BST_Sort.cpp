/* SORTING USING BINARY SEARCH TREE
    Binary Search Tree is a special type of binary tree where
    1. The value of all the nodes in the left sub-tree is less than or equal to the value of the root.
    2. The value of all the nodes in the right sub-tree is greater than value of the root.
    3. This rule will be recursively applied to all the left and right sub-trees of the root.

    Inorder traversal
    1. Traverse the left subtree
    2. Visit the root.
    3. Traverse the right subtree

    Inorder traversal in BST gives sorted list
*/

#include <bits/stdc++.h>
using namespace std;

// Declare treeNode with data , rc (right child) and lc (left child )
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
        ptr = new treeNode;
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

//to sort-inorder traversal gives sorted list
void inorder(treeNode *root)
{
    //If tree is empty
    if (root)
    {
        // recursively visit left sub-tree,root and right sub-tree
        inorder(root->lc);
        printf("%d ", root->data);
        inorder(root->rc);
    }
}

// driver code
int main()
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
    printf("\nSorted list : ");
    inorder(root);
    printf("\n");
    return 0;
}
/*
    Sample input:
    7
    1 2 5 3 7 4 6

    Sample output:
    1 2 3 4 5 6 7
*/
/*
    Time complexity : O(n)
    Space complexity : O(n)
*/
