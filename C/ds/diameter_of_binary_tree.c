/*algorithm for finding diameter of binary tree;the diameter of a tree (sometimes called the width)is the number of nodes on the longest 
path between two leaf nodes in the tree*/
#include <stdio.h>
#include <malloc.h>

struct BinaryTree {
    int data;
    struct BinaryTree *left, *right;
};
/*creates binary tree*/
struct BinaryTree* creation()
{
    struct BinaryTree* new_node;
    int choice;
    new_node = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    printf("enter the data of node");
    scanf("%d", &new_node->data);
    new_node->left = NULL;
    new_node->right = NULL;

    printf("press 1 if %d has left child else press 2", new_node->data);
    scanf("%d", &choice);
    if (choice == 1) {
        new_node->left = creation();
    }
    printf("press 1 if %d has right child else press 2", new_node->data);
    scanf("%d", &choice);
    if (choice == 1) {
        new_node->right = creation();
    }
    return new_node;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
/*computes height of binary tree*/
int Height(struct BinaryTree* root)
{
    if (root == NULL)
        return 0;

    return 1 + max(Height(root->left), Height(root->right));
}
/*computes diameter of binary tree*/
int diameter(struct BinaryTree* root)
{
    if (root == NULL)
        return 0;
    int lHeight = Height(root->left);
    int rHeight = Height(root->right);

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);
    /*diameter is maximum out of the following :
	1.diameter of left subtree
	2.diameter of right sub tree
	3.longest path between leaves that goes through the root*/
    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}
/*display binary tree(inorder)*/
void inorder(struct BinaryTree* root)
{
    if (root) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct BinaryTree* root;
    root = creation();
    printf("\nINORDER TRAVERSAL: ");
    inorder(root);
    printf("\nDIAMETER: %d", diameter(root));
    return 0;
}
/*sample input output
enter the data of node1
press 1 if 1 has left child else press 21
enter the data of node2
press 1 if 2 has left child else press 21
enter the data of node3
press 1 if 3 has left child else press 22
press 1 if 3 has right child else press 22
press 1 if 2 has right child else press 21
enter the data of node4
press 1 if 4 has left child else press 22
press 1 if 4 has right child else press 22
press 1 if 1 has right child else press 21
enter the data of node5
press 1 if 5 has left child else press 22
press 1 if 5 has right child else press 22

INORDER TRAVERSAL: 3->2->4->1->5->
DIAMETER: 4

Time Complexity: O(n^2)
Space Complexity: O(n)*/
