//This is the post-order traversal 
/*
Author - Chaitanya Khinvasara
*/

/*
Working of the algorithm 
   
   1. Traverse the left subtree until you find null
   2. Traverse the right subtree until you find null
   3. Visit the root.
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

//Post-order traversal
void postorder(struct node *root)
{
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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


    cout<<"Post-order is " <<endl;
    postorder(root);
    return 0;
}
