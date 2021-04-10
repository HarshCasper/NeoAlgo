/*
Construction of binary tree from inorder and preorder traversal

binary tree can be uniquely constructed if it's preorder and inorder traversals
are given.
The following steps need to be followed
1. From the preorder traversal , it is evident that the first element is the root node
2. In inorder traversal, all the nodes which are on the left side of root (from preorder)
belong to the left sub-tree and those which are on right side of the root (from preorder)
are on right side of root (from preorder) belong to right sub-tree
3. Now the problem reduces to form sub-trees and the same procedure can be applied
repeatedly.
*/

#include <stdio.h>
#include <stdlib.h>
//struct for binary tree
typedef struct Tree
{
    char data;
    struct Tree *left;
    struct Tree *right;
} TreeNode;
// search function searches the inorder traversal and returns the index if found
int search(char in[], int start, int end, char key)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == key)
        {
            return i;
        }
    }
}

// Build Tree Builds the tree from preorder and inorder traversals

TreeNode *BuildTree(char in[], char pre[], int start, int end)
{
    //preindex is static as it should get incremented after each recursive calls
    static int preindex = 0;
    if (start > end)
    {
        return NULL;
    }
    //get New node and make left and right as null
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = pre[preindex];
    node->left = NULL;
    node->right = NULL;
    preindex++;
    //if there is only one node return that node
    if (start == end)
    {
        return node;
    }
    // find the location of the root from the preorder traversal in the inorder
    //traversal and store it in loc
    int loc = search(in, start, end, node->data);
    //the elements to the left of the inorder traversal forms the left subtree
    node->left = BuildTree(in, pre, start, loc - 1);
    // the elements to the right of the inorder traversal forms the right subtree
    node->right = BuildTree(in, pre, loc + 1, end);
    return node;
}

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void printTree(TreeNode *root)
{
    printf("\nThe inorder traversal of the tree is\n");
    inorder(root);
    printf("\nThe preorder traversal of the tree is\n");
    preorder(root);
    printf("\nThe postorder traversal of the tree is\n");
    postorder(root);
    printf("\n");
}

int main()
{
    printf("Enter the number of nodes in the binary tree \n");
    int n;
    scanf("%d", &n);
    char *pre = (char *)malloc(sizeof(char) * (n + 1));
    char *in = (char *)malloc(sizeof(char) * (n + 1));
    printf("Enter the preorder traversal of the tree\n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &pre[i]);
    }
    printf("Enter the inorder traversal of the tree \n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &in[i]);
    }
    TreeNode *root = BuildTree(in, pre, 0, n - 1);
    printTree(root);
    return 0;
}
/*
Sample I/O :
1)
Enter the number of nodes in the binary tree
6
Enter the preorder traversal of the tree
A B D E C F
Enter the inorder traversal of the tree
D B E A F C

The inorder traversal of the tree is
D B E A F C
The preorder traversal of the tree is
A B D E C F
The postorder traversal of the tree is
D E B F C A


2)
Enter the number of nodes in the binary tree
4
Enter the preorder traversal of the tree
A B D C
Enter the inorder traversal of the tree
B D A C

The inorder traversal of the tree is
B D A C
The preorder traversal of the tree is
A B D C
The postorder traversal of the tree is
D B C A

Time complexity : O( n^2 )
Space complexity : O( n )
*/
