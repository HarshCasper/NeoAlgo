//This is the pre-order traversal of the binary tree
/*
Author - Chaitanya Khinvasara
*/

/*
Working of the algorithm 
   1. Visit the root.
   2. Traverse the left subtree until you find null
   3. Traverse the right subtree until you find null
*/



#include <iostream>
using namespace std;


struct node
{
    int data;
    struct node *left, *right;
};

//Creation of new node
struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
};

//insertion of the node
struct node * insert(struct node *root, int element)
{
    if(root == NULL)
        return newNode(element);
    if(root->data > element)
        root->left = insert(root->left, element);
    else if (root->data < element)
        root->right = insert(root->right, element);
    return root;
}

//Pre-order traversal
void preorder(struct node *root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 60);
    insert(root, 40);
    insert(root, 50);
    insert(root, 70);
    insert(root, 80);
    insert(root, 10);


    cout<<"Pre-order is " <<endl;
    preorder(root);
    return 0;
}